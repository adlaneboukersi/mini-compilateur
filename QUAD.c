#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "QUAD.h"
#include "TS.h"
#include "Pile.h"

int indq=0;
int nTemp=0;
char tempC[12]="";
int prochainEtiq=0;

void initQuad()
{
	teteQ=NULL; 
	queQ=NULL;
}

quadruplet* getQuad(int i)
{
 	quadruplet* q=queQ;
	while(q!=NULL&&q->i!=i) q=q->prd;
	return q;
}

quadruplet* getQuad2(char* temp)
{
	quadruplet* q=queQ;
	while(q!=NULL&&strcmp(q->res,temp)!=0) q=q->prd;
	return q;	
}

void suppQuad(quadruplet **p)
{
	if(teteQ==*p)
	{
		teteQ=teteQ->svt;
		
		if(teteQ==NULL) queQ=NULL;
		else teteQ->prd=NULL;
	}
	else if(queQ==*p)
	{
		queQ=queQ->prd;
		queQ->svt=NULL;
	}	
	else
	{
		((*p)->svt)->prd=(*p)->prd;
		((*p)->prd)->svt=(*p)->svt;
	}
	free(*p);
}

quadruplet* insertQuadAfter(quadruplet *p)
{
	quadruplet *q=malloc(sizeof(quadruplet));
	if(p==NULL)
	{
		q->prd=NULL;
		q->svt=NULL;
		teteQ=q;
		queQ=q;
	}
	else
	{
		q->svt=p->svt;
		q->prd=p;
		if(p->svt!=NULL) (p->svt)->prd=q;
		p->svt=q;
	}
	return q;	
}

void quad (char* o,char* o1,char* o2,char* r)
{
	queQ=insertQuadAfter(queQ);
	queQ->opr=strdup(o);
	queQ->op1=strdup(o1);
	queQ->op2=strdup(o2);
	queQ->res=strdup(r);
	queQ->i=indq;
	queQ->etiq=prochainEtiq;
	prochainEtiq=0;
	indq++;
}

void quadAFF(char* var,char* temp)
{
	quad("AFF",temp,"",var);
}

char* quadARTH(char* o,char* o1,char* o2)
{
	char* x;

	//creer un temp
	sprintf(tempC,"^T%d",nTemp);
    nTemp++;

	quad(o,o1,o2,tempC);

	x=strdup(tempC);
	tempC[0]='\0';
	return x;
}

char* quadAND(char* exp1,char* exp2)
{
	char x[12],*y;

	//creer un tempon
	sprintf(tempC,"^T%d",nTemp);
    nTemp++; 	

	//si exp1==FALSE alors brancher dans temp=FALSE car AND(FALSE,.) == FALSE
	sprintf(x,"%d",indq+4);
	quad("BZ",exp1,"",x);
	x[0]='\0';

	//si exp2==FALSE alors brancher dans temp=FALSE car AND(TRUE,FALSE) == FALSE
    sprintf(x,"%d",indq+3);
	quad("BZ",exp2,"",x);
	x[0]='\0';

	//si exp1==TRUE et exp2==TRUE alors temp=TRUE car AND(TRUE,TRUE) == TRUE
	quadAFF(tempC,"TRUE");

	//brancher dans l'instruction suivante
    sprintf(x,"%d",indq+2);
	quad("BR","","",x);
	x[0]='\0';

	//si exp1==FALSE ou exp2==FALSE alors temp=FALSE
	prochainEtiq=1;
	quadAFF(tempC,"FALSE");

	prochainEtiq=1;

	y=strdup(tempC);
    tempC[0]='\0';	
	return y;
}

char* quadOR(char* exp1,char* exp2)
{
	char x[12],*y;
	
	//creer un temp
	sprintf(tempC,"^T%d",nTemp);
    nTemp++; 	

	//si exp1==TRUE alors brancher dans temp=TRUE car OR(TRUE,.) == TRUE
	sprintf(x,"%d",indq+4);
	quad("BNZ",exp1,"",x);
	x[0]='\0';

	//si exp2==TRUE alors brancher dans temp=TRUE car OR(FALSE,TRUE) == TRUE
    sprintf(x,"%d",indq+3);
	quad("BNZ",exp2,"",x);
	x[0]='\0';

	//si exp1==FALSE et exp2==FALSE alors temp=FALSE car OR(FALSE,FALSE) == FALSE
	quadAFF(tempC,"FALSE");

	//brancher dans l'instruction suivante
    sprintf(x,"%d",indq+2);
	quad("BR","","",x);
	x[0]='\0';

	//si exp1==TRUE ou exp2==TRUE alors temp=TRUE
	prochainEtiq=1;
	quadAFF(tempC,"TRUE");

	prochainEtiq=1;

	y=strdup(tempC);
    tempC[0]='\0';	
	return y;
}

