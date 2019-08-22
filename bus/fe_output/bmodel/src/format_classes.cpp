/*
 * SCRIPT GENERATED FILE, DO NOT MODIFY
*/


#include "format_classes.h"

#include "bm_field.h"

void packet_value_t::set_value(_8192bits value, int maxbit, int minbit) {
    bool __print__value = false;
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 8191;
    }

#ifndef NO_CONSOLE_OUTPUT
    if ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_ALL) ||
        ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_NZ) && ((value(maxbit, minbit) != 0) or (value != 0)))) {
        __print__value = true;
    }

#endif
    value(maxbit, minbit) = value;

#ifndef NO_CONSOLE_OUTPUT
    if (__print__value) {
        bmi_log->normal("BM_DEBUG: packet_value_t->value: 0x" + value.to_string(SC_HEX_US, false));
    }
#endif
}

packet_value_t::packet_value_t() {
    uint i;

    set_resetval();
}

packet_value_t::~packet_value_t() {
    uint i;

}

void packet_value_t::set_resetval(void) {
    uint i;

    value = (_8192bits)(0x0U);
}

void packet_value_t::set_randval(void) {
    uint i;

    value = (_8192bits)(rand());
}

void packet_value_t::print() {
#ifndef NO_CONSOLE_OUTPUT
    uint i;

    bmi_log->normal("packet_value_t->value = 0x" + value.to_string(SC_HEX_US, false));
#endif
}

int packet_value_t::compare(packet_value_t *ref, packet_value_t *ref_mask) {
    uint mismatch = 0;
    uint i;

    if (ref_mask == NULL) {
        if (value != ref->value) {
            mismatch = 1;
        }
    } else {
        if ((value & ref_mask->value) != (ref->value & ref_mask->value)) {
            mismatch = 1;
        }
    }

    return mismatch;
}

void packet_value_t::deep_copy(packet_value_t *ref) {
    uint i;

    value = ref->value;
}

void packet_value_t::unpack_data(uint32_t *_data, int offset) {
    uint32_t field;
    uint i;

    bm_field_get(_data, 0, 8191, &field);
    set_value((_8192bits)field, -1, -1);
}

void packet_value_t::pack_data(uint32_t *_data, int offset) {
    uint32_t field;
    uint i;

    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
}

int packet_value_t::minbit() {
    return 0;
}

int packet_value_t::maxbit() {
    return 8191;
}

void tmp_t::set_value_1(_1bit value, int maxbit, int minbit) {
    bool __print__value = false;
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 0;
    }

#ifndef NO_CONSOLE_OUTPUT
    if ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_ALL) ||
        ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_NZ) && ((value_1(maxbit, minbit) != 0) or (value != 0)))) {
        __print__value = true;
    }

#endif
    value_1(maxbit, minbit) = value;

#ifndef NO_CONSOLE_OUTPUT
    if (__print__value) {
        bmi_log->normal("BM_DEBUG: tmp_t->value_1: 0x" + value_1.to_string(SC_HEX_US, false));
    }
#endif
}

void tmp_t::set_value_48(_48bits value, int maxbit, int minbit) {
    bool __print__value = false;
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 47;
    }

#ifndef NO_CONSOLE_OUTPUT
    if ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_ALL) ||
        ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_NZ) && ((value_48(maxbit, minbit) != 0) or (value != 0)))) {
        __print__value = true;
    }

#endif
    value_48(maxbit, minbit) = value;

#ifndef NO_CONSOLE_OUTPUT
    if (__print__value) {
        bmi_log->normal("BM_DEBUG: tmp_t->value_48: 0x" + value_48.to_string(SC_HEX_US, false));
    }
#endif
}

void tmp_t::set_value_32(_32bits value, int maxbit, int minbit) {
    bool __print__value = false;
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 31;
    }

#ifndef NO_CONSOLE_OUTPUT
    if ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_ALL) ||
        ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_NZ) && ((value_32(maxbit, minbit) != 0) or (value != 0)))) {
        __print__value = true;
    }

#endif
    value_32(maxbit, minbit) = value;

#ifndef NO_CONSOLE_OUTPUT
    if (__print__value) {
        bmi_log->normal("BM_DEBUG: tmp_t->value_32: 0x" + value_32.to_string(SC_HEX_US, false));
    }
#endif
}

void tmp_t::set_value_16(_16bits value, int maxbit, int minbit) {
    bool __print__value = false;
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 15;
    }

#ifndef NO_CONSOLE_OUTPUT
    if ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_ALL) ||
        ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_NZ) && ((value_16(maxbit, minbit) != 0) or (value != 0)))) {
        __print__value = true;
    }

#endif
    value_16(maxbit, minbit) = value;

#ifndef NO_CONSOLE_OUTPUT
    if (__print__value) {
        bmi_log->normal("BM_DEBUG: tmp_t->value_16: 0x" + value_16.to_string(SC_HEX_US, false));
    }
#endif
}

void tmp_t::set_set_cast(_16bits value, int maxbit, int minbit) {
    bool __print__value = false;
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 15;
    }

#ifndef NO_CONSOLE_OUTPUT
    if ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_ALL) ||
        ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_NZ) && ((set_cast(maxbit, minbit) != 0) or (value != 0)))) {
        __print__value = true;
    }

#endif
    set_cast(maxbit, minbit) = value;

#ifndef NO_CONSOLE_OUTPUT
    if (__print__value) {
        bmi_log->normal("BM_DEBUG: tmp_t->set_cast: 0x" + set_cast.to_string(SC_HEX_US, false));
    }
#endif
}

void tmp_t::set_diff_exp(_16bits value, int maxbit, int minbit) {
    bool __print__value = false;
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 15;
    }

#ifndef NO_CONSOLE_OUTPUT
    if ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_ALL) ||
        ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_NZ) && ((diff_exp(maxbit, minbit) != 0) or (value != 0)))) {
        __print__value = true;
    }

#endif
    diff_exp(maxbit, minbit) = value;

#ifndef NO_CONSOLE_OUTPUT
    if (__print__value) {
        bmi_log->normal("BM_DEBUG: tmp_t->diff_exp: 0x" + diff_exp.to_string(SC_HEX_US, false));
    }
#endif
}

void tmp_t::set_shift(_16bits value, int maxbit, int minbit) {
    bool __print__value = false;
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 15;
    }

#ifndef NO_CONSOLE_OUTPUT
    if ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_ALL) ||
        ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_NZ) && ((shift(maxbit, minbit) != 0) or (value != 0)))) {
        __print__value = true;
    }

#endif
    shift(maxbit, minbit) = value;

#ifndef NO_CONSOLE_OUTPUT
    if (__print__value) {
        bmi_log->normal("BM_DEBUG: tmp_t->shift: 0x" + shift.to_string(SC_HEX_US, false));
    }
#endif
}

tmp_t::tmp_t() {
    uint i;

    set_resetval();
}

tmp_t::~tmp_t() {
    uint i;

}

void tmp_t::set_resetval(void) {
    uint i;

    value_1 = (_1bit)(0x0U);
    value_48 = (_48bits)(0x0U);
    value_32 = (_32bits)(0x0U);
    value_16 = (_16bits)(0x0U);
    set_cast = (_16bits)(0x0U);
    diff_exp = (_16bits)(0x0U);
    shift = (_16bits)(0x0U);
}

void tmp_t::set_randval(void) {
    uint i;

    value_1 = (_1bit)(rand());
    value_48 = (_48bits)(rand());
    value_32 = (_32bits)(rand());
    value_16 = (_16bits)(rand());
    set_cast = (_16bits)(rand());
    diff_exp = (_16bits)(rand());
    shift = (_16bits)(rand());
}

void tmp_t::print() {
#ifndef NO_CONSOLE_OUTPUT
    uint i;

    bmi_log->normal("tmp_t->value_1 = 0x" + value_1.to_string(SC_HEX_US, false));
    bmi_log->normal("tmp_t->value_48 = 0x" + value_48.to_string(SC_HEX_US, false));
    bmi_log->normal("tmp_t->value_32 = 0x" + value_32.to_string(SC_HEX_US, false));
    bmi_log->normal("tmp_t->value_16 = 0x" + value_16.to_string(SC_HEX_US, false));
    bmi_log->normal("tmp_t->set_cast = 0x" + set_cast.to_string(SC_HEX_US, false));
    bmi_log->normal("tmp_t->diff_exp = 0x" + diff_exp.to_string(SC_HEX_US, false));
    bmi_log->normal("tmp_t->shift = 0x" + shift.to_string(SC_HEX_US, false));
#endif
}

