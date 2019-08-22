/*
 * SCRIPT GENERATED FILE, DO NOT MODIFY
*/


#include "reg_classes.h"
#include "base/cLog.h"

void tuple_t::set_data_t(_32bits value, int maxbit, int minbit) {
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 31;
    }

    data_t(maxbit, minbit) = value;
}

tuple_t::tuple_t() {
    uint i;

    data_t = (_32bits)(0);
}

void tuple_t::print() {
#ifndef NO_CONSOLE_OUTPUT
    uint i;

    bmi_log->normal("tuple_t->data_t = 0x" + data_t.to_string(SC_HEX_US, false));
#endif
}

int tuple_t::compare(tuple_t *ref, tuple_t *ref_mask) {
    uint mismatch = 0;
    uint i;

    if (ref_mask == NULL) {
        if (data_t != ref->data_t) {
            mismatch = 1;
        }
    } else {
        if ((data_t & ref_mask->data_t) != (ref->data_t & ref_mask->data_t)) {
            mismatch = 1;
        }
    }

    return mismatch;
}

void tuple_t::deep_copy(tuple_t *ref) {
    uint i;

    data_t = ref->data_t;
}

void ps_worker_count::set_value0(_16bits value, int maxbit, int minbit) {
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 15;
    }

    value0(maxbit, minbit) = value;
}

void ps_worker_count::set_value1(_16bits value, int maxbit, int minbit) {
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 15;
    }

    value1(maxbit, minbit) = value;
}

void ps_worker_count::set_value2(_16bits value, int maxbit, int minbit) {
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 15;
    }

    value2(maxbit, minbit) = value;
}

void ps_worker_count::set_value3(_16bits value, int maxbit, int minbit) {
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 15;
    }

    value3(maxbit, minbit) = value;
}

ps_worker_count::ps_worker_count() {
    uint i;

    value0 = (_16bits)(0);
    value1 = (_16bits)(0);
    value2 = (_16bits)(0);
    value3 = (_16bits)(0);
}

void ps_worker_count::print() {
#ifndef NO_CONSOLE_OUTPUT
    uint i;

    bmi_log->normal("ps_worker_count->value0 = 0x" + value0.to_string(SC_HEX_US, false));
    bmi_log->normal("ps_worker_count->value1 = 0x" + value1.to_string(SC_HEX_US, false));
    bmi_log->normal("ps_worker_count->value2 = 0x" + value2.to_string(SC_HEX_US, false));
    bmi_log->normal("ps_worker_count->value3 = 0x" + value3.to_string(SC_HEX_US, false));
#endif
}

int ps_worker_count::compare(ps_worker_count *ref, ps_worker_count *ref_mask) {
    uint mismatch = 0;
    uint i;

    if (ref_mask == NULL) {
        if (value0 != ref->value0) {
            mismatch = 1;
        }
    } else {
        if ((value0 & ref_mask->value0) != (ref->value0 & ref_mask->value0)) {
            mismatch = 1;
        }
    }

    if (ref_mask == NULL) {
        if (value1 != ref->value1) {
            mismatch = 1;
        }
    } else {
        if ((value1 & ref_mask->value1) != (ref->value1 & ref_mask->value1)) {
            mismatch = 1;
        }
    }

    if (ref_mask == NULL) {
        if (value2 != ref->value2) {
            mismatch = 1;
        }
    } else {
        if ((value2 & ref_mask->value2) != (ref->value2 & ref_mask->value2)) {
            mismatch = 1;
        }
    }

    if (ref_mask == NULL) {
        if (value3 != ref->value3) {
            mismatch = 1;
        }
    } else {
        if ((value3 & ref_mask->value3) != (ref->value3 & ref_mask->value3)) {
            mismatch = 1;
        }
    }

    return mismatch;
}

void ps_worker_count::deep_copy(ps_worker_count *ref) {
    uint i;

    value0 = ref->value0;
    value1 = ref->value1;
    value2 = ref->value2;
    value3 = ref->value3;
}

