/*
 * SCRIPT GENERATED FILE, DO NOT MODIFY
*/


#include "header_classes.h"
#include "bmodel.h"

udp_t::udp_t() {
    sport = (_16bits)(0x0U);
    dport = (_16bits)(0x0U);
    length = (_16bits)(0x0U);
    checksum = (_16bits)(0x0U);
    job_id = (_16bits)(0x0U);
    max_worker = (_16bits)(0x0U);
    worker_id = (_16bits)(0x0U);
    sequence = (_16bits)(0x0U);
    exp = (_16bits)(0x0U);
    bias = (_16bits)(0x0U);
    bias_exp = (_16bits)(0x0U);
    _PRESENT = (_1bit)(0x0U);
    _PRESENT_CUR = (_1bit)(0x0U);
    num_bytes = 22;
    last_header_op = 0x0U;
    hdr_bytes = new _8bits[num_bytes];
}

udp_t::~udp_t() {
    delete[] hdr_bytes;
}

void udp_t::set_resetval() {
    uint i;

    reset_header_base_class();
    sport = (_16bits)(0x0U);
    dport = (_16bits)(0x0U);
    length = (_16bits)(0x0U);
    checksum = (_16bits)(0x0U);
    job_id = (_16bits)(0x0U);
    max_worker = (_16bits)(0x0U);
    worker_id = (_16bits)(0x0U);
    sequence = (_16bits)(0x0U);
    exp = (_16bits)(0x0U);
    bias = (_16bits)(0x0U);
    bias_exp = (_16bits)(0x0U);
    _PRESENT = (_1bit)(0x0U);
    _PRESENT_CUR = (_1bit)(0x0U);
    num_bytes = 22;
    last_header_op = 0x0U;
    for (i = 0; i < num_bytes; i++) {
        hdr_bytes[i] = 0x0U;
    }

}

int udp_t::extract_fields(_8bits *pkt, _32bits *hdr_ptr, _32bits *pkt_len) {
    uint byte_ptr;
    uint i;

    start_byte = *hdr_ptr;
    if (*pkt_len < (start_byte+22)) {
        // Remaining packet bytes are less than fixed header size
        *hdr_ptr = *pkt_len;
        return -1;
    }
    byte_ptr = 0;
    for (i = 0; i < 2; i++) {
        if (i != 1) {
            sport |= (((_16bits)(pkt[*hdr_ptr + byte_ptr + i]) << (8 * (2 - i - 1))));
        } else {
            sport |= (((_16bits)(pkt[*hdr_ptr + byte_ptr + i]) >> 0));
        }
    }

    byte_ptr = 2;
    for (i = 0; i < 2; i++) {
        if (i != 1) {
            dport |= (((_16bits)(pkt[*hdr_ptr + byte_ptr + i]) << (8 * (2 - i - 1))));
        } else {
            dport |= (((_16bits)(pkt[*hdr_ptr + byte_ptr + i]) >> 0));
        }
    }

    byte_ptr = 4;
    for (i = 0; i < 2; i++) {
        if (i != 1) {
            length |= (((_16bits)(pkt[*hdr_ptr + byte_ptr + i]) << (8 * (2 - i - 1))));
        } else {
            length |= (((_16bits)(pkt[*hdr_ptr + byte_ptr + i]) >> 0));
        }
    }

    byte_ptr = 6;
    for (i = 0; i < 2; i++) {
        if (i != 1) {
            checksum |= (((_16bits)(pkt[*hdr_ptr + byte_ptr + i]) << (8 * (2 - i - 1))));
        } else {
            checksum |= (((_16bits)(pkt[*hdr_ptr + byte_ptr + i]) >> 0));
        }
    }

    byte_ptr = 8;
    for (i = 0; i < 2; i++) {
        if (i != 1) {
            job_id |= (((_16bits)(pkt[*hdr_ptr + byte_ptr + i]) << (8 * (2 - i - 1))));
        } else {
            job_id |= (((_16bits)(pkt[*hdr_ptr + byte_ptr + i]) >> 0));
        }
    }

    byte_ptr = 10;
    for (i = 0; i < 2; i++) {
        if (i != 1) {
            max_worker |= (((_16bits)(pkt[*hdr_ptr + byte_ptr + i]) << (8 * (2 - i - 1))));
        } else {
            max_worker |= (((_16bits)(pkt[*hdr_ptr + byte_ptr + i]) >> 0));
        }
    }

    byte_ptr = 12;
    for (i = 0; i < 2; i++) {
        if (i != 1) {
            worker_id |= (((_16bits)(pkt[*hdr_ptr + byte_ptr + i]) << (8 * (2 - i - 1))));
        } else {
            worker_id |= (((_16bits)(pkt[*hdr_ptr + byte_ptr + i]) >> 0));
        }
    }

    byte_ptr = 14;
    for (i = 0; i < 2; i++) {
        if (i != 1) {
            sequence |= (((_16bits)(pkt[*hdr_ptr + byte_ptr + i]) << (8 * (2 - i - 1))));
        } else {
            sequence |= (((_16bits)(pkt[*hdr_ptr + byte_ptr + i]) >> 0));
        }
    }

    byte_ptr = 16;
    for (i = 0; i < 2; i++) {
        if (i != 1) {
            exp |= (((_16bits)(pkt[*hdr_ptr + byte_ptr + i]) << (8 * (2 - i - 1))));
        } else {
            exp |= (((_16bits)(pkt[*hdr_ptr + byte_ptr + i]) >> 0));
        }
    }

    byte_ptr = 18;
    for (i = 0; i < 2; i++) {
        if (i != 1) {
            bias |= (((_16bits)(pkt[*hdr_ptr + byte_ptr + i]) << (8 * (2 - i - 1))));
        } else {
            bias |= (((_16bits)(pkt[*hdr_ptr + byte_ptr + i]) >> 0));
        }
    }

    byte_ptr = 20;
    for (i = 0; i < 2; i++) {
        if (i != 1) {
            bias_exp |= (((_16bits)(pkt[*hdr_ptr + byte_ptr + i]) << (8 * (2 - i - 1))));
        } else {
            bias_exp |= (((_16bits)(pkt[*hdr_ptr + byte_ptr + i]) >> 0));
        }
    }

    *hdr_ptr +=  (byte_ptr + i);
    stop_byte = *hdr_ptr - 1;

    pack();

    return 0;
}

