#include "common.h"
#include <stdio.h>
#include <stdlib.h>
#include "Users.h"
#include "common.h"
#include "DateList.h"

/* Array da sub estrutura users */
struct users{
	xmlChar* shortbio;    			/* xmlChar correspondente a short bio */ 	
	xmlChar* displayname;			/* xmlChar correspondte ao display name */
	xmlChar* reputation;			/* xmlChar corresponde a reputação */
	int nposts;						/* int correspondente ao número de posts */
	LDate posts; 					/* Lista ligada com os posts de cada user */
};

char* getSBio(Users u){
	return(mystrdup((const char *)u->shortbio));
}

char* getDisplayName(Users u){ 
	return(mystrdup((const char *) u->displayname));
} 

long getReputation(Users u){ 
	return (strtol((const char* restrict )u->reputation,NULL,0));
}

int getNPosts(Users u){
	return u->nposts;
}

LDate getPosts_user(Users u){
	LDate r = datecpy(u->posts);
	return r;
}

long getPostDateID(Users u, int i){
	return getID(u->posts, i);
}
void set_Post_User(Users *u, long i, xmlChar* d){
	setDate((&((*u)->posts)), i, d);
	((*u)->nposts)++;
}

void set_User(Users *u, xmlChar* a, xmlChar* b, xmlChar* c){
	*u = malloc(sizeof (struct users));
		
	(*u)->shortbio = (malloc (sizeof (xmlStrlen(a))));
	(*u)->shortbio = xmlStrndup(a, xmlStrlen(a));
		
	(*u)->displayname = (malloc (sizeof (xmlStrlen(b))));
	(*u)->displayname = xmlStrndup(b, xmlStrlen(b));
		
	(*u)->reputation = (malloc (sizeof (xmlStrlen(c))));
	(*u)->reputation = xmlStrndup(c, xmlStrlen(c));
		
	(*u)->nposts = 0;
	(*u)->posts = NULL;
}

void cleanUser(Users *u){
	if(*u){
			if((*u)->shortbio) xmlFree((*u)->shortbio);

			if((*u)->displayname) xmlFree((*u)->displayname);

			if((*u)->reputation) xmlFree((*u)->reputation);

			freeLDate((*u)->posts);
	}
			free(*u);
}
