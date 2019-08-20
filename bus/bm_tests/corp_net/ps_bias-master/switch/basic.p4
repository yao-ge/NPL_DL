/* -*- P4_16 -*- */
#include <core.p4>
#include <v1model.p4>


#define DEBUG

#define JOB_SIZE 4
#define BLOCK_SIZE 4
#define WORKER_NUM 4
#define WORKER_BITS ((1<<WORKER_NUM)-1)

//#define VALUE_BITS 8256
//#define VALUE_BITS 10288
//#define VALUE_BITS 65600
//#define VALUE_BITS 131136
//#define VALUE_BITS 262208
//#define VALUE_BITS 516160
#define VALUE_BITS 523760

#define BLOCK_ADDR (meta.ps_metadata.job_id * BLOCK_SIZE + meta.ps_metadata.sequence % BLOCK_SIZE)
#define WORKER_BITS_ADDR BLOCK_ADDR 
#define WORKER_BITS_RESET_ADDR (meta.ps_metadata.job_id * BLOCK_SIZE +(meta.ps_metadata.sequence - (BLOCK_SIZE/2))% BLOCK_SIZE); 
#define WORKER_COUNT_ADDR BLOCK_ADDR
#define WORKER_INFO_SAVE_ADDR (meta.ps_metadata.job_id * WORKER_NUM + meta.ps_metadata.worker_count - 1);
#define WORKER_INFO_LOAD_ADDR (meta.ps_metadata.job_id * WORKER_NUM + meta.ps_metadata.worker_count);

const bit<16> TYPE_IPV4 = 16w0x800;

/*************************************************************************
 *********************** H E A D E R S  ***********************************
 *************************************************************************/
typedef bit<48> macAddr_t;
typedef bit<32> ip4Addr_t;

struct intrinsic_metadata_t {
    bit<16> mcast_grp;
    bit<16> egress_rid;
    bit<16> mcast_hash;
    bit<32> lf_field_list;
    bit<48> ingress_global_timestamp;
}

struct routing_metadata_t {
    bit<32> nhop_ipv4;
}

struct ps_metadata_t {
    bit<16> job_id;
    bit<16> max_worker;
    bit<16> worker_id;
    bit<16> sequence;
    bit<16> exp;
    bit<16> bias;
    bit<16> bias_exp;
    bit<16> worker_count;
    bit<16> worker_init_bits;
    bit<16> worker_bits;
    bit<16> max_worker_bits;
    bit<16> reset_worker_bits;
    bit<VALUE_BITS> masks;
}

header ethernet_t {
    macAddr_t dstAddr;
    macAddr_t srcAddr;
    bit<16>   etherType;
}

header ipv4_t {
    bit<4>    version;
    bit<4>    ihl;
    bit<8>    diffserv;
    bit<16>   totalLen;
    bit<16>   identification;
    bit<3>    flags;
    bit<13>   fragOffset;
    bit<8>    ttl;
    bit<8>    protocol;
    bit<16>   hdrChecksum;
    ip4Addr_t srcAddr;
    ip4Addr_t dstAddr;
}

header udp_t {
    bit<16>   sport;
    bit<16>   dport;
    bit<16>   length;
    bit<16>   checksum;
    bit<16>   job_id;
    bit<16>   max_worker;
    bit<16>   worker_id;
    bit<16>   sequence;
    bit<16>   exp;
    bit<16>   bias;
    bit<16>   bias_exp;
    bit<VALUE_BITS>   payload;
}

header ps_t {

    bit<16>   value;

}
struct metadata {
    intrinsic_metadata_t intrinsic_metadata;
    routing_metadata_t   routing_metadata;
    ps_metadata_t       ps_metadata;
}

struct headers {
    ethernet_t        ethernet;
    ipv4_t            ipv4;
    udp_t             udp;
}

/*************************************************************************
 *********************** P A R S E R  ***********************************
 *************************************************************************/

