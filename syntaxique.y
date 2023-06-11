%{
    #include <stdio.h>
    #include <stdlib.h> 
    #include <string.h>
    #include "TS.h"
    #include "RS.h"
    #include "QUAD.h"
    #include "Pile.h"
    #include "Optm.h"


    extern FILE* yyin;
    int ligne=1,colomne=1;
    int type=0,i,indx,dans_boucle=0;
    char *x;
    elem* element;
%}

%union {char* nom;  struct { int type; char* res; }NT; }

%token mc_prgm mc_sub mc_var mc_as mc_array mc_cst 
%token mc_int mc_flt mc_bol mc_chr mc_str mc_body
%token mc_and mc_or mc_not mc_sup mc_supe mc_inf 
%token mc_infe mc_ega mc_dif mc_aff mc_input mc_output  
%token mc_if mc_then mc_else mc_do mc_while mc_for mc_until
%token<nom> ENTIER ENTIERSigne REEL REELSigne CHR STR BOOL IDF
%token symbole_ouvrant symbole_fermant symbole_ouvrant2 symbole_fermant2 ptexcl parenthes_ouvrante parenthes_fermant soustraction addition multiplication division egal
%token dpts virgule bar croo crof err

%left mc_or
%left mc_and
%left mc_sup mc_supe mc_inf mc_infe mc_ega mc_dif
%left addition soustraction
%left multiplication division
%left mc_not
%left parenthes_ouvrante parenthes_fermant

%type<NT> EXP VARIABLE EXP_ARTH EXP_BOOL EXP_COMP VAL 
%type<nom> INT FLT INIT_FOR

%start S

%%

S:             DEBUT DECLAR BODY FIN {printf("le programme lexicalement, syntaxiquement et semantiquement correct\n");YYACCEPT;}

DEBUT:         
symbole_ouvrant ptexcl mc_prgm IDF symbole_fermant2
 {
 
indx=Fhach($4);//trouver de l'idf dans TS
inserer(strdup($4),0,0,0,indx);//inserer le comme l'id de prg
get_obj($4)->nbrUse+=2;//pour proteger l'id de optimisation 

 }



TYPE:        
  mc_int {type=1;}|
  mc_flt {type=2;}|
  mc_str {type=3;}|
  mc_chr {type=4;}|
  mc_bol {type=5;}



DECLARATION:     DECLARATION_VAR | DECLARATION_CST | DECLARATION_ARRAY     

LIST_DECLARATION:     DECLARATION LIST_DECLARATION | DECLARATION



DEB_DECLAR:    symbole_ouvrant mc_sub mc_var symbole_fermant

FIN_DECLAR:    symbole_ouvrant2 mc_sub mc_var symbole_fermant

DECLAR:       
 DEB_DECLAR LIST_DECLARATION FIN_DECLAR |
 DEB_DECLAR FIN_DECLAR



LIST_IDF:     
 IDF                   {empiler(strdup($1));}| 
 IDF bar LIST_IDF      {empiler(strdup($1));}      


DECLARATION_VAR:     
 symbole_ouvrant LIST_IDF mc_as TYPE symbole_fermant2 
 {

  while(!pileVide())
{
x=depiler();
i=recherche(x,&indx,&element);
doubleDec(i);
inserer(x,type,1,0,indx);                                       
}
type=0;
x="";

}



BALISE_ARRAY:  symbole_ouvrant IDF dpts ENTIER symbole_fermant2 
{
empiler(strdup($4));//empiler la taille
empiler(strdup($2));
}

LIST_ARRAY:    BALISE_ARRAY LIST_ARRAY  | BALISE_ARRAY

DECLARATION_ARRAY:    symbole_ouvrant mc_array mc_as TYPE symbole_fermant LIST_ARRAY symbole_ouvrant2 mc_array symbole_fermant
               {
while(!pileVide())
{
x=depiler();
i=recherche(x,&indx,&element);
doubleDec(i);
i=atoi(depiler());//la taille
erreur_taille(i);
inserer(x,type,2,i,indx);                                       
 }
 type=0;
 x="";
                }                                              



BALISE_CST_F1: symbole_ouvrant IDF egal EXP symbole_fermant2     
 {
  x=strdup($2);
i=recherche(x,&indx,&element);
doubleDec(i);
inserer(x,$4.type,3,0,indx);
quadAFF($2,$4.res);
get_obj(x)->nbrAff++;
x="";

}                                                   

BALISE_CST_F2: symbole_ouvrant LIST_IDF mc_as TYPE symbole_fermant2
 {
while(!pileVide())
{
x=depiler();
i=recherche(x,&indx,&element);
doubleDec(i);
inserer(x,type,4,0,indx);                                       
}
type=0;
x="";
 }  

LIST_CST:      BALISE_CST_F1 LIST_CST | BALISE_CST_F2 LIST_CST | BALISE_CST_F1 | BALISE_CST_F2



DEB_DECLARATION_CST:  symbole_ouvrant mc_sub mc_cst symbole_fermant

FIN_DECLARATION_CST:  symbole_ouvrant2 mc_sub mc_cst symbole_fermant 

