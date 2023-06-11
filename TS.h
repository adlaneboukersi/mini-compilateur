#ifndef TS_H
#define TS_H

#define taille 100

typedef struct elt{
	char* nom;
	int type;
	int classe;
	int tailleTab;
	char* exp;
	int nbrAff;
	int nbrUse;
	struct elt* svt;
}elem;

elem * TS[taille];

void init();
int Fhach(char*);
int recherche(char*,int*,elem**);
void inserer(char*,int,int,int,int);
char* getNomType(int);
char* getNomClasse(int);
void afficherTS();
void afficherOpt();
char* supp_char(char*,int);
int nb_occurrence(char,char*);

#endif //TS_H
