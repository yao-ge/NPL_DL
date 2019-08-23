/*
 * SCRIPT GENERATED FILE, DO NOT MODIFY
*/


#include "table_entry_classes.h"

#include "bm_field.h"

void sfc_edb_profile_entry_t::set__VALID(_1bit value, int maxbit, int minbit) {
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 0;
    }

    _VALID(maxbit, minbit) = value;
}

void sfc_edb_profile_entry_t::set__INDEX(_1bit value, int maxbit, int minbit) {
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 0;
    }

    _INDEX(maxbit, minbit) = value;
}

void sfc_edb_profile_entry_t::set_edb_index(_1bit value, int maxbit, int minbit) {
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 0;
    }

    edb_index(maxbit, minbit) = value;
}

void sfc_edb_profile_entry_t::set_in_drop_vector(void* value, int maxbit, int minbit) {
    in_drop_vector = value;
}

void sfc_edb_profile_entry_t::set_in_dst_mod(void* value, int maxbit, int minbit) {
    in_dst_mod = value;
}

void sfc_edb_profile_entry_t::set_in_dst_port(void* value, int maxbit, int minbit) {
    in_dst_port = value;
}

void sfc_edb_profile_entry_t::set__LOOKUP0(_1bit value, int maxbit, int minbit) {
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 0;
    }

    _LOOKUP0(maxbit, minbit) = value;
}

void sfc_edb_profile_entry_t::set__HIT_INDEX0(_32bits value, int maxbit, int minbit) {
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 31;
    }

    _HIT_INDEX0(maxbit, minbit) = value;
}

sfc_edb_profile_entry_t::sfc_edb_profile_entry_t() {
    uint i;

    _VALID = (_1bit)(0x0U);
    _INDEX = (_1bit)(0x0U);
    edb_index = (_1bit)(0x0U);
    in_drop_vector = (void*)(0x0U);
    in_dst_mod = (void*)(0x0U);
    in_dst_port = (void*)(0x0U);
    _LOOKUP0 = (_1bit)(0x0U);
    _HIT_INDEX0 = (_32bits)(0x0U);
}

sfc_edb_profile_entry_t::~sfc_edb_profile_entry_t() {
    uint i;

}

void sfc_edb_profile_entry_t::print() {
#ifndef NO_CONSOLE_OUTPUT
    uint i;

    bmi_log->normal("sfc_edb_profile_entry_t->_VALID = 0x" + _VALID.to_string(SC_HEX_US, false));
    bmi_log->normal("sfc_edb_profile_entry_t->_INDEX = 0x" + _INDEX.to_string(SC_HEX_US, false));
    bmi_log->normal("sfc_edb_profile_entry_t->edb_index = 0x" + edb_index.to_string(SC_HEX_US, false));
    bmi_log->normal("sfc_edb_profile_entry_t->in_drop_vector = %p", in_drop_vector);
    bmi_log->normal("sfc_edb_profile_entry_t->in_dst_mod = %p", in_dst_mod);
    bmi_log->normal("sfc_edb_profile_entry_t->in_dst_port = %p", in_dst_port);
    bmi_log->normal("sfc_edb_profile_entry_t->_LOOKUP0 = 0x" + _LOOKUP0.to_string(SC_HEX_US, false));
    bmi_log->normal("sfc_edb_profile_entry_t->_HIT_INDEX0 = 0x" + _HIT_INDEX0.to_string(SC_HEX_US, false));
#endif
}

