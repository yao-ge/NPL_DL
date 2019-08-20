/*
 * SCRIPT GENERATED FILE, DO NOT MODIFY
*/

#ifndef _FORMAT_CLASSES
#define _FORMAT_CLASSES

#include <stdlib.h>
#include "bit_types.h"
#include "base_classes.h"

class packet_value_t;
class tmp_t;
class obj_bus_t;
class index_t;
class ccbi_t;
class ccbe_t;
class control_id_t;
class egr_obj_bus_t;
class aux_bus_t;
class packet_info_t;
class time_bus_t;

class packet_value_t {
public:
    _8192bits value;

    packet_value_t(void);
    ~packet_value_t(void);

    void set_value(_8192bits, int, int);

    void set_resetval(void);
    void set_randval(void);
    void print(void);
    int compare(packet_value_t *ref, packet_value_t *ref_mask);
    void deep_copy(packet_value_t *ref);
    void unpack_data(uint32_t *_data, int offset = 0);
    void pack_data(uint32_t *_data, int offset = 0);
    int minbit();
    int maxbit();

};

class tmp_t {
public:
    _48bits value_48;
    _32bits value_32;
    _16bits value_16;

    tmp_t(void);
    ~tmp_t(void);

    void set_value_48(_48bits, int, int);
    void set_value_32(_32bits, int, int);
    void set_value_16(_16bits, int, int);

    void set_resetval(void);
    void set_randval(void);
    void print(void);
    int compare(tmp_t *ref, tmp_t *ref_mask);
    void deep_copy(tmp_t *ref);
    void unpack_data(uint32_t *_data, int offset = 0);
    void pack_data(uint32_t *_data, int offset = 0);
    int minbit();
    int maxbit();

};

class obj_bus_t {
public:
    _2bits port_type_cfg;
    _7bits port_num;
    _8bits dst_modid;
    _7bits dst_port;

    obj_bus_t(void);
    ~obj_bus_t(void);

    void set_port_type_cfg(_2bits, int, int);
    void set_port_num(_7bits, int, int);
    void set_dst_modid(_8bits, int, int);
    void set_dst_port(_7bits, int, int);

    void set_resetval(void);
    void set_randval(void);
    void print(void);
    int compare(obj_bus_t *ref, obj_bus_t *ref_mask);
    void deep_copy(obj_bus_t *ref);
    void unpack_data(uint32_t *_data, int offset = 0);
    void pack_data(uint32_t *_data, int offset = 0);
    int minbit();
    int maxbit();

};

class index_t {
public:
    _48bits value_48;
    _32bits value_32;
    _16bits value_16;

    index_t(void);
    ~index_t(void);

    void set_value_48(_48bits, int, int);
    void set_value_32(_32bits, int, int);
    void set_value_16(_16bits, int, int);

    void set_resetval(void);
    void set_randval(void);
    void print(void);
    int compare(index_t *ref, index_t *ref_mask);
    void deep_copy(index_t *ref);
    void unpack_data(uint32_t *_data, int offset = 0);
    void pack_data(uint32_t *_data, int offset = 0);
    int minbit();
    int maxbit();

};

class ccbi_t {
public:
    _128bits l2_pbm;
    _128bits l3_pbm;

    ccbi_t(void);
    ~ccbi_t(void);

    void set_l2_pbm(_128bits, int, int);
    void set_l3_pbm(_128bits, int, int);

    void set_resetval(void);
    void set_randval(void);
    void print(void);
    int compare(ccbi_t *ref, ccbi_t *ref_mask);
    void deep_copy(ccbi_t *ref);
    void unpack_data(uint32_t *_data, int offset = 0);
    void pack_data(uint32_t *_data, int offset = 0);
    int minbit();
    int maxbit();

};

class ccbe_t {
public:
    _7bits dst_port;

    ccbe_t(void);
    ~ccbe_t(void);

    void set_dst_port(_7bits, int, int);

    void set_resetval(void);
    void set_randval(void);
    void print(void);
    int compare(ccbe_t *ref, ccbe_t *ref_mask);
    void deep_copy(ccbe_t *ref);
    void unpack_data(uint32_t *_data, int offset = 0);
    void pack_data(uint32_t *_data, int offset = 0);
    int minbit();
    int maxbit();

};

