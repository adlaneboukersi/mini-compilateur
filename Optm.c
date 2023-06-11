#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Optm.h"

extern nTemp;
int nExpIn=1;

int est_nbr(char* num)//pour vérifier s'il est un nombre
{
	return (num[0]>='0'&&num[0]<='9')||num[0]=='-';
}

int est_var(char* var)//pour vérifier s'il est une variable
{
	//la variable n'est pas TRUE ou FALSE et elle ne commence pas par ^ et elle commence par lettre 
	return strcmp(var,"TRUE")!=0&&strcmp(var,"FALSE")!=0&&var[0]!='^'&&var[0]>='A'&&var[0]<='z';
}

int est_tab(char* op)//pour vérifier s'il est une variable
{
	int i=0;
	while(op[i]!='\0'&&op[i]!='[') i++;
	if(op[i]!='\0') return 1; 
	return 0;
}

int est_tmp(char* temp)//pour vérifier s'il est un tempon
{
	return temp[0]=='^';
}



int comparer(char* s1,char* s2)//comparer le resultat d'un quad avec le nom d'une variable
{
	if(est_tab(s1)) return 1;//on ne compare pas avec tableau à cause de traitement d'indice
	return strcmp(s1,s2);
}



char* recreer_exp(char* temp)//elle recree l'exp d'un tempon se forme postfixee
{
	char exp[50]="[";
	quadruplet *q;
	if(est_tmp(temp))
	{
		q=getQuad2(strdup(temp));//rechercher le quad qui creer le tempon

		strcat(exp,recreer_exp(q->op1));//mettre l'exp de l'op1 dans exp
		exp[strlen(exp)]=',';
		strcat(exp,recreer_exp(q->op2));//mettre l'exp de l'op2 dans exp
		exp[strlen(exp)]=',';
		strcat(exp,q->opr);//mettre operateur dans exp
		exp[strlen(exp)]=']';
		return strdup(exp);
	}
	else if(est_var(temp))//s'il est une variable
	{
		return strdup((get_obj(temp)->exp));//retour l'exp de la var
	}
	else// il est une val
	{
		return strdup(temp);
	}
}

char* creer_exp_in()//elle cree une valeur pour IN
{
	char y[12];
	sprintf(y,"IN%d",nExpIn);
	nExpIn++;
	return strdup(y);
}



char*  simpl_alg_calc_inut(quadruplet *q)//simplifier les calculs inutile
{
	//p est le precedent de que 
	quadruplet *p=q->prd;

	//p: T2=T1+1 et q: T3=T2-1 ===> eliminer p et eliminer q et utiliser T1 directement dans q->svt
	if(est_tmp(q->op1)&&est_nbr(q->op2))//q->op1==T2
	{
		//si l'opration de q est l'inverse de p
		if((p->opr[0]=='+'&&q->opr[0]=='-')||(p->opr[0]=='-'&&q->opr[0]=='+')||(p->opr[0]=='*'&&q->opr[0]=='/')||(p->opr[0]=='/'&&q->opr[0]=='*'))
		{
			if(strcmp(q->op2,p->op1)==0)//q->op2==p->op1==le nombre     dans l'exmple precedent est 1
			{
				//eliminer ces quads
				p->i=-1; 
				q->i=-1;
				return strdup(p->op2);//retourner T1
			} 
			else if(strcmp(q->op2,p->op2)==0)//q->op2==p->op2==le nombre     dans l'exmple precedent est 1
			{
				//eliminer ces quads
				p->i = -1;
				q->i = -1;
				return strdup(p->op1);//retourner T1
			}
		}
	}
	else if(est_tmp(q->op2)&&est_nbr(q->op1))//q->op2==T2
	{
		//si l'opration de q est l'inverse de p
		if((p->opr[0]=='+'&&q->opr[0]=='-')||(p->opr[0]=='-'&&q->opr[0]=='+')||(p->opr[0]=='*'&&q->opr[0]=='/')||(p->opr[0]=='/'&&q->opr[0]=='*'))
		{
			if(strcmp(q->op1,p->op1)==0)//q->op1==p->op1==le nombre     dans l'exmple precedent est 1
			{
				//eliminer ces quads
				p->i = -1;
				q->i = -1;
				return strdup(p->op2);//retourner T1
			} 
			else if(strcmp(q->op1,p->op2)==0)//q->op1==p->op1==le nombre     dans l'exmple precedent est 1
			{
				//eliminer ces quads
				p->i = -1;
				q->i = -1;
				return strdup(p->op1);//retourner T1
			}
		}
	}
	return strdup(q->res);//sinon retourner le res de pour ne change rien 
}