void sfc_edb_profile_entry_t::pack_data(uint32_t *data) {
    uint32_t field;
    uint64_t ref_value;
    _64bits ref_addr;

    field = (uint32_t) _VALID;
    bm_field_set(data, 0, 0, &field);
    field = (uint32_t) _INDEX;
    bm_field_set(data, 1, 1, &field);
    field = (uint32_t) edb_index;
    bm_field_set(data, 2, 2, &field);
    ref_value = (uint64_t) in_drop_vector;
    ref_addr(63, 0)  = ref_value;
    field = (uint32_t) ref_addr.range(31, 0);
    bm_field_set(data, 3, 34, &field);
    field = (uint32_t) ref_addr.range(63, 32);
    bm_field_set(data, 35, 66, &field);
    ref_value = (uint64_t) in_dst_mod;
    ref_addr(63, 0)  = ref_value;
    field = (uint32_t) ref_addr.range(31, 0);
    bm_field_set(data, 67, 98, &field);
    field = (uint32_t) ref_addr.range(63, 32);
    bm_field_set(data, 99, 130, &field);
    ref_value = (uint64_t) in_dst_port;
    ref_addr(63, 0)  = ref_value;
    field = (uint32_t) ref_addr.range(31, 0);
    bm_field_set(data, 131, 162, &field);
    field = (uint32_t) ref_addr.range(63, 32);
    bm_field_set(data, 163, 194, &field);
}

void sfc_edb_profile_entry_t::unpack_data(uint32_t *data) {
    uint32_t field;
    uint64_t ref_value;
    _64bits ref_addr;

    bm_field_get(data, 0, 0, &field);
    set__VALID((_1bit) field, -1, -1);
    bm_field_get(data, 1, 1, &field);
    set__INDEX((_1bit) field, -1, -1);
    bm_field_get(data, 2, 2, &field);
    set_edb_index((_1bit) field, -1, -1);
    bm_field_get(data, 3, 34, &field);
    ref_addr(31, 0)  = field;
    bm_field_get(data, 35, 66, &field);
    ref_addr(63, 32)  = field;
    ref_value = (uint64_t) ref_addr;
    set_in_drop_vector((void*)ref_value, -1, -1);
    bm_field_get(data, 67, 98, &field);
    ref_addr(31, 0)  = field;
    bm_field_get(data, 99, 130, &field);
    ref_addr(63, 32)  = field;
    ref_value = (uint64_t) ref_addr;
    set_in_dst_mod((void*)ref_value, -1, -1);
    bm_field_get(data, 131, 162, &field);
    ref_addr(31, 0)  = field;
    bm_field_get(data, 163, 194, &field);
    ref_addr(63, 32)  = field;
    ref_value = (uint64_t) ref_addr;
    set_in_dst_port((void*)ref_value, -1, -1);
}

void sfc_mmu_profile_entry_t::set__VALID(_1bit value, int maxbit, int minbit) {
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 0;
    }

    _VALID(maxbit, minbit) = value;
}

void sfc_mmu_profile_entry_t::set__INDEX(_1bit value, int maxbit, int minbit) {
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 0;
    }

    _INDEX(maxbit, minbit) = value;
}

void sfc_mmu_profile_entry_t::set_mmu_index(_1bit value, int maxbit, int minbit) {
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 0;
    }

    mmu_index(maxbit, minbit) = value;
}

void sfc_mmu_profile_entry_t::set_in_l2_pbm(void* value, int maxbit, int minbit) {
    in_l2_pbm = value;
}

void sfc_mmu_profile_entry_t::set_in_l3_pbm(void* value, int maxbit, int minbit) {
    in_l3_pbm = value;
}

void sfc_mmu_profile_entry_t::set_out_dst_port(void* value, int maxbit, int minbit) {
    out_dst_port = value;
}

void sfc_mmu_profile_entry_t::set__LOOKUP0(_1bit value, int maxbit, int minbit) {
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 0;
    }

    _LOOKUP0(maxbit, minbit) = value;
}

void sfc_mmu_profile_entry_t::set__HIT_INDEX0(_32bits value, int maxbit, int minbit) {
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 31;
    }

    _HIT_INDEX0(maxbit, minbit) = value;
}

sfc_mmu_profile_entry_t::sfc_mmu_profile_entry_t() {
    uint i;

    _VALID = (_1bit)(0x0U);
    _INDEX = (_1bit)(0x0U);
    mmu_index = (_1bit)(0x0U);
    in_l2_pbm = (void*)(0x0U);
    in_l3_pbm = (void*)(0x0U);
    out_dst_port = (void*)(0x0U);
    _LOOKUP0 = (_1bit)(0x0U);
    _HIT_INDEX0 = (_32bits)(0x0U);
}