void ps_value::set_value00(_8192bits value, int maxbit, int minbit) {
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 8191;
    }

    value00(maxbit, minbit) = value;
}

void ps_value::set_value01(_8192bits value, int maxbit, int minbit) {
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 8191;
    }

    value01(maxbit, minbit) = value;
}

void ps_value::set_value10(_8192bits value, int maxbit, int minbit) {
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 8191;
    }

    value10(maxbit, minbit) = value;
}

void ps_value::set_value11(_8192bits value, int maxbit, int minbit) {
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 8191;
    }

    value11(maxbit, minbit) = value;
}

void ps_value::set_value20(_8192bits value, int maxbit, int minbit) {
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 8191;
    }

    value20(maxbit, minbit) = value;
}

void ps_value::set_value21(_8192bits value, int maxbit, int minbit) {
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 8191;
    }

    value21(maxbit, minbit) = value;
}

void ps_value::set_value30(_8192bits value, int maxbit, int minbit) {
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 8191;
    }

    value30(maxbit, minbit) = value;
}

void ps_value::set_value31(_8192bits value, int maxbit, int minbit) {
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 8191;
    }

    value31(maxbit, minbit) = value;
}

ps_value::ps_value() {
    uint i;

    value00 = (_8192bits)(0);
    value01 = (_8192bits)(0);
    value10 = (_8192bits)(0);
    value11 = (_8192bits)(0);
    value20 = (_8192bits)(0);
    value21 = (_8192bits)(0);
    value30 = (_8192bits)(0);
    value31 = (_8192bits)(0);
}

void ps_value::print() {
#ifndef NO_CONSOLE_OUTPUT
    uint i;

    bmi_log->normal("ps_value->value00 = 0x" + value00.to_string(SC_HEX_US, false));
    bmi_log->normal("ps_value->value01 = 0x" + value01.to_string(SC_HEX_US, false));
    bmi_log->normal("ps_value->value10 = 0x" + value10.to_string(SC_HEX_US, false));
    bmi_log->normal("ps_value->value11 = 0x" + value11.to_string(SC_HEX_US, false));
    bmi_log->normal("ps_value->value20 = 0x" + value20.to_string(SC_HEX_US, false));
    bmi_log->normal("ps_value->value21 = 0x" + value21.to_string(SC_HEX_US, false));
    bmi_log->normal("ps_value->value30 = 0x" + value30.to_string(SC_HEX_US, false));
    bmi_log->normal("ps_value->value31 = 0x" + value31.to_string(SC_HEX_US, false));
#endif
}

int ps_value::compare(ps_value *ref, ps_value *ref_mask) {
    uint mismatch = 0;
    uint i;

    if (ref_mask == NULL) {
        if (value00 != ref->value00) {
            mismatch = 1;
        }
    } else {
        if ((value00 & ref_mask->value00) != (ref->value00 & ref_mask->value00)) {
            mismatch = 1;
        }
    }

    if (ref_mask == NULL) {
        if (value01 != ref->value01) {
            mismatch = 1;
        }
    } else {
        if ((value01 & ref_mask->value01) != (ref->value01 & ref_mask->value01)) {
            mismatch = 1;
        }
    }

    if (ref_mask == NULL) {
        if (value10 != ref->value10) {
            mismatch = 1;
        }
    } else {
        if ((value10 & ref_mask->value10) != (ref->value10 & ref_mask->value10)) {
            mismatch = 1;
        }
    }

    if (ref_mask == NULL) {
        if (value11 != ref->value11) {
            mismatch = 1;
        }
    } else {
        if ((value11 & ref_mask->value11) != (ref->value11 & ref_mask->value11)) {
            mismatch = 1;
        }
    }

    if (ref_mask == NULL) {
        if (value20 != ref->value20) {
            mismatch = 1;
        }
    } else {
        if ((value20 & ref_mask->value20) != (ref->value20 & ref_mask->value20)) {
            mismatch = 1;
        }
    }

    if (ref_mask == NULL) {
        if (value21 != ref->value21) {
            mismatch = 1;
        }
    } else {
        if ((value21 & ref_mask->value21) != (ref->value21 & ref_mask->value21)) {
            mismatch = 1;
        }
    }

    if (ref_mask == NULL) {
        if (value30 != ref->value30) {
            mismatch = 1;
        }
    } else {
        if ((value30 & ref_mask->value30) != (ref->value30 & ref_mask->value30)) {
            mismatch = 1;
        }
    }

    if (ref_mask == NULL) {
        if (value31 != ref->value31) {
            mismatch = 1;
        }
    } else {
        if ((value31 & ref_mask->value31) != (ref->value31 & ref_mask->value31)) {
            mismatch = 1;
        }
    }

    return mismatch;
}

