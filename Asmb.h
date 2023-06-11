#ifndef ASM_H
#define ASM_H
#include <stdlib.h>
#include <stdio.h>
#include "TS.h"
#include "QUAD.h"
#include "Optm.h"

char* getIdPrgm();
void creeTitle(FILE*);

void creeArray(FILE*,elem*);
void creeVariable(FILE*,elem*);
void creeVariables(FILE*);
void creeTemps(FILE*);
void creeDataSeg(FILE*);

int getIndiceTemp(char*);
int estArray(char*,char[]);
char* traitementIndiceTab(char*);
char* traitementOprd(char*);
void creeInstArth(FILE*,quadruplet*,char*);
void creeInstAff(FILE*,quadruplet*);
void creeEtiq(FILE*,int);
int estValeur(char*);
char* traitementCmp(quadruplet*);
void creeInstBr(FILE*,quadruplet*);
char* getInstAffichageCara(char*,int*);
void traitementAffichageInt(FILE*,char*);
void creeInstOut(FILE*,quadruplet*);
void traitementSautLigne(FILE*);
void traitementLectureStr(FILE*,char*);
void traitementLectureInt(FILE*,char*);
void creeInstIn(FILE*,quadruplet*);
void creeInsts(FILE*);
void creeCodeSeg(FILE*);

void  generationCode();

#endif //ASM_H