sfc_mmu_profile_entry_t::~sfc_mmu_profile_entry_t() {
    uint i;

}

void sfc_mmu_profile_entry_t::print() {
#ifndef NO_CONSOLE_OUTPUT
    uint i;

    bmi_log->normal("sfc_mmu_profile_entry_t->_VALID = 0x" + _VALID.to_string(SC_HEX_US, false));
    bmi_log->normal("sfc_mmu_profile_entry_t->_INDEX = 0x" + _INDEX.to_string(SC_HEX_US, false));
    bmi_log->normal("sfc_mmu_profile_entry_t->mmu_index = 0x" + mmu_index.to_string(SC_HEX_US, false));
    bmi_log->normal("sfc_mmu_profile_entry_t->in_l2_pbm = %p", in_l2_pbm);
    bmi_log->normal("sfc_mmu_profile_entry_t->in_l3_pbm = %p", in_l3_pbm);
    bmi_log->normal("sfc_mmu_profile_entry_t->out_dst_port = %p", out_dst_port);
    bmi_log->normal("sfc_mmu_profile_entry_t->_LOOKUP0 = 0x" + _LOOKUP0.to_string(SC_HEX_US, false));
    bmi_log->normal("sfc_mmu_profile_entry_t->_HIT_INDEX0 = 0x" + _HIT_INDEX0.to_string(SC_HEX_US, false));
#endif
}

void sfc_mmu_profile_entry_t::pack_data(uint32_t *data) {
    uint32_t field;
    uint64_t ref_value;
    _64bits ref_addr;

    field = (uint32_t) _VALID;
    bm_field_set(data, 0, 0, &field);
    field = (uint32_t) _INDEX;
    bm_field_set(data, 1, 1, &field);
    field = (uint32_t) mmu_index;
    bm_field_set(data, 2, 2, &field);
    ref_value = (uint64_t) in_l2_pbm;
    ref_addr(63, 0)  = ref_value;
    field = (uint32_t) ref_addr.range(31, 0);
    bm_field_set(data, 3, 34, &field);
    field = (uint32_t) ref_addr.range(63, 32);
    bm_field_set(data, 35, 66, &field);
    ref_value = (uint64_t) in_l3_pbm;
    ref_addr(63, 0)  = ref_value;
    field = (uint32_t) ref_addr.range(31, 0);
    bm_field_set(data, 67, 98, &field);
    field = (uint32_t) ref_addr.range(63, 32);
    bm_field_set(data, 99, 130, &field);
    ref_value = (uint64_t) out_dst_port;
    ref_addr(63, 0)  = ref_value;
    field = (uint32_t) ref_addr.range(31, 0);
    bm_field_set(data, 131, 162, &field);
    field = (uint32_t) ref_addr.range(63, 32);
    bm_field_set(data, 163, 194, &field);
}

void sfc_mmu_profile_entry_t::unpack_data(uint32_t *data) {
    uint32_t field;
    uint64_t ref_value;
    _64bits ref_addr;

    bm_field_get(data, 0, 0, &field);
    set__VALID((_1bit) field, -1, -1);
    bm_field_get(data, 1, 1, &field);
    set__INDEX((_1bit) field, -1, -1);
    bm_field_get(data, 2, 2, &field);
    set_mmu_index((_1bit) field, -1, -1);
    bm_field_get(data, 3, 34, &field);
    ref_addr(31, 0)  = field;
    bm_field_get(data, 35, 66, &field);
    ref_addr(63, 32)  = field;
    ref_value = (uint64_t) ref_addr;
    set_in_l2_pbm((void*)ref_value, -1, -1);
    bm_field_get(data, 67, 98, &field);
    ref_addr(31, 0)  = field;
    bm_field_get(data, 99, 130, &field);
    ref_addr(63, 32)  = field;
    ref_value = (uint64_t) ref_addr;
    set_in_l3_pbm((void*)ref_value, -1, -1);
    bm_field_get(data, 131, 162, &field);
    ref_addr(31, 0)  = field;
    bm_field_get(data, 163, 194, &field);
    ref_addr(63, 32)  = field;
    ref_value = (uint64_t) ref_addr;
    set_out_dst_port((void*)ref_value, -1, -1);
}

