flex lexical.l
bison -d syntaxique.y
gcc lex.yy.c syntaxique.tab.c TS.c RS.c QUAD.c Pile.c Optm.c Asmb.c -lfl -ly -o compil.exe
compil.exe