void ps_value::deep_copy(ps_value *ref) {
    uint i;

    value00 = ref->value00;
    value01 = ref->value01;
    value10 = ref->value10;
    value11 = ref->value11;
    value20 = ref->value20;
    value21 = ref->value21;
    value30 = ref->value30;
    value31 = ref->value31;
}

void ps_worker_smac::set_value0(_48bits value, int maxbit, int minbit) {
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 47;
    }

    value0(maxbit, minbit) = value;
}

void ps_worker_smac::set_value1(_48bits value, int maxbit, int minbit) {
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 47;
    }

    value1(maxbit, minbit) = value;
}

void ps_worker_smac::set_value2(_48bits value, int maxbit, int minbit) {
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 47;
    }

    value2(maxbit, minbit) = value;
}

void ps_worker_smac::set_value3(_48bits value, int maxbit, int minbit) {
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 47;
    }

    value3(maxbit, minbit) = value;
}

ps_worker_smac::ps_worker_smac() {
    uint i;

    value0 = (_48bits)(0);
    value1 = (_48bits)(0);
    value2 = (_48bits)(0);
    value3 = (_48bits)(0);
}

void ps_worker_smac::print() {
#ifndef NO_CONSOLE_OUTPUT
    uint i;

    bmi_log->normal("ps_worker_smac->value0 = 0x" + value0.to_string(SC_HEX_US, false));
    bmi_log->normal("ps_worker_smac->value1 = 0x" + value1.to_string(SC_HEX_US, false));
    bmi_log->normal("ps_worker_smac->value2 = 0x" + value2.to_string(SC_HEX_US, false));
    bmi_log->normal("ps_worker_smac->value3 = 0x" + value3.to_string(SC_HEX_US, false));
#endif
}

int ps_worker_smac::compare(ps_worker_smac *ref, ps_worker_smac *ref_mask) {
    uint mismatch = 0;
    uint i;

    if (ref_mask == NULL) {
        if (value0 != ref->value0) {
            mismatch = 1;
        }
    } else {
        if ((value0 & ref_mask->value0) != (ref->value0 & ref_mask->value0)) {
            mismatch = 1;
        }
    }

    if (ref_mask == NULL) {
        if (value1 != ref->value1) {
            mismatch = 1;
        }
    } else {
        if ((value1 & ref_mask->value1) != (ref->value1 & ref_mask->value1)) {
            mismatch = 1;
        }
    }

    if (ref_mask == NULL) {
        if (value2 != ref->value2) {
            mismatch = 1;
        }
    } else {
        if ((value2 & ref_mask->value2) != (ref->value2 & ref_mask->value2)) {
            mismatch = 1;
        }
    }

    if (ref_mask == NULL) {
        if (value3 != ref->value3) {
            mismatch = 1;
        }
    } else {
        if ((value3 & ref_mask->value3) != (ref->value3 & ref_mask->value3)) {
            mismatch = 1;
        }
    }

    return mismatch;
}

void ps_worker_smac::deep_copy(ps_worker_smac *ref) {
    uint i;

    value0 = ref->value0;
    value1 = ref->value1;
    value2 = ref->value2;
    value3 = ref->value3;
}

