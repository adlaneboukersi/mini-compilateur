#ifndef RS_H
#define RS_H

void nonDec (int);
void doubleDec (int);
int incomptabiliteType(int,int);
char* ajuster_entier(char*);
char* ajuster_float(char*);
void erreur_taille(int);
void erreur_indice(int);
void erreur_tab(int);
void div_zero(char*);
void err_type_arth(int);
char* get_tabName(char*);
elem* get_obj(char*);
void err_aff_cst(int,int);
char get_io_sign(int);
int traitement_io(char*,int);
void traitement_str(char*);

#endif//RS_H
