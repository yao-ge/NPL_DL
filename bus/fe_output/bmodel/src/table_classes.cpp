/*
 * SCRIPT GENERATED FILE, DO NOT MODIFY
*/


#include "table_classes.h"
#include "hash_crc.h"

#define BUCKET_SIZE    4

sfc_edb_profile_tab_t::sfc_edb_profile_tab_t() {
    uint i;

    max_entries = 2;
    for (i = 0; i < 2; i++) {
        sfc_edb_profile_entry_array[i] = new sfc_edb_profile_entry_t;
    }
}

sfc_edb_profile_tab_t::~sfc_edb_profile_tab_t() {
    uint i;

    max_entries = 2;
    for (i = 0; i < 2; i++) {
        delete sfc_edb_profile_entry_array[i];
    }
}

void sfc_edb_profile_tab_t::write_entry(_1bit *index, sfc_edb_profile_entry_t *sfc_edb_profile_entry) {
    uint i;

#ifndef NO_CONSOLE_OUTPUT
    bmi_log->debug("sfc_edb_profile::write_entry() index = %d", (int)*index);
#endif
    sfc_edb_profile_entry_array[*index]->_VALID = sfc_edb_profile_entry->_VALID;
    sfc_edb_profile_entry_array[*index]->_INDEX = sfc_edb_profile_entry->_INDEX;
    sfc_edb_profile_entry_array[*index]->edb_index = sfc_edb_profile_entry->edb_index;
    sfc_edb_profile_entry_array[*index]->in_drop_vector = sfc_edb_profile_entry->in_drop_vector;
    sfc_edb_profile_entry_array[*index]->in_dst_mod = sfc_edb_profile_entry->in_dst_mod;
    sfc_edb_profile_entry_array[*index]->in_dst_port = sfc_edb_profile_entry->in_dst_port;
    sfc_edb_profile_entry_array[*index]->_LOOKUP0 = sfc_edb_profile_entry->_LOOKUP0;
    sfc_edb_profile_entry_array[*index]->_HIT_INDEX0 = sfc_edb_profile_entry->_HIT_INDEX0;
}

void sfc_edb_profile_tab_t::find_index(sfc_edb_profile_entry_t *sfc_edb_profile_entry, int *idx, int *avbl_idx, int *pidx) {
    _1bit _full_key = 0;

    *idx = -1;
    *avbl_idx = -1;
    *pidx = -1;
    _full_key = (sfc_edb_profile_entry->edb_index);
    if (sfc_edb_profile_entry_array[_full_key]->_VALID == 1) {
        *idx = _full_key;
    } else {
        *avbl_idx = _full_key;
    }
#ifndef NO_CONSOLE_OUTPUT
    bmi_log->debug("sfc_edb_profile::find_index() idx = %d; avbl_idx = %d; pidx = %d", *idx, *avbl_idx, *pidx);
#endif
}

int sfc_edb_profile_tab_t::insert_entry(sfc_edb_profile_entry_t *sfc_edb_profile_entry) {
    int idx, avbl_idx, pidx;
    _1bit index;

#ifndef NO_CONSOLE_OUTPUT
    bmi_log->debug("sfc_edb_profile::insert_entry()");
#endif
    find_index(sfc_edb_profile_entry, &idx, &avbl_idx, &pidx);
    if(idx != -1) {
#ifndef NO_CONSOLE_OUTPUT
        bmi_log->normal("sfc_edb_profile::insert_entry() table entry in use");
#endif
        return -2;
    }

    if(avbl_idx == -1) {
#ifndef NO_CONSOLE_OUTPUT
        bmi_log->normal("sfc_edb_profile::insert_entry() table full");
#endif
        return -3;
    }

    index = (_1bit) avbl_idx;
    sfc_edb_profile_entry->_VALID = 1;
    write_entry(&index, sfc_edb_profile_entry);
    return 0;
}