void udp_t::pack() {
    uint byte_ptr;
    uint i;

    for (i = 0; i < num_bytes; i++) {
        hdr_bytes[i] = 0x0U;
    }

    byte_ptr = 0;
    for (i = 0; i < 2; i++) {
        if (i != 1) {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((sport) >> (8 * (2 - i - 1))));
        } else {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((sport) << 0));
        }
    }
    byte_ptr = 2;
    for (i = 0; i < 2; i++) {
        if (i != 1) {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((dport) >> (8 * (2 - i - 1))));
        } else {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((dport) << 0));
        }
    }
    byte_ptr = 4;
    for (i = 0; i < 2; i++) {
        if (i != 1) {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((length) >> (8 * (2 - i - 1))));
        } else {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((length) << 0));
        }
    }
    byte_ptr = 6;
    for (i = 0; i < 2; i++) {
        if (i != 1) {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((checksum) >> (8 * (2 - i - 1))));
        } else {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((checksum) << 0));
        }
    }
    byte_ptr = 8;
    for (i = 0; i < 2; i++) {
        if (i != 1) {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((job_id) >> (8 * (2 - i - 1))));
        } else {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((job_id) << 0));
        }
    }
    byte_ptr = 10;
    for (i = 0; i < 2; i++) {
        if (i != 1) {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((max_worker) >> (8 * (2 - i - 1))));
        } else {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((max_worker) << 0));
        }
    }
    byte_ptr = 12;
    for (i = 0; i < 2; i++) {
        if (i != 1) {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((worker_id) >> (8 * (2 - i - 1))));
        } else {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((worker_id) << 0));
        }
    }
    byte_ptr = 14;
    for (i = 0; i < 2; i++) {
        if (i != 1) {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((sequence) >> (8 * (2 - i - 1))));
        } else {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((sequence) << 0));
        }
    }
    byte_ptr = 16;
    for (i = 0; i < 2; i++) {
        if (i != 1) {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((exp) >> (8 * (2 - i - 1))));
        } else {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((exp) << 0));
        }
    }
    byte_ptr = 18;
    for (i = 0; i < 2; i++) {
        if (i != 1) {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((bias) >> (8 * (2 - i - 1))));
        } else {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((bias) << 0));
        }
    }
    byte_ptr = 20;
    for (i = 0; i < 2; i++) {
        if (i != 1) {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((bias_exp) >> (8 * (2 - i - 1))));
        } else {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((bias_exp) << 0));
        }
    }
    update_header_location();

}

