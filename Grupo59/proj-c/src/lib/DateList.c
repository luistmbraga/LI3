#include <libxml/parser.h>  
#include <libxml/xmlmemory.h>
#include <string.h>
#include "DateList.h"


struct datelist{
	long id;
	xmlChar *date;
	struct datelist* prox;
};

void initDate(LDate *data){
	*data = NULL;
}

long getID(LDate data, int i){
	for(int j = 0; data && j < i; j++)
		data = data->prox;

	if(data) return data->id;
	else return -1;
}
LDate* GetheadID(LDate *data, long *id){
	long r = -1;

	if(*data) r = (*data)->id;
	
	*id = r;
	return &((*data)->prox);
}

xmlChar* getDate(LDate data, long i){
	while(i != data->id)
		data = data->prox;
	if (data == NULL) return NULL;
	else return xmlStrndup(data->date, xmlStrlen(data->date));
}

void setDate(LDate *data, long i, xmlChar* d){
		LDate new;
		while(*data && xmlStrcmp(d, (*data)->date) <= 0)
			data = &((*data)->prox);
		new = (LDate) malloc (sizeof (struct datelist));
		new->id = i;
		new->date = malloc (sizeof (xmlStrlen(d)));
		new->date = xmlStrndup(d, xmlStrlen(d));
		new->prox = *data;
		*data = new;
}

LDate datecpy(LDate d){
	LDate r = NULL;
	LDate aux2 = d;
	if (aux2 != NULL){
		LDate aux;
		r = malloc (sizeof (struct datelist));
		r->id = aux2->id;
		r->date = malloc (sizeof (xmlStrlen(aux2->date)));
		r->date = xmlStrndup(aux2->date, xmlStrlen(aux2->date));
		r->prox = NULL;
		aux = r;
		aux2 = aux2->prox;
		while(aux2 != NULL){
			aux->prox = malloc(sizeof(struct datelist));
			aux->prox->id = aux2->id;
			aux->date = malloc (sizeof (xmlStrlen(aux2->date)));
			aux->date = xmlStrndup(aux2->date, xmlStrlen(aux2->date));
			aux->prox->prox = NULL;
			aux2 = aux2->prox;
			aux = aux->prox;
		}
	}
	return r;
}

int pertence(long id, LDate d){
	while(d && id != d->id)
		 d = d->prox;

	return(d != NULL);
}

long* dateToArray(LDate beg, long size){
	long* r = malloc(sizeof(long)*size);
	for(long i = 0; i < size; i++){
		r[i] = beg->id;
		beg = beg->prox;
	}
	return r;
}
// testar se as datas estao direitas
long* getIntervalo(LDate d, char* begin, char* end, long *size){
	if (strcmp(begin, end) <= 0){
		long i = 0;
		LDate aux,ant,aux2;
		aux = d;
		
		while(aux && xmlStrncasecmp(aux->date, (const xmlChar *) end, 10) > 0)
				aux = aux->prox;

	
		aux2 = aux;
		ant = NULL;
		while(aux2 && xmlStrncasecmp(aux2->date, (const xmlChar *) begin, 10) >= 0){
			ant = aux2;
			aux2 = aux2->prox;
			i++;
		}
		if (ant == NULL) return NULL;
		else {
			*size = i;
			return dateToArray(aux, i);
		}
	}

	else return NULL;

}

void freeLDate(LDate posts){
	LDate *lp1;
	while(posts){
		lp1=&(posts->prox);
		xmlFree(posts->date);
		free(posts);
		posts = *lp1;
	}
}
