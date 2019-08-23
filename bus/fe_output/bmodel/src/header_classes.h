/*
 * SCRIPT GENERATED FILE, DO NOT MODIFY
*/

#ifndef _HEADER_CLASSES
#define _HEADER_CLASSES

#include "global_var.h"
#include "header_base_class.h"
#include "bit_types.h"

class udp_t : public header_base_t {
public:
    _16bits sport;
    _16bits dport;
    _16bits length;
    _16bits checksum;
    _16bits job_id;
    _16bits max_worker;
    _16bits worker_id;
    _16bits sequence;
    _16bits exp;
    _16bits bias;
    _16bits bias_exp;

    udp_t(void);
    ~udp_t(void);

    int extract_fields(_8bits *pkt, _32bits *hdr_ptr, _32bits *pkt_len);
    void print(void);
    void pack(void);
    void set_resetval(void);
    void deep_copy(udp_t *ref);
};

class pss_t : public header_base_t {
public:
    _8192bits values;

    pss_t(void);
    ~pss_t(void);

    int extract_fields(_8bits *pkt, _32bits *hdr_ptr, _32bits *pkt_len);
    void print(void);
    void pack(void);
    void set_resetval(void);
    void deep_copy(pss_t *ref);
};

class l2_t : public header_base_t {
public:
    _48bits macda;
    _48bits macsa;
    _16bits ethertype;

    l2_t(void);
    ~l2_t(void);

    int extract_fields(_8bits *pkt, _32bits *hdr_ptr, _32bits *pkt_len);
    void print(void);
    void pack(void);
    void set_resetval(void);
    void deep_copy(l2_t *ref);
};

class ipv4_t : public header_base_t {
public:
    _4bits version;
    _4bits hdr_len;
    _8bits tos;
    _16bits v4_length;
    _16bits id;
    _3bits flags;
    _13bits frag_offset;
    _8bits ttl;
    _8bits protocol;
    _16bits hdr_checksum;
    _32bits sip;
    _32bits dip;
    _512bits option;

    ipv4_t(void);
    ~ipv4_t(void);

    int extract_fields(_8bits *pkt, _32bits *hdr_ptr, _32bits *pkt_len);
    void print(void);
    void pack(void);
    void set_resetval(void);
    void deep_copy(ipv4_t *ref);
};

class payload_grp_t {
public:
    pss_t *pss[2];

    void set_pss(pss_t **ref);
    void set_pss(int, pss_t *ref);

    payload_grp_t(void);
    ~payload_grp_t(void);

    void set_resetval();
    void deep_copy(payload_grp_t *ref);
};

class l3_hdr_grp_t {
public:
    ipv4_t *ipv4;

    void set_ipv4(ipv4_t *ref);

    l3_hdr_grp_t(void);
    ~l3_hdr_grp_t(void);

    void set_resetval();
    void deep_copy(l3_hdr_grp_t *ref);
};

class l4_hdr_grp_t {
public:
    udp_t *udp;

    void set_udp(udp_t *ref);

    l4_hdr_grp_t(void);
    ~l4_hdr_grp_t(void);

    void set_resetval();
    void deep_copy(l4_hdr_grp_t *ref);
};

class l2_hdr_grp_t {
public:
    l2_t *l2;

    void set_l2(l2_t *ref);

    l2_hdr_grp_t(void);
    ~l2_hdr_grp_t(void);

    void set_resetval();
    void deep_copy(l2_hdr_grp_t *ref);
};

class ingress_pkt_t : public packet_base_t {
public:
    _5bits _match_id;
    l3_hdr_grp_t *l3_hdr;
    l2_hdr_grp_t *l2_hdr;
    payload_grp_t *payload;
    l4_hdr_grp_t *l4_hdr;

    void set_l3_hdr(l3_hdr_grp_t *ref);
    void set_l2_hdr(l2_hdr_grp_t *ref);
    void set_payload(payload_grp_t *ref);
    void set_l4_hdr(l4_hdr_grp_t *ref);

    ingress_pkt_t(void);
    ~ingress_pkt_t(void);

    void set_resetval();
    void deep_copy(ingress_pkt_t *ref);
};

class egress_pkt_t : public packet_base_t {
public:
    _5bits _match_id;
    l3_hdr_grp_t *l3_hdr;
    l2_hdr_grp_t *l2_hdr;
    payload_grp_t *payload;
    l4_hdr_grp_t *l4_hdr;

    void set_l3_hdr(l3_hdr_grp_t *ref);
    void set_l2_hdr(l2_hdr_grp_t *ref);
    void set_payload(payload_grp_t *ref);
    void set_l4_hdr(l4_hdr_grp_t *ref);

    egress_pkt_t(void);
    ~egress_pkt_t(void);

    void set_resetval();
    void deep_copy(egress_pkt_t *ref);
};

#endif