int tmp_t::compare(tmp_t *ref, tmp_t *ref_mask) {
    uint mismatch = 0;
    uint i;

    if (ref_mask == NULL) {
        if (value_1 != ref->value_1) {
            mismatch = 1;
        }
    } else {
        if ((value_1 & ref_mask->value_1) != (ref->value_1 & ref_mask->value_1)) {
            mismatch = 1;
        }
    }

    if (ref_mask == NULL) {
        if (value_48 != ref->value_48) {
            mismatch = 1;
        }
    } else {
        if ((value_48 & ref_mask->value_48) != (ref->value_48 & ref_mask->value_48)) {
            mismatch = 1;
        }
    }

    if (ref_mask == NULL) {
        if (value_32 != ref->value_32) {
            mismatch = 1;
        }
    } else {
        if ((value_32 & ref_mask->value_32) != (ref->value_32 & ref_mask->value_32)) {
            mismatch = 1;
        }
    }

    if (ref_mask == NULL) {
        if (value_16 != ref->value_16) {
            mismatch = 1;
        }
    } else {
        if ((value_16 & ref_mask->value_16) != (ref->value_16 & ref_mask->value_16)) {
            mismatch = 1;
        }
    }

    if (ref_mask == NULL) {
        if (set_cast != ref->set_cast) {
            mismatch = 1;
        }
    } else {
        if ((set_cast & ref_mask->set_cast) != (ref->set_cast & ref_mask->set_cast)) {
            mismatch = 1;
        }
    }

    if (ref_mask == NULL) {
        if (diff_exp != ref->diff_exp) {
            mismatch = 1;
        }
    } else {
        if ((diff_exp & ref_mask->diff_exp) != (ref->diff_exp & ref_mask->diff_exp)) {
            mismatch = 1;
        }
    }

    if (ref_mask == NULL) {
        if (shift != ref->shift) {
            mismatch = 1;
        }
    } else {
        if ((shift & ref_mask->shift) != (ref->shift & ref_mask->shift)) {
            mismatch = 1;
        }
    }

    return mismatch;
}

void tmp_t::deep_copy(tmp_t *ref) {
    uint i;

    value_1 = ref->value_1;
    value_48 = ref->value_48;
    value_32 = ref->value_32;
    value_16 = ref->value_16;
    set_cast = ref->set_cast;
    diff_exp = ref->diff_exp;
    shift = ref->shift;
}

void tmp_t::unpack_data(uint32_t *_data, int offset) {
    uint32_t field;
    uint i;

    bm_field_get(_data, 0, 0, &field);
    set_value_1((_1bit)field, -1, -1);
    bm_field_get(_data, 1, 48, &field);
    set_value_48((_48bits)field, -1, -1);
    bm_field_get(_data, 49, 80, &field);
    set_value_32((_32bits)field, -1, -1);
    bm_field_get(_data, 81, 96, &field);
    set_value_16((_16bits)field, -1, -1);
    bm_field_get(_data, 97, 112, &field);
    set_set_cast((_16bits)field, -1, -1);
    bm_field_get(_data, 113, 128, &field);
    set_diff_exp((_16bits)field, -1, -1);
    bm_field_get(_data, 129, 144, &field);
    set_shift((_16bits)field, -1, -1);
}

void tmp_t::pack_data(uint32_t *_data, int offset) {
    uint32_t field;
    uint i;

    field = (uint32_t) value_1.range(0, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 0), &field);
    field = (uint32_t) value_48.range(31, 0).to_int();
    bm_field_set(_data, (offset + 1), (offset + 32), &field);
    field = (uint32_t) value_48.range(15, 0).to_int();
    bm_field_set(_data, (offset + 1), (offset + 16), &field);
    field = (uint32_t) value_32.range(31, 0).to_int();
    bm_field_set(_data, (offset + 49), (offset + 80), &field);
    field = (uint32_t) value_16.range(15, 0).to_int();
    bm_field_set(_data, (offset + 81), (offset + 96), &field);
    field = (uint32_t) set_cast.range(15, 0).to_int();
    bm_field_set(_data, (offset + 97), (offset + 112), &field);
    field = (uint32_t) diff_exp.range(15, 0).to_int();
    bm_field_set(_data, (offset + 113), (offset + 128), &field);
    field = (uint32_t) shift.range(15, 0).to_int();
    bm_field_set(_data, (offset + 129), (offset + 144), &field);
}

int tmp_t::minbit() {
    return 0;
}

int tmp_t::maxbit() {
    return 144;
}

void obj_bus_t::set_port_type_cfg(_2bits value, int maxbit, int minbit) {
    bool __print__value = false;
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 1;
    }

#ifndef NO_CONSOLE_OUTPUT
    if ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_ALL) ||
        ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_NZ) && ((port_type_cfg(maxbit, minbit) != 0) or (value != 0)))) {
        __print__value = true;
    }

#endif
    port_type_cfg(maxbit, minbit) = value;

#ifndef NO_CONSOLE_OUTPUT
    if (__print__value) {
        bmi_log->normal("BM_DEBUG: obj_bus_t->port_type_cfg: 0x" + port_type_cfg.to_string(SC_HEX_US, false));
    }
#endif
}

void obj_bus_t::set_port_num(_7bits value, int maxbit, int minbit) {
    bool __print__value = false;
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 6;
    }

#ifndef NO_CONSOLE_OUTPUT
    if ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_ALL) ||
        ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_NZ) && ((port_num(maxbit, minbit) != 0) or (value != 0)))) {
        __print__value = true;
    }

#endif
    port_num(maxbit, minbit) = value;

#ifndef NO_CONSOLE_OUTPUT
    if (__print__value) {
        bmi_log->normal("BM_DEBUG: obj_bus_t->port_num: 0x" + port_num.to_string(SC_HEX_US, false));
    }
#endif
}

void obj_bus_t::set_dst_modid(_8bits value, int maxbit, int minbit) {
    bool __print__value = false;
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 7;
    }

#ifndef NO_CONSOLE_OUTPUT
    if ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_ALL) ||
        ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_NZ) && ((dst_modid(maxbit, minbit) != 0) or (value != 0)))) {
        __print__value = true;
    }

#endif
    dst_modid(maxbit, minbit) = value;

#ifndef NO_CONSOLE_OUTPUT
    if (__print__value) {
        bmi_log->normal("BM_DEBUG: obj_bus_t->dst_modid: 0x" + dst_modid.to_string(SC_HEX_US, false));
    }
#endif
}

void obj_bus_t::set_dst_port(_7bits value, int maxbit, int minbit) {
    bool __print__value = false;
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 6;
    }

#ifndef NO_CONSOLE_OUTPUT
    if ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_ALL) ||
        ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_NZ) && ((dst_port(maxbit, minbit) != 0) or (value != 0)))) {
        __print__value = true;
    }

#endif
    dst_port(maxbit, minbit) = value;

#ifndef NO_CONSOLE_OUTPUT
    if (__print__value) {
        bmi_log->normal("BM_DEBUG: obj_bus_t->dst_port: 0x" + dst_port.to_string(SC_HEX_US, false));
    }
#endif
}

obj_bus_t::obj_bus_t() {
    uint i;

    set_resetval();
}

obj_bus_t::~obj_bus_t() {
    uint i;

}

void obj_bus_t::set_resetval(void) {
    uint i;

    port_type_cfg = (_2bits)(0x0U);
    port_num = (_7bits)(0x0U);
    dst_modid = (_8bits)(0x0U);
    dst_port = (_7bits)(0x0U);
}

void obj_bus_t::set_randval(void) {
    uint i;

    port_type_cfg = (_2bits)(rand());
    port_num = (_7bits)(rand());
    dst_modid = (_8bits)(rand());
    dst_port = (_7bits)(rand());
}