void udp_t::print() {
#ifndef NO_CONSOLE_OUTPUT
    bmi_log->normal("udp_t->sport = 0x" + sport.to_string(SC_HEX_US, false));
    bmi_log->normal("udp_t->dport = 0x" + dport.to_string(SC_HEX_US, false));
    bmi_log->normal("udp_t->length = 0x" + length.to_string(SC_HEX_US, false));
    bmi_log->normal("udp_t->checksum = 0x" + checksum.to_string(SC_HEX_US, false));
    bmi_log->normal("udp_t->job_id = 0x" + job_id.to_string(SC_HEX_US, false));
    bmi_log->normal("udp_t->max_worker = 0x" + max_worker.to_string(SC_HEX_US, false));
    bmi_log->normal("udp_t->worker_id = 0x" + worker_id.to_string(SC_HEX_US, false));
    bmi_log->normal("udp_t->sequence = 0x" + sequence.to_string(SC_HEX_US, false));
    bmi_log->normal("udp_t->exp = 0x" + exp.to_string(SC_HEX_US, false));
    bmi_log->normal("udp_t->bias = 0x" + bias.to_string(SC_HEX_US, false));
    bmi_log->normal("udp_t->bias_exp = 0x" + bias_exp.to_string(SC_HEX_US, false));
    bmi_log->normal("udp_t->_PRESENT = 0x" + _PRESENT.to_string(SC_HEX_US, false));
    bmi_log->normal("udp_t->_PRESENT_CUR = 0x" + _PRESENT_CUR.to_string(SC_HEX_US, false));
#endif
}

void udp_t::deep_copy(udp_t *ref) {
    uint i;

    for (i = 0; i < num_bytes; i++) {
        hdr_bytes[i] = ref->hdr_bytes[i];
    }

    start_byte = ref->start_byte;
    stop_byte = ref->stop_byte;
    num_bytes = ref->num_bytes;
    last_header_op = ref->last_header_op;
    sport = ref->sport;
    dport = ref->dport;
    length = ref->length;
    checksum = ref->checksum;
    job_id = ref->job_id;
    max_worker = ref->max_worker;
    worker_id = ref->worker_id;
    sequence = ref->sequence;
    exp = ref->exp;
    bias = ref->bias;
    bias_exp = ref->bias_exp;
    _PRESENT = ref->_PRESENT;
    _PRESENT_CUR = ref->_PRESENT_CUR;
}

l2_t::l2_t() {
    macda = (_48bits)(0x0U);
    macsa = (_48bits)(0x0U);
    ethertype = (_16bits)(0x0U);
    _PRESENT = (_1bit)(0x0U);
    _PRESENT_CUR = (_1bit)(0x0U);
    num_bytes = 14;
    last_header_op = 0x0U;
    hdr_bytes = new _8bits[num_bytes];
}

l2_t::~l2_t() {
    delete[] hdr_bytes;
}

void l2_t::set_resetval() {
    uint i;

    reset_header_base_class();
    macda = (_48bits)(0x0U);
    macsa = (_48bits)(0x0U);
    ethertype = (_16bits)(0x0U);
    _PRESENT = (_1bit)(0x0U);
    _PRESENT_CUR = (_1bit)(0x0U);
    num_bytes = 14;
    last_header_op = 0x0U;
    for (i = 0; i < num_bytes; i++) {
        hdr_bytes[i] = 0x0U;
    }

}

