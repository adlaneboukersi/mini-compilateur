%{    
    #include "syntaxique.tab.h"
    #include "TS.h"
    #include <string.h>
    extern ligne;
    extern colomne;
%}

lettre [a-zA-Z]

chiffre [0-9]

IDF {lettre}({lettre}|{chiffre})*

ENTIER {chiffre}+
ENTIERSigne \([\+\-]{ENTIER}\)

REEL {chiffre}+\.{chiffre}+
REELSigne \([\+\-]{REEL}\)

caractere ([^'"\\]|\\[nst'"\\])
STR \"{caractere}*\"
CHR '{caractere}'

BOOL TRUE|FALSE

espace ("\t"|" ")+
sauteLigne "\n"+

COMMENTAIRE ";"([^;]|"\n")*";"

%%

"docprogram" {printf(" le mot cle || %s || est reconnu \n",yytext);colomne= colomne+yyleng; return mc_prgm;}
"SUB"        {printf(" le mot cle || %s || est reconnu \n",yytext);colomne= colomne+yyleng; return mc_sub;}
"VARIABLE"   {printf(" le mot cle || %s || est reconnu \n",yytext);colomne= colomne+yyleng; return mc_var;}
"AS"         {printf(" le mot cle || %s || est reconnu \n",yytext);colomne= colomne+yyleng; return mc_as;}
"ARRAY"      {printf(" le mot cle || %s || est reconnu \n",yytext);colomne= colomne+yyleng; return mc_array;}
"CONSTANTE"  {printf(" le mot cle || %s || est reconnu \n",yytext);colomne= colomne+yyleng; return mc_cst;}

"INT"        {printf(" le mot cle || %s || est reconnu \n",yytext);colomne= colomne+yyleng; return mc_int;}

"FLT"        {printf(" le mot cle || %s || est reconnu \n",yytext);colomne= colomne+yyleng; return mc_flt;}

"BOL"        {printf(" le mot cle || %s || est reconnu \n",yytext);colomne= colomne+yyleng; return mc_bol;}

"CHR"        {printf(" le mot cle || %s || est reconnu \n",yytext);colomne= colomne+yyleng; return mc_chr;}

"STR"        {printf(" le mot cle || %s || est reconnu \n",yytext);colomne= colomne+yyleng; return mc_str;}

"body"       {printf(" le mot cle || %s || est reconnu \n",yytext);colomne= colomne+yyleng; return mc_body;}
"AND"        {printf(" le mot cle || %s || est reconnu \n",yytext);colomne= colomne+yyleng; return mc_and;}
"OR"         {printf(" le mot cle || %s || est reconnu \n",yytext);colomne= colomne+yyleng; return mc_or;}
"NOT"        {printf(" le mot cle || %s || est reconnu \n",yytext);colomne= colomne+yyleng; return mc_not;}
"SUP"        {printf(" le mot cle || %s || est reconnu \n",yytext);colomne= colomne+yyleng; return mc_sup;}
"SUPE"       {printf(" le mot cle || %s || est reconnu \n",yytext);colomne= colomne+yyleng; return mc_supe;}
"INF"        {printf(" le mot cle || %s || est reconnu \n",yytext);colomne= colomne+yyleng; return mc_inf;}
"INFE"       {printf(" le mot cle || %s || est reconnu \n",yytext);colomne= colomne+yyleng; return mc_infe;}
"EGA"        {printf(" le mot cle || %s || est reconnu \n",yytext);colomne= colomne+yyleng; return mc_ega;}
"DIF"        {printf(" le mot cle || %s || est reconnu \n",yytext);colomne= colomne+yyleng; return mc_dif;}
"AFF"        {printf(" le mot cle || %s || est reconnu \n",yytext);colomne= colomne+yyleng; return mc_aff;}
"INPUT"      {printf(" le mot cle || %s || est reconnu \n",yytext);colomne= colomne+yyleng; return mc_input;}
"OUTPUT"     {printf(" le mot cle || %s || est reconnu \n",yytext);colomne= colomne+yyleng; return mc_output;}
"IF"         {printf(" le mot cle || %s || est reconnu \n",yytext);colomne= colomne+yyleng; return mc_if;}
"THEN"       {printf(" le mot cle || %s || est reconnu \n",yytext);colomne= colomne+yyleng; return mc_then;}
"ELSE"       {printf(" le mot cle || %s || est reconnu \n",yytext);colomne= colomne+yyleng; return mc_else;}
"DO"         {printf(" le mot cle || %s || est reconnu \n",yytext);colomne= colomne+yyleng; return mc_do;}
"WHILE"      {printf(" le mot cle || %s || est reconnu \n",yytext);colomne= colomne+yyleng; return mc_while;}
"FOR"        {printf(" le mot cle || %s || est reconnu \n",yytext);colomne= colomne+yyleng; return mc_for;}
"Until"      {printf(" le mot cle || %s || est reconnu \n",yytext);colomne= colomne+yyleng; return mc_until;}

{ENTIER}   {
           printf(" ENTIER || %s || est reconnu \n",yytext);
           colomne= colomne+yyleng;
           yylval.nom = strdup(yytext); 
           return ENTIER;
           }

{ENTIERSigne}  {
           printf(" ENTIERSigne || %s || est reconnu \n",yytext);
           colomne= colomne+yyleng;
           yylval.nom = strdup(yytext); 
           return ENTIERSigne;
           }

{REEL}     {
           printf(" REEL || %s || est reconnu \n",yytext);
           colomne= colomne+yyleng;
           yylval.nom = strdup(yytext); 
           return REEL;
           }

{REELSigne}    {
           printf(" REELSigne || %s || est reconnu \n",yytext);
           colomne= colomne+yyleng;
           yylval.nom = strdup(yytext); 
           return REELSigne;
           }

{CHR}      {
           printf(" CHR || %s || est reconnu \n",yytext);
           colomne= colomne+yyleng;
           yylval.nom=strdup(yytext); 
           return CHR;
           }

{STR}      {
           printf(" STR || %s || est reconnu \n",yytext);
           colomne= colomne+yyleng;
           yylval.nom=strdup(yytext);
           return STR;
           }

{BOOL}     {
           printf(" BOOL || %s || est reconnu \n",yytext);
           colomne= colomne+yyleng;
           yylval.nom = strdup(yytext); 
           return BOOL;
           }

{IDF}      {
                colomne= colomne+yyleng;
                if(yyleng>10){
                    printf("erreur lexicale << longeur idf tres grande la ligne %d la colomne %d entite || %s || >> \n",ligne,colomne,yytext);
                    return err;
                }
                else{
                    printf(" IDF || %s || est reconnu  \n",yytext);
                    yylval.nom = strdup(yytext); 
                    return IDF;
                }
           }

"<"        {printf(" le separateur || %s || est reconnu \n",yytext);colomne= colomne+yyleng; return symbole_ouvrant;}
">"        {printf(" le separateur || %s || est reconnu \n",yytext);colomne= colomne+yyleng; return symbole_fermant;}
"</"       {printf(" le separateur || %s || est reconnu \n",yytext);colomne= colomne+yyleng; return symbole_ouvrant2;}
"/>"       {printf(" le separateur || %s || est reconnu \n",yytext);colomne= colomne+yyleng; return symbole_fermant2;}
"!"        {printf(" le separateur || %s || est reconnu \n",yytext);colomne= colomne+yyleng; return ptexcl;}
"("        {printf(" le separateur || %s || est reconnu \n",yytext);colomne= colomne+yyleng; return parenthes_ouvrante;}
")"        {printf(" le separateur || %s || est reconnu \n",yytext);colomne= colomne+yyleng; return parenthes_fermant;}
"-"        {printf(" le separateur || %s || est reconnu \n",yytext);colomne= colomne+yyleng; return soustraction;}
"+"        {printf(" le separateur || %s || est reconnu \n",yytext);colomne= colomne+yyleng; return addition;}
"*"        {printf(" le separateur || %s || est reconnu \n",yytext);colomne= colomne+yyleng; return multiplication;}
"/"        {printf(" le separateur || %s || est reconnu \n",yytext);colomne= colomne+yyleng; return division;}
"="        {printf(" le separateur || %s || est reconnu \n",yytext);colomne= colomne+yyleng; return egal;}
":"        {printf(" le separateur || %s || est reconnu \n",yytext);colomne= colomne+yyleng; return dpts;}
","        {printf(" le separateur || %s || est reconnu \n",yytext);colomne= colomne+yyleng; return virgule;}
"|"        {printf(" le separateur || %s || est reconnu \n",yytext);colomne= colomne+yyleng; return bar;}
"["        {printf(" le separateur || %s || est reconnu \n",yytext);colomne= colomne+yyleng; return croo;}
"]"        {printf(" le separateur || %s || est reconnu \n",yytext);colomne= colomne+yyleng; return crof;}

{espace}      {colomne+=yyleng;}
{sauteLigne}  {colomne=1; ligne+=yyleng;}
{COMMENTAIRE} {ligne+=nb_occurrence('\n',yytext);}

.          {
            printf("erreur lexicale << l'entite n'est pas reconnu la ligne %d la colomne %d entite || %s || >> \n",ligne,colomne,yytext);
            return err;
           }