DECLARATION_CST:      DEB_DECLARATION_CST  LIST_CST  FIN_DECLARATION_CST  



INT:           ENTIER  {$$=ajuster_entier($1);}| 
               ENTIERSigne {$$=ajuster_entier($1);}

FLT:           REEL  {$$=ajuster_float($1);}| 
               REELSigne {$$=ajuster_float($1);}

VAL:           INT
{
$$.type=1;
$$.res=strdup($1);
}| 

               FLT                               
{
$$.type=2;
$$.res=strdup($1);
}|
               STR                               
{
$$.type=3;
$$.res=strdup($1);
}|
               CHR                               
{
$$.type=4;
$$.res=strdup($1);
}|
               BOOL                              
{
$$.type=5;
$$.res=$1;
}   



DEB_BODY:      symbole_ouvrant mc_body symbole_fermant

FIN_BODY:      symbole_ouvrant2 mc_body symbole_fermant 

BODY:          DEB_BODY BLOC_INST FIN_BODY|
               DEB_BODY FIN_BODY 



INST:          AFF | INPUT| OUTPUT | WHILE | FOR | IF  

BLOC_INST:     BLOC_INST INST | INST



VARIABLE:      
IDF                              
{
x=strdup($1);
i=recherche(x,&indx,&element);
nonDec(i);
erreur_indice(element->classe);
$$.type=element->type;
$$.res=strdup(x);
x="";
}|

IDF croo EXP crof             
{
x=strdup($1);

i=recherche(x,&indx,&element);
nonDec(i);
erreur_tab(element->classe);                   
incomptabiliteType($3.type,1);//l'indice' doit etre int
$$.type=element->type;
sprintf(x,"%s[%s]",strdup(x),strdup($3.res));
$$.res=strdup(x);
x="";
}               



EXP_ARTH:      
EXP addition EXP                     
{
$$.type=incomptabiliteType($1.type,$3.type);
err_type_arth($$.type);
$$.res=quadARTH("+",$1.res,$3.res);
}|

               
EXP soustraction EXP                 
{
$$.type=incomptabiliteType($1.type,$3.type);
err_type_arth($$.type);
$$.res=quadARTH("-",$1.res,$3.res);
}|

EXP multiplication EXP               
{
$$.type=incomptabiliteType($1.type,$3.type);
err_type_arth($$.type);
$$.res=quadARTH("*",$1.res,$3.res);
}|

EXP division EXP                     
{
$$.type=incomptabiliteType($1.type,$3.type);
err_type_arth($$.type);
div_zero($3.res);
$$.res=quadARTH("/",$1.res,$3.res);
}|

parenthes_ouvrante EXP parenthes_fermant                            
{
err_type_arth($2.type);
$$.type=$2.type;
$$.res=$2.res;
}
                



EXP_COMP:     
 mc_sup parenthes_ouvrante EXP virgule EXP parenthes_fermant           
 {

$$.type=incomptabiliteType($3.type,$5.type);
err_type_arth($$.type);
$$.res=quadSUP($3.res,$5.res);
}|

mc_supe parenthes_ouvrante EXP virgule EXP parenthes_fermant          
{
$$.type=incomptabiliteType($3.type,$5.type);
err_type_arth($$.type);
$$.res=quadSUPE($3.res,$5.res);
}|

mc_inf parenthes_ouvrante EXP virgule EXP parenthes_fermant           
{
$$.type=incomptabiliteType($3.type,$5.type);
err_type_arth($$.type);
$$.res=quadINF($3.res,$5.res);
}|

mc_infe parenthes_ouvrante EXP virgule EXP parenthes_fermant          
{
$$.type=incomptabiliteType($3.type,$5.type);
err_type_arth($$.type);
$$.res=quadINFE($3.res,$5.res);
}|

mc_ega parenthes_ouvrante EXP virgule EXP parenthes_fermant             
{
$$.type=incomptabiliteType($3.type,$5.type);
$$.res=quadEGA($3.res,$5.res);
}|

mc_dif parenthes_ouvrante EXP virgule EXP parenthes_fermant             
{
$$.type=incomptabiliteType($3.type,$5.type);
$$.res=quadDIF($3.res,$5.res);
}               



EXP_BOOL:      
mc_and parenthes_ouvrante EXP virgule EXP parenthes_fermant  
{
incomptabiliteType($3.type,5);
incomptabiliteType(5,$5.type);
$$.type=5;
$$.res=quadAND($3.res,$5.res);
}|

mc_or parenthes_ouvrante EXP virgule EXP parenthes_fermant   
{
incomptabiliteType($3.type,5);
incomptabiliteType(5,$5.type);
$$.type=5;
$$.res=quadOR($3.res,$5.res);
}|

mc_not parenthes_ouvrante EXP parenthes_fermant       
{
$$.type=incomptabiliteType(5,$3.type);
$$.res=quadNOT($3.res);
}|

EXP_COMP                
{
$$.type=5;
$$.res=$1.res;
}