void ps_worker_sip::set_value0(_32bits value, int maxbit, int minbit) {
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 31;
    }

    value0(maxbit, minbit) = value;
}

void ps_worker_sip::set_value1(_32bits value, int maxbit, int minbit) {
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 31;
    }

    value1(maxbit, minbit) = value;
}

void ps_worker_sip::set_value2(_32bits value, int maxbit, int minbit) {
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 31;
    }

    value2(maxbit, minbit) = value;
}

void ps_worker_sip::set_value3(_32bits value, int maxbit, int minbit) {
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 31;
    }

    value3(maxbit, minbit) = value;
}

ps_worker_sip::ps_worker_sip() {
    uint i;

    value0 = (_32bits)(0);
    value1 = (_32bits)(0);
    value2 = (_32bits)(0);
    value3 = (_32bits)(0);
}

void ps_worker_sip::print() {
#ifndef NO_CONSOLE_OUTPUT
    uint i;

    bmi_log->normal("ps_worker_sip->value0 = 0x" + value0.to_string(SC_HEX_US, false));
    bmi_log->normal("ps_worker_sip->value1 = 0x" + value1.to_string(SC_HEX_US, false));
    bmi_log->normal("ps_worker_sip->value2 = 0x" + value2.to_string(SC_HEX_US, false));
    bmi_log->normal("ps_worker_sip->value3 = 0x" + value3.to_string(SC_HEX_US, false));
#endif
}

int ps_worker_sip::compare(ps_worker_sip *ref, ps_worker_sip *ref_mask) {
    uint mismatch = 0;
    uint i;

    if (ref_mask == NULL) {
        if (value0 != ref->value0) {
            mismatch = 1;
        }
    } else {
        if ((value0 & ref_mask->value0) != (ref->value0 & ref_mask->value0)) {
            mismatch = 1;
        }
    }

    if (ref_mask == NULL) {
        if (value1 != ref->value1) {
            mismatch = 1;
        }
    } else {
        if ((value1 & ref_mask->value1) != (ref->value1 & ref_mask->value1)) {
            mismatch = 1;
        }
    }

    if (ref_mask == NULL) {
        if (value2 != ref->value2) {
            mismatch = 1;
        }
    } else {
        if ((value2 & ref_mask->value2) != (ref->value2 & ref_mask->value2)) {
            mismatch = 1;
        }
    }

    if (ref_mask == NULL) {
        if (value3 != ref->value3) {
            mismatch = 1;
        }
    } else {
        if ((value3 & ref_mask->value3) != (ref->value3 & ref_mask->value3)) {
            mismatch = 1;
        }
    }

    return mismatch;
}

void ps_worker_sip::deep_copy(ps_worker_sip *ref) {
    uint i;

    value0 = ref->value0;
    value1 = ref->value1;
    value2 = ref->value2;
    value3 = ref->value3;
}

void ps_worker_sport::set_value0(_16bits value, int maxbit, int minbit) {
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 15;
    }

    value0(maxbit, minbit) = value;
}

void ps_worker_sport::set_value1(_16bits value, int maxbit, int minbit) {
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 15;
    }

    value1(maxbit, minbit) = value;
}

void ps_worker_sport::set_value2(_16bits value, int maxbit, int minbit) {
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 15;
    }

    value2(maxbit, minbit) = value;
}

void ps_worker_sport::set_value3(_16bits value, int maxbit, int minbit) {
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 15;
    }

    value3(maxbit, minbit) = value;
}

ps_worker_sport::ps_worker_sport() {
    uint i;

    value0 = (_16bits)(0);
    value1 = (_16bits)(0);
    value2 = (_16bits)(0);
    value3 = (_16bits)(0);
}

void ps_worker_sport::print() {
#ifndef NO_CONSOLE_OUTPUT
    uint i;

    bmi_log->normal("ps_worker_sport->value0 = 0x" + value0.to_string(SC_HEX_US, false));
    bmi_log->normal("ps_worker_sport->value1 = 0x" + value1.to_string(SC_HEX_US, false));
    bmi_log->normal("ps_worker_sport->value2 = 0x" + value2.to_string(SC_HEX_US, false));
    bmi_log->normal("ps_worker_sport->value3 = 0x" + value3.to_string(SC_HEX_US, false));
#endif
}