int l2_t::extract_fields(_8bits *pkt, _32bits *hdr_ptr, _32bits *pkt_len) {
    uint byte_ptr;
    uint i;

    start_byte = *hdr_ptr;
    if (*pkt_len < (start_byte+14)) {
        // Remaining packet bytes are less than fixed header size
        *hdr_ptr = *pkt_len;
        return -1;
    }
    byte_ptr = 0;
    for (i = 0; i < 6; i++) {
        if (i != 5) {
            macda |= (((_48bits)(pkt[*hdr_ptr + byte_ptr + i]) << (8 * (6 - i - 1))));
        } else {
            macda |= (((_48bits)(pkt[*hdr_ptr + byte_ptr + i]) >> 0));
        }
    }

    byte_ptr = 6;
    for (i = 0; i < 6; i++) {
        if (i != 5) {
            macsa |= (((_48bits)(pkt[*hdr_ptr + byte_ptr + i]) << (8 * (6 - i - 1))));
        } else {
            macsa |= (((_48bits)(pkt[*hdr_ptr + byte_ptr + i]) >> 0));
        }
    }

    byte_ptr = 12;
    for (i = 0; i < 2; i++) {
        if (i != 1) {
            ethertype |= (((_16bits)(pkt[*hdr_ptr + byte_ptr + i]) << (8 * (2 - i - 1))));
        } else {
            ethertype |= (((_16bits)(pkt[*hdr_ptr + byte_ptr + i]) >> 0));
        }
    }

    *hdr_ptr +=  (byte_ptr + i);
    stop_byte = *hdr_ptr - 1;

    pack();

    return 0;
}

void l2_t::pack() {
    uint byte_ptr;
    uint i;

    for (i = 0; i < num_bytes; i++) {
        hdr_bytes[i] = 0x0U;
    }

    byte_ptr = 0;
    for (i = 0; i < 6; i++) {
        if (i != 5) {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((macda) >> (8 * (6 - i - 1))));
        } else {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((macda) << 0));
        }
    }
    byte_ptr = 6;
    for (i = 0; i < 6; i++) {
        if (i != 5) {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((macsa) >> (8 * (6 - i - 1))));
        } else {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((macsa) << 0));
        }
    }
    byte_ptr = 12;
    for (i = 0; i < 2; i++) {
        if (i != 1) {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((ethertype) >> (8 * (2 - i - 1))));
        } else {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((ethertype) << 0));
        }
    }
    update_header_location();

}

void l2_t::print() {
#ifndef NO_CONSOLE_OUTPUT
    bmi_log->normal("l2_t->macda = 0x" + macda.to_string(SC_HEX_US, false));
    bmi_log->normal("l2_t->macsa = 0x" + macsa.to_string(SC_HEX_US, false));
    bmi_log->normal("l2_t->ethertype = 0x" + ethertype.to_string(SC_HEX_US, false));
    bmi_log->normal("l2_t->_PRESENT = 0x" + _PRESENT.to_string(SC_HEX_US, false));
    bmi_log->normal("l2_t->_PRESENT_CUR = 0x" + _PRESENT_CUR.to_string(SC_HEX_US, false));
#endif
}

void l2_t::deep_copy(l2_t *ref) {
    uint i;

    for (i = 0; i < num_bytes; i++) {
        hdr_bytes[i] = ref->hdr_bytes[i];
    }

    start_byte = ref->start_byte;
    stop_byte = ref->stop_byte;
    num_bytes = ref->num_bytes;
    last_header_op = ref->last_header_op;
    macda = ref->macda;
    macsa = ref->macsa;
    ethertype = ref->ethertype;
    _PRESENT = ref->_PRESENT;
    _PRESENT_CUR = ref->_PRESENT_CUR;
}

ipv4_t::ipv4_t() {
    version = (_4bits)(0x0U);
    tos = (_8bits)(0x0U);
    v4_length = (_16bits)(0x0U);
    id = (_16bits)(0x0U);
    flags = (_3bits)(0x0U);
    frag_offset = (_13bits)(0x0U);
    ttl = (_8bits)(0x0U);
    protocol = (_8bits)(0x0U);
    hdr_checksum = (_16bits)(0x0U);
    sip = (_32bits)(0x0U);
    dip = (_32bits)(0x0U);
    option = (_512bits)(0x0U);
    _PRESENT = (_1bit)(0x0U);
    _PRESENT_CUR = (_1bit)(0x0U);
    _VARBIT_LENGTH = (_32bits)(0x0U);
    hdr_len = (_4bits)(5);

    num_bytes = 84;
    last_header_op = 0x0U;
    hdr_bytes = new _8bits[num_bytes];
}

ipv4_t::~ipv4_t() {
    delete[] hdr_bytes;
}