parser MyParser(packet_in packet,
        out headers hdr,
        inout metadata meta,
        inout standard_metadata_t standard_metadata) {

    state start {
        transition parse_ethernet;
    }
    state parse_ethernet {
        packet.extract(hdr.ethernet);
        transition select(hdr.ethernet.etherType){
            TYPE_IPV4 : parse_ipv4;
            default : accept;
        }
    }
    state parse_ipv4 {
        packet.extract(hdr.ipv4);
        transition parse_udp;
    }

    state parse_udp {
        packet.extract(hdr.udp);
        meta.ps_metadata.job_id = hdr.udp.job_id;
        meta.ps_metadata.max_worker = hdr.udp.max_worker;
        meta.ps_metadata.worker_id = hdr.udp.worker_id;
        meta.ps_metadata.sequence = hdr.udp.sequence;
        meta.ps_metadata.exp = hdr.udp.exp;
        meta.ps_metadata.bias = hdr.udp.bias;
        meta.ps_metadata.bias = hdr.udp.bias_exp;
        transition accept;
    }

}

/*************************************************************************
 ************   C H E C K S U M    V E R I F I C A T I O N   *************
 *************************************************************************/

control MyVerifyChecksum(inout headers hdr, inout metadata meta) {   
    apply {  }
}

/*************************************************************************
 ************************  R E G I S T E R S   ***************************
 *************************************************************************/

register<bit<VALUE_BITS>>(BLOCK_SIZE * JOB_SIZE)            ps_value;
register<bit<16>>(BLOCK_SIZE * JOB_SIZE)                    ps_exp;
register<bit<16>>(BLOCK_SIZE * JOB_SIZE)                    ps_bias;
register<bit<16>>(BLOCK_SIZE * JOB_SIZE)                    ps_bias_exp;
register<bit<16>>(BLOCK_SIZE * JOB_SIZE)                    ps_worker_init_bits;
register<bit<16>>(BLOCK_SIZE * JOB_SIZE)                    ps_worker_bits;
register<bit<16>>(BLOCK_SIZE * JOB_SIZE)                    ps_worker_count;
register<bit<48>>(JOB_SIZE * WORKER_NUM)                    ps_worker_smac;
register<bit<32>>(JOB_SIZE * WORKER_NUM)                    ps_worker_sip;
register<bit<16>>(JOB_SIZE * WORKER_NUM)                    ps_worker_sport;

/*************************************************************************
 **************  I N G R E S S   P R O C E S S I N G   *******************
 *************************************************************************/