void obj_bus_t::print() {
#ifndef NO_CONSOLE_OUTPUT
    uint i;

    bmi_log->normal("obj_bus_t->port_type_cfg = 0x" + port_type_cfg.to_string(SC_HEX_US, false));
    bmi_log->normal("obj_bus_t->port_num = 0x" + port_num.to_string(SC_HEX_US, false));
    bmi_log->normal("obj_bus_t->dst_modid = 0x" + dst_modid.to_string(SC_HEX_US, false));
    bmi_log->normal("obj_bus_t->dst_port = 0x" + dst_port.to_string(SC_HEX_US, false));
#endif
}

int obj_bus_t::compare(obj_bus_t *ref, obj_bus_t *ref_mask) {
    uint mismatch = 0;
    uint i;

    if (ref_mask == NULL) {
        if (port_type_cfg != ref->port_type_cfg) {
            mismatch = 1;
        }
    } else {
        if ((port_type_cfg & ref_mask->port_type_cfg) != (ref->port_type_cfg & ref_mask->port_type_cfg)) {
            mismatch = 1;
        }
    }

    if (ref_mask == NULL) {
        if (port_num != ref->port_num) {
            mismatch = 1;
        }
    } else {
        if ((port_num & ref_mask->port_num) != (ref->port_num & ref_mask->port_num)) {
            mismatch = 1;
        }
    }

    if (ref_mask == NULL) {
        if (dst_modid != ref->dst_modid) {
            mismatch = 1;
        }
    } else {
        if ((dst_modid & ref_mask->dst_modid) != (ref->dst_modid & ref_mask->dst_modid)) {
            mismatch = 1;
        }
    }

    if (ref_mask == NULL) {
        if (dst_port != ref->dst_port) {
            mismatch = 1;
        }
    } else {
        if ((dst_port & ref_mask->dst_port) != (ref->dst_port & ref_mask->dst_port)) {
            mismatch = 1;
        }
    }

    return mismatch;
}

void obj_bus_t::deep_copy(obj_bus_t *ref) {
    uint i;

    port_type_cfg = ref->port_type_cfg;
    port_num = ref->port_num;
    dst_modid = ref->dst_modid;
    dst_port = ref->dst_port;
}

void obj_bus_t::unpack_data(uint32_t *_data, int offset) {
    uint32_t field;
    uint i;

    bm_field_get(_data, 0, 1, &field);
    set_port_type_cfg((_2bits)field, -1, -1);
    bm_field_get(_data, 2, 8, &field);
    set_port_num((_7bits)field, -1, -1);
    bm_field_get(_data, 9, 16, &field);
    set_dst_modid((_8bits)field, -1, -1);
    bm_field_get(_data, 17, 23, &field);
    set_dst_port((_7bits)field, -1, -1);
}

void obj_bus_t::pack_data(uint32_t *_data, int offset) {
    uint32_t field;
    uint i;

    field = (uint32_t) port_type_cfg.range(1, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 1), &field);
    field = (uint32_t) port_num.range(6, 0).to_int();
    bm_field_set(_data, (offset + 2), (offset + 8), &field);
    field = (uint32_t) dst_modid.range(7, 0).to_int();
    bm_field_set(_data, (offset + 9), (offset + 16), &field);
    field = (uint32_t) dst_port.range(6, 0).to_int();
    bm_field_set(_data, (offset + 17), (offset + 23), &field);
}

int obj_bus_t::minbit() {
    return 0;
}

int obj_bus_t::maxbit() {
    return 23;
}

void index_t::set_value_48(_48bits value, int maxbit, int minbit) {
    bool __print__value = false;
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 47;
    }

#ifndef NO_CONSOLE_OUTPUT
    if ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_ALL) ||
        ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_NZ) && ((value_48(maxbit, minbit) != 0) or (value != 0)))) {
        __print__value = true;
    }

#endif
    value_48(maxbit, minbit) = value;

#ifndef NO_CONSOLE_OUTPUT
    if (__print__value) {
        bmi_log->normal("BM_DEBUG: index_t->value_48: 0x" + value_48.to_string(SC_HEX_US, false));
    }
#endif
}

void index_t::set_value_32(_32bits value, int maxbit, int minbit) {
    bool __print__value = false;
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 31;
    }

#ifndef NO_CONSOLE_OUTPUT
    if ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_ALL) ||
        ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_NZ) && ((value_32(maxbit, minbit) != 0) or (value != 0)))) {
        __print__value = true;
    }

#endif
    value_32(maxbit, minbit) = value;

#ifndef NO_CONSOLE_OUTPUT
    if (__print__value) {
        bmi_log->normal("BM_DEBUG: index_t->value_32: 0x" + value_32.to_string(SC_HEX_US, false));
    }
#endif
}

void index_t::set_value_16(_16bits value, int maxbit, int minbit) {
    bool __print__value = false;
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 15;
    }

#ifndef NO_CONSOLE_OUTPUT
    if ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_ALL) ||
        ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_NZ) && ((value_16(maxbit, minbit) != 0) or (value != 0)))) {
        __print__value = true;
    }

#endif
    value_16(maxbit, minbit) = value;

#ifndef NO_CONSOLE_OUTPUT
    if (__print__value) {
        bmi_log->normal("BM_DEBUG: index_t->value_16: 0x" + value_16.to_string(SC_HEX_US, false));
    }
#endif
}

index_t::index_t() {
    uint i;

    set_resetval();
}

index_t::~index_t() {
    uint i;

}

void index_t::set_resetval(void) {
    uint i;

    value_48 = (_48bits)(0x0U);
    value_32 = (_32bits)(0x0U);
    value_16 = (_16bits)(0x0U);
}

void index_t::set_randval(void) {
    uint i;

    value_48 = (_48bits)(rand());
    value_32 = (_32bits)(rand());
    value_16 = (_16bits)(rand());
}

void index_t::print() {
#ifndef NO_CONSOLE_OUTPUT
    uint i;

    bmi_log->normal("index_t->value_48 = 0x" + value_48.to_string(SC_HEX_US, false));
    bmi_log->normal("index_t->value_32 = 0x" + value_32.to_string(SC_HEX_US, false));
    bmi_log->normal("index_t->value_16 = 0x" + value_16.to_string(SC_HEX_US, false));
#endif
}

int index_t::compare(index_t *ref, index_t *ref_mask) {
    uint mismatch = 0;
    uint i;

    if (ref_mask == NULL) {
        if (value_48 != ref->value_48) {
            mismatch = 1;
        }
    } else {
        if ((value_48 & ref_mask->value_48) != (ref->value_48 & ref_mask->value_48)) {
            mismatch = 1;
        }
    }

    if (ref_mask == NULL) {
        if (value_32 != ref->value_32) {
            mismatch = 1;
        }
    } else {
        if ((value_32 & ref_mask->value_32) != (ref->value_32 & ref_mask->value_32)) {
            mismatch = 1;
        }
    }

    if (ref_mask == NULL) {
        if (value_16 != ref->value_16) {
            mismatch = 1;
        }
    } else {
        if ((value_16 & ref_mask->value_16) != (ref->value_16 & ref_mask->value_16)) {
            mismatch = 1;
        }
    }

    return mismatch;
}

void index_t::deep_copy(index_t *ref) {
    uint i;

    value_48 = ref->value_48;
    value_32 = ref->value_32;
    value_16 = ref->value_16;
}

void index_t::unpack_data(uint32_t *_data, int offset) {
    uint32_t field;
    uint i;

    bm_field_get(_data, 0, 47, &field);
    set_value_48((_48bits)field, -1, -1);
    bm_field_get(_data, 48, 79, &field);
    set_value_32((_32bits)field, -1, -1);
    bm_field_get(_data, 80, 95, &field);
    set_value_16((_16bits)field, -1, -1);
}

void index_t::pack_data(uint32_t *_data, int offset) {
    uint32_t field;
    uint i;

    field = (uint32_t) value_48.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) value_48.range(15, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 15), &field);
    field = (uint32_t) value_32.range(31, 0).to_int();
    bm_field_set(_data, (offset + 48), (offset + 79), &field);
    field = (uint32_t) value_16.range(15, 0).to_int();
    bm_field_set(_data, (offset + 80), (offset + 95), &field);
}

int index_t::minbit() {
    return 0;
}

int index_t::maxbit() {
    return 95;
}

void ccbi_t::set_l2_pbm(_128bits value, int maxbit, int minbit) {
    bool __print__value = false;
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 127;
    }