void ipv4_t::set_resetval() {
    uint i;

    reset_header_base_class();
    version = (_4bits)(0x0U);
    tos = (_8bits)(0x0U);
    v4_length = (_16bits)(0x0U);
    id = (_16bits)(0x0U);
    flags = (_3bits)(0x0U);
    frag_offset = (_13bits)(0x0U);
    ttl = (_8bits)(0x0U);
    protocol = (_8bits)(0x0U);
    hdr_checksum = (_16bits)(0x0U);
    sip = (_32bits)(0x0U);
    dip = (_32bits)(0x0U);
    option = (_512bits)(0x0U);
    _PRESENT = (_1bit)(0x0U);
    _PRESENT_CUR = (_1bit)(0x0U);
    _VARBIT_LENGTH = (_32bits)(0x0U);
    hdr_len = (_4bits)(5);

    num_bytes = 84;
    last_header_op = 0x0U;
    for (i = 0; i < num_bytes; i++) {
        hdr_bytes[i] = 0x0U;
    }

}

int ipv4_t::extract_fields(_8bits *pkt, _32bits *hdr_ptr, _32bits *pkt_len) {
    uint byte_ptr;
    uint _loc_hdr_len;
    uint i;

    start_byte = *hdr_ptr;
    if (*pkt_len < (start_byte+20)) {
        // Remaining packet bytes are less than fixed header size
        *hdr_ptr = *pkt_len;
        return -1;
    }
    byte_ptr = 0;
    version = (_4bits)((pkt[*hdr_ptr + byte_ptr] >> 4) & 0xf);

    byte_ptr = 0;
    hdr_len = (_4bits)((pkt[*hdr_ptr + byte_ptr] >> 0) & 0xf);

    byte_ptr = 1;
    tos = (_8bits)((pkt[*hdr_ptr + byte_ptr] >> 0) & 0xff);

    byte_ptr = 2;
    for (i = 0; i < 2; i++) {
        if (i != 1) {
            v4_length |= (((_16bits)(pkt[*hdr_ptr + byte_ptr + i]) << (8 * (2 - i - 1))));
        } else {
            v4_length |= (((_16bits)(pkt[*hdr_ptr + byte_ptr + i]) >> 0));
        }
    }

    byte_ptr = 4;
    for (i = 0; i < 2; i++) {
        if (i != 1) {
            id |= (((_16bits)(pkt[*hdr_ptr + byte_ptr + i]) << (8 * (2 - i - 1))));
        } else {
            id |= (((_16bits)(pkt[*hdr_ptr + byte_ptr + i]) >> 0));
        }
    }

    byte_ptr = 6;
    flags = (_3bits)((pkt[*hdr_ptr + byte_ptr] >> 5) & 0x7);

    byte_ptr = 6;
    for (i = 0; i < 2; i++) {
        if (i != 1) {
            frag_offset |= (((_13bits)(pkt[*hdr_ptr + byte_ptr + i]) << (8 * (2 - i - 1))));
        } else {
            frag_offset |= (((_13bits)(pkt[*hdr_ptr + byte_ptr + i]) >> 0));
        }
    }

    byte_ptr = 8;
    ttl = (_8bits)((pkt[*hdr_ptr + byte_ptr] >> 0) & 0xff);

    byte_ptr = 9;
    protocol = (_8bits)((pkt[*hdr_ptr + byte_ptr] >> 0) & 0xff);

    byte_ptr = 10;
    for (i = 0; i < 2; i++) {
        if (i != 1) {
            hdr_checksum |= (((_16bits)(pkt[*hdr_ptr + byte_ptr + i]) << (8 * (2 - i - 1))));
        } else {
            hdr_checksum |= (((_16bits)(pkt[*hdr_ptr + byte_ptr + i]) >> 0));
        }
    }

    byte_ptr = 12;
    for (i = 0; i < 4; i++) {
        if (i != 3) {
            sip |= (((_32bits)(pkt[*hdr_ptr + byte_ptr + i]) << (8 * (4 - i - 1))));
        } else {
            sip |= (((_32bits)(pkt[*hdr_ptr + byte_ptr + i]) >> 0));
        }
    }

    byte_ptr = 16;
    for (i = 0; i < 4; i++) {
        if (i != 3) {
            dip |= (((_32bits)(pkt[*hdr_ptr + byte_ptr + i]) << (8 * (4 - i - 1))));
        } else {
            dip |= (((_32bits)(pkt[*hdr_ptr + byte_ptr + i]) >> 0));
        }
    }

    _loc_hdr_len = (hdr_len * 4 + 0);
    if (_loc_hdr_len < 20) {
        // Variable header length is less than fixed header
        _loc_hdr_len = 20;
    }
    if (_loc_hdr_len > (512/8 + 20)) {
        // variable header length is greater than max header size
        _loc_hdr_len = (512/8 + 20);
    }
    if (*pkt_len < (start_byte + _loc_hdr_len)) {
        // Remaining packet bytes are less than variable header size
        _loc_hdr_len = *pkt_len - start_byte;
    }
    byte_ptr = 20;
    _VARBIT_LENGTH = (_loc_hdr_len - 20)*8;
    for (i = 0; i < (_loc_hdr_len - 20); i++) {
        if (i != ((_loc_hdr_len - 20) - 1)) {
            option |= (((_512bits)(pkt[*hdr_ptr + byte_ptr + i]) << (8 * ((_loc_hdr_len - 20) - i - 1))));
        } else {
            option |= (((_512bits)(pkt[*hdr_ptr + byte_ptr + i]) >> 0));
        }
    }

    num_bytes = (byte_ptr + i);
    *hdr_ptr +=  (byte_ptr + i);
    stop_byte = *hdr_ptr - 1;

    pack();

    return 0;
}