int ps_worker_sport::compare(ps_worker_sport *ref, ps_worker_sport *ref_mask) {
    uint mismatch = 0;
    uint i;

    if (ref_mask == NULL) {
        if (value0 != ref->value0) {
            mismatch = 1;
        }
    } else {
        if ((value0 & ref_mask->value0) != (ref->value0 & ref_mask->value0)) {
            mismatch = 1;
        }
    }

    if (ref_mask == NULL) {
        if (value1 != ref->value1) {
            mismatch = 1;
        }
    } else {
        if ((value1 & ref_mask->value1) != (ref->value1 & ref_mask->value1)) {
            mismatch = 1;
        }
    }

    if (ref_mask == NULL) {
        if (value2 != ref->value2) {
            mismatch = 1;
        }
    } else {
        if ((value2 & ref_mask->value2) != (ref->value2 & ref_mask->value2)) {
            mismatch = 1;
        }
    }

    if (ref_mask == NULL) {
        if (value3 != ref->value3) {
            mismatch = 1;
        }
    } else {
        if ((value3 & ref_mask->value3) != (ref->value3 & ref_mask->value3)) {
            mismatch = 1;
        }
    }

    return mismatch;
}

void ps_worker_sport::deep_copy(ps_worker_sport *ref) {
    uint i;

    value0 = ref->value0;
    value1 = ref->value1;
    value2 = ref->value2;
    value3 = ref->value3;
}

void ps_bias_exp::set_value0(_16bits value, int maxbit, int minbit) {
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 15;
    }

    value0(maxbit, minbit) = value;
}

void ps_bias_exp::set_value1(_16bits value, int maxbit, int minbit) {
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 15;
    }

    value1(maxbit, minbit) = value;
}

void ps_bias_exp::set_value2(_16bits value, int maxbit, int minbit) {
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 15;
    }

    value2(maxbit, minbit) = value;
}

void ps_bias_exp::set_value3(_16bits value, int maxbit, int minbit) {
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 15;
    }

    value3(maxbit, minbit) = value;
}

ps_bias_exp::ps_bias_exp() {
    uint i;

    value0 = (_16bits)(0);
    value1 = (_16bits)(0);
    value2 = (_16bits)(0);
    value3 = (_16bits)(0);
}

void ps_bias_exp::print() {
#ifndef NO_CONSOLE_OUTPUT
    uint i;

    bmi_log->normal("ps_bias_exp->value0 = 0x" + value0.to_string(SC_HEX_US, false));
    bmi_log->normal("ps_bias_exp->value1 = 0x" + value1.to_string(SC_HEX_US, false));
    bmi_log->normal("ps_bias_exp->value2 = 0x" + value2.to_string(SC_HEX_US, false));
    bmi_log->normal("ps_bias_exp->value3 = 0x" + value3.to_string(SC_HEX_US, false));
#endif
}

int ps_bias_exp::compare(ps_bias_exp *ref, ps_bias_exp *ref_mask) {
    uint mismatch = 0;
    uint i;

    if (ref_mask == NULL) {
        if (value0 != ref->value0) {
            mismatch = 1;
        }
    } else {
        if ((value0 & ref_mask->value0) != (ref->value0 & ref_mask->value0)) {
            mismatch = 1;
        }
    }

    if (ref_mask == NULL) {
        if (value1 != ref->value1) {
            mismatch = 1;
        }
    } else {
        if ((value1 & ref_mask->value1) != (ref->value1 & ref_mask->value1)) {
            mismatch = 1;
        }
    }

    if (ref_mask == NULL) {
        if (value2 != ref->value2) {
            mismatch = 1;
        }
    } else {
        if ((value2 & ref_mask->value2) != (ref->value2 & ref_mask->value2)) {
            mismatch = 1;
        }
    }

    if (ref_mask == NULL) {
        if (value3 != ref->value3) {
            mismatch = 1;
        }
    } else {
        if ((value3 & ref_mask->value3) != (ref->value3 & ref_mask->value3)) {
            mismatch = 1;
        }
    }

    return mismatch;
}