#ifndef NO_CONSOLE_OUTPUT
    if ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_ALL) ||
        ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_NZ) && ((l2_pbm(maxbit, minbit) != 0) or (value != 0)))) {
        __print__value = true;
    }

#endif
    l2_pbm(maxbit, minbit) = value;

#ifndef NO_CONSOLE_OUTPUT
    if (__print__value) {
        bmi_log->normal("BM_DEBUG: ccbi_t->l2_pbm: 0x" + l2_pbm.to_string(SC_HEX_US, false));
    }
#endif
}

void ccbi_t::set_l3_pbm(_128bits value, int maxbit, int minbit) {
    bool __print__value = false;
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 127;
    }

#ifndef NO_CONSOLE_OUTPUT
    if ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_ALL) ||
        ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_NZ) && ((l3_pbm(maxbit, minbit) != 0) or (value != 0)))) {
        __print__value = true;
    }

#endif
    l3_pbm(maxbit, minbit) = value;

#ifndef NO_CONSOLE_OUTPUT
    if (__print__value) {
        bmi_log->normal("BM_DEBUG: ccbi_t->l3_pbm: 0x" + l3_pbm.to_string(SC_HEX_US, false));
    }
#endif
}

ccbi_t::ccbi_t() {
    uint i;

    set_resetval();
}

ccbi_t::~ccbi_t() {
    uint i;

}

void ccbi_t::set_resetval(void) {
    uint i;

    l2_pbm = (_128bits)(0x0U);
    l3_pbm = (_128bits)(0x0U);
}

void ccbi_t::set_randval(void) {
    uint i;

    l2_pbm = (_128bits)(rand());
    l3_pbm = (_128bits)(rand());
}

void ccbi_t::print() {
#ifndef NO_CONSOLE_OUTPUT
    uint i;

    bmi_log->normal("ccbi_t->l2_pbm = 0x" + l2_pbm.to_string(SC_HEX_US, false));
    bmi_log->normal("ccbi_t->l3_pbm = 0x" + l3_pbm.to_string(SC_HEX_US, false));
#endif
}

int ccbi_t::compare(ccbi_t *ref, ccbi_t *ref_mask) {
    uint mismatch = 0;
    uint i;

    if (ref_mask == NULL) {
        if (l2_pbm != ref->l2_pbm) {
            mismatch = 1;
        }
    } else {
        if ((l2_pbm & ref_mask->l2_pbm) != (ref->l2_pbm & ref_mask->l2_pbm)) {
            mismatch = 1;
        }
    }

    if (ref_mask == NULL) {
        if (l3_pbm != ref->l3_pbm) {
            mismatch = 1;
        }
    } else {
        if ((l3_pbm & ref_mask->l3_pbm) != (ref->l3_pbm & ref_mask->l3_pbm)) {
            mismatch = 1;
        }
    }

    return mismatch;
}

void ccbi_t::deep_copy(ccbi_t *ref) {
    uint i;

    l2_pbm = ref->l2_pbm;
    l3_pbm = ref->l3_pbm;
}

void ccbi_t::unpack_data(uint32_t *_data, int offset) {
    uint32_t field;
    uint i;

    bm_field_get(_data, 0, 127, &field);
    set_l2_pbm((_128bits)field, -1, -1);
    bm_field_get(_data, 128, 255, &field);
    set_l3_pbm((_128bits)field, -1, -1);
}

void ccbi_t::pack_data(uint32_t *_data, int offset) {
    uint32_t field;
    uint i;

    field = (uint32_t) l2_pbm.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) l2_pbm.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) l2_pbm.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) l2_pbm.range(31, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 31), &field);
    field = (uint32_t) l3_pbm.range(31, 0).to_int();
    bm_field_set(_data, (offset + 128), (offset + 159), &field);
    field = (uint32_t) l3_pbm.range(31, 0).to_int();
    bm_field_set(_data, (offset + 128), (offset + 159), &field);
    field = (uint32_t) l3_pbm.range(31, 0).to_int();
    bm_field_set(_data, (offset + 128), (offset + 159), &field);
    field = (uint32_t) l3_pbm.range(31, 0).to_int();
    bm_field_set(_data, (offset + 128), (offset + 159), &field);
}

int ccbi_t::minbit() {
    return 0;
}

int ccbi_t::maxbit() {
    return 255;
}

void ccbe_t::set_dst_port(_7bits value, int maxbit, int minbit) {
    bool __print__value = false;
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 6;
    }

#ifndef NO_CONSOLE_OUTPUT
    if ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_ALL) ||
        ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_NZ) && ((dst_port(maxbit, minbit) != 0) or (value != 0)))) {
        __print__value = true;
    }

#endif
    dst_port(maxbit, minbit) = value;

#ifndef NO_CONSOLE_OUTPUT
    if (__print__value) {
        bmi_log->normal("BM_DEBUG: ccbe_t->dst_port: 0x" + dst_port.to_string(SC_HEX_US, false));
    }
#endif
}

ccbe_t::ccbe_t() {
    uint i;

    set_resetval();
}

ccbe_t::~ccbe_t() {
    uint i;

}

void ccbe_t::set_resetval(void) {
    uint i;

    dst_port = (_7bits)(0x0U);
}

void ccbe_t::set_randval(void) {
    uint i;

    dst_port = (_7bits)(rand());
}

void ccbe_t::print() {
#ifndef NO_CONSOLE_OUTPUT
    uint i;

    bmi_log->normal("ccbe_t->dst_port = 0x" + dst_port.to_string(SC_HEX_US, false));
#endif
}

int ccbe_t::compare(ccbe_t *ref, ccbe_t *ref_mask) {
    uint mismatch = 0;
    uint i;

    if (ref_mask == NULL) {
        if (dst_port != ref->dst_port) {
            mismatch = 1;
        }
    } else {
        if ((dst_port & ref_mask->dst_port) != (ref->dst_port & ref_mask->dst_port)) {
            mismatch = 1;
        }
    }

    return mismatch;
}

void ccbe_t::deep_copy(ccbe_t *ref) {
    uint i;

    dst_port = ref->dst_port;
}

void ccbe_t::unpack_data(uint32_t *_data, int offset) {
    uint32_t field;
    uint i;

    bm_field_get(_data, 0, 6, &field);
    set_dst_port((_7bits)field, -1, -1);
}

void ccbe_t::pack_data(uint32_t *_data, int offset) {
    uint32_t field;
    uint i;

    field = (uint32_t) dst_port.range(6, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 6), &field);
}

int ccbe_t::minbit() {
    return 0;
}

int ccbe_t::maxbit() {
    return 6;
}

void control_id_t::set_otpid_enable(_4bits value, int maxbit, int minbit) {
    bool __print__value = false;
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 3;
    }

#ifndef NO_CONSOLE_OUTPUT
    if ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_ALL) ||
        ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_NZ) && ((otpid_enable(maxbit, minbit) != 0) or (value != 0)))) {
        __print__value = true;
    }

#endif
    otpid_enable(maxbit, minbit) = value;

#ifndef NO_CONSOLE_OUTPUT
    if (__print__value) {
        bmi_log->normal("BM_DEBUG: control_id_t->otpid_enable: 0x" + otpid_enable.to_string(SC_HEX_US, false));
    }
#endif
}

void control_id_t::set_ts_enable(_1bit value, int maxbit, int minbit) {
    bool __print__value = false;
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 0;
    }

#ifndef NO_CONSOLE_OUTPUT
    if ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_ALL) ||
        ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_NZ) && ((ts_enable(maxbit, minbit) != 0) or (value != 0)))) {
        __print__value = true;
    }

#endif
    ts_enable(maxbit, minbit) = value;

#ifndef NO_CONSOLE_OUTPUT
    if (__print__value) {
        bmi_log->normal("BM_DEBUG: control_id_t->ts_enable: 0x" + ts_enable.to_string(SC_HEX_US, false));
    }
#endif
}

control_id_t::control_id_t() {
    uint i;

    set_resetval();
}

control_id_t::~control_id_t() {
    uint i;

}

void control_id_t::set_resetval(void) {
    uint i;

    otpid_enable = (_4bits)(0x0U);
    ts_enable = (_1bit)(0x0U);
}

