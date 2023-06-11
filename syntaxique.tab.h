
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     mc_prgm = 258,
     mc_sub = 259,
     mc_var = 260,
     mc_as = 261,
     mc_array = 262,
     mc_cst = 263,
     mc_int = 264,
     mc_flt = 265,
     mc_bol = 266,
     mc_chr = 267,
     mc_str = 268,
     mc_body = 269,
     mc_and = 270,
     mc_or = 271,
     mc_not = 272,
     mc_sup = 273,
     mc_supe = 274,
     mc_inf = 275,
     mc_infe = 276,
     mc_ega = 277,
     mc_dif = 278,
     mc_aff = 279,
     mc_input = 280,
     mc_output = 281,
     mc_if = 282,
     mc_then = 283,
     mc_else = 284,
     mc_do = 285,
     mc_while = 286,
     mc_for = 287,
     mc_until = 288,
     ENTIER = 289,
     ENTIERSigne = 290,
     REEL = 291,
     REELSigne = 292,
     CHR = 293,
     STR = 294,
     BOOL = 295,
     IDF = 296,
     symbole_ouvrant = 297,
     symbole_fermant = 298,
     symbole_ouvrant2 = 299,
     symbole_fermant2 = 300,
     ptexcl = 301,
     parenthes_ouvrante = 302,
     parenthes_fermant = 303,
     soustraction = 304,
     addition = 305,
     multiplication = 306,
     division = 307,
     egal = 308,
     dpts = 309,
     virgule = 310,
     bar = 311,
     croo = 312,
     crof = 313,
     err = 314
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 19 "syntaxique.y"
char* nom;  struct { int type; char* res; }NT; 


/* Line 1676 of yacc.c  */
#line 115 "syntaxique.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


