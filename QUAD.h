#ifndef QUAD_H
#define QUAD_H

// la structure d'un element
typedef struct eltQ{
	char* opr;
	char* op1;
	char* op2;
	char* res;
	int i;
	int etiq;
	struct eltQ* svt;
	struct eltQ* prd;
}quadruplet;

//				 
quadruplet *teteQ,*queQ;

//signature des fonctions de quad.c

void initQuad();
quadruplet* getQuad(int);
quadruplet* getQuad2(char*);
void suppQuad(quadruplet**);
quadruplet* insertQuadAfter(quadruplet*);


void quad (char*,char*,char*,char*);

char* quadARTH(char*,char*,char*);

char* quadAND(char*,char*);
char* quadOR(char*,char*);
char* quadNOT(char*);

char* quadSUP(char*,char*);
char* quadSUPE(char*,char*);
char* quadINF(char*,char*);
char* quadINFE(char*,char*);
char* quadEGA(char*,char*);
char* quadDIF(char*,char*);

void quadAFF(char*,char*);

void quadBR_FIN_THEN(char*);
void quadBR_FIN_IF();
void remplir_FIN_THEN();
void remplir_FIN_IF();

void sauvDEB_WHILE();
void quadBR_DEB_WHILE(char*);

void quadBR_FIN_FOR(char*,char*);
void quadBR_DEB_FOR();

void quadOUT(int,char*,char*);
void quadIN(int,char*,char*);

void afficherQUAD();

#endif//QUAD_H
