#include <stdio.h>
#include <stdlib.h>
#include "lligada.h"


/* Lista ligada da sub estrutura da sub estrutura do posts */
struct lligada{
	long id;						/* id correspondente a identificação */
	struct lligada* prox;			/* apontador para a próxima casa */
};


void setL_ID(LInt *l, long i){
	(*l)->id = i;
}

void setL_prox(LInt *l, LInt proxi){
	(*l)->prox = proxi;
}

LInt* setCaixa_Cauda(LInt *l, long id){
	*l = malloc(sizeof (struct lligada));
	(*l)->id = id;
	(*l)->prox = NULL;
	return &((*l)->prox);
}

LInt* avancaLEnder(LInt *l){
	return &((*l)->prox);
}

LInt avancaL(LInt l){
	return l->prox;
}

long getL_ID(LInt l){
	return l->id;
}

void create_List(LInt *l){
	*l = (LInt) malloc (sizeof (struct lligada));  
}

LInt listacpy(LInt l){
	LInt r = NULL;
	LInt aux2 = l;
	if (aux2 != NULL){
		LInt aux;
		r = malloc (sizeof (struct lligada));
		r->id = aux2->id;
		r->prox = NULL;
		aux = r;
		aux2 = aux2->prox;
		while(aux2 != NULL){
			aux->prox = malloc(sizeof(struct lligada));
			aux->prox->id = aux2->id;
			aux->prox->prox = NULL;
			aux2 = aux2->prox;
			aux = aux->prox;
		}
	}
	return r;
}

void LItoLDL(LONG_list r, LInt *l){
	for(long i = 0; *l; i++){
		if ((*l)->id == 0) set_list(r, i, -1);
		else set_list(r, i, (*l)->id);
		l = &((*l)->prox);
	}

}

void rmUltimo(LInt* l){
	while(*l && (*l)->prox)
		l = &((*l)->prox);
	if(*l){
		free(*l);
		*l = NULL;
	}
}

void insertHead(LInt *l, long j){
	LInt res = malloc (sizeof (struct lligada));
	res->id = j;
	res->prox = *l;
	*l = res;
}

/* Métodos de libertação de espaço */
	void freeL(LInt l){
		LInt *l1;
		while(l){
			l1=&(l->prox);
			free(l);
			l = *l1;
		}
	}