void ipv4_t::pack() {
    uint byte_ptr;
    uint _loc_hdr_len;
    uint i;

    for (i = 0; i < num_bytes; i++) {
        hdr_bytes[i] = 0x0U;
    }

    byte_ptr = 0;
    hdr_bytes[byte_ptr] |= (_8bits)((((_8bits)(version)) << 4) & (_8bits)(0xf0U));
    byte_ptr = 0;
    hdr_bytes[byte_ptr] |= (_8bits)((((_8bits)(hdr_len)) << 0) & (_8bits)(0xfU));
    byte_ptr = 1;
    hdr_bytes[byte_ptr] |= (_8bits)((((_8bits)(tos)) << 0) & (_8bits)(0xffU));
    byte_ptr = 2;
    for (i = 0; i < 2; i++) {
        if (i != 1) {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((v4_length) >> (8 * (2 - i - 1))));
        } else {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((v4_length) << 0));
        }
    }
    byte_ptr = 4;
    for (i = 0; i < 2; i++) {
        if (i != 1) {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((id) >> (8 * (2 - i - 1))));
        } else {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((id) << 0));
        }
    }
    byte_ptr = 6;
    hdr_bytes[byte_ptr] |= (_8bits)((((_8bits)(flags)) << 5) & (_8bits)(0xe0U));
    byte_ptr = 6;
    for (i = 0; i < 2; i++) {
        if (i != 1) {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((frag_offset) >> (8 * (2 - i - 1))));
        } else {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((frag_offset) << 0));
        }
    }
    byte_ptr = 8;
    hdr_bytes[byte_ptr] |= (_8bits)((((_8bits)(ttl)) << 0) & (_8bits)(0xffU));
    byte_ptr = 9;
    hdr_bytes[byte_ptr] |= (_8bits)((((_8bits)(protocol)) << 0) & (_8bits)(0xffU));
    byte_ptr = 10;
    for (i = 0; i < 2; i++) {
        if (i != 1) {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((hdr_checksum) >> (8 * (2 - i - 1))));
        } else {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((hdr_checksum) << 0));
        }
    }
    byte_ptr = 12;
    for (i = 0; i < 4; i++) {
        if (i != 3) {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((sip) >> (8 * (4 - i - 1))));
        } else {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((sip) << 0));
        }
    }
    byte_ptr = 16;
    for (i = 0; i < 4; i++) {
        if (i != 3) {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((dip) >> (8 * (4 - i - 1))));
        } else {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((dip) << 0));
        }
    }
    _loc_hdr_len = (hdr_len * 4 + 0);
    if (_loc_hdr_len < 20) {
        // Variable header length is less than fixed header
        _loc_hdr_len = 20;
    }
    if (_loc_hdr_len > (512/8 + 20)) {
        // variable header length is greater than max header size
        _loc_hdr_len = (512/8 + 20);
    }
    byte_ptr = 20;
    for (i = 0; i < (_loc_hdr_len - 20); i++) {
        if (i != ((_loc_hdr_len - 20) - 1)) {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((option) >> (8 * ((_loc_hdr_len - 20) - i - 1))));
        } else {
            hdr_bytes[byte_ptr + i] |= (_8bits)(((option) << 0));
        }
    }
    num_bytes = (byte_ptr + i);
    update_header_location();

}

