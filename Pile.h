#ifndef PILE_H
#define PILE_H

typedef struct uniteP{
	char* val;
	struct uniteP* svt;
}pile;

pile *tetePile;

void initPile();
void empiler(char*);
char* depiler();
int pileVide();
void afficherPile();

#endif