void control_id_t::set_randval(void) {
    uint i;

    otpid_enable = (_4bits)(rand());
    ts_enable = (_1bit)(rand());
}

void control_id_t::print() {
#ifndef NO_CONSOLE_OUTPUT
    uint i;

    bmi_log->normal("control_id_t->otpid_enable = 0x" + otpid_enable.to_string(SC_HEX_US, false));
    bmi_log->normal("control_id_t->ts_enable = 0x" + ts_enable.to_string(SC_HEX_US, false));
#endif
}

int control_id_t::compare(control_id_t *ref, control_id_t *ref_mask) {
    uint mismatch = 0;
    uint i;

    if (ref_mask == NULL) {
        if (otpid_enable != ref->otpid_enable) {
            mismatch = 1;
        }
    } else {
        if ((otpid_enable & ref_mask->otpid_enable) != (ref->otpid_enable & ref_mask->otpid_enable)) {
            mismatch = 1;
        }
    }

    if (ref_mask == NULL) {
        if (ts_enable != ref->ts_enable) {
            mismatch = 1;
        }
    } else {
        if ((ts_enable & ref_mask->ts_enable) != (ref->ts_enable & ref_mask->ts_enable)) {
            mismatch = 1;
        }
    }

    return mismatch;
}

void control_id_t::deep_copy(control_id_t *ref) {
    uint i;

    otpid_enable = ref->otpid_enable;
    ts_enable = ref->ts_enable;
}

void control_id_t::unpack_data(uint32_t *_data, int offset) {
    uint32_t field;
    uint i;

    bm_field_get(_data, 0, 3, &field);
    set_otpid_enable((_4bits)field, -1, -1);
    bm_field_get(_data, 4, 4, &field);
    set_ts_enable((_1bit)field, -1, -1);
}

void control_id_t::pack_data(uint32_t *_data, int offset) {
    uint32_t field;
    uint i;

    field = (uint32_t) otpid_enable.range(3, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 3), &field);
    field = (uint32_t) ts_enable.range(0, 0).to_int();
    bm_field_set(_data, (offset + 4), (offset + 4), &field);
}

int control_id_t::minbit() {
    return 0;
}

int control_id_t::maxbit() {
    return 4;
}

void egr_obj_bus_t::set_dst_modid(_8bits value, int maxbit, int minbit) {
    bool __print__value = false;
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 7;
    }

#ifndef NO_CONSOLE_OUTPUT
    if ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_ALL) ||
        ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_NZ) && ((dst_modid(maxbit, minbit) != 0) or (value != 0)))) {
        __print__value = true;
    }

#endif
    dst_modid(maxbit, minbit) = value;

#ifndef NO_CONSOLE_OUTPUT
    if (__print__value) {
        bmi_log->normal("BM_DEBUG: egr_obj_bus_t->dst_modid: 0x" + dst_modid.to_string(SC_HEX_US, false));
    }
#endif
}

void egr_obj_bus_t::set_dst_port(_7bits value, int maxbit, int minbit) {
    bool __print__value = false;
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 6;
    }

#ifndef NO_CONSOLE_OUTPUT
    if ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_ALL) ||
        ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_NZ) && ((dst_port(maxbit, minbit) != 0) or (value != 0)))) {
        __print__value = true;
    }

#endif
    dst_port(maxbit, minbit) = value;

#ifndef NO_CONSOLE_OUTPUT
    if (__print__value) {
        bmi_log->normal("BM_DEBUG: egr_obj_bus_t->dst_port: 0x" + dst_port.to_string(SC_HEX_US, false));
    }
#endif
}

void egr_obj_bus_t::set_ing_port(_7bits value, int maxbit, int minbit) {
    bool __print__value = false;
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 6;
    }

#ifndef NO_CONSOLE_OUTPUT
    if ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_ALL) ||
        ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_NZ) && ((ing_port(maxbit, minbit) != 0) or (value != 0)))) {
        __print__value = true;
    }

#endif
    ing_port(maxbit, minbit) = value;

#ifndef NO_CONSOLE_OUTPUT
    if (__print__value) {
        bmi_log->normal("BM_DEBUG: egr_obj_bus_t->ing_port: 0x" + ing_port.to_string(SC_HEX_US, false));
    }
#endif
}

void egr_obj_bus_t::set_ingress_timestamp(_16bits value, int maxbit, int minbit) {
    bool __print__value = false;
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 15;
    }

#ifndef NO_CONSOLE_OUTPUT
    if ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_ALL) ||
        ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_NZ) && ((ingress_timestamp(maxbit, minbit) != 0) or (value != 0)))) {
        __print__value = true;
    }

#endif
    ingress_timestamp(maxbit, minbit) = value;

#ifndef NO_CONSOLE_OUTPUT
    if (__print__value) {
        bmi_log->normal("BM_DEBUG: egr_obj_bus_t->ingress_timestamp: 0x" + ingress_timestamp.to_string(SC_HEX_US, false));
    }
#endif
}

egr_obj_bus_t::egr_obj_bus_t() {
    uint i;

    set_resetval();
}

egr_obj_bus_t::~egr_obj_bus_t() {
    uint i;

}

void egr_obj_bus_t::set_resetval(void) {
    uint i;

    dst_modid = (_8bits)(0x0U);
    dst_port = (_7bits)(0x0U);
    ing_port = (_7bits)(0x0U);
    ingress_timestamp = (_16bits)(0x0U);
}

void egr_obj_bus_t::set_randval(void) {
    uint i;

    dst_modid = (_8bits)(rand());
    dst_port = (_7bits)(rand());
    ing_port = (_7bits)(rand());
    ingress_timestamp = (_16bits)(rand());
}

void egr_obj_bus_t::print() {
#ifndef NO_CONSOLE_OUTPUT
    uint i;

    bmi_log->normal("egr_obj_bus_t->dst_modid = 0x" + dst_modid.to_string(SC_HEX_US, false));
    bmi_log->normal("egr_obj_bus_t->dst_port = 0x" + dst_port.to_string(SC_HEX_US, false));
    bmi_log->normal("egr_obj_bus_t->ing_port = 0x" + ing_port.to_string(SC_HEX_US, false));
    bmi_log->normal("egr_obj_bus_t->ingress_timestamp = 0x" + ingress_timestamp.to_string(SC_HEX_US, false));
#endif
}

int egr_obj_bus_t::compare(egr_obj_bus_t *ref, egr_obj_bus_t *ref_mask) {
    uint mismatch = 0;
    uint i;

    if (ref_mask == NULL) {
        if (dst_modid != ref->dst_modid) {
            mismatch = 1;
        }
    } else {
        if ((dst_modid & ref_mask->dst_modid) != (ref->dst_modid & ref_mask->dst_modid)) {
            mismatch = 1;
        }
    }

    if (ref_mask == NULL) {
        if (dst_port != ref->dst_port) {
            mismatch = 1;
        }
    } else {
        if ((dst_port & ref_mask->dst_port) != (ref->dst_port & ref_mask->dst_port)) {
            mismatch = 1;
        }
    }

    if (ref_mask == NULL) {
        if (ing_port != ref->ing_port) {
            mismatch = 1;
        }
    } else {
        if ((ing_port & ref_mask->ing_port) != (ref->ing_port & ref_mask->ing_port)) {
            mismatch = 1;
        }
    }

    if (ref_mask == NULL) {
        if (ingress_timestamp != ref->ingress_timestamp) {
            mismatch = 1;
        }
    } else {
        if ((ingress_timestamp & ref_mask->ingress_timestamp) != (ref->ingress_timestamp & ref_mask->ingress_timestamp)) {
            mismatch = 1;
        }
    }

    return mismatch;
}

void egr_obj_bus_t::deep_copy(egr_obj_bus_t *ref) {
    uint i;

    dst_modid = ref->dst_modid;
    dst_port = ref->dst_port;
    ing_port = ref->ing_port;
    ingress_timestamp = ref->ingress_timestamp;
}