EXP:           EXP_ARTH                
{
$$.type=$1.type;
$$.res=$1.res;
}|

               EXP_BOOL                
{
$$.type=5;
$$.res=$1.res;
}|

               VARIABLE                
{
$$.type=$1.type;
$$.res=$1.res;
                                       
if(dans_boucle==0)
{
(element->nbrUse)++;
} 
else
{  //les var des conditions des boucles sont utilisé plusieurs fois
(element->nbrUse)+=2;
} 

}|

               VAL                     
{
$$.type=$1.type;
$$.res=$1.res;
}



AFF:           symbole_ouvrant mc_aff dpts VARIABLE virgule EXP symbole_fermant2  
{
incomptabiliteType($4.type,$6.type);
element=get_obj($4.res);//car exp peut avoir var
err_aff_cst(element->classe,element->nbrAff);                                                                
(element->nbrAff)++;
quadAFF($4.res,$6.res);
element=NULL;
x="";
}



INPUT:         symbole_ouvrant mc_input dpts VARIABLE STR symbole_fermant2      
{
err_aff_cst(element->classe,element->nbrAff);
i=traitement_io($5,$4.type);
quadIN(i,$4.res,$5);
(element->nbrAff)++;
(element->nbrUse)=+2;
element=NULL;
}



OUTPUT_SUITE: OUTPUT_SUITE addition STR addition VARIABLE         
{
i=traitement_io($3,$5.type);
quadOUT(i,$3,$5.res);
(element->nbrUse)+=2;
element=NULL;
}|
              STR addition VARIABLE                               
{
i=traitement_io($1,$3.type);
quadOUT(i,$1,$3.res);
(element->nbrUse)+=2;
element=NULL;
}


OUTPUT:        symbole_ouvrant mc_output dpts OUTPUT_SUITE symbole_fermant2       |

               symbole_ouvrant mc_output dpts OUTPUT_SUITE addition STR symbole_fermant2       
  {
traitement_str($6);
quadOUT(-1,$6,"");
}|

               symbole_ouvrant mc_output dpts STR symbole_fermant2              
{
traitement_str($4);
quadOUT(-1,$4,"");
}|

               symbole_ouvrant mc_output dpts VARIABLE symbole_fermant2           
{
quadOUT(-1,"",$4.res);
(element->nbrUse)+=2;
element=NULL;
}



DEB_WHILE:     symbole_ouvrant mc_do symbole_fermant                            
{
dans_boucle=1;
sauvDEB_WHILE();
}

CONDT_WHILE:   symbole_ouvrant mc_while dpts EXP symbole_fermant2             
{
incomptabiliteType($4.type,5);
quadBR_DEB_WHILE($4.res);
} 

FIN_WHILE:     symbole_ouvrant2 mc_do symbole_fermant                           
{
dans_boucle=0;
}

WHILE:         DEB_WHILE BLOC_INST CONDT_WHILE FIN_WHILE



INIT_FOR:      VARIABLE egal EXP                           
{
incomptabiliteType($1.type,1);
incomptabiliteType($3.type,1);
quadAFF($1.res,$3.res);
$$=strdup($1.res);

dans_boucle=1;
(get_obj($1.res)->nbrUse)+=2;//car on est dans une boucle et $1 n'est pas dans une exp
(get_obj($1.res)->nbrAff)++;
} 

DEB_FOR:       symbole_ouvrant mc_for INIT_FOR mc_until EXP symbole_fermant
               {
                   incomptabiliteType($5.type,1);
                   quadBR_FIN_FOR($3,$5.res); 
               }

FIN_FOR:       symbole_ouvrant2 mc_for symbole_fermant  
{
dans_boucle=0;
}

FOR:           DEB_FOR BLOC_INST FIN_FOR 
{
quadBR_DEB_FOR();
}



DEB_IF:        symbole_ouvrant mc_if dpts EXP symbole_fermant                             
{
incomptabiliteType($4.type,5);
quadBR_FIN_THEN($4.res);
}

THEN:          symbole_ouvrant mc_then symbole_fermant BLOC_INST symbole_ouvrant2 mc_then symbole_fermant 
{
remplir_FIN_THEN();
quadBR_FIN_IF();
} 

ELSE:          symbole_ouvrant mc_else symbole_fermant BLOC_INST symbole_ouvrant2 mc_else symbole_fermant 

FIN_IF:        symbole_ouvrant2 mc_if symbole_fermant 

IF:            DEB_IF THEN FIN_IF 
{
remplir_FIN_IF();
}|

               DEB_IF THEN ELSE FIN_IF                                    
{
remplir_FIN_IF();
}



FIN:           symbole_ouvrant2 mc_prgm symbole_fermant

%%
int yyerror(char *msg)
{
    printf("\n%s la ligne %d la colomne %d >>\n",msg,ligne,colomne);
    exit(0);
    return 1;
}
main()
{
    yyin =fopen ("testgeneral.txt" ,"r");
    init();
    initQuad();
    initPile();
    
    yyparse();

    //optimisation();

    generationCode();
    
    afficherTS();
    afficherOpt();
    afficherQUAD();

    fclose(yyin);
}
yywrap()
{
}