elem* find_var_exp(char* exp)//pour avoir la variable qu'elle contient l'exp
{
	int i=0;
	elem* p;
	while(i<taille)
	{
		if(TS[i]!=NULL)
		{
			p=TS[i];
			while(p!=NULL)
			{
				if(strcmp(p->exp,exp)==0)
				{
					return p;
				}
				else
				{
					p=p->svt;
				}
			}
		}
		i++;
	}
	return NULL;
}

void  supp_quads(char* temp)//pour eliminer les quads  qui calculer ce tempon
{
	quadruplet *q;

	q=getQuad2(temp);//rechercher le quad qui creer ce tempon
	q->i = -1;		 // eliminer ce quad

	if(est_tmp(q->op1))//eliminer les quads qui creer les tempons utiliser dans q  
	{
		supp_quads(q->op1);
	}
	else if(est_var(q->op1))//si op1 est une variable
	{
		(get_obj(q->op1)->nbrUse)--;
	}

	if(est_tmp(q->op2))//eliminer les quads qui creer les tempons utiliser dans q
	{
		supp_quads(q->op2);
	}
	else if(est_var(q->op2))//si op2 est une variable
	{
		(get_obj(q->op2)->nbrUse)--;
	}	
}

char* elimin_exps_redond(char* exp,char* temp)//eliminer les exps redondants
{
    elem* var;
    if((var=find_var_exp(exp))!=NULL)//s' il existe une var contenir cette exp
    {
        supp_quads(temp);//supprimer les quad de calcul temp
        (var->nbrUse)++;
        return strdup(var->nom);//retour le nom de variable qui contenir cette exp
    }
    else//s'il n'est pas un tempon ne fait rien 
    {
		return temp;
    }
}



void ajuster_exps()
{
	quadruplet *q=teteQ;
	char* exp;
	elem *adr;
	while(q!=NULL)
	{
		//si le precedent de q est un quad arth alors on vérifier si on peut simplifier les calc inutiles 
		if(q->prd!=NULL&&((q->prd)->opr[0]=='+'||(q->prd)->opr[0]=='-'||(q->prd)->opr[0]=='*'||(q->prd)->opr[0]=='/'))
		{
			if(strcmp(q->op1,"")!=0&&est_tmp(q->op1)&&strcmp(q->op1,(q->prd)->res)==0)
			{
				q->op1=simpl_alg_calc_inut(q->prd);
			}
			else if(strcmp(q->op2,"")!=0&&est_tmp(q->op2)&&strcmp(q->op2,(q->prd)->res)==0)
			{
				q->op2=simpl_alg_calc_inut(q->prd);
			}			
		}
		adr=get_obj(q->res);
		//si on affecte à une var alors eliminer les exps redo et sauvegarder l'exp pour la var 
		if(strcmp(q->opr,"AFF")==0&&est_var(q->res)&&adr->type<3)
		{
			if(est_tmp(q->op1))
			{
				exp=recreer_exp(q->op1);
				q->op1=elimin_exps_redond(exp,q->op1);
				adr->exp=exp;
			}
			else 
			{
				adr->exp=q->op1;
			}
		}
		else if(strcmp(q->opr,"IN")==0)
		{
			adr->exp=creer_exp_in();//pour attribuer un valeur dans le res
		}
		q=q->svt;
	}
}



