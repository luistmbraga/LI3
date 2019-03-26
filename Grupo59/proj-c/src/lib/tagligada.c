#include <libxml/parser.h>
#include <libxml/xmlmemory.h>
#include "tagligada.h"
#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "list.h"


struct tag{
	xmlChar* tagName;
	long id;
	struct tag *prox;
};

LTag get_Tag (LTag t, long i){
		LTag aux = t;
		while(aux != NULL){
			if (aux->id == i) return aux;
			if (aux->id > i) return NULL;
			aux = aux->prox;
		}
		return NULL;
	}

char* get_TagName (LTag t, long i){
		LTag aux = t;
		while(aux != NULL){
			if (aux->id == i) return(mystrdup((const char *)aux->tagName));
			if (aux->id > i) return NULL;
			aux = aux->prox;
		}
		return NULL;
}

void set_Tag(LTag *t, long i, xmlChar *tn){
		LTag new;
		while(*t)
			t = &((*t)->prox);
		new = (LTag) malloc(sizeof (struct tag));
		new->id = i;
		new->tagName = malloc (sizeof (xmlStrlen(tn)));
		new->tagName = xmlStrndup(tn, xmlStrlen(tn));
		new->prox = *t;
		*t = new;
}
void insert_Tag(LTag *t, char *aux){
	while(*t && xmlStrcmp((*t)->tagName, (const xmlChar *)aux) != 0)
		t = &((*t)->prox);
	if(*t) (*t)->id++;
	else{
		LTag new = malloc(sizeof(struct tag));
		new->id = 1;
		new->tagName = (xmlChar*)aux;
		new->prox = NULL;
		(*t) = new;
	}
}

LTag maisUsada(LTag *d){
	LTag *aux; 
	LTag *r;
	LTag new = NULL;
	aux = d;
	long i = 0;
	while(*aux){
		long mayused = (*aux)->id;
		if (mayused > i) {i = mayused; r = aux;}
		aux = &((*aux)->prox);
	}
	new = *r;
	new->prox = NULL;
	*r = (*r)->prox;
	return new;

}

void insertOrd_tagused(LTag *resultado, LTag tag, int N){
	LTag aux = tag;
	for (int i = 0; aux && i < N; i++){
		*resultado = maisUsada(&aux);
		resultado = &((*resultado)->prox);
	}
}

long procuraID(LTag t, xmlChar* tag){
	LTag aux = t;

	while(aux && xmlStrcmp(aux->tagName, tag) != 0)
		aux = aux->prox;
	if(aux != NULL) return aux->id;
	return 0;
}

void procura_insert_ID(LTag tags, LTag maisusadas, int N, LONG_list *r){
	LTag aux = tags;
	for(int i = 0; maisusadas && i < N; i++){
			//printf("%s\n", maisusadas->tagName);
	 		set_list(*r, i, procuraID(aux, maisusadas->tagName));
	 		maisusadas = maisusadas->prox;
	 }
}

void clean_Tags(LTag l){
	LTag *lp1;
	while(l){
		lp1=&(l->prox);
		xmlFree(l->tagName);
		free(l);
		l = *lp1;
	}
}
