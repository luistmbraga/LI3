#include <stdio.h>
#include <stdlib.h>
#include "commonligada.h"

struct commonligada{
	long id;
	long common;
	struct commonligada* prox;
};

void create_LDLong(LDLong* l){
	(*l) = malloc(sizeof(struct commonligada));
}

long get_id_common(LDLong u){
	return u->id;
}

long get_common(LDLong u){
	return u->common;
}

long get_ultimoCommon(LDLong l){
	LDLong aux = l;
	while(aux->prox)
		aux = aux->prox;

	return aux->common;
}

void set_id_common(LDLong* u, long id){
	(*u)->id = id;
}

void set_common(LDLong* u, long common){
	(*u)->common = common;
}

void set_LDLprox(LDLong* l, LDLong proxi){
	(*l)->prox = proxi;
}

LDLong avancaCommon(LDLong u){
	return u->prox;
}

LDLong* avancaEndCommon(LDLong* u){
	return &((*u)->prox);
}

long inserOrdcommon(LDLong* l, long i, int common){
	LDLong new;
		
	while(*l && (*l)->common > common)
		l = &((*l)->prox);
	new = malloc(sizeof(struct commonligada));
	new->id = i;
	new->common = common;
	new->prox = *l;
	set_LDLprox(&new, *l);
	*l = new;

	return get_ultimoCommon(*l);
}

void rmUltimol(LDLong* l){
	while(*l && (*l)->prox)
		l = &((*l)->prox);
	if(*l){
		free(*l);
		*l = NULL;
	}
}

void LDLtoLL(LONG_list r, LDLong *l, int N){
	int  i;
	for(i = 0; *l; i++){
		if ((*l)->id == 0) set_list(r, i, -1);
		else set_list(r, i, (*l)->id);
		l = &((*l)->prox);
	}

	while(i < N)
		set_list(r, i++, -2);
}

void freeLcommon(LDLong l){
	LDLong *l1;
	while(l){
		l1=&(l->prox);
		free(l);
		l = *l1;
	}
}