void trt_elimin_prpg_exps(elem *var)
{
	//var est une variable utiliser une seule fois donc on va le remplacer avec son exp 
	char* tempExp;
	quadruplet *q=teteQ;
	while(q!=NULL)
	{
		//si quad n'est pas eliminer et opr est AFF et le resultat est la variable var
		if(strcmp(q->opr,"AFF")==0&&comparer(q->res,var->nom)==0)
		{
			tempExp=strdup(q->op1);//sauvgarder le temp d'exp affecter pour la var
			q->i = -1;			   // eliminer le quad d'aff
		}
		else //si le quad n'est pas aff
		{
			if(comparer(q->op1,var->nom)==0)//si op1 est var
			{
				q->op1=tempExp;
				(var->nbrUse)--;
				break;
			}
			else if(comparer(q->op2,var->nom)==0)//si op2 est var 
			{
				q->op2=tempExp;
				(var->nbrUse)--;
				break;
			}
		}
		q=q->svt;
	}
}



void  elimin_prpg_exps()//eliminer les propagtions des exps
{
	elem *p,*q;
	int i;
		for(i=0;i<taille;i++)
		{	
			if (TS[i]!=NULL)
			{
				q=NULL;
				p=TS[i]; 
				while(p!=NULL) 
				{
					if(p->nbrUse==1)//si var est utilisé une seule fois  
					{
						trt_elimin_prpg_exps(p);
					}
					q=p;
					if(p!=NULL)p=p->svt;
				}
			}
		}
}



int test_condt_prpg_copies(quadruplet *r,elem *var1,elem *var2)
{
	return (strcmp(r->opr,"IN")!=0&&strcmp(r->opr,"AFF")!=0)  ||
	       (comparer(r->res,var1->nom)!=0&&comparer(r->res,var2->nom)!=0);
}

void  elimin_prpg_copies()//eliminer les propagtions des copies
{
	elem *var1=NULL,*var2=NULL;
	quadruplet *q=teteQ,*r;
	while(q!=NULL)
	{
		//si opr est aff et op1 est une var et res est une var et op1!=res		
		if(strcmp(q->opr,"AFF")==0&&est_var(q->op1)&&!est_tab(q->op1)&&
		    est_var(q->res)&&!est_tab(q->res)&&strcmp(q->op1,q->res)!=0)
		{
			var1=get_obj(q->res);//t1
			var2=get_obj(q->op1);//t2
			r=q->svt;
			while(r!=NULL&&test_condt_prpg_copies(r,var1,var2))//pour remplacer les var2 dans les quads par var1 tantque les valeurs de var1 et var2 non pas changer
			{
				if(comparer(r->op1,var2->nom)==0)//si op1==var2 remplacer var2 par var1
				{
					r->op1=strdup(var1->nom);
					(var1->nbrUse++);
					(var2->nbrUse--);
				}
				else if(comparer(r->op2,var2->nom)==0)//si op2==var2 remplacer var2 par var1  
				{
					r->op2=strdup(var1->nom);
					(var1->nbrUse++);
					(var2->nbrUse--);
				}
				
				r=r->svt;
			}
			var1=NULL;
			var2=NULL;
		}
		q=q->svt;
	}
}