void ps_bias_exp::deep_copy(ps_bias_exp *ref) {
    uint i;

    value0 = ref->value0;
    value1 = ref->value1;
    value2 = ref->value2;
    value3 = ref->value3;
}

void ps_exp::set_value0(_16bits value, int maxbit, int minbit) {
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 15;
    }

    value0(maxbit, minbit) = value;
}

void ps_exp::set_value1(_16bits value, int maxbit, int minbit) {
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 15;
    }

    value1(maxbit, minbit) = value;
}

void ps_exp::set_value2(_16bits value, int maxbit, int minbit) {
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 15;
    }

    value2(maxbit, minbit) = value;
}

void ps_exp::set_value3(_16bits value, int maxbit, int minbit) {
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 15;
    }

    value3(maxbit, minbit) = value;
}

ps_exp::ps_exp() {
    uint i;

    value0 = (_16bits)(0);
    value1 = (_16bits)(0);
    value2 = (_16bits)(0);
    value3 = (_16bits)(0);
}

void ps_exp::print() {
#ifndef NO_CONSOLE_OUTPUT
    uint i;

    bmi_log->normal("ps_exp->value0 = 0x" + value0.to_string(SC_HEX_US, false));
    bmi_log->normal("ps_exp->value1 = 0x" + value1.to_string(SC_HEX_US, false));
    bmi_log->normal("ps_exp->value2 = 0x" + value2.to_string(SC_HEX_US, false));
    bmi_log->normal("ps_exp->value3 = 0x" + value3.to_string(SC_HEX_US, false));
#endif
}

int ps_exp::compare(ps_exp *ref, ps_exp *ref_mask) {
    uint mismatch = 0;
    uint i;

    if (ref_mask == NULL) {
        if (value0 != ref->value0) {
            mismatch = 1;
        }
    } else {
        if ((value0 & ref_mask->value0) != (ref->value0 & ref_mask->value0)) {
            mismatch = 1;
        }
    }

    if (ref_mask == NULL) {
        if (value1 != ref->value1) {
            mismatch = 1;
        }
    } else {
        if ((value1 & ref_mask->value1) != (ref->value1 & ref_mask->value1)) {
            mismatch = 1;
        }
    }

    if (ref_mask == NULL) {
        if (value2 != ref->value2) {
            mismatch = 1;
        }
    } else {
        if ((value2 & ref_mask->value2) != (ref->value2 & ref_mask->value2)) {
            mismatch = 1;
        }
    }

    if (ref_mask == NULL) {
        if (value3 != ref->value3) {
            mismatch = 1;
        }
    } else {
        if ((value3 & ref_mask->value3) != (ref->value3 & ref_mask->value3)) {
            mismatch = 1;
        }
    }

    return mismatch;
}

void ps_exp::deep_copy(ps_exp *ref) {
    uint i;

    value0 = ref->value0;
    value1 = ref->value1;
    value2 = ref->value2;
    value3 = ref->value3;
}

void ps_worker_bits::set_value0(_16bits value, int maxbit, int minbit) {
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 15;
    }

    value0(maxbit, minbit) = value;
}

void ps_worker_bits::set_value1(_16bits value, int maxbit, int minbit) {
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 15;
    }

    value1(maxbit, minbit) = value;
}

void ps_worker_bits::set_value2(_16bits value, int maxbit, int minbit) {
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 15;
    }

    value2(maxbit, minbit) = value;
}

void ps_worker_bits::set_value3(_16bits value, int maxbit, int minbit) {
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 15;
    }

    value3(maxbit, minbit) = value;
}