void sfc_iarb_profile_entry_t::set__VALID(_1bit value, int maxbit, int minbit) {
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 0;
    }

    _VALID(maxbit, minbit) = value;
}

void sfc_iarb_profile_entry_t::set__INDEX(_1bit value, int maxbit, int minbit) {
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 0;
    }

    _INDEX(maxbit, minbit) = value;
}

void sfc_iarb_profile_entry_t::set_iarb_index(_1bit value, int maxbit, int minbit) {
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 0;
    }

    iarb_index(maxbit, minbit) = value;
}

void sfc_iarb_profile_entry_t::set_out_otpid_enable(void* value, int maxbit, int minbit) {
    out_otpid_enable = value;
}

void sfc_iarb_profile_entry_t::set_out_ts_enable(void* value, int maxbit, int minbit) {
    out_ts_enable = value;
}

void sfc_iarb_profile_entry_t::set_out_port_num(void* value, int maxbit, int minbit) {
    out_port_num = value;
}

void sfc_iarb_profile_entry_t::set_out_port_type_cfg(void* value, int maxbit, int minbit) {
    out_port_type_cfg = value;
}

void sfc_iarb_profile_entry_t::set_out_currenttime(void* value, int maxbit, int minbit) {
    out_currenttime = value;
}

void sfc_iarb_profile_entry_t::set__LOOKUP0(_1bit value, int maxbit, int minbit) {
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 0;
    }

    _LOOKUP0(maxbit, minbit) = value;
}

void sfc_iarb_profile_entry_t::set__HIT_INDEX0(_32bits value, int maxbit, int minbit) {
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 31;
    }

    _HIT_INDEX0(maxbit, minbit) = value;
}

sfc_iarb_profile_entry_t::sfc_iarb_profile_entry_t() {
    uint i;

    _VALID = (_1bit)(0x0U);
    _INDEX = (_1bit)(0x0U);
    iarb_index = (_1bit)(0x0U);
    out_otpid_enable = (void*)(0x0U);
    out_ts_enable = (void*)(0x0U);
    out_port_num = (void*)(0x0U);
    out_port_type_cfg = (void*)(0x0U);
    out_currenttime = (void*)(0x0U);
    _LOOKUP0 = (_1bit)(0x0U);
    _HIT_INDEX0 = (_32bits)(0x0U);
}

sfc_iarb_profile_entry_t::~sfc_iarb_profile_entry_t() {
    uint i;

}

void sfc_iarb_profile_entry_t::print() {
#ifndef NO_CONSOLE_OUTPUT
    uint i;

    bmi_log->normal("sfc_iarb_profile_entry_t->_VALID = 0x" + _VALID.to_string(SC_HEX_US, false));
    bmi_log->normal("sfc_iarb_profile_entry_t->_INDEX = 0x" + _INDEX.to_string(SC_HEX_US, false));
    bmi_log->normal("sfc_iarb_profile_entry_t->iarb_index = 0x" + iarb_index.to_string(SC_HEX_US, false));
    bmi_log->normal("sfc_iarb_profile_entry_t->out_otpid_enable = %p", out_otpid_enable);
    bmi_log->normal("sfc_iarb_profile_entry_t->out_ts_enable = %p", out_ts_enable);
    bmi_log->normal("sfc_iarb_profile_entry_t->out_port_num = %p", out_port_num);
    bmi_log->normal("sfc_iarb_profile_entry_t->out_port_type_cfg = %p", out_port_type_cfg);
    bmi_log->normal("sfc_iarb_profile_entry_t->out_currenttime = %p", out_currenttime);
    bmi_log->normal("sfc_iarb_profile_entry_t->_LOOKUP0 = 0x" + _LOOKUP0.to_string(SC_HEX_US, false));
    bmi_log->normal("sfc_iarb_profile_entry_t->_HIT_INDEX0 = 0x" + _HIT_INDEX0.to_string(SC_HEX_US, false));
#endif
}