control MyIngress(inout headers hdr,
        inout metadata meta,
        inout standard_metadata_t standard_metadata) {

    action _drop() {
        mark_to_drop();
    }

    action reset_all(){
        bit<32> index = (bit<32>)meta.ps_metadata.job_id * BLOCK_SIZE;
        ps_worker_bits.write(index, 0 );index = index + 1;
        ps_worker_bits.write(index, 0 );index = index + 1;
        ps_worker_bits.write(index, 0 );index = index + 1;
        ps_worker_bits.write(index, 0 );index = index + 1;
#if BLOCK_SIZE > 4        
        ps_worker_bits.write(index, 0 );index = index + 1;
        ps_worker_bits.write(index, 0 );index = index + 1;
        ps_worker_bits.write(index, 0 );index = index + 1;
        ps_worker_bits.write(index, 0 );index = index + 1;
#if BLOCK_SIZE > 8        
        ps_worker_bits.write(index, 0 );index = index + 1;
        ps_worker_bits.write(index, 0 );index = index + 1;
        ps_worker_bits.write(index, 0 );index = index + 1;
        ps_worker_bits.write(index, 0 );index = index + 1;
        ps_worker_bits.write(index, 0 );index = index + 1;
        ps_worker_bits.write(index, 0 );index = index + 1;
        ps_worker_bits.write(index, 0 );index = index + 1;
        ps_worker_bits.write(index, 0 );index = index + 1;
#if BLOCK_SIZE > 16        
        ps_worker_bits.write(index, 0 );index = index + 1;
        ps_worker_bits.write(index, 0 );index = index + 1;
        ps_worker_bits.write(index, 0 );index = index + 1;
        ps_worker_bits.write(index, 0 );index = index + 1;
        ps_worker_bits.write(index, 0 );index = index + 1;
        ps_worker_bits.write(index, 0 );index = index + 1;
        ps_worker_bits.write(index, 0 );index = index + 1;
        ps_worker_bits.write(index, 0 );index = index + 1;
        ps_worker_bits.write(index, 0 );index = index + 1;
        ps_worker_bits.write(index, 0 );index = index + 1;
        ps_worker_bits.write(index, 0 );index = index + 1;
        ps_worker_bits.write(index, 0 );index = index + 1;
        ps_worker_bits.write(index, 0 );index = index + 1;
        ps_worker_bits.write(index, 0 );index = index + 1;
        ps_worker_bits.write(index, 0 );index = index + 1;
        ps_worker_bits.write(index, 0 );index = index + 1;
#endif        
#endif        
#endif        
    }

    action bcast(){
        meta.intrinsic_metadata.mcast_grp = 1;
        standard_metadata.mcast_grp = 1;
    }

    action set_dmac(bit<48> dmac) {
        hdr.ethernet.dstAddr = dmac;
    }
    
    action update_all_header(){
        bit<48> tmp48;
        tmp48 = hdr.ethernet.dstAddr;
        hdr.ethernet.dstAddr = hdr.ethernet.srcAddr;
        hdr.ethernet.srcAddr = tmp48;
        standard_metadata.egress_spec = standard_metadata.ingress_port;
        hdr.ipv4.ttl = hdr.ipv4.ttl + 8w255;
 
        bit<32> tmp32;
        tmp32 = hdr.ipv4.dstAddr;
        hdr.ipv4.dstAddr = hdr.ipv4.srcAddr;
        hdr.ipv4.srcAddr = tmp32;
 
        bit<16> tmp16;
        tmp16 = hdr.udp.dport;
        hdr.udp.dport = hdr.udp.sport;
        hdr.udp.sport = tmp16;
    }

    action save_worker() {
        bit<32> index = (bit<32>)WORKER_INFO_SAVE_ADDR;
        ps_worker_smac.write(index, hdr.ethernet.srcAddr);
        ps_worker_sip.write(index, hdr.ipv4.srcAddr);
        ps_worker_sport.write(index, hdr.udp.sport);
    }

    action worker_count_add() {
        bit<16> tmp;
        bit<32> index = (bit<32>)WORKER_COUNT_ADDR;
        ps_worker_count.read(tmp, index);
        tmp = tmp + 1;
        ps_worker_count.write(index, tmp );
        meta.ps_metadata.worker_count = tmp;
    }

    action worker_count_set(bit<16> value) {
        bit<32> index = (bit<32>)WORKER_COUNT_ADDR;
        ps_worker_count.write(index, value );
        meta.ps_metadata.worker_count = value;
    }

    action worker_count_reset() {
        bit<32> index = (bit<32>)WORKER_COUNT_ADDR;
        ps_worker_count.write(index, 0 );
    }

    action load_bits(){
        bit<16> tmp;
        bit<32> index = (bit<32>)WORKER_BITS_ADDR;
        ps_worker_bits.read(tmp, index);
        meta.ps_metadata.worker_bits = tmp;
    }

    action load_reset_bits(){
        bit<16> tmp;
        bit<32> index = (bit<32>)WORKER_BITS_RESET_ADDR;
        ps_worker_bits.read(tmp, index);
        meta.ps_metadata.reset_worker_bits = tmp;
    }

    action load_init_bits(){
        bit<16> tmp;
        bit<32> index = (bit<32>)WORKER_BITS_ADDR;
        ps_worker_init_bits.read(tmp, index);
        meta.ps_metadata.worker_init_bits = tmp;
    }

    action reset_init_bits(){
        bit<16> tmp;
        bit<32> index = (bit<32>)WORKER_BITS_ADDR;
        ps_worker_init_bits.write(index, 0);
    }

    action set_init_bits( bit<16> val){
        bit<16> tmp;
        bit<32> index = (bit<32>)WORKER_BITS_ADDR;
        ps_worker_init_bits.read(tmp, index);
        tmp = tmp | (16w1 << (bit<8>)val);
        ps_worker_init_bits.write(index, tmp);
        meta.ps_metadata.worker_init_bits = tmp;
    }

    action reset_bits(){
        bit<16> tmp;
        bit<32> index = (bit<32>)WORKER_BITS_RESET_ADDR;
        ps_worker_bits.write(index, 0);
    }

    action set_bits( bit<16> val){
        bit<16> tmp;
        bit<32> index = (bit<32>)WORKER_BITS_ADDR;
        ps_worker_bits.read(tmp, index);
        tmp = tmp | (16w1 << (bit<8>)val);
        ps_worker_bits.write(index, tmp);
        meta.ps_metadata.worker_bits = tmp;
    }

    action load_exp() {
        bit<16> tmp;
        bit<32> index = (bit<32>)BLOCK_ADDR;
        ps_exp.read(tmp, index);
        hdr.udp.exp = tmp;
    }

    action read_exp() {
        bit<16> tmp;
        bit<32> index = (bit<32>)BLOCK_ADDR;
        ps_exp.read(tmp, index);
        meta.ps_metadata.exp = tmp;
    }

    action save_first_exp() {
        bit<16> tmp;
        bit<32> index = (bit<32>)BLOCK_ADDR;
        ps_exp.read(tmp, index);
        tmp = hdr.udp.exp;
        ps_exp.write(index, tmp );
    }

    action save_exp() {
        bit<16> tmp;
        bit<32> index = (bit<32>)BLOCK_ADDR;
        ps_exp.read(tmp, index);
        tmp = ( (int<16>)tmp < (int<16>)hdr.udp.exp )?tmp:hdr.udp.exp;
        ps_exp.write(index, tmp );
    }

    action reset_exp() {
        bit<32> index = (bit<32>)BLOCK_ADDR;
        ps_exp.write(index, 0x7fff );
    }

    action load_bias_exp() {
        bit<16> tmp;
        bit<32> index = (bit<32>)BLOCK_ADDR;
        ps_bias_exp.read(tmp, index);
        hdr.udp.bias_exp = tmp;
    }


    action read_bias_exp() {
        bit<16> tmp;
        bit<32> index = (bit<32>)BLOCK_ADDR;
        ps_bias_exp.read(tmp, index);
        meta.ps_metadata.bias_exp = tmp;
    }


    action save_first_bias_exp() {
        bit<16> tmp;
        bit<32> index = (bit<32>)BLOCK_ADDR;
        ps_bias_exp.read(tmp, index);
        tmp = hdr.udp.bias_exp;
        ps_bias_exp.write(index, tmp );
    }

    action save_bias_exp() {
        bit<16> tmp;
        bit<32> index = (bit<32>)BLOCK_ADDR;
        ps_bias_exp.read(tmp, index);
        tmp = ( (int<16>)tmp < (int<16>)hdr.udp.bias_exp )?tmp:hdr.udp.bias_exp;
        ps_bias_exp.write(index, tmp );
    }

    action reset_bias_exp() {
        bit<32> index = (bit<32>)BLOCK_ADDR;
        ps_bias_exp.write(index, 0x7fff );
    }


    action load_bias() {
        bit<16> tmp;
        bit<32> index = (bit<32>)BLOCK_ADDR;
        ps_bias.read(tmp, index);
        hdr.udp.bias = tmp;
    }

    action save_first_bias() {
        bit<16> tmp;
        bit<32> index = (bit<32>)BLOCK_ADDR;
        ps_bias.read(tmp, index);
        tmp = hdr.udp.bias;
        ps_bias.write(index, tmp );
    }

    action save_bias() {
        bit<16> tmp;
        bit<32> index = (bit<32>)BLOCK_ADDR;
        read_bias_exp();
        ps_bias.read(tmp, index);
        int<16> v = (int<16>)meta.ps_metadata.bias_exp - (int<16>)hdr.udp.bias_exp;
        bit<16> shift = (v >= 0)? (bit<16>)v:(bit<16>)(-v);
        tmp = (shift == 0)? (bit<16>)((int<16>)tmp + (int<16>)hdr.udp.bias):( (v>=0)? (bit<16>)(((int<16>)tmp >> (bit<8>)shift)  + (int<16>)hdr.udp.bias):(bit<16>)((int<16>)tmp + ((int<16>)hdr.udp.bias >> (bit<8>)shift) ));
        //tmp = (bit<16>)((int<16>)tmp + (int<16>)hdr.udp.bias);
        ps_bias.write(index, tmp );
    }

    action reset_bias() {
        bit<32> index = (bit<32>)BLOCK_ADDR;
        ps_bias.write(index, 0 );
    }


    action load_value() {
        bit<VALUE_BITS> tmp;
        bit<32> index = (bit<32>)BLOCK_ADDR;
        ps_value.read(tmp, index);
        hdr.udp.payload = tmp;
    }

    action save_first_value() {
        bit<VALUE_BITS> tmp;
        bit<32> index = (bit<32>)BLOCK_ADDR;
        ps_value.read(tmp, index);
        tmp = tmp + hdr.udp.payload;
        ps_value.write(index, tmp );
    }
    
    action calc_masks(bit<16> sh){
        bit<16> shift = sh;
        bit<VALUE_BITS> masks = (bit<VALUE_BITS>)(16w0x7fff);

        masks = (masks << 16) | masks;
        masks = (masks << 32) | masks;
        masks = (masks << 64) | masks;
        masks = (masks << 128) | masks;
        masks = (masks << 256) | masks;
        masks = (masks << 512) | masks;
        masks = (masks << 1024) | masks;
        masks = (masks << 2048) | masks;
        masks = (masks << 4096) | masks;
        masks = (masks << 8192) | masks;
        masks = (masks << 16384) | masks;
        masks = (masks << 32768) | masks;
        masks = (masks << 65536) | masks;
        masks = (masks << 131072) | masks;
        masks = (masks << 261616) | masks;

        shift = (shift == 0)? 0: shift - 1;
        masks = (shift == 0)? masks: ( masks >> 1) & masks;
        shift = (shift == 0)? 0: shift - 1;
        masks = (shift == 0)? masks: ( masks >> 1) & masks;
        shift = (shift == 0)? 0: shift - 1;
        masks = (shift == 0)? masks: ( masks >> 1) & masks;
        shift = (shift == 0)? 0: shift - 1;
        masks = (shift == 0)? masks: ( masks >> 1) & masks;
        shift = (shift == 0)? 0: shift - 1;
        masks = (shift == 0)? masks: ( masks >> 1) & masks;
        shift = (shift == 0)? 0: shift - 1;
        masks = (shift == 0)? masks: ( masks >> 1) & masks;
        shift = (shift == 0)? 0: shift - 1;
        masks = (shift == 0)? masks: ( masks >> 1) & masks;
        shift = (shift == 0)? 0: shift - 1;
        masks = (shift == 0)? masks: ( masks >> 1) & masks;
        shift = (shift == 0)? 0: shift - 1;
        masks = (shift == 0)? masks: ( masks >> 1) & masks;
        shift = (shift == 0)? 0: shift - 1;
        masks = (shift == 0)? masks: ( masks >> 1) & masks;
        shift = (shift == 0)? 0: shift - 1;
        masks = (shift == 0)? masks: ( masks >> 1) & masks;
        shift = (shift == 0)? 0: shift - 1;
        masks = (shift == 0)? masks: ( masks >> 1) & masks;
        shift = (shift == 0)? 0: shift - 1;
        masks = (shift == 0)? masks: ( masks >> 1) & masks;
        shift = (shift == 0)? 0: shift - 1;
        masks = (shift == 0)? masks: ( masks >> 1) & masks;
        shift = (shift == 0)? 0: shift - 1;
        masks = (shift == 0)? masks: ( masks >> 1) & masks;
        shift = (shift == 0)? 0: shift - 1;
        masks = (shift == 0)? masks: ( masks >> 1) & masks;
        meta.ps_metadata.masks = masks;
    }

    action save_value() {
        bit<VALUE_BITS> tmp;
        bit<32> index = (bit<32>)BLOCK_ADDR;
        ps_value.read(tmp, index);
        int<16> v = (int<16>)meta.ps_metadata.exp - (int<16>)hdr.udp.exp;
        bit<16> shift = ( v >= 0)? (bit<16>)v:(bit<16>)(-v);
        calc_masks(shift);
        tmp = (shift == 0)? tmp + hdr.udp.payload:( (v>=0)? (((tmp >> (bit<8>)shift) & meta.ps_metadata.masks) + hdr.udp.payload):(tmp + ((hdr.udp.payload >> (bit<8>)shift ) & meta.ps_metadata.masks)));
        //tmp = tmp + hdr.udp.payload;
        ps_value.write(index, tmp );
    }

    action reset_value() {
        bit<32> index = (bit<32>)BLOCK_ADDR;
        ps_value.write(index, 0 );
    }

    action get_max_worker_bits( bit<16> val ){
        meta.ps_metadata.max_worker_bits = (bit<16>)((32w1 << (bit<8>)val) - 32w1);
    }
/*
    table debuger {
        key = {
            meta.ps_metadata.masks: exact;
        }
        actions = {
            NoAction;
        }
        size = 1024;
        default_action = NoAction();
    }
*/

#ifdef DEBUG
    table debug {
        key = {
            meta.ps_metadata.job_id: exact;
            meta.ps_metadata.max_worker: exact;
            meta.ps_metadata.worker_count: exact;
            meta.ps_metadata.sequence: exact;
            standard_metadata.egress_spec: exact;
            hdr.ipv4.ttl: exact;
        //    hdr.udp.payload: exact;
        }
        actions = {
            NoAction;
        }
        size = 1024;
        default_action = NoAction();
    }

    table debug1 {
        key = {
            meta.ps_metadata.max_worker: exact;
            meta.ps_metadata.worker_count: exact;
            meta.ps_metadata.sequence: exact;
            meta.ps_metadata.max_worker_bits: exact;
        }
        actions = {
            NoAction;
        }
        size = 1024;
        default_action = NoAction();
    }

    table debug_end {
        key = {
            meta.ps_metadata.max_worker: exact;
            meta.ps_metadata.worker_count: exact;
            standard_metadata.egress_spec: exact;
            hdr.ipv4.ttl: exact;
        }
        actions = {
            NoAction;
        }
        size = 1024;
        default_action = NoAction();
    }
#endif
    apply {
        @atomic{

            if(!hdr.ipv4.isValid()){
                _drop();
                return;
            }
            if(!hdr.udp.isValid()){
                _drop();
                return;
            }

            if(hdr.udp.dport != 1111){
                _drop();
                return;
            }

#ifdef DEBUG
            debug.apply();
#endif            
            get_max_worker_bits(meta.ps_metadata.max_worker); // calculate the bits mask of workers
            
            // initialize package
            if( meta.ps_metadata.sequence >= 16w60000){ // for reset operation

                load_init_bits(); 
                if(( meta.ps_metadata.sequence <= 16w65530) && ( meta.ps_metadata.worker_init_bits == 0 )){
                    update_all_header();
                    return;
                }

                if( meta.ps_metadata.worker_init_bits == 0 )
                {
                    worker_count_reset(); // set worker count to 0
                }

                if( meta.ps_metadata.worker_init_bits & (16w1 << (bit<8>)meta.ps_metadata.worker_id) != 0 ){ // this worker has already updated
                    _drop();
                    return;
                }

                set_init_bits(meta.ps_metadata.worker_id);
                worker_count_add();
                save_worker(); // save worker infomation

                if(meta.ps_metadata.worker_init_bits != meta.ps_metadata.max_worker_bits){ // only reset once by worker 0, other workers dont't reset.
                    _drop();
                    return;
                }
                reset_init_bits();
                reset_all();
                update_all_header();
                bcast(); // enable broadcasting 
                return; 
            }

            // update package 
            load_bits();
            if( meta.ps_metadata.worker_bits == meta.ps_metadata.max_worker_bits){ // all workers have updated
                update_all_header();
                load_exp();  // replay values
                load_bias();  // replay values
                load_bias_exp();  // replay values
                load_value();   // replay values
                return; 
            }
#ifdef DEBUG
            debug1.apply();
#endif
            if(meta.ps_metadata.worker_bits == 0){ // no worker updated
                reset_exp(); // set values to 0 
                reset_bias(); // set values to 0 
                reset_bias_exp(); // set values to 0 
                reset_value(); // set values to 0 
                if( meta.ps_metadata.sequence > (BLOCK_SIZE/2) ){
                    load_reset_bits(); // load to worker bit that will be reset
                    if(meta.ps_metadata.reset_worker_bits ==  meta.ps_metadata.max_worker_bits){ // all workers have updated
                        reset_bits(); // clean the worker bits
                    }
                }
            }

            if( meta.ps_metadata.worker_bits & (16w1 << (bit<8>)meta.ps_metadata.worker_id) != 0 ){ // this worker has already updated
                _drop();
                return;
            }

            set_bits(meta.ps_metadata.worker_id); // record the updated worker

            read_exp();
            if(meta.ps_metadata.exp == 0x7fff){
                save_first_exp();
                save_first_bias();
                save_first_bias_exp();
                save_first_value();

            }else{
                save_bias();
                save_bias_exp();
                save_value();
                save_exp();
                //debuger.apply();
            }

            load_bits();
            if(meta.ps_metadata.worker_bits != meta.ps_metadata.max_worker_bits){ // not all workers have updated
                _drop();
                return;
            }
            
            // result package
            worker_count_set(meta.ps_metadata.max_worker);
            update_all_header();
            load_exp();  // replay values
            load_bias();  // replay values
            load_bias_exp();  // replay values
            load_value();  // replay values
            bcast(); // enable broadcasting 
#ifdef DEBUG
            debug_end.apply();
#endif
        }
    }
}