void egr_obj_bus_t::unpack_data(uint32_t *_data, int offset) {
    uint32_t field;
    uint i;

    bm_field_get(_data, 0, 7, &field);
    set_dst_modid((_8bits)field, -1, -1);
    bm_field_get(_data, 8, 14, &field);
    set_dst_port((_7bits)field, -1, -1);
    bm_field_get(_data, 15, 21, &field);
    set_ing_port((_7bits)field, -1, -1);
    bm_field_get(_data, 22, 37, &field);
    set_ingress_timestamp((_16bits)field, -1, -1);
}

void egr_obj_bus_t::pack_data(uint32_t *_data, int offset) {
    uint32_t field;
    uint i;

    field = (uint32_t) dst_modid.range(7, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 7), &field);
    field = (uint32_t) dst_port.range(6, 0).to_int();
    bm_field_set(_data, (offset + 8), (offset + 14), &field);
    field = (uint32_t) ing_port.range(6, 0).to_int();
    bm_field_set(_data, (offset + 15), (offset + 21), &field);
    field = (uint32_t) ingress_timestamp.range(15, 0).to_int();
    bm_field_set(_data, (offset + 22), (offset + 37), &field);
}

int egr_obj_bus_t::minbit() {
    return 0;
}

int egr_obj_bus_t::maxbit() {
    return 37;
}

void aux_bus_t::set_drop_vector(_16bits value, int maxbit, int minbit) {
    bool __print__value = false;
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 15;
    }

#ifndef NO_CONSOLE_OUTPUT
    if ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_ALL) ||
        ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_NZ) && ((drop_vector(maxbit, minbit) != 0) or (value != 0)))) {
        __print__value = true;
    }

#endif
    drop_vector(maxbit, minbit) = value;

#ifndef NO_CONSOLE_OUTPUT
    if (__print__value) {
        bmi_log->normal("BM_DEBUG: aux_bus_t->drop_vector: 0x" + drop_vector.to_string(SC_HEX_US, false));
    }
#endif
}

aux_bus_t::aux_bus_t() {
    uint i;

    set_resetval();
}

aux_bus_t::~aux_bus_t() {
    uint i;

}

void aux_bus_t::set_resetval(void) {
    uint i;

    drop_vector = (_16bits)(0x0U);
}

void aux_bus_t::set_randval(void) {
    uint i;

    drop_vector = (_16bits)(rand());
}

void aux_bus_t::print() {
#ifndef NO_CONSOLE_OUTPUT
    uint i;

    bmi_log->normal("aux_bus_t->drop_vector = 0x" + drop_vector.to_string(SC_HEX_US, false));
#endif
}

int aux_bus_t::compare(aux_bus_t *ref, aux_bus_t *ref_mask) {
    uint mismatch = 0;
    uint i;

    if (ref_mask == NULL) {
        if (drop_vector != ref->drop_vector) {
            mismatch = 1;
        }
    } else {
        if ((drop_vector & ref_mask->drop_vector) != (ref->drop_vector & ref_mask->drop_vector)) {
            mismatch = 1;
        }
    }

    return mismatch;
}

void aux_bus_t::deep_copy(aux_bus_t *ref) {
    uint i;

    drop_vector = ref->drop_vector;
}

void aux_bus_t::unpack_data(uint32_t *_data, int offset) {
    uint32_t field;
    uint i;

    bm_field_get(_data, 0, 15, &field);
    set_drop_vector((_16bits)field, -1, -1);
}

void aux_bus_t::pack_data(uint32_t *_data, int offset) {
    uint32_t field;
    uint i;

    field = (uint32_t) drop_vector.range(15, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 15), &field);
}

int aux_bus_t::minbit() {
    return 0;
}

int aux_bus_t::maxbit() {
    return 15;
}

void packet_info_t::set_job_id(_16bits value, int maxbit, int minbit) {
    bool __print__value = false;
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 15;
    }

#ifndef NO_CONSOLE_OUTPUT
    if ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_ALL) ||
        ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_NZ) && ((job_id(maxbit, minbit) != 0) or (value != 0)))) {
        __print__value = true;
    }

#endif
    job_id(maxbit, minbit) = value;

#ifndef NO_CONSOLE_OUTPUT
    if (__print__value) {
        bmi_log->normal("BM_DEBUG: packet_info_t->job_id: 0x" + job_id.to_string(SC_HEX_US, false));
    }
#endif
}

void packet_info_t::set_max_worker(_16bits value, int maxbit, int minbit) {
    bool __print__value = false;
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 15;
    }

#ifndef NO_CONSOLE_OUTPUT
    if ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_ALL) ||
        ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_NZ) && ((max_worker(maxbit, minbit) != 0) or (value != 0)))) {
        __print__value = true;
    }

#endif
    max_worker(maxbit, minbit) = value;

#ifndef NO_CONSOLE_OUTPUT
    if (__print__value) {
        bmi_log->normal("BM_DEBUG: packet_info_t->max_worker: 0x" + max_worker.to_string(SC_HEX_US, false));
    }
#endif
}

void packet_info_t::set_worker_id(_16bits value, int maxbit, int minbit) {
    bool __print__value = false;
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 15;
    }

#ifndef NO_CONSOLE_OUTPUT
    if ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_ALL) ||
        ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_NZ) && ((worker_id(maxbit, minbit) != 0) or (value != 0)))) {
        __print__value = true;
    }

#endif
    worker_id(maxbit, minbit) = value;

#ifndef NO_CONSOLE_OUTPUT
    if (__print__value) {
        bmi_log->normal("BM_DEBUG: packet_info_t->worker_id: 0x" + worker_id.to_string(SC_HEX_US, false));
    }
#endif
}

void packet_info_t::set_sequence(_16bits value, int maxbit, int minbit) {
    bool __print__value = false;
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 15;
    }

#ifndef NO_CONSOLE_OUTPUT
    if ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_ALL) ||
        ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_NZ) && ((sequence(maxbit, minbit) != 0) or (value != 0)))) {
        __print__value = true;
    }

#endif
    sequence(maxbit, minbit) = value;

#ifndef NO_CONSOLE_OUTPUT
    if (__print__value) {
        bmi_log->normal("BM_DEBUG: packet_info_t->sequence: 0x" + sequence.to_string(SC_HEX_US, false));
    }
#endif
}

void packet_info_t::set_exp(_16bits value, int maxbit, int minbit) {
    bool __print__value = false;
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 15;
    }

#ifndef NO_CONSOLE_OUTPUT
    if ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_ALL) ||
        ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_NZ) && ((exp(maxbit, minbit) != 0) or (value != 0)))) {
        __print__value = true;
    }

#endif
    exp(maxbit, minbit) = value;

#ifndef NO_CONSOLE_OUTPUT
    if (__print__value) {
        bmi_log->normal("BM_DEBUG: packet_info_t->exp: 0x" + exp.to_string(SC_HEX_US, false));
    }
#endif
}

void packet_info_t::set_bias(_16bits value, int maxbit, int minbit) {
    bool __print__value = false;
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 15;
    }

#ifndef NO_CONSOLE_OUTPUT
    if ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_ALL) ||
        ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_NZ) && ((bias(maxbit, minbit) != 0) or (value != 0)))) {
        __print__value = true;
    }

#endif
    bias(maxbit, minbit) = value;

#ifndef NO_CONSOLE_OUTPUT
    if (__print__value) {
        bmi_log->normal("BM_DEBUG: packet_info_t->bias: 0x" + bias.to_string(SC_HEX_US, false));
    }
#endif
}

void packet_info_t::set_bias_exp(_16bits value, int maxbit, int minbit) {
    bool __print__value = false;
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 15;
    }

#ifndef NO_CONSOLE_OUTPUT
    if ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_ALL) ||
        ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_NZ) && ((bias_exp(maxbit, minbit) != 0) or (value != 0)))) {
        __print__value = true;
    }

#endif
    bias_exp(maxbit, minbit) = value;

#ifndef NO_CONSOLE_OUTPUT
    if (__print__value) {
        bmi_log->normal("BM_DEBUG: packet_info_t->bias_exp: 0x" + bias_exp.to_string(SC_HEX_US, false));
    }
#endif
}

void packet_info_t::set_worker_count(_16bits value, int maxbit, int minbit) {
    bool __print__value = false;
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 15;
    }

#ifndef NO_CONSOLE_OUTPUT
    if ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_ALL) ||
        ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_NZ) && ((worker_count(maxbit, minbit) != 0) or (value != 0)))) {
        __print__value = true;
    }

