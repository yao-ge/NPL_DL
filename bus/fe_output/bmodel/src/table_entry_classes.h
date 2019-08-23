/*
 * SCRIPT GENERATED FILE, DO NOT MODIFY
*/

#ifndef _TABLE_ENTRY_CLASSES
#define _TABLE_ENTRY_CLASSES

#include "bit_types.h"
#include "format_classes.h"

class sfc_edb_profile_entry_t {
public:
    _1bit _VALID;
    _1bit _INDEX;
    _1bit edb_index;
    void* in_drop_vector;
    void* in_dst_mod;
    void* in_dst_port;
    _1bit _LOOKUP0;
    _32bits _HIT_INDEX0;

    void set__VALID(_1bit, int, int);
    void set__INDEX(_1bit, int, int);
    void set_edb_index(_1bit, int, int);
    void set_in_drop_vector(void*, int, int);
    void set_in_dst_mod(void*, int, int);
    void set_in_dst_port(void*, int, int);
    void set__LOOKUP0(_1bit, int, int);
    void set__HIT_INDEX0(_32bits, int, int);
    sfc_edb_profile_entry_t(void);
    ~sfc_edb_profile_entry_t(void);
    void print(void);
    void unpack_data(uint32_t *data);
    void pack_data(uint32_t *data);
};

class sfc_mmu_profile_entry_t {
public:
    _1bit _VALID;
    _1bit _INDEX;
    _1bit mmu_index;
    void* in_l2_pbm;
    void* in_l3_pbm;
    void* out_dst_port;
    _1bit _LOOKUP0;
    _32bits _HIT_INDEX0;

    void set__VALID(_1bit, int, int);
    void set__INDEX(_1bit, int, int);
    void set_mmu_index(_1bit, int, int);
    void set_in_l2_pbm(void*, int, int);
    void set_in_l3_pbm(void*, int, int);
    void set_out_dst_port(void*, int, int);
    void set__LOOKUP0(_1bit, int, int);
    void set__HIT_INDEX0(_32bits, int, int);
    sfc_mmu_profile_entry_t(void);
    ~sfc_mmu_profile_entry_t(void);
    void print(void);
    void unpack_data(uint32_t *data);
    void pack_data(uint32_t *data);
};

class sfc_iarb_profile_entry_t {
public:
    _1bit _VALID;
    _1bit _INDEX;
    _1bit iarb_index;
    void* out_otpid_enable;
    void* out_ts_enable;
    void* out_port_num;
    void* out_port_type_cfg;
    void* out_currenttime;
    _1bit _LOOKUP0;
    _32bits _HIT_INDEX0;

    void set__VALID(_1bit, int, int);
    void set__INDEX(_1bit, int, int);
    void set_iarb_index(_1bit, int, int);
    void set_out_otpid_enable(void*, int, int);
    void set_out_ts_enable(void*, int, int);
    void set_out_port_num(void*, int, int);
    void set_out_port_type_cfg(void*, int, int);
    void set_out_currenttime(void*, int, int);
    void set__LOOKUP0(_1bit, int, int);
    void set__HIT_INDEX0(_32bits, int, int);
    sfc_iarb_profile_entry_t(void);
    ~sfc_iarb_profile_entry_t(void);
    void print(void);
    void unpack_data(uint32_t *data);
    void pack_data(uint32_t *data);
};

#endif
