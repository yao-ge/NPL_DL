/*
 * SCRIPT GENERATED FILE, DO NOT MODIFY
*/

#ifndef _REG_CLASSES
#define _REG_CLASSES

#include "bit_types.h"

class tuple_t;
class ps_worker_count;
class ps_value;
class ps_worker_smac;
class ps_worker_sip;
class ps_worker_sport;
class ps_bias_exp;
class ps_exp;
class ps_worker_bits;
class ps_bias;
class ps_worker_init_bits;

class tuple_t {
public:
    _32bits data_t;

    tuple_t(void);

    void set_data_t(_32bits, int, int);

    void print(void);
    int compare(tuple_t *ref, tuple_t *ref_mask);
    void deep_copy(tuple_t *ref);

};

class ps_worker_count {
public:
    _16bits value0;
    _16bits value1;
    _16bits value2;
    _16bits value3;

    ps_worker_count(void);

    void set_value0(_16bits, int, int);
    void set_value1(_16bits, int, int);
    void set_value2(_16bits, int, int);
    void set_value3(_16bits, int, int);

    void print(void);
    int compare(ps_worker_count *ref, ps_worker_count *ref_mask);
    void deep_copy(ps_worker_count *ref);

};

class ps_value {
public:
    _8192bits value00;
    _8192bits value01;
    _8192bits value10;
    _8192bits value11;
    _8192bits value20;
    _8192bits value21;
    _8192bits value30;
    _8192bits value31;

    ps_value(void);

    void set_value00(_8192bits, int, int);
    void set_value01(_8192bits, int, int);
    void set_value10(_8192bits, int, int);
    void set_value11(_8192bits, int, int);
    void set_value20(_8192bits, int, int);
    void set_value21(_8192bits, int, int);
    void set_value30(_8192bits, int, int);
    void set_value31(_8192bits, int, int);

    void print(void);
    int compare(ps_value *ref, ps_value *ref_mask);
    void deep_copy(ps_value *ref);

};

class ps_worker_smac {
public:
    _48bits value0;
    _48bits value1;
    _48bits value2;
    _48bits value3;

    ps_worker_smac(void);

    void set_value0(_48bits, int, int);
    void set_value1(_48bits, int, int);
    void set_value2(_48bits, int, int);
    void set_value3(_48bits, int, int);

    void print(void);
    int compare(ps_worker_smac *ref, ps_worker_smac *ref_mask);
    void deep_copy(ps_worker_smac *ref);

};

class ps_worker_sip {
public:
    _32bits value0;
    _32bits value1;
    _32bits value2;
    _32bits value3;

    ps_worker_sip(void);

    void set_value0(_32bits, int, int);
    void set_value1(_32bits, int, int);
    void set_value2(_32bits, int, int);
    void set_value3(_32bits, int, int);

    void print(void);
    int compare(ps_worker_sip *ref, ps_worker_sip *ref_mask);
    void deep_copy(ps_worker_sip *ref);

};

class ps_worker_sport {
public:
    _16bits value0;
    _16bits value1;
    _16bits value2;
    _16bits value3;

    ps_worker_sport(void);

    void set_value0(_16bits, int, int);
    void set_value1(_16bits, int, int);
    void set_value2(_16bits, int, int);
    void set_value3(_16bits, int, int);

    void print(void);
    int compare(ps_worker_sport *ref, ps_worker_sport *ref_mask);
    void deep_copy(ps_worker_sport *ref);

};

class ps_bias_exp {
public:
    _16bits value0;
    _16bits value1;
    _16bits value2;
    _16bits value3;

    ps_bias_exp(void);

    void set_value0(_16bits, int, int);
    void set_value1(_16bits, int, int);
    void set_value2(_16bits, int, int);
    void set_value3(_16bits, int, int);

    void print(void);
    int compare(ps_bias_exp *ref, ps_bias_exp *ref_mask);
    void deep_copy(ps_bias_exp *ref);

};

class ps_exp {
public:
    _16bits value0;
    _16bits value1;
    _16bits value2;
    _16bits value3;

    ps_exp(void);

    void set_value0(_16bits, int, int);
    void set_value1(_16bits, int, int);
    void set_value2(_16bits, int, int);
    void set_value3(_16bits, int, int);

    void print(void);
    int compare(ps_exp *ref, ps_exp *ref_mask);
    void deep_copy(ps_exp *ref);

};

class ps_worker_bits {
public:
    _16bits value0;
    _16bits value1;
    _16bits value2;
    _16bits value3;

    ps_worker_bits(void);

    void set_value0(_16bits, int, int);
    void set_value1(_16bits, int, int);
    void set_value2(_16bits, int, int);
    void set_value3(_16bits, int, int);

    void print(void);
    int compare(ps_worker_bits *ref, ps_worker_bits *ref_mask);
    void deep_copy(ps_worker_bits *ref);

};

class ps_bias {
public:
    _16bits value0;
    _16bits value1;
    _16bits value2;
    _16bits value3;

    ps_bias(void);

    void set_value0(_16bits, int, int);
    void set_value1(_16bits, int, int);
    void set_value2(_16bits, int, int);
    void set_value3(_16bits, int, int);

    void print(void);
    int compare(ps_bias *ref, ps_bias *ref_mask);
    void deep_copy(ps_bias *ref);

};

class ps_worker_init_bits {
public:
    _16bits value0;
    _16bits value1;
    _16bits value2;
    _16bits value3;

    ps_worker_init_bits(void);

    void set_value0(_16bits, int, int);
    void set_value1(_16bits, int, int);
    void set_value2(_16bits, int, int);
    void set_value3(_16bits, int, int);

    void print(void);
    int compare(ps_worker_init_bits *ref, ps_worker_init_bits *ref_mask);
    void deep_copy(ps_worker_init_bits *ref);

};

#endif
