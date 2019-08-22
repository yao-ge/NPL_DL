/*
 * SCRIPT GENERATED FILE, DO NOT MODIFY
*/

#ifndef _TABLE_CLASSES
#define _TABLE_CLASSES

#include "bit_types.h"

#include "table_entry_classes.h"

typedef enum _table_enums_e_ {
    SFC_EDB_PROFILE_ENUM,
    SFC_MMU_PROFILE_ENUM,
    SFC_IARB_PROFILE_ENUM,
} _table_enums_t_;

class sfc_edb_profile_tab_t {
public:
    sfc_edb_profile_entry_t *sfc_edb_profile_entry_array[2];
    uint max_entries;

    sfc_edb_profile_tab_t(void);
    ~sfc_edb_profile_tab_t(void);

    void write_entry(_1bit *index, sfc_edb_profile_entry_t *sfc_edb_profile_entry);
    void find_index(sfc_edb_profile_entry_t *sfc_edb_profile_entry, int *idx, int *avbl_idx, int *pidx);
    int insert_entry(sfc_edb_profile_entry_t *sfc_edb_profile_entry);
    int delete_entry(sfc_edb_profile_entry_t *sfc_edb_profile_entry);
    int lookup_entry(sfc_edb_profile_entry_t **sfc_edb_profile_entry);
    sfc_edb_profile_entry_t* read_entry(_1bit *index);
    sfc_edb_profile_entry_t* lookup(int _lookup_idx_, _1bit *index);
};

class sfc_mmu_profile_tab_t {
public:
    sfc_mmu_profile_entry_t *sfc_mmu_profile_entry_array[2];
    uint max_entries;

    sfc_mmu_profile_tab_t(void);
    ~sfc_mmu_profile_tab_t(void);

    void write_entry(_1bit *index, sfc_mmu_profile_entry_t *sfc_mmu_profile_entry);
    void find_index(sfc_mmu_profile_entry_t *sfc_mmu_profile_entry, int *idx, int *avbl_idx, int *pidx);
    int insert_entry(sfc_mmu_profile_entry_t *sfc_mmu_profile_entry);
    int delete_entry(sfc_mmu_profile_entry_t *sfc_mmu_profile_entry);
    int lookup_entry(sfc_mmu_profile_entry_t **sfc_mmu_profile_entry);
    sfc_mmu_profile_entry_t* read_entry(_1bit *index);
    sfc_mmu_profile_entry_t* lookup(int _lookup_idx_, _1bit *index);
};

class sfc_iarb_profile_tab_t {
public:
    sfc_iarb_profile_entry_t *sfc_iarb_profile_entry_array[2];
    uint max_entries;

    sfc_iarb_profile_tab_t(void);
    ~sfc_iarb_profile_tab_t(void);

    void write_entry(_1bit *index, sfc_iarb_profile_entry_t *sfc_iarb_profile_entry);
    void find_index(sfc_iarb_profile_entry_t *sfc_iarb_profile_entry, int *idx, int *avbl_idx, int *pidx);
    int insert_entry(sfc_iarb_profile_entry_t *sfc_iarb_profile_entry);
    int delete_entry(sfc_iarb_profile_entry_t *sfc_iarb_profile_entry);
    int lookup_entry(sfc_iarb_profile_entry_t **sfc_iarb_profile_entry);
    sfc_iarb_profile_entry_t* read_entry(_1bit *index);
    sfc_iarb_profile_entry_t* lookup(int _lookup_idx_, _1bit *index);
};

#endif