ps_worker_bits::ps_worker_bits() {
    uint i;

    value0 = (_16bits)(0);
    value1 = (_16bits)(0);
    value2 = (_16bits)(0);
    value3 = (_16bits)(0);
}

void ps_worker_bits::print() {
#ifndef NO_CONSOLE_OUTPUT
    uint i;

    bmi_log->normal("ps_worker_bits->value0 = 0x" + value0.to_string(SC_HEX_US, false));
    bmi_log->normal("ps_worker_bits->value1 = 0x" + value1.to_string(SC_HEX_US, false));
    bmi_log->normal("ps_worker_bits->value2 = 0x" + value2.to_string(SC_HEX_US, false));
    bmi_log->normal("ps_worker_bits->value3 = 0x" + value3.to_string(SC_HEX_US, false));
#endif
}

int ps_worker_bits::compare(ps_worker_bits *ref, ps_worker_bits *ref_mask) {
    uint mismatch = 0;
    uint i;

    if (ref_mask == NULL) {
        if (value0 != ref->value0) {
            mismatch = 1;
        }
    } else {
        if ((value0 & ref_mask->value0) != (ref->value0 & ref_mask->value0)) {
            mismatch = 1;
        }
    }

    if (ref_mask == NULL) {
        if (value1 != ref->value1) {
            mismatch = 1;
        }
    } else {
        if ((value1 & ref_mask->value1) != (ref->value1 & ref_mask->value1)) {
            mismatch = 1;
        }
    }

    if (ref_mask == NULL) {
        if (value2 != ref->value2) {
            mismatch = 1;
        }
    } else {
        if ((value2 & ref_mask->value2) != (ref->value2 & ref_mask->value2)) {
            mismatch = 1;
        }
    }

    if (ref_mask == NULL) {
        if (value3 != ref->value3) {
            mismatch = 1;
        }
    } else {
        if ((value3 & ref_mask->value3) != (ref->value3 & ref_mask->value3)) {
            mismatch = 1;
        }
    }

    return mismatch;
}

void ps_worker_bits::deep_copy(ps_worker_bits *ref) {
    uint i;

    value0 = ref->value0;
    value1 = ref->value1;
    value2 = ref->value2;
    value3 = ref->value3;
}

void ps_bias::set_value0(_16bits value, int maxbit, int minbit) {
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 15;
    }

    value0(maxbit, minbit) = value;
}

void ps_bias::set_value1(_16bits value, int maxbit, int minbit) {
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 15;
    }

    value1(maxbit, minbit) = value;
}

void ps_bias::set_value2(_16bits value, int maxbit, int minbit) {
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 15;
    }

    value2(maxbit, minbit) = value;
}

void ps_bias::set_value3(_16bits value, int maxbit, int minbit) {
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 15;
    }

    value3(maxbit, minbit) = value;
}

ps_bias::ps_bias() {
    uint i;

    value0 = (_16bits)(0);
    value1 = (_16bits)(0);
    value2 = (_16bits)(0);
    value3 = (_16bits)(0);
}

void ps_bias::print() {
#ifndef NO_CONSOLE_OUTPUT
    uint i;

    bmi_log->normal("ps_bias->value0 = 0x" + value0.to_string(SC_HEX_US, false));
    bmi_log->normal("ps_bias->value1 = 0x" + value1.to_string(SC_HEX_US, false));
    bmi_log->normal("ps_bias->value2 = 0x" + value2.to_string(SC_HEX_US, false));
    bmi_log->normal("ps_bias->value3 = 0x" + value3.to_string(SC_HEX_US, false));
#endif
}