#endif
    worker_count(maxbit, minbit) = value;

#ifndef NO_CONSOLE_OUTPUT
    if (__print__value) {
        bmi_log->normal("BM_DEBUG: packet_info_t->worker_count: 0x" + worker_count.to_string(SC_HEX_US, false));
    }
#endif
}

void packet_info_t::set_worker_init_bits(_16bits value, int maxbit, int minbit) {
    bool __print__value = false;
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 15;
    }

#ifndef NO_CONSOLE_OUTPUT
    if ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_ALL) ||
        ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_NZ) && ((worker_init_bits(maxbit, minbit) != 0) or (value != 0)))) {
        __print__value = true;
    }

#endif
    worker_init_bits(maxbit, minbit) = value;

#ifndef NO_CONSOLE_OUTPUT
    if (__print__value) {
        bmi_log->normal("BM_DEBUG: packet_info_t->worker_init_bits: 0x" + worker_init_bits.to_string(SC_HEX_US, false));
    }
#endif
}

void packet_info_t::set_worker_bits(_16bits value, int maxbit, int minbit) {
    bool __print__value = false;
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 15;
    }

#ifndef NO_CONSOLE_OUTPUT
    if ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_ALL) ||
        ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_NZ) && ((worker_bits(maxbit, minbit) != 0) or (value != 0)))) {
        __print__value = true;
    }

#endif
    worker_bits(maxbit, minbit) = value;

#ifndef NO_CONSOLE_OUTPUT
    if (__print__value) {
        bmi_log->normal("BM_DEBUG: packet_info_t->worker_bits: 0x" + worker_bits.to_string(SC_HEX_US, false));
    }
#endif
}

void packet_info_t::set_max_worker_bits(_16bits value, int maxbit, int minbit) {
    bool __print__value = false;
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 15;
    }

#ifndef NO_CONSOLE_OUTPUT
    if ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_ALL) ||
        ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_NZ) && ((max_worker_bits(maxbit, minbit) != 0) or (value != 0)))) {
        __print__value = true;
    }

#endif
    max_worker_bits(maxbit, minbit) = value;

#ifndef NO_CONSOLE_OUTPUT
    if (__print__value) {
        bmi_log->normal("BM_DEBUG: packet_info_t->max_worker_bits: 0x" + max_worker_bits.to_string(SC_HEX_US, false));
    }
#endif
}

void packet_info_t::set_reset_worker_bits(_16bits value, int maxbit, int minbit) {
    bool __print__value = false;
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 15;
    }

#ifndef NO_CONSOLE_OUTPUT
    if ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_ALL) ||
        ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_NZ) && ((reset_worker_bits(maxbit, minbit) != 0) or (value != 0)))) {
        __print__value = true;
    }

#endif
    reset_worker_bits(maxbit, minbit) = value;

#ifndef NO_CONSOLE_OUTPUT
    if (__print__value) {
        bmi_log->normal("BM_DEBUG: packet_info_t->reset_worker_bits: 0x" + reset_worker_bits.to_string(SC_HEX_US, false));
    }
#endif
}

void packet_info_t::set_masks(packet_value_t *ref) {
    bool __print__value = false;
    uint i;

    masks->deep_copy(ref);
}

packet_info_t::packet_info_t() {
    uint i;

    masks = new packet_value_t;
    set_resetval();
}

packet_info_t::~packet_info_t() {
    uint i;

    delete masks;
}

void packet_info_t::set_resetval(void) {
    uint i;

    job_id = (_16bits)(0x0U);
    max_worker = (_16bits)(0x0U);
    worker_id = (_16bits)(0x0U);
    sequence = (_16bits)(0x0U);
    exp = (_16bits)(0x0U);
    bias = (_16bits)(0x0U);
    bias_exp = (_16bits)(0x0U);
    worker_count = (_16bits)(0x0U);
    worker_init_bits = (_16bits)(0x0U);
    worker_bits = (_16bits)(0x0U);
    max_worker_bits = (_16bits)(0x0U);
    reset_worker_bits = (_16bits)(0x0U);
    masks->set_resetval();
}

void packet_info_t::set_randval(void) {
    uint i;

    job_id = (_16bits)(rand());
    max_worker = (_16bits)(rand());
    worker_id = (_16bits)(rand());
    sequence = (_16bits)(rand());
    exp = (_16bits)(rand());
    bias = (_16bits)(rand());
    bias_exp = (_16bits)(rand());
    worker_count = (_16bits)(rand());
    worker_init_bits = (_16bits)(rand());
    worker_bits = (_16bits)(rand());
    max_worker_bits = (_16bits)(rand());
    reset_worker_bits = (_16bits)(rand());
    masks->set_randval();
}

void packet_info_t::print() {
#ifndef NO_CONSOLE_OUTPUT
    uint i;

    bmi_log->normal("packet_info_t->job_id = 0x" + job_id.to_string(SC_HEX_US, false));
    bmi_log->normal("packet_info_t->max_worker = 0x" + max_worker.to_string(SC_HEX_US, false));
    bmi_log->normal("packet_info_t->worker_id = 0x" + worker_id.to_string(SC_HEX_US, false));
    bmi_log->normal("packet_info_t->sequence = 0x" + sequence.to_string(SC_HEX_US, false));
    bmi_log->normal("packet_info_t->exp = 0x" + exp.to_string(SC_HEX_US, false));
    bmi_log->normal("packet_info_t->bias = 0x" + bias.to_string(SC_HEX_US, false));
    bmi_log->normal("packet_info_t->bias_exp = 0x" + bias_exp.to_string(SC_HEX_US, false));
    bmi_log->normal("packet_info_t->worker_count = 0x" + worker_count.to_string(SC_HEX_US, false));
    bmi_log->normal("packet_info_t->worker_init_bits = 0x" + worker_init_bits.to_string(SC_HEX_US, false));
    bmi_log->normal("packet_info_t->worker_bits = 0x" + worker_bits.to_string(SC_HEX_US, false));
    bmi_log->normal("packet_info_t->max_worker_bits = 0x" + max_worker_bits.to_string(SC_HEX_US, false));
    bmi_log->normal("packet_info_t->reset_worker_bits = 0x" + reset_worker_bits.to_string(SC_HEX_US, false));
    masks->print();
#endif
}

int packet_info_t::compare(packet_info_t *ref, packet_info_t *ref_mask) {
    uint mismatch = 0;
    uint i;

    if (ref_mask == NULL) {
        if (job_id != ref->job_id) {
            mismatch = 1;
        }
    } else {
        if ((job_id & ref_mask->job_id) != (ref->job_id & ref_mask->job_id)) {
            mismatch = 1;
        }
    }

    if (ref_mask == NULL) {
        if (max_worker != ref->max_worker) {
            mismatch = 1;
        }
    } else {
        if ((max_worker & ref_mask->max_worker) != (ref->max_worker & ref_mask->max_worker)) {
            mismatch = 1;
        }
    }

    if (ref_mask == NULL) {
        if (worker_id != ref->worker_id) {
            mismatch = 1;
        }
    } else {
        if ((worker_id & ref_mask->worker_id) != (ref->worker_id & ref_mask->worker_id)) {
            mismatch = 1;
        }
    }

    if (ref_mask == NULL) {
        if (sequence != ref->sequence) {
            mismatch = 1;
        }
    } else {
        if ((sequence & ref_mask->sequence) != (ref->sequence & ref_mask->sequence)) {
            mismatch = 1;
        }
    }

    if (ref_mask == NULL) {
        if (exp != ref->exp) {
            mismatch = 1;
        }
    } else {
        if ((exp & ref_mask->exp) != (ref->exp & ref_mask->exp)) {
            mismatch = 1;
        }
    }

    if (ref_mask == NULL) {
        if (bias != ref->bias) {
            mismatch = 1;
        }
    } else {
        if ((bias & ref_mask->bias) != (ref->bias & ref_mask->bias)) {
            mismatch = 1;
        }
    }

    if (ref_mask == NULL) {
        if (bias_exp != ref->bias_exp) {
            mismatch = 1;
        }
    } else {
        if ((bias_exp & ref_mask->bias_exp) != (ref->bias_exp & ref_mask->bias_exp)) {
            mismatch = 1;
        }
    }

    if (ref_mask == NULL) {
        if (worker_count != ref->worker_count) {
            mismatch = 1;
        }
    } else {
        if ((worker_count & ref_mask->worker_count) != (ref->worker_count & ref_mask->worker_count)) {
            mismatch = 1;
        }
    }

    if (ref_mask == NULL) {
        if (worker_init_bits != ref->worker_init_bits) {
            mismatch = 1;
        }
    } else {
        if ((worker_init_bits & ref_mask->worker_init_bits) != (ref->worker_init_bits & ref_mask->worker_init_bits)) {
            mismatch = 1;
        }
    }

    if (ref_mask == NULL) {
        if (worker_bits != ref->worker_bits) {
            mismatch = 1;
        }
    } else {
        if ((worker_bits & ref_mask->worker_bits) != (ref->worker_bits & ref_mask->worker_bits)) {
            mismatch = 1;
        }
    }

    if (ref_mask == NULL) {
        if (max_worker_bits != ref->max_worker_bits) {
            mismatch = 1;
        }
    } else {
        if ((max_worker_bits & ref_mask->max_worker_bits) != (ref->max_worker_bits & ref_mask->max_worker_bits)) {
            mismatch = 1;
        }
    }

    if (ref_mask == NULL) {
        if (reset_worker_bits != ref->reset_worker_bits) {
            mismatch = 1;
        }
    } else {
        if ((reset_worker_bits & ref_mask->reset_worker_bits) != (ref->reset_worker_bits & ref_mask->reset_worker_bits)) {
            mismatch = 1;
        }
    }

    if (ref_mask == NULL) {
        if (masks->compare(ref->masks, NULL) == 1) {
            mismatch = 1;
        }
    } else {
        if (masks->compare(ref->masks, ref_mask->masks) == 1) {
            mismatch = 1;
        }
    }
    return mismatch;
}