int sfc_edb_profile_tab_t::delete_entry(sfc_edb_profile_entry_t *sfc_edb_profile_entry) {
    int idx, avbl_idx, pidx;
    _1bit index;

#ifndef NO_CONSOLE_OUTPUT
    bmi_log->debug("sfc_edb_profile::delete_entry()");
#endif
    find_index(sfc_edb_profile_entry, &idx, &avbl_idx, &pidx);
    if(idx == -1) {
#ifndef NO_CONSOLE_OUTPUT
        bmi_log->normal("sfc_edb_profile::delete_entry() could not find entry");
#endif
        return -1;
    }

    index = (_1bit) idx;
    sfc_edb_profile_entry->_VALID = 0;
    write_entry(&index, sfc_edb_profile_entry);
    return 0;
}

int sfc_edb_profile_tab_t::lookup_entry(sfc_edb_profile_entry_t **sfc_edb_profile_entry) {
    sfc_edb_profile_entry_t *rentry;
    int idx, avbl_idx, pidx;
    _1bit index;

#ifndef NO_CONSOLE_OUTPUT
    bmi_log->debug("sfc_edb_profile::lookup_entry()");
#endif
    find_index(*sfc_edb_profile_entry, &idx, &avbl_idx, &pidx);
    if(idx == -1) {
#ifndef NO_CONSOLE_OUTPUT
        bmi_log->normal("sfc_edb_profile::lookup_entry() could not find entry");
#endif
        return -1;
    }

    index = (_1bit) idx;
    rentry = read_entry(&index);
    memcpy(*sfc_edb_profile_entry, rentry, sizeof(sfc_edb_profile_entry_t));
    return 0;
}

sfc_edb_profile_entry_t* sfc_edb_profile_tab_t::read_entry(_1bit *index) {
#ifndef NO_CONSOLE_OUTPUT
    bmi_log->debug("sfc_edb_profile::read_entry() index = %d", (int)*index);
#endif
    return sfc_edb_profile_entry_array[*index];

}

sfc_edb_profile_entry_t* sfc_edb_profile_tab_t::lookup(int _lookup_idx_, _1bit *index) {
#ifndef NO_CONSOLE_OUTPUT
    bmi_log->normal("Looking up sfc_edb_profile");
#endif

    sfc_edb_profile_entry_array[*index]->_INDEX = *index;
    sfc_edb_profile_entry_array[*index]->_LOOKUP0 = 1;
    sfc_edb_profile_entry_array[*index]->_HIT_INDEX0(31,31) = 1;
    sfc_edb_profile_entry_array[*index]->_HIT_INDEX0(30,24) = SFC_EDB_PROFILE_ENUM;
    sfc_edb_profile_entry_array[*index]->_HIT_INDEX0(23,0) = *index;
#ifndef NO_CONSOLE_OUTPUT
    bmi_log->debug("sfc_edb_profile::lookup() index = %d", (int)*index);
#endif

    return sfc_edb_profile_entry_array[*index];
}

sfc_mmu_profile_tab_t::sfc_mmu_profile_tab_t() {
    uint i;

    max_entries = 2;
    for (i = 0; i < 2; i++) {
        sfc_mmu_profile_entry_array[i] = new sfc_mmu_profile_entry_t;
    }
}

sfc_mmu_profile_tab_t::~sfc_mmu_profile_tab_t() {
    uint i;

    max_entries = 2;
    for (i = 0; i < 2; i++) {
        delete sfc_mmu_profile_entry_array[i];
    }
}

void sfc_mmu_profile_tab_t::write_entry(_1bit *index, sfc_mmu_profile_entry_t *sfc_mmu_profile_entry) {
    uint i;

#ifndef NO_CONSOLE_OUTPUT
    bmi_log->debug("sfc_mmu_profile::write_entry() index = %d", (int)*index);
#endif
    sfc_mmu_profile_entry_array[*index]->_VALID = sfc_mmu_profile_entry->_VALID;
    sfc_mmu_profile_entry_array[*index]->_INDEX = sfc_mmu_profile_entry->_INDEX;
    sfc_mmu_profile_entry_array[*index]->mmu_index = sfc_mmu_profile_entry->mmu_index;
    sfc_mmu_profile_entry_array[*index]->in_l2_pbm = sfc_mmu_profile_entry->in_l2_pbm;
    sfc_mmu_profile_entry_array[*index]->in_l3_pbm = sfc_mmu_profile_entry->in_l3_pbm;
    sfc_mmu_profile_entry_array[*index]->out_dst_port = sfc_mmu_profile_entry->out_dst_port;
    sfc_mmu_profile_entry_array[*index]->_LOOKUP0 = sfc_mmu_profile_entry->_LOOKUP0;
    sfc_mmu_profile_entry_array[*index]->_HIT_INDEX0 = sfc_mmu_profile_entry->_HIT_INDEX0;
}