char* quadNOT(char* exp1)
{
	char x[12],*y;

	//creer un temp
	sprintf(tempC,"^T%d",nTemp);
    nTemp++; 	

	//si exp1==FALSE alors brancher dans temp=TRUE car NOT(FALSE) == TRUE
    sprintf(x,"%d",indq+3);
	quad("BZ",exp1,"",x);
	x[0]='\0';	

	//si exp1==TRUE alors temp=FALSE car NOT(TRUE) == FALSE
	quadAFF(tempC,"FALSE");	

	//brancher dans l'instruction suivante
    sprintf(x,"%d",indq+2);
	quad("BR","","",x);
	x[0]='\0';

	//si exp1==FALSE alors temp=TRUE car NOT(FALSE) == TRUE
	prochainEtiq=1;
	quadAFF(tempC,"TRUE");

	prochainEtiq=1;

	y=strdup(tempC);
    tempC[0]='\0';	
	return y;
}

char* quadSUP(char* exp1,char* exp2)
{
	char x[12],*y;

	//creer un temp de resultat finale
	sprintf(tempC,"^T%d",nTemp);
    nTemp++; 	

	//si exp1>exp2 alors brancher dans tempC=TRUE 
	sprintf(x,"%d",indq+3);
	quad("BG",exp1,exp2,x);
	x[0]='\0';

	//si exp1<=exp2 alors tempC=FALSE 
    quadAFF(tempC,"FALSE");

	//brancher dans l'instruction suivante
    sprintf(x,"%d",indq+2);
	quad("BR","","",x);
	x[0]='\0';

	//tempC=TRUE car exp1>exp2
	prochainEtiq=1;
	quadAFF(tempC,"TRUE");

	prochainEtiq=1;

	y=strdup(tempC);
    tempC[0]='\0';	
	return y;
}

char* quadSUPE(char* exp1,char* exp2)
{
	char x[12],*y;

	//creer un temp de resultat finale
	sprintf(tempC,"^T%d",nTemp);
    nTemp++; 	

	//si exp1>=exp2 alors brancher dans tempC=TRUE 
	sprintf(x,"%d",indq+3);
	quad("BGE",exp1,exp2,x);
	x[0]='\0';

	//si exp1<exp2 alors tempC=FALSE 
    quadAFF(tempC,"FALSE");

	//brancher dans l'instruction suivante
    sprintf(x,"%d",indq+2);
	quad("BR","","",x);
	x[0]='\0';

	//tempC=TRUE car exp1>=exp2
	prochainEtiq=1;
	quadAFF(tempC,"TRUE");

	prochainEtiq=1;

	y=strdup(tempC);
    tempC[0]='\0';	
	return y;
}

char* quadINF(char* exp1,char* exp2)
{
	char x[12],*y;

	//creer un temp de resultat finale
	sprintf(tempC,"^T%d",nTemp);
    nTemp++; 	

	//si exp1<exp2 alors brancher dans tempC=TRUE 
	sprintf(x,"%d",indq+3);
	quad("BL",exp1,exp2,x);
	x[0]='\0';

	//si exp1>=exp2 alors tempC=FALSE 
    quadAFF(tempC,"FALSE");

	//brancher dans l'instruction suivante
    sprintf(x,"%d",indq+2);
	quad("BR","","",x);
	x[0]='\0';

	//tempC=TRUE car exp1<exp2
	prochainEtiq=1;
	quadAFF(tempC,"TRUE");

	prochainEtiq=1;

	y=strdup(tempC);
    tempC[0]='\0';	
	return y;
}

char* quadINFE(char* exp1,char* exp2)
{
	char x[12],*y;

	//creer un temp de resultat finale
	sprintf(tempC,"^T%d",nTemp);
    nTemp++; 	

	//si exp1<=exp2 alors brancher dans tempC=TRUE 
	sprintf(x,"%d",indq+3);
	quad("BLE",exp1,exp2,x);
	x[0]='\0';

	//si exp1>exp2 alors tempC=FALSE 
    quadAFF(tempC,"FALSE");

	//brancher dans l'instruction suivante
    sprintf(x,"%d",indq+2);
	quad("BR","","",x);
	x[0]='\0';

	//tempC=TRUE car exp1<=exp2
	prochainEtiq=1;
	quadAFF(tempC,"TRUE");

	prochainEtiq=1;

	y=strdup(tempC);
    tempC[0]='\0';	
	return y;
}

