#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "TS.h"

void init ()
{ 
	int i;
	for (i=0;i<taille;i++)
		TS[i]=NULL;
}

int Fhach (char* e)
{
	int i=0,count=0; 
	while(e[i]!='\0')
	{
		count+=e[i]*i*(10*(i+1));i++;
	} 
	return (count%taille);
} 

int recherche (char * el, int* index, elem** adr)
{
	elem* p;
	*index = Fhach(el);
	p=TS[*index]; 
	*adr =p;
	if (p==NULL) return 0;
	if (strcmp(p->nom,el)==0) return 1;
	p=p->svt;
	while (p!=NULL && strcmp(p->nom,el)!=0) 
		p=p->svt;
	*adr =p;
	if (p==NULL) return 0;
	return 1;
}

void inserer (char* el,int type,int classe,int tailleTab,int index)
{
	elem* p; 

	p=malloc(sizeof(elem));
	
	p->nom=el; 
	p->type=type;
	p->classe=classe;
	p->tailleTab=tailleTab;
	p->nbrAff=0;
	p->nbrUse=0;
	p->exp="";

	if (TS[index]==NULL) 
	{
		p->svt=NULL; 
		TS[index]=p;
	}
	else 
	{
		p->svt=TS[index]; 
		TS[index]=p;
	}
}

char* getNomType(int type)
{
    switch (type)
    {
        case 1 : return "INT";

        case 2 : return "FLT";

		case 3 : return "STR";

        case 4 : return "CHR";

        case 5 : return "BOL";
    
        default: return "";
    }	
}

char* getNomClasse(int classe)
{
    switch (classe)
    {
        case 0 : return "idf";

        case 1 : return "variable";

        case 2 : return "array";

        case 3 : return "cst_f1";

        case 4 : return "cst_f2";
    
        default: return "";
    }	
}

void afficherTS ()
{
	int i; 
	elem* p;
	printf("_________________________________________________________________________________");
	printf("\n\t|   Nom_IDF   |   Type_IDF   |   Classe_IDF   |   estAff    |  tailleTab");
	printf("\n_________________________________________________________________________________");	
	for(i=0;i<taille;i++)
	{	
		if (TS[i]!=NULL)
		{
			p=TS[i]; 
			while(p!=NULL) 
			{
				printf ("\n\t|%10s   |%11s   | %13s  | %10d  | %10d  ",p->nom,getNomType(p->type),getNomClasse(p->classe),p->nbrAff,p->tailleTab);
				p=p->svt;
			}
		}
	}
	printf("\n_________________________________________________________________________________\n\n");					  
}

void afficherOpt()
{
	int i; 
	elem* p;
	printf("________________________________________________________________________________________________________");
	printf("\n\t|   Nom_IDF   |                        Exp_IDF                        |   Nbr_Use");
	printf("\n________________________________________________________________________________________________________");	
	for(i=0;i<taille;i++)
	{	
		if (TS[i]!=NULL)
		{
			p=TS[i]; 
			while(p!=NULL) 
			{
				printf ("\n\t|%10s   |%50s     |%10d   ",p->nom,p->exp,p->nbrUse);
				p=p->svt;
			}
		}
	}
	printf("\n________________________________________________________________________________________________________\n\n");					  
}

char* supp_char(char *s,int k)
{
	int l=strlen(s);
	char x[l-1];
	int i,j=0;
	for(i=0;i<l;i++)
	{
		if(i!=k)
		{
			x[j]=s[i];
			j++;	
		}
	}
	x[l-1]='\0';
	return strdup(x);
}

int nb_occurrence(char c,char* s)
{
    int cc=0,i=0;
    while(s[i]!='\0')
    {
        if(s[i]==c)
        {
            cc++;
        }
        i++;
    }
    return cc;
}
