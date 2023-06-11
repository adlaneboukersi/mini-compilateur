#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pile.h"

void initPile()
{
	tetePile=NULL;
}

void empiler(char *x)
{
	pile *e=malloc(sizeof(pile));
	e->val=strdup(x);
	e->svt=tetePile;
	tetePile=e;	
}

char* depiler()
{
	char *x;
	pile *e;
	if(tetePile!=NULL)
	{
		x=strdup((tetePile)->val);
		e=tetePile;
		tetePile=(tetePile)->svt;
		free(e);
		return x;		
	}
	else
	{
		return NULL;
	}	
}

int pileVide()
{
	if(tetePile==NULL) return 1;
	return 0;	
}

void afficherPile()
{
 	pile* t=tetePile;
	while(t!=NULL)
	{
		printf("%s\n",t->val);
		t=t->svt;
	}   
}