char* quadEGA(char* exp1,char* exp2)
{
	char x[12],*y;

	//creer un temp de resultat finale
	sprintf(tempC,"^T%d",nTemp);
    nTemp++; 	

	//si exp1==exp2 alors brancher dans tempC=TRUE 
	sprintf(x,"%d",indq+3);
	quad("BE",exp1,exp2,x);
	x[0]='\0';

	//si exp1!=exp2 alors tempC=FALSE 
    quadAFF(tempC,"FALSE");

	//brancher dans l'instruction suivante
    sprintf(x,"%d",indq+2);
	quad("BR","","",x);
	x[0]='\0';

	//tempC=TRUE car exp1==exp2
	prochainEtiq=1;
	quadAFF(tempC,"TRUE");

	prochainEtiq=1;

	y=strdup(tempC);
    tempC[0]='\0';	
	return y;
}

char* quadDIF(char* exp1,char* exp2)
{
	char x[12],*y;

	//creer un temp de resultat finale
	sprintf(tempC,"^T%d",nTemp);
    nTemp++; 	

	//si exp1!=exp2 alors brancher dans tempC=TRUE 
	sprintf(x,"%d",indq+3);
	quad("BNE",exp1,exp2,x);
	x[0]='\0';

	//si exp1==exp2 alors tempC=FALSE 
    quadAFF(tempC,"FALSE");

	//brancher dans l'instruction suivante
    sprintf(x,"%d",indq+2);
	quad("BR","","",x);
	x[0]='\0';

	//tempC=TRUE car exp1!=exp2
	prochainEtiq=1;
	quadAFF(tempC,"TRUE");

	prochainEtiq=1;

	y=strdup(tempC);
    tempC[0]='\0';	
	return y;
}

void quadBR_FIN_THEN(char* temp)
{
	char x[12];

	sprintf(x,"%d",indq);
	empiler(x);

	quad("BZ",temp,"","");
}

void quadBR_FIN_IF()
{
	char x[12];

	sprintf(x,"%d",indq);
	empiler(x);
	
	quad("BR","","","");
	
	prochainEtiq=1;
}

void remplir_FIN_THEN()
{
	char x[12];
	int i=atoi(depiler());
	sprintf(x,"%d",indq+1);
	getQuad(i)->res=strdup(x);
}

void remplir_FIN_IF()
{
	char x[12];
	int i=atoi(depiler());
	sprintf(x,"%d",indq);
	getQuad(i)->res=strdup(x);
	prochainEtiq=1;
}

void sauvDEB_WHILE()
{
	char x[12];

	sprintf(x,"%d",indq);
	empiler(x);
	prochainEtiq=1;
}

void quadBR_DEB_WHILE(char* temp)
{
	char x[12];
	int i=atoi(depiler());
	sprintf(x,"%d",i);
	quad("BNZ",temp,"",x);
}

void quadBR_FIN_FOR(char* var,char* until)
{
	char x[12];

	//sauvegarder la position de ce quad
	sprintf(x,"%d",indq);
	empiler(x);	

	prochainEtiq=1;

	//si var>until alors brancher dans fin de for
	quad("BG",var,until,"");
	
	//sauvgarder Var et Until
	empiler(var);
	empiler(until);		
}

void quadBR_DEB_FOR()
{
	char *var,*until,*y,*x;
	int i;

	//récuperer var et until de for
	until=depiler();
	var=depiler();

	//récuperer l'indice de quad de debut de for
	x=depiler();	

	//var=var+1
	y=quadARTH("+",var,"1");
	quadAFF(var,y);

	//brancher dans debut de for 
	quad("BR","","",x);

	//remplir la position de fin for dans le debut de for
	i=atoi(x);
	sprintf(x,"%d",indq);
	getQuad(i)->res=strdup(x);

	prochainEtiq=1;
}

void quadOUT(int i,char *str,char *var)
{
	if(strlen(str)!=0&&i!=-1)
	{
		//enlever le signe s'il existe
		str=supp_char(str,i);
	}
	quad("OUT",str,var,"");
}

void quadIN(int i,char *var,char *str)
{
	char* x;

	if(strlen(str)!=0)
	{
		quadOUT(i,str,"");
	}
	quad("IN","","",var);
}

void afficherQUAD()
{ 
	int i;
	quadruplet *q=teteQ;
	while(q!=NULL)
	{
		if(q->i==-1) printf("**");
		else printf("%d",q->i);
		printf("-( %s , %s , %s , %s ) etiq=%d\n",q->opr,q->op1,q->op2,q->res,q->etiq);
		q=q->svt;
	}
}