void trt_simpl_alg_mul(quadruplet *q,char* op1,char* op2)
{
	int i,iop1=atoi(op1);
	char  tempC[12],*res=strdup(q->res);
	quadruplet* p;

	if(iop1>1)//il ne doit pas egale à 1 car var*1=var
	{
		op1=strdup(op2);//op1 sera prendre la somme des op2
		for(i=1;i<iop1;i++)
		{
			q=insertQuadAfter(q);//inserer un nouveau quad

			//ce quad est (somme des op2)+op2
			q->opr="+";
			q->op1=strdup(op1);
			q->op2=strdup(op2);

			//pour ne pas changer les autres quads il faut que le dernier quad utilise le tempon de quad déja eliminer
			if(i+1==iop1)
			{
				q->res=strdup(res);
			}
			else
			{
				//creer nouveau tempon pour ce nouveau quad
				sprintf(tempC,"^T%d",nTemp);
				q->res=strdup(tempC);
				nTemp++;
				tempC[0]='\0';			
			}

			q->i=indq;
			indq++;	

			//pour sauvegarder dans op1 la somme des op2
			op1=q->res;		
		}
	}
	else if(iop1==1)
	{
		p=q->svt;
		while(p!=NULL)
		{
			if(strcmp(res,(p)->op1)==0)
			{
				(p)->op1=op2;
			}
			if(strcmp(res,(p)->op2)==0)
			{
				(p)->op2=op2;
			}
			p=p->svt;
		}
	}	
}

void simpl_alg_mul()//simplifier les multiplications
{
	quadruplet *q=teteQ;
	while(q!=NULL)
	{
		//si quad est non eliminer et opr est * et (op1 est un nombre ou op2 est un nombre)
		if(strcmp(q->opr,"*")==0&&(est_nbr(q->op1)||est_nbr(q->op2)))
		{
			if(est_nbr(q->op1)&&est_nbr(q->op2))
			{
				if(atoi(q->op2)<atoi(q->op1)&&q->op1[0]!='-')
				{
					q->i = -1;
					trt_simpl_alg_mul(q,q->op2,q->op1);					
				}
				else if(atoi(q->op1)<atoi(q->op2)&&q->op2[0]!='-')
				{
					q->i = -1;
					trt_simpl_alg_mul(q,q->op1,q->op2);
				}
			}
			else if(est_nbr(q->op1)&&q->op1[0]!='-')
			{
				q->i = -1;
				trt_simpl_alg_mul(q,q->op1,q->op2);
			}
			else if(q->op2[0]!='-')
			{
				q->i = -1;
				trt_simpl_alg_mul(q,q->op2,q->op1);
			}
		}
		q=q->svt;
	}	
}



void supp_ele(elem **p,elem **q,int i)//supp un ele de la liste
{
	if(*q==NULL)
	{
		TS[i]=(*p)->svt;
		free(*p);
		*q=NULL;
		*p=TS[i];
	}
	else
	{
		(*q)->svt=(*p)->svt;
		free(*p);
		*p=(*q)->svt;
	}	
}

void trt_elimin_code_inut(elem *var)
{
	//var est une variable jamais utiliser
	char* tempExp;
	quadruplet *q=teteQ;
	while(q!=NULL)
	{
		if(q->i!=-1&&strcmp(q->opr,"AFF")==0&&strcmp(get_tabName(q->res),var->nom)==0)
		{
			q->i = -1; // eliminer le quad d'aff nbr
		}
		q=q->svt;
	}
}

void  elimin_code_inut()//eliminer les codes inutiles
{
	elem *p,*q;
	int i;
	for(i=0;i<taille;i++)
	{	
		if (TS[i]!=NULL)
		{
			q=NULL;
			p=TS[i]; 
			while(p!=NULL) 
			{
				if(p->nbrUse==0)//si var n'est pas utilisé
				{
					trt_elimin_code_inut(p);
					supp_ele(&p,&q,i);//supp la variable
				}
				else
				{
					q=p;
					p=p->svt;
				}
			}
		}
	}
}



void  appliquer_elimin_quads()
{
	quadruplet *q=teteQ,*p;
	while(q!=NULL)
	{
		if(q->i==-1)
		{
			p=q;
			q=q->svt;
			suppQuad(&p);
		}
		else
		{
			q=q->svt;
		}
		
	}	
}



void optimisation()
{
	ajuster_exps();
	appliquer_elimin_quads();
	elimin_prpg_exps();
	appliquer_elimin_quads();
	elimin_prpg_copies();
	appliquer_elimin_quads();
	elimin_code_inut();
	appliquer_elimin_quads();
	simpl_alg_mul();
	appliquer_elimin_quads();
}











