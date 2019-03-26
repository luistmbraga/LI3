#include <libxml/parser.h>  
#include <libxml/xmlmemory.h>
#include <stdio.h>
#include <stdlib.h>
#include "Post.h"
#include "common.h"
#include "lligada.h"

/* Array da sub estrutura posts */
struct posts{
	xmlChar* parentId;				/* xmlChar correspondente ao parent ID */ 
	xmlChar* titulo;				/* xmlChar correspondente ao titulo */ 
	xmlChar* userId;				/* xmlChar correspondente ao user ID */
	xmlChar* tags;					/* xmlChar correspondente as tags */
	xmlChar* date;					/* xmlChar correspondente a data */
	long scr;						/* long correspondente ao score */ 
	long ncom;						/* long correspondente ao número de comentários */
	int nresp;						/* int correspondente ao número de respostas */
	LInt resp; 						/* Lista ligada com as respostas */
};

void initPost(Posts *p){
	 *p = NULL;
}

long getParentID(Posts p){
	return(strtol((const char* restrict) p->parentId, NULL, 0));
}

char* getTitle(Posts p) { 		
	return(mystrdup((const char *) p->titulo));
}

long getUserID(Posts p){ 
	return(strtol((const char* restrict) p->userId,NULL,0));
} 

long getScr(Posts p){
	return p->scr;
}

long getNcom(Posts p){
	return p->ncom;
}

LInt getResp(Posts p){
	LInt r = listacpy(p->resp);
	return r;
}
int GetNResp(Posts p){
	return p->nresp;
}
char* get_TagsP(Posts p){
	return(mystrdup((const char *) p->tags));
}

char* get_DatePer(Posts p){
	return(mystrdup((const char *) p->date));
}

void setPostPer(Posts *p, xmlChar *t, xmlChar *tag, xmlChar *date){
		 

		*p = malloc(sizeof (struct posts));

		(*p)->titulo = (malloc (sizeof (xmlStrlen(t))));
		(*p)->titulo = xmlStrndup(t, xmlStrlen(t));

		(*p)->parentId = NULL;

		(*p)->tags = malloc (sizeof (xmlStrlen(tag)));
		(*p)->tags = xmlStrndup(tag, xmlStrlen(tag));

		(*p)->date = malloc(sizeof(10));
		(*p)->date = xmlStrsub(date, 0, 10);

		(*p)->resp = NULL;
		(*p)->nresp = 0;
		(*p)->ncom = -1;
		(*p)->scr = -1;

}

void setPostRes(Posts *p, xmlChar *s, long scr, long ncom){
	*p = malloc(sizeof (struct posts));

	(*p)->parentId = (malloc (sizeof (xmlStrlen(s))));
	(*p)->parentId = xmlStrndup(s, xmlStrlen(s));

	(*p)->titulo = NULL;
	(*p)->tags = NULL;
	(*p)->resp = NULL;
	(*p)->date = NULL;
	(*p)->nresp = -1;

	(*p)->ncom = ncom;
	(*p)->scr = scr;
}

void setPostU(Posts *p, xmlChar *u){
		(*p)->userId = malloc(sizeof (xmlStrlen(u)));
		(*p)->userId = xmlStrndup(u, xmlStrlen(u)); 
}

void setRespAPer(Posts *p, long j){
	insertHead(&((*p)->resp), j);
	(*p)->nresp++;
}

int temParentID (Posts p) { 
		return (p->parentId != NULL);
}

void cleanPost(Posts *p){
	if(*p){
		if((*p)->parentId) xmlFree((*p)->parentId);

		if((*p)->titulo) xmlFree((*p)->titulo);

		if((*p)->userId) xmlFree((*p)->userId);

		if((*p)->tags) xmlFree((*p)->tags);

		freeL((*p)->resp);

	}

	free(*p);	
}

	