void packet_info_t::deep_copy(packet_info_t *ref) {
    uint i;

    job_id = ref->job_id;
    max_worker = ref->max_worker;
    worker_id = ref->worker_id;
    sequence = ref->sequence;
    exp = ref->exp;
    bias = ref->bias;
    bias_exp = ref->bias_exp;
    worker_count = ref->worker_count;
    worker_init_bits = ref->worker_init_bits;
    worker_bits = ref->worker_bits;
    max_worker_bits = ref->max_worker_bits;
    reset_worker_bits = ref->reset_worker_bits;
    masks->deep_copy(ref->masks);
}

void packet_info_t::unpack_data(uint32_t *_data, int offset) {
    uint32_t field;
    uint i;

    bm_field_get(_data, 0, 15, &field);
    set_job_id((_16bits)field, -1, -1);
    bm_field_get(_data, 16, 31, &field);
    set_max_worker((_16bits)field, -1, -1);
    bm_field_get(_data, 32, 47, &field);
    set_worker_id((_16bits)field, -1, -1);
    bm_field_get(_data, 48, 63, &field);
    set_sequence((_16bits)field, -1, -1);
    bm_field_get(_data, 64, 79, &field);
    set_exp((_16bits)field, -1, -1);
    bm_field_get(_data, 80, 95, &field);
    set_bias((_16bits)field, -1, -1);
    bm_field_get(_data, 96, 111, &field);
    set_bias_exp((_16bits)field, -1, -1);
    bm_field_get(_data, 112, 127, &field);
    set_worker_count((_16bits)field, -1, -1);
    bm_field_get(_data, 128, 143, &field);
    set_worker_init_bits((_16bits)field, -1, -1);
    bm_field_get(_data, 144, 159, &field);
    set_worker_bits((_16bits)field, -1, -1);
    bm_field_get(_data, 160, 175, &field);
    set_max_worker_bits((_16bits)field, -1, -1);
    bm_field_get(_data, 176, 191, &field);
    set_reset_worker_bits((_16bits)field, -1, -1);
    bm_field_get(_data, 192, 8383, &field);
    masks->unpack_data(&field);
}

void packet_info_t::pack_data(uint32_t *_data, int offset) {
    uint32_t field;
    uint i;

    field = (uint32_t) job_id.range(15, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 15), &field);
    field = (uint32_t) max_worker.range(15, 0).to_int();
    bm_field_set(_data, (offset + 16), (offset + 31), &field);
    field = (uint32_t) worker_id.range(15, 0).to_int();
    bm_field_set(_data, (offset + 32), (offset + 47), &field);
    field = (uint32_t) sequence.range(15, 0).to_int();
    bm_field_set(_data, (offset + 48), (offset + 63), &field);
    field = (uint32_t) exp.range(15, 0).to_int();
    bm_field_set(_data, (offset + 64), (offset + 79), &field);
    field = (uint32_t) bias.range(15, 0).to_int();
    bm_field_set(_data, (offset + 80), (offset + 95), &field);
    field = (uint32_t) bias_exp.range(15, 0).to_int();
    bm_field_set(_data, (offset + 96), (offset + 111), &field);
    field = (uint32_t) worker_count.range(15, 0).to_int();
    bm_field_set(_data, (offset + 112), (offset + 127), &field);
    field = (uint32_t) worker_init_bits.range(15, 0).to_int();
    bm_field_set(_data, (offset + 128), (offset + 143), &field);
    field = (uint32_t) worker_bits.range(15, 0).to_int();
    bm_field_set(_data, (offset + 144), (offset + 159), &field);
    field = (uint32_t) max_worker_bits.range(15, 0).to_int();
    bm_field_set(_data, (offset + 160), (offset + 175), &field);
    field = (uint32_t) reset_worker_bits.range(15, 0).to_int();
    bm_field_set(_data, (offset + 176), (offset + 191), &field);
    masks->pack_data(_data, 192);
}

int packet_info_t::minbit() {
    return 0;
}

int packet_info_t::maxbit() {
    return 8383;
}

void time_bus_t::set_currenttime(_16bits value, int maxbit, int minbit) {
    bool __print__value = false;
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 15;
    }

#ifndef NO_CONSOLE_OUTPUT
    if ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_ALL) ||
        ((bm_debug_lvl>=BM_DEBUG_LVL_DEBUG_NZ) && ((currenttime(maxbit, minbit) != 0) or (value != 0)))) {
        __print__value = true;
    }

#endif
    currenttime(maxbit, minbit) = value;

#ifndef NO_CONSOLE_OUTPUT
    if (__print__value) {
        bmi_log->normal("BM_DEBUG: time_bus_t->currenttime: 0x" + currenttime.to_string(SC_HEX_US, false));
    }
#endif
}

time_bus_t::time_bus_t() {
    uint i;

    set_resetval();
}

time_bus_t::~time_bus_t() {
    uint i;

}

void time_bus_t::set_resetval(void) {
    uint i;

    currenttime = (_16bits)(0x0U);
}

void time_bus_t::set_randval(void) {
    uint i;

    currenttime = (_16bits)(rand());
}

void time_bus_t::print() {
#ifndef NO_CONSOLE_OUTPUT
    uint i;

    bmi_log->normal("time_bus_t->currenttime = 0x" + currenttime.to_string(SC_HEX_US, false));
#endif
}

int time_bus_t::compare(time_bus_t *ref, time_bus_t *ref_mask) {
    uint mismatch = 0;
    uint i;

    if (ref_mask == NULL) {
        if (currenttime != ref->currenttime) {
            mismatch = 1;
        }
    } else {
        if ((currenttime & ref_mask->currenttime) != (ref->currenttime & ref_mask->currenttime)) {
            mismatch = 1;
        }
    }

    return mismatch;
}

void time_bus_t::deep_copy(time_bus_t *ref) {
    uint i;

    currenttime = ref->currenttime;
}

void time_bus_t::unpack_data(uint32_t *_data, int offset) {
    uint32_t field;
    uint i;

    bm_field_get(_data, 0, 15, &field);
    set_currenttime((_16bits)field, -1, -1);
}

void time_bus_t::pack_data(uint32_t *_data, int offset) {
    uint32_t field;
    uint i;

    field = (uint32_t) currenttime.range(15, 0).to_int();
    bm_field_set(_data, (offset + 0), (offset + 15), &field);
}

int time_bus_t::minbit() {
    return 0;
}

int time_bus_t::maxbit() {
    return 15;
}

