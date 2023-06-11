#include <stdio.h>
#include <string.h>
#include "TS.h"

int yyerror(char*);

void nonDec (int rech)
{ 
    if (rech==0)
    {
        yyerror("erreur semantique << il y a un IDF non declarer");
    }
}

void doubleDec(int rech)
{  
    if (rech==1)
    {
        yyerror("erreur semantique << il y a une double declaration");
    }
}

int incomptabiliteType(int type1,int type2)
{
    if(type1!=type2)
    {
        yyerror("erreur semantique << incompatibilite des types");
    }
    return type1;
}

char* ajuster_entier(char* i)
{
    int x;

    if(i[0]=='(')//pour vérifier si i est signé
    {
        i=supp_char(i,0);//enlever (
        i=supp_char(i,strlen(i)-1);//enlever )
        if(i[0]=='+')
        {
            i=supp_char(i,0);
        } 
    }

    //vérifier que ce int est dans l'intervalle
    x=atoi(i);
    if(x<-32768 || x>32767)
    {
        yyerror("erreur semantique << la valeur int est fausse");
    } 
 
    sprintf(i,"%d",x);
    return i;
}

char* ajuster_float(char* f)
{
    int reel;
    int entier;
    char neg[12]="\0";

    if(f[0]=='(')//pour vérifier si f est signé
    {
        f=supp_char(f,0);//enlever (
        f=supp_char(f,strlen(f)-1);//enlever )
        if(f[0]=='-')
        {
            neg[0]='-';
        }
        f=supp_char(f,0);//enlever + ou -
    }

    reel=strlen(strchr(f,'.'));//la longeur de la partie reelle
    entier=strlen(f)-reel;//la longeur de la partie entierre

    //enlever les 0 dans le debut de la partie entierre par ex 0001.0==>1.0
    while(entier>1&&f[0]=='0')
    {
        f=supp_char(f,0);
        entier--;
    }

    //enlever les 0 dans la fin de la partie reelle par ex 1.0000==>1.0
    while(reel>2&&f[entier+reel-1]=='0')
    {
        f=supp_char(f,entier+reel-1);
        reel--;
    }   

    //si longeur(partie reelle)>4 ou longeur(partie entierre)>7 
    if(reel>4 || entier>7)
    {
        yyerror("erreur semantique << la valeur flt est fausse");
    }

    
    if(neg[0]!='\0')
    {
        strcat(neg,f);
        return strdup(neg);
    }
    return f;
}

void erreur_taille(int taille_tab)
{
    if(taille_tab<=0)
    {
       yyerror("erreur semantique << la taille est errone"); 
    }
}

void erreur_indice(int classe)
{
    if(classe==2)
    {
        yyerror("erreur semantique << il manque l'indice");
    }
}

void erreur_tab(int classe)//
{
    if(classe!=2)
    {
        yyerror("erreur semantique << cette variable n'est pas un tableau");
    }    
}

void div_zero(char* zero)
{
    if(strcmp(zero,"0")==0)
    {
        yyerror("erreur semantique << il y a une division par zero");
    }
}

void err_type_arth(int type)
{
    if(type!=1&&type!=2)
    {
        yyerror("erreur semantique << il faut un type arthemitique");
    }    
}

char* get_tabName(char* idf)
{
    int i=0,j;
    char x[12];

    while(idf[i]!='['&&idf[i]!='\0') i++;
    
    for(j=0;j<i;j++)
    {
    	x[j]=idf[j];
	}
    x[i]='\0';

    return strdup(x);
}

elem* get_obj(char* idf)
{
    char* x;
    int i,index;
    elem* adr;
    x=get_tabName(strdup(idf));//pour avoir le nom de la variable seulement
    i=recherche(x,&index,&adr);
    return adr;
}

void err_aff_cst(int classe,int nbrAff)
{
    if((classe==3||classe==4)&&nbrAff>0)
    {
        yyerror("erreur semantique << il y a une reaffectation d'une constante");
    }
}

char get_io_sign(int type)
{
    switch (type)
    {
        case 1 : return '$';

        case 2 : return '%';

        case 3 : return '#';

        case 4 : return '&';

        case 5 : return '@';
    
        default: return '\0';
    }
}

int traitement_io(char* s,int type)
{
    char c=get_io_sign(type);
    int j,l=strlen(s);
    
    //s[l-2] car s[l-1]=\"
    if(l-2<1||(s[l-2]!='$'&&s[l-2]!='%'&&s[l-2]!='#'&&s[l-2]!='&'&&s[l-2]!='@'))//si la chaine est vide ou la fin n'est pas un signe
    {
        yyerror("erreur semantique << il manque le signe");
    }
    else
    {
        if(s[l-2]!=c)
        {
            yyerror("erreur semantique << incompatibilite des types");
        }
        else
        {
            j=0;
            while(j<l-1&&s[j]!='$'&&s[j]!='%'&&s[j]!='#'&&s[j]!='&'&&s[j]!='@')
            {
                j++;
            }
            if(j==l-2)
            {
               return j; 
            }
            else
            {
                yyerror("erreur semantique << il y a un signe supplementaire");
            }
        }
    }
}

void traitement_str(char* s)
{
    int i=0;
    while(s[i]!='\0'&&s[i]!='$'&&s[i]!='%'&&s[i]!='#'&&s[i]!='&'&&s[i]!='@')//avancer jusque fin ou signe
    {
        i++;
    }
    if(s[i]!='\0')
    {
        yyerror("erreur semantique << il y a un signe supplementaire");
    }
}