class control_id_t {
public:
    _4bits otpid_enable;
    _1bit ts_enable;

    control_id_t(void);
    ~control_id_t(void);

    void set_otpid_enable(_4bits, int, int);
    void set_ts_enable(_1bit, int, int);

    void set_resetval(void);
    void set_randval(void);
    void print(void);
    int compare(control_id_t *ref, control_id_t *ref_mask);
    void deep_copy(control_id_t *ref);
    void unpack_data(uint32_t *_data, int offset = 0);
    void pack_data(uint32_t *_data, int offset = 0);
    int minbit();
    int maxbit();

};

class egr_obj_bus_t {
public:
    _8bits dst_modid;
    _7bits dst_port;
    _7bits ing_port;
    _16bits ingress_timestamp;

    egr_obj_bus_t(void);
    ~egr_obj_bus_t(void);

    void set_dst_modid(_8bits, int, int);
    void set_dst_port(_7bits, int, int);
    void set_ing_port(_7bits, int, int);
    void set_ingress_timestamp(_16bits, int, int);

    void set_resetval(void);
    void set_randval(void);
    void print(void);
    int compare(egr_obj_bus_t *ref, egr_obj_bus_t *ref_mask);
    void deep_copy(egr_obj_bus_t *ref);
    void unpack_data(uint32_t *_data, int offset = 0);
    void pack_data(uint32_t *_data, int offset = 0);
    int minbit();
    int maxbit();

};

class aux_bus_t {
public:
    _16bits drop_vector;

    aux_bus_t(void);
    ~aux_bus_t(void);

    void set_drop_vector(_16bits, int, int);

    void set_resetval(void);
    void set_randval(void);
    void print(void);
    int compare(aux_bus_t *ref, aux_bus_t *ref_mask);
    void deep_copy(aux_bus_t *ref);
    void unpack_data(uint32_t *_data, int offset = 0);
    void pack_data(uint32_t *_data, int offset = 0);
    int minbit();
    int maxbit();

};

class packet_info_t {
public:
    _16bits job_id;
    _16bits max_worker;
    _16bits worker_id;
    _16bits sequence;
    _16bits exp;
    _16bits bias;
    _16bits bias_exp;
    _16bits worker_count;
    _16bits worker_init_bits;
    _16bits worker_bits;
    _16bits max_worker_bits;
    _16bits reset_worker_bits;
    packet_value_t *masks[2];

    packet_info_t(void);
    ~packet_info_t(void);

    void set_job_id(_16bits, int, int);
    void set_max_worker(_16bits, int, int);
    void set_worker_id(_16bits, int, int);
    void set_sequence(_16bits, int, int);
    void set_exp(_16bits, int, int);
    void set_bias(_16bits, int, int);
    void set_bias_exp(_16bits, int, int);
    void set_worker_count(_16bits, int, int);
    void set_worker_init_bits(_16bits, int, int);
    void set_worker_bits(_16bits, int, int);
    void set_max_worker_bits(_16bits, int, int);
    void set_reset_worker_bits(_16bits, int, int);
    void set_masks(packet_value_t**);
    void set_masks(int, packet_value_t*);

    void set_resetval(void);
    void set_randval(void);
    void print(void);
    int compare(packet_info_t *ref, packet_info_t *ref_mask);
    void deep_copy(packet_info_t *ref);
    void unpack_data(uint32_t *_data, int offset = 0);
    void pack_data(uint32_t *_data, int offset = 0);
    int minbit();
    int maxbit();

};

class time_bus_t {
public:
    _16bits currenttime;

    time_bus_t(void);
    ~time_bus_t(void);

    void set_currenttime(_16bits, int, int);

    void set_resetval(void);
    void set_randval(void);
    void print(void);
    int compare(time_bus_t *ref, time_bus_t *ref_mask);
    void deep_copy(time_bus_t *ref);
    void unpack_data(uint32_t *_data, int offset = 0);
    void pack_data(uint32_t *_data, int offset = 0);
    int minbit();
    int maxbit();

};

#endif
