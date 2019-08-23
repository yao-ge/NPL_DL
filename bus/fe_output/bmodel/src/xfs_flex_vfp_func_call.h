/*
 * SCRIPT GENERATED FILE, DO NOT MODIFY
*/

#ifndef VFP_FUNC_CALL_H
#define VFP_FUNC_CALL_H

void target_pp_top::dt_vfp_func(_0bit* presel_BITMAP, _0bit* rule_BITMAP, ) {
    dt_vfp_presel_template_data_entry_t *presel_entry;
    dt_vfp_rule_template_data_entry_t *rule_entry;
    dt_vfp_action_template_data_entry_t *action_entry;
    dt_vfp_entry_data_entry_t *main_entry;
    _16bits presel_id;
    _16bits rule_id;
    _16bits action_id;


    presel_entry = dt_vfp_presel_template_data->lookup(0, 

    rule_entry = dt_vfp_rule_template_data->lookup(0, 

    presel_id = presel_entry->template_id;
    rule_id = rule_entry->template_id;
    main_entry = dt_vfp_entry_data->lookup(0, &rule_id, &presel_id);

    action_id = main_entry->dt_vfp_action_template_id;
    action_entry =  dt_vfp_action_template_data->lookup(0, &action_id);


}


#endif