void sfc_mmu_profile_tab_t::find_index(sfc_mmu_profile_entry_t *sfc_mmu_profile_entry, int *idx, int *avbl_idx, int *pidx) {
    _1bit _full_key = 0;

    *idx = -1;
    *avbl_idx = -1;
    *pidx = -1;
    _full_key = (sfc_mmu_profile_entry->mmu_index);
    if (sfc_mmu_profile_entry_array[_full_key]->_VALID == 1) {
        *idx = _full_key;
    } else {
        *avbl_idx = _full_key;
    }
#ifndef NO_CONSOLE_OUTPUT
    bmi_log->debug("sfc_mmu_profile::find_index() idx = %d; avbl_idx = %d; pidx = %d", *idx, *avbl_idx, *pidx);
#endif
}

int sfc_mmu_profile_tab_t::insert_entry(sfc_mmu_profile_entry_t *sfc_mmu_profile_entry) {
    int idx, avbl_idx, pidx;
    _1bit index;

#ifndef NO_CONSOLE_OUTPUT
    bmi_log->debug("sfc_mmu_profile::insert_entry()");
#endif
    find_index(sfc_mmu_profile_entry, &idx, &avbl_idx, &pidx);
    if(idx != -1) {
#ifndef NO_CONSOLE_OUTPUT
        bmi_log->normal("sfc_mmu_profile::insert_entry() table entry in use");
#endif
        return -2;
    }

    if(avbl_idx == -1) {
#ifndef NO_CONSOLE_OUTPUT
        bmi_log->normal("sfc_mmu_profile::insert_entry() table full");
#endif
        return -3;
    }

    index = (_1bit) avbl_idx;
    sfc_mmu_profile_entry->_VALID = 1;
    write_entry(&index, sfc_mmu_profile_entry);
    return 0;
}

int sfc_mmu_profile_tab_t::delete_entry(sfc_mmu_profile_entry_t *sfc_mmu_profile_entry) {
    int idx, avbl_idx, pidx;
    _1bit index;

#ifndef NO_CONSOLE_OUTPUT
    bmi_log->debug("sfc_mmu_profile::delete_entry()");
#endif
    find_index(sfc_mmu_profile_entry, &idx, &avbl_idx, &pidx);
    if(idx == -1) {
#ifndef NO_CONSOLE_OUTPUT
        bmi_log->normal("sfc_mmu_profile::delete_entry() could not find entry");
#endif
        return -1;
    }

    index = (_1bit) idx;
    sfc_mmu_profile_entry->_VALID = 0;
    write_entry(&index, sfc_mmu_profile_entry);
    return 0;
}

int sfc_mmu_profile_tab_t::lookup_entry(sfc_mmu_profile_entry_t **sfc_mmu_profile_entry) {
    sfc_mmu_profile_entry_t *rentry;
    int idx, avbl_idx, pidx;
    _1bit index;

#ifndef NO_CONSOLE_OUTPUT
    bmi_log->debug("sfc_mmu_profile::lookup_entry()");
#endif
    find_index(*sfc_mmu_profile_entry, &idx, &avbl_idx, &pidx);
    if(idx == -1) {
#ifndef NO_CONSOLE_OUTPUT
        bmi_log->normal("sfc_mmu_profile::lookup_entry() could not find entry");
#endif
        return -1;
    }

    index = (_1bit) idx;
    rentry = read_entry(&index);
    memcpy(*sfc_mmu_profile_entry, rentry, sizeof(sfc_mmu_profile_entry_t));
    return 0;
}