int ps_bias::compare(ps_bias *ref, ps_bias *ref_mask) {
    uint mismatch = 0;
    uint i;

    if (ref_mask == NULL) {
        if (value0 != ref->value0) {
            mismatch = 1;
        }
    } else {
        if ((value0 & ref_mask->value0) != (ref->value0 & ref_mask->value0)) {
            mismatch = 1;
        }
    }

    if (ref_mask == NULL) {
        if (value1 != ref->value1) {
            mismatch = 1;
        }
    } else {
        if ((value1 & ref_mask->value1) != (ref->value1 & ref_mask->value1)) {
            mismatch = 1;
        }
    }

    if (ref_mask == NULL) {
        if (value2 != ref->value2) {
            mismatch = 1;
        }
    } else {
        if ((value2 & ref_mask->value2) != (ref->value2 & ref_mask->value2)) {
            mismatch = 1;
        }
    }

    if (ref_mask == NULL) {
        if (value3 != ref->value3) {
            mismatch = 1;
        }
    } else {
        if ((value3 & ref_mask->value3) != (ref->value3 & ref_mask->value3)) {
            mismatch = 1;
        }
    }

    return mismatch;
}

void ps_bias::deep_copy(ps_bias *ref) {
    uint i;

    value0 = ref->value0;
    value1 = ref->value1;
    value2 = ref->value2;
    value3 = ref->value3;
}

void ps_worker_init_bits::set_value0(_16bits value, int maxbit, int minbit) {
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 15;
    }

    value0(maxbit, minbit) = value;
}

void ps_worker_init_bits::set_value1(_16bits value, int maxbit, int minbit) {
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 15;
    }

    value1(maxbit, minbit) = value;
}

void ps_worker_init_bits::set_value2(_16bits value, int maxbit, int minbit) {
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 15;
    }

    value2(maxbit, minbit) = value;
}

void ps_worker_init_bits::set_value3(_16bits value, int maxbit, int minbit) {
    uint i;

    if ((maxbit == -1) || (minbit == -1)) {
        minbit = 0;
        maxbit = 15;
    }

    value3(maxbit, minbit) = value;
}

ps_worker_init_bits::ps_worker_init_bits() {
    uint i;

    value0 = (_16bits)(0);
    value1 = (_16bits)(0);
    value2 = (_16bits)(0);
    value3 = (_16bits)(0);
}

void ps_worker_init_bits::print() {
#ifndef NO_CONSOLE_OUTPUT
    uint i;

    bmi_log->normal("ps_worker_init_bits->value0 = 0x" + value0.to_string(SC_HEX_US, false));
    bmi_log->normal("ps_worker_init_bits->value1 = 0x" + value1.to_string(SC_HEX_US, false));
    bmi_log->normal("ps_worker_init_bits->value2 = 0x" + value2.to_string(SC_HEX_US, false));
    bmi_log->normal("ps_worker_init_bits->value3 = 0x" + value3.to_string(SC_HEX_US, false));
#endif
}

int ps_worker_init_bits::compare(ps_worker_init_bits *ref, ps_worker_init_bits *ref_mask) {
    uint mismatch = 0;
    uint i;

    if (ref_mask == NULL) {
        if (value0 != ref->value0) {
            mismatch = 1;
        }
    } else {
        if ((value0 & ref_mask->value0) != (ref->value0 & ref_mask->value0)) {
            mismatch = 1;
        }
    }

    if (ref_mask == NULL) {
        if (value1 != ref->value1) {
            mismatch = 1;
        }
    } else {
        if ((value1 & ref_mask->value1) != (ref->value1 & ref_mask->value1)) {
            mismatch = 1;
        }
    }

    if (ref_mask == NULL) {
        if (value2 != ref->value2) {
            mismatch = 1;
        }
    } else {
        if ((value2 & ref_mask->value2) != (ref->value2 & ref_mask->value2)) {
            mismatch = 1;
        }
    }

    if (ref_mask == NULL) {
        if (value3 != ref->value3) {
            mismatch = 1;
        }
    } else {
        if ((value3 & ref_mask->value3) != (ref->value3 & ref_mask->value3)) {
            mismatch = 1;
        }
    }

    return mismatch;
}

void ps_worker_init_bits::deep_copy(ps_worker_init_bits *ref) {
    uint i;

    value0 = ref->value0;
    value1 = ref->value1;
    value2 = ref->value2;
    value3 = ref->value3;
}