/*************************************************************************
 ****************  E G R E S S   P R O C E S S I N G   *******************
 *************************************************************************/

control MyEgress(inout headers hdr,
        inout metadata meta,
        inout standard_metadata_t standard_metadata) {

    action load_worker() {
        bit<32> index = (bit<32>)WORKER_INFO_LOAD_ADDR;
        ps_worker_smac.read(hdr.ethernet.dstAddr, index);
        ps_worker_sip.read(hdr.ipv4.dstAddr, index);
        ps_worker_sport.read(hdr.udp.dport, index);
    }

    action worker_count_sub() {
        bit<16> tmp;
        bit<32> index = (bit<32>)WORKER_COUNT_ADDR;
        ps_worker_count.read(tmp, index);
        tmp = tmp - 1;
        meta.ps_metadata.worker_count = tmp;
        ps_worker_count.write(index, tmp );
    }

#ifdef DEBUG
    table debug {
        key = {
            hdr.ethernet.dstAddr: exact;
            meta.intrinsic_metadata.mcast_grp: exact;
            meta.routing_metadata.nhop_ipv4: exact;
            meta.ps_metadata.worker_count: exact;
            standard_metadata.egress_spec: exact;
            hdr.ipv4.ttl: exact;
        }
        actions = {
            NoAction;
        }
        size = 1024;
        default_action = NoAction();
    }

    table debug_end {
        key = {
            hdr.ethernet.dstAddr: exact;
            meta.intrinsic_metadata.mcast_grp: exact;
            meta.routing_metadata.nhop_ipv4: exact;
            meta.ps_metadata.worker_count: exact;
            standard_metadata.egress_spec: exact;
            hdr.ipv4.ttl: exact;
        }
        actions = {
            NoAction;
        }
        size = 1024;
        default_action = NoAction();
    }
#endif

    apply {
        @atomic{
#ifdef DEBUG
            debug.apply();
#endif
            if(standard_metadata.mcast_grp == 1){ // broadcasting enabled
                worker_count_sub();
                load_worker();
            }
#ifdef DEBUG            
            debug_end.apply();
#endif            
        }
    }
}