sfc_mmu_profile_entry_t* sfc_mmu_profile_tab_t::read_entry(_1bit *index) {
#ifndef NO_CONSOLE_OUTPUT
    bmi_log->debug("sfc_mmu_profile::read_entry() index = %d", (int)*index);
#endif
    return sfc_mmu_profile_entry_array[*index];

}

sfc_mmu_profile_entry_t* sfc_mmu_profile_tab_t::lookup(int _lookup_idx_, _1bit *index) {
#ifndef NO_CONSOLE_OUTPUT
    bmi_log->normal("Looking up sfc_mmu_profile");
#endif

    sfc_mmu_profile_entry_array[*index]->_INDEX = *index;
    sfc_mmu_profile_entry_array[*index]->_LOOKUP0 = 1;
    sfc_mmu_profile_entry_array[*index]->_HIT_INDEX0(31,31) = 1;
    sfc_mmu_profile_entry_array[*index]->_HIT_INDEX0(30,24) = SFC_MMU_PROFILE_ENUM;
    sfc_mmu_profile_entry_array[*index]->_HIT_INDEX0(23,0) = *index;
#ifndef NO_CONSOLE_OUTPUT
    bmi_log->debug("sfc_mmu_profile::lookup() index = %d", (int)*index);
#endif

    return sfc_mmu_profile_entry_array[*index];
}

sfc_iarb_profile_tab_t::sfc_iarb_profile_tab_t() {
    uint i;

    max_entries = 2;
    for (i = 0; i < 2; i++) {
        sfc_iarb_profile_entry_array[i] = new sfc_iarb_profile_entry_t;
    }
}

sfc_iarb_profile_tab_t::~sfc_iarb_profile_tab_t() {
    uint i;

    max_entries = 2;
    for (i = 0; i < 2; i++) {
        delete sfc_iarb_profile_entry_array[i];
    }
}

void sfc_iarb_profile_tab_t::write_entry(_1bit *index, sfc_iarb_profile_entry_t *sfc_iarb_profile_entry) {
    uint i;

#ifndef NO_CONSOLE_OUTPUT
    bmi_log->debug("sfc_iarb_profile::write_entry() index = %d", (int)*index);
#endif
    sfc_iarb_profile_entry_array[*index]->_VALID = sfc_iarb_profile_entry->_VALID;
    sfc_iarb_profile_entry_array[*index]->_INDEX = sfc_iarb_profile_entry->_INDEX;
    sfc_iarb_profile_entry_array[*index]->iarb_index = sfc_iarb_profile_entry->iarb_index;
    sfc_iarb_profile_entry_array[*index]->out_otpid_enable = sfc_iarb_profile_entry->out_otpid_enable;
    sfc_iarb_profile_entry_array[*index]->out_ts_enable = sfc_iarb_profile_entry->out_ts_enable;
    sfc_iarb_profile_entry_array[*index]->out_port_num = sfc_iarb_profile_entry->out_port_num;
    sfc_iarb_profile_entry_array[*index]->out_port_type_cfg = sfc_iarb_profile_entry->out_port_type_cfg;
    sfc_iarb_profile_entry_array[*index]->out_currenttime = sfc_iarb_profile_entry->out_currenttime;
    sfc_iarb_profile_entry_array[*index]->_LOOKUP0 = sfc_iarb_profile_entry->_LOOKUP0;
    sfc_iarb_profile_entry_array[*index]->_HIT_INDEX0 = sfc_iarb_profile_entry->_HIT_INDEX0;
}

void sfc_iarb_profile_tab_t::find_index(sfc_iarb_profile_entry_t *sfc_iarb_profile_entry, int *idx, int *avbl_idx, int *pidx) {
    _1bit _full_key = 0;

    *idx = -1;
    *avbl_idx = -1;
    *pidx = -1;
    _full_key = (sfc_iarb_profile_entry->iarb_index);
    if (sfc_iarb_profile_entry_array[_full_key]->_VALID == 1) {
        *idx = _full_key;
    } else {
        *avbl_idx = _full_key;
    }
#ifndef NO_CONSOLE_OUTPUT
    bmi_log->debug("sfc_iarb_profile::find_index() idx = %d; avbl_idx = %d; pidx = %d", *idx, *avbl_idx, *pidx);
#endif
}