void ipv4_t::print() {
#ifndef NO_CONSOLE_OUTPUT
    bmi_log->normal("ipv4_t->version = 0x" + version.to_string(SC_HEX_US, false));
    bmi_log->normal("ipv4_t->hdr_len = 0x" + hdr_len.to_string(SC_HEX_US, false));
    bmi_log->normal("ipv4_t->tos = 0x" + tos.to_string(SC_HEX_US, false));
    bmi_log->normal("ipv4_t->v4_length = 0x" + v4_length.to_string(SC_HEX_US, false));
    bmi_log->normal("ipv4_t->id = 0x" + id.to_string(SC_HEX_US, false));
    bmi_log->normal("ipv4_t->flags = 0x" + flags.to_string(SC_HEX_US, false));
    bmi_log->normal("ipv4_t->frag_offset = 0x" + frag_offset.to_string(SC_HEX_US, false));
    bmi_log->normal("ipv4_t->ttl = 0x" + ttl.to_string(SC_HEX_US, false));
    bmi_log->normal("ipv4_t->protocol = 0x" + protocol.to_string(SC_HEX_US, false));
    bmi_log->normal("ipv4_t->hdr_checksum = 0x" + hdr_checksum.to_string(SC_HEX_US, false));
    bmi_log->normal("ipv4_t->sip = 0x" + sip.to_string(SC_HEX_US, false));
    bmi_log->normal("ipv4_t->dip = 0x" + dip.to_string(SC_HEX_US, false));
    bmi_log->normal("ipv4_t->option = 0x" + option.to_string(SC_HEX_US, false));
    bmi_log->normal("ipv4_t->_PRESENT = 0x" + _PRESENT.to_string(SC_HEX_US, false));
    bmi_log->normal("ipv4_t->_PRESENT_CUR = 0x" + _PRESENT_CUR.to_string(SC_HEX_US, false));
    bmi_log->normal("ipv4_t->_VARBIT_LENGTH = 0x" + _VARBIT_LENGTH.to_string(SC_HEX_US, false));
#endif
}

void ipv4_t::deep_copy(ipv4_t *ref) {
    uint i;

    for (i = 0; i < num_bytes; i++) {
        hdr_bytes[i] = ref->hdr_bytes[i];
    }

    start_byte = ref->start_byte;
    stop_byte = ref->stop_byte;
    num_bytes = ref->num_bytes;
    last_header_op = ref->last_header_op;
    version = ref->version;
    hdr_len = ref->hdr_len;
    tos = ref->tos;
    v4_length = ref->v4_length;
    id = ref->id;
    flags = ref->flags;
    frag_offset = ref->frag_offset;
    ttl = ref->ttl;
    protocol = ref->protocol;
    hdr_checksum = ref->hdr_checksum;
    sip = ref->sip;
    dip = ref->dip;
    option = ref->option;
    _PRESENT = ref->_PRESENT;
    _PRESENT_CUR = ref->_PRESENT_CUR;
}

void l3_hdr_grp_t::set_ipv4(ipv4_t *ref) {
    uint i;
    ipv4->deep_copy(ref);
}

l3_hdr_grp_t::l3_hdr_grp_t() {
    uint i;
    ipv4 = new ipv4_t;
}

void l3_hdr_grp_t::set_resetval() {
    uint i;
    ipv4->set_resetval();
}

l3_hdr_grp_t::~l3_hdr_grp_t() {
    uint i;
    delete ipv4;
}

void l3_hdr_grp_t::deep_copy(l3_hdr_grp_t *ref) {
    uint i;
    ipv4->deep_copy(ref->ipv4);
}

void l4_hdr_grp_t::set_udp(udp_t *ref) {
    uint i;
    udp->deep_copy(ref);
}

l4_hdr_grp_t::l4_hdr_grp_t() {
    uint i;
    udp = new udp_t;
}

void l4_hdr_grp_t::set_resetval() {
    uint i;
    udp->set_resetval();
}

l4_hdr_grp_t::~l4_hdr_grp_t() {
    uint i;
    delete udp;
}

void l4_hdr_grp_t::deep_copy(l4_hdr_grp_t *ref) {
    uint i;
    udp->deep_copy(ref->udp);
}