void sfc_iarb_profile_entry_t::pack_data(uint32_t *data) {
    uint32_t field;
    uint64_t ref_value;
    _64bits ref_addr;

    field = (uint32_t) _VALID;
    bm_field_set(data, 0, 0, &field);
    field = (uint32_t) _INDEX;
    bm_field_set(data, 1, 1, &field);
    field = (uint32_t) iarb_index;
    bm_field_set(data, 2, 2, &field);
    ref_value = (uint64_t) out_otpid_enable;
    ref_addr(63, 0)  = ref_value;
    field = (uint32_t) ref_addr.range(31, 0);
    bm_field_set(data, 3, 34, &field);
    field = (uint32_t) ref_addr.range(63, 32);
    bm_field_set(data, 35, 66, &field);
    ref_value = (uint64_t) out_ts_enable;
    ref_addr(63, 0)  = ref_value;
    field = (uint32_t) ref_addr.range(31, 0);
    bm_field_set(data, 67, 98, &field);
    field = (uint32_t) ref_addr.range(63, 32);
    bm_field_set(data, 99, 130, &field);
    ref_value = (uint64_t) out_port_num;
    ref_addr(63, 0)  = ref_value;
    field = (uint32_t) ref_addr.range(31, 0);
    bm_field_set(data, 131, 162, &field);
    field = (uint32_t) ref_addr.range(63, 32);
    bm_field_set(data, 163, 194, &field);
    ref_value = (uint64_t) out_port_type_cfg;
    ref_addr(63, 0)  = ref_value;
    field = (uint32_t) ref_addr.range(31, 0);
    bm_field_set(data, 195, 226, &field);
    field = (uint32_t) ref_addr.range(63, 32);
    bm_field_set(data, 227, 258, &field);
    ref_value = (uint64_t) out_currenttime;
    ref_addr(63, 0)  = ref_value;
    field = (uint32_t) ref_addr.range(31, 0);
    bm_field_set(data, 259, 290, &field);
    field = (uint32_t) ref_addr.range(63, 32);
    bm_field_set(data, 291, 322, &field);
}

void sfc_iarb_profile_entry_t::unpack_data(uint32_t *data) {
    uint32_t field;
    uint64_t ref_value;
    _64bits ref_addr;

    bm_field_get(data, 0, 0, &field);
    set__VALID((_1bit) field, -1, -1);
    bm_field_get(data, 1, 1, &field);
    set__INDEX((_1bit) field, -1, -1);
    bm_field_get(data, 2, 2, &field);
    set_iarb_index((_1bit) field, -1, -1);
    bm_field_get(data, 3, 34, &field);
    ref_addr(31, 0)  = field;
    bm_field_get(data, 35, 66, &field);
    ref_addr(63, 32)  = field;
    ref_value = (uint64_t) ref_addr;
    set_out_otpid_enable((void*)ref_value, -1, -1);
    bm_field_get(data, 67, 98, &field);
    ref_addr(31, 0)  = field;
    bm_field_get(data, 99, 130, &field);
    ref_addr(63, 32)  = field;
    ref_value = (uint64_t) ref_addr;
    set_out_ts_enable((void*)ref_value, -1, -1);
    bm_field_get(data, 131, 162, &field);
    ref_addr(31, 0)  = field;
    bm_field_get(data, 163, 194, &field);
    ref_addr(63, 32)  = field;
    ref_value = (uint64_t) ref_addr;
    set_out_port_num((void*)ref_value, -1, -1);
    bm_field_get(data, 195, 226, &field);
    ref_addr(31, 0)  = field;
    bm_field_get(data, 227, 258, &field);
    ref_addr(63, 32)  = field;
    ref_value = (uint64_t) ref_addr;
    set_out_port_type_cfg((void*)ref_value, -1, -1);
    bm_field_get(data, 259, 290, &field);
    ref_addr(31, 0)  = field;
    bm_field_get(data, 291, 322, &field);
    ref_addr(63, 32)  = field;
    ref_value = (uint64_t) ref_addr;
    set_out_currenttime((void*)ref_value, -1, -1);
}