int sfc_iarb_profile_tab_t::insert_entry(sfc_iarb_profile_entry_t *sfc_iarb_profile_entry) {
    int idx, avbl_idx, pidx;
    _1bit index;

#ifndef NO_CONSOLE_OUTPUT
    bmi_log->debug("sfc_iarb_profile::insert_entry()");
#endif
    find_index(sfc_iarb_profile_entry, &idx, &avbl_idx, &pidx);
    if(idx != -1) {
#ifndef NO_CONSOLE_OUTPUT
        bmi_log->normal("sfc_iarb_profile::insert_entry() table entry in use");
#endif
        return -2;
    }

    if(avbl_idx == -1) {
#ifndef NO_CONSOLE_OUTPUT
        bmi_log->normal("sfc_iarb_profile::insert_entry() table full");
#endif
        return -3;
    }

    index = (_1bit) avbl_idx;
    sfc_iarb_profile_entry->_VALID = 1;
    write_entry(&index, sfc_iarb_profile_entry);
    return 0;
}

int sfc_iarb_profile_tab_t::delete_entry(sfc_iarb_profile_entry_t *sfc_iarb_profile_entry) {
    int idx, avbl_idx, pidx;
    _1bit index;

#ifndef NO_CONSOLE_OUTPUT
    bmi_log->debug("sfc_iarb_profile::delete_entry()");
#endif
    find_index(sfc_iarb_profile_entry, &idx, &avbl_idx, &pidx);
    if(idx == -1) {
#ifndef NO_CONSOLE_OUTPUT
        bmi_log->normal("sfc_iarb_profile::delete_entry() could not find entry");
#endif
        return -1;
    }

    index = (_1bit) idx;
    sfc_iarb_profile_entry->_VALID = 0;
    write_entry(&index, sfc_iarb_profile_entry);
    return 0;
}

int sfc_iarb_profile_tab_t::lookup_entry(sfc_iarb_profile_entry_t **sfc_iarb_profile_entry) {
    sfc_iarb_profile_entry_t *rentry;
    int idx, avbl_idx, pidx;
    _1bit index;

#ifndef NO_CONSOLE_OUTPUT
    bmi_log->debug("sfc_iarb_profile::lookup_entry()");
#endif
    find_index(*sfc_iarb_profile_entry, &idx, &avbl_idx, &pidx);
    if(idx == -1) {
#ifndef NO_CONSOLE_OUTPUT
        bmi_log->normal("sfc_iarb_profile::lookup_entry() could not find entry");
#endif
        return -1;
    }

    index = (_1bit) idx;
    rentry = read_entry(&index);
    memcpy(*sfc_iarb_profile_entry, rentry, sizeof(sfc_iarb_profile_entry_t));
    return 0;
}

sfc_iarb_profile_entry_t* sfc_iarb_profile_tab_t::read_entry(_1bit *index) {
#ifndef NO_CONSOLE_OUTPUT
    bmi_log->debug("sfc_iarb_profile::read_entry() index = %d", (int)*index);
#endif
    return sfc_iarb_profile_entry_array[*index];

}

sfc_iarb_profile_entry_t* sfc_iarb_profile_tab_t::lookup(int _lookup_idx_, _1bit *index) {
#ifndef NO_CONSOLE_OUTPUT
    bmi_log->normal("Looking up sfc_iarb_profile");
#endif

    sfc_iarb_profile_entry_array[*index]->_INDEX = *index;
    sfc_iarb_profile_entry_array[*index]->_LOOKUP0 = 1;
    sfc_iarb_profile_entry_array[*index]->_HIT_INDEX0(31,31) = 1;
    sfc_iarb_profile_entry_array[*index]->_HIT_INDEX0(30,24) = SFC_IARB_PROFILE_ENUM;
    sfc_iarb_profile_entry_array[*index]->_HIT_INDEX0(23,0) = *index;
#ifndef NO_CONSOLE_OUTPUT
    bmi_log->debug("sfc_iarb_profile::lookup() index = %d", (int)*index);
#endif

    return sfc_iarb_profile_entry_array[*index];
}