void l2_hdr_grp_t::set_l2(l2_t *ref) {
    uint i;
    l2->deep_copy(ref);
}

l2_hdr_grp_t::l2_hdr_grp_t() {
    uint i;
    l2 = new l2_t;
}

void l2_hdr_grp_t::set_resetval() {
    uint i;
    l2->set_resetval();
}

l2_hdr_grp_t::~l2_hdr_grp_t() {
    uint i;
    delete l2;
}

void l2_hdr_grp_t::deep_copy(l2_hdr_grp_t *ref) {
    uint i;
    l2->deep_copy(ref->l2);
}

void ingress_pkt_t::set_l3_hdr(l3_hdr_grp_t *ref) {
    uint i;
    l3_hdr->deep_copy(ref);
}

void ingress_pkt_t::set_l2_hdr(l2_hdr_grp_t *ref) {
    uint i;
    l2_hdr->deep_copy(ref);
}

void ingress_pkt_t::set_l4_hdr(l4_hdr_grp_t *ref) {
    uint i;
    l4_hdr->deep_copy(ref);
}

ingress_pkt_t::ingress_pkt_t() {
    uint i;
    _match_id = 0;
    l3_hdr = new l3_hdr_grp_t;
    l2_hdr = new l2_hdr_grp_t;
    l4_hdr = new l4_hdr_grp_t;

    num_hdr = 3;
    hdr_ptr_array = (header_base_t **)(malloc(3 * sizeof(header_base_t *)));

}

ingress_pkt_t::~ingress_pkt_t() {
    delete l3_hdr;
    delete l2_hdr;
    delete l4_hdr;
    free(hdr_ptr_array);
}

void ingress_pkt_t::set_resetval() {
    l3_hdr->set_resetval();
    l2_hdr->set_resetval();
    l4_hdr->set_resetval();
    num_hdr = 3;
    l2_hdr->l2->hdr_id = 0;
    hdr_ptr_array[0] = l2_hdr->l2;
    l3_hdr->ipv4->hdr_id = 1;
    hdr_ptr_array[1] = l3_hdr->ipv4;
    l4_hdr->udp->hdr_id = 2;
    hdr_ptr_array[2] = l4_hdr->udp;
}

void ingress_pkt_t::deep_copy(ingress_pkt_t *ref) {
    uint i;
    l3_hdr->deep_copy(ref->l3_hdr);
    l2_hdr->deep_copy(ref->l2_hdr);
    l4_hdr->deep_copy(ref->l4_hdr);
}

void egress_pkt_t::set_l3_hdr(l3_hdr_grp_t *ref) {
    uint i;
    l3_hdr->deep_copy(ref);
}

void egress_pkt_t::set_l2_hdr(l2_hdr_grp_t *ref) {
    uint i;
    l2_hdr->deep_copy(ref);
}

void egress_pkt_t::set_l4_hdr(l4_hdr_grp_t *ref) {
    uint i;
    l4_hdr->deep_copy(ref);
}

egress_pkt_t::egress_pkt_t() {
    uint i;
    _match_id = 0;
    l3_hdr = new l3_hdr_grp_t;
    l2_hdr = new l2_hdr_grp_t;
    l4_hdr = new l4_hdr_grp_t;

    num_hdr = 3;
    hdr_ptr_array = (header_base_t **)(malloc(3 * sizeof(header_base_t *)));

}

egress_pkt_t::~egress_pkt_t() {
    delete l3_hdr;
    delete l2_hdr;
    delete l4_hdr;
    free(hdr_ptr_array);
}

void egress_pkt_t::set_resetval() {
    l3_hdr->set_resetval();
    l2_hdr->set_resetval();
    l4_hdr->set_resetval();
    num_hdr = 3;
    l2_hdr->l2->hdr_id = 3;
    hdr_ptr_array[0] = l2_hdr->l2;
    l3_hdr->ipv4->hdr_id = 4;
    hdr_ptr_array[1] = l3_hdr->ipv4;
    l4_hdr->udp->hdr_id = 5;
    hdr_ptr_array[2] = l4_hdr->udp;
}

void egress_pkt_t::deep_copy(egress_pkt_t *ref) {
    uint i;
    l3_hdr->deep_copy(ref->l3_hdr);
    l2_hdr->deep_copy(ref->l2_hdr);
    l4_hdr->deep_copy(ref->l4_hdr);
}