/*************************************************************************
 *************   C H E C K S U M    C O M P U T A T I O N   **************
 *************************************************************************/
 
control MyComputeChecksum(inout headers hdr, inout metadata meta) {
    apply {
        update_checksum(
                hdr.ipv4.isValid(),
                { hdr.ipv4.version,
                hdr.ipv4.ihl,
                hdr.ipv4.diffserv,
                hdr.ipv4.totalLen,
                hdr.ipv4.identification,
                hdr.ipv4.flags,
                hdr.ipv4.fragOffset,
                hdr.ipv4.ttl,
                hdr.ipv4.protocol,
                hdr.ipv4.srcAddr,
                hdr.ipv4.dstAddr },
                hdr.ipv4.hdrChecksum,
                HashAlgorithm.csum16);

        update_checksum_with_payload(
                hdr.udp.isValid(),
                { 
                hdr.ipv4.srcAddr, hdr.ipv4.dstAddr, 8w0, hdr.ipv4.protocol, hdr.ipv4.totalLen, 16w0xffeb,
                hdr.udp.sport,
                hdr.udp.dport,
                hdr.udp.length,
                hdr.udp.job_id,
                hdr.udp.max_worker,
                hdr.udp.worker_id,
                hdr.udp.sequence,
                hdr.udp.exp,
                hdr.udp.bias,
                hdr.udp.bias_exp,
                hdr.udp.payload
                },
                hdr.udp.checksum,
                HashAlgorithm.csum16);

    }
}

/*************************************************************************
 ***********************  D E P A R S E R  *******************************
 *************************************************************************/

control MyDeparser(packet_out packet, in headers hdr) {
    apply {
        /* TODO: add deparser logic */
        packet.emit(hdr.ethernet);
        packet.emit(hdr.ipv4);
        packet.emit(hdr.udp);
    }
}

/*************************************************************************
 ***********************  S W I T C H  *******************************
 *************************************************************************/

    V1Switch(
            MyParser(),
            MyVerifyChecksum(),
            MyIngress(),
            MyEgress(),
            MyComputeChecksum(),
            MyDeparser()
            ) main;
