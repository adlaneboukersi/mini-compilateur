#ifndef OPT_H
#define OPT_H

#include "TS.h"
#include "RS.h"
#include "QUAD.h"

extern int indq;

int est_nbr(char*);
int est_var(char*);
int est_tab(char*);
int est_tmp(char*);
int comparer(char*,char*);
char*  simpl_alg_calc_inut(quadruplet*);
char* recreer_exp(char*);
char* creer_exp_in();
elem* find_var_exp(char*);
void  supp_quads(char*);
char* elimin_exps_redond(char*,char*);
void ajuster_exps();
void supp_ele(elem**,elem**,int);
void trt_elimin_prpg_exps(elem*);
void  elimin_prpg_exps();
int test_condt_prpg_copies(quadruplet*,elem*,elem*);
void  elimin_prpg_copies();
void trt_simpl_alg_mul(quadruplet*,char*,char*);
void  simpl_alg_mul();
void  appliquer_elimin_quads();
void trt_elimin_code_inut(elem*);
void  elimin_code_inut();
void optimisation();


#endif//OPT_H
