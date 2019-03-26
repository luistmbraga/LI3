#include <stdio.h> 
#include <stdlib.h> 
#include "interface.h" 
#include "community.h"

//Funcao que carrega os posts numa hash (simultaneamente carrega a lista de ids de posts ordenada por cronologia inversa), carrega os posts de cada user por cronologia inversa
TAD_community loadPosts(TAD_community com, char* dump_path){

	char *stackover;
	stackover = mystrdup(dump_path);

	//Criacao do pointer para o documento
	xmlDocPtr doc = xmlParseFile(strcat( stackover, "Posts.xml"));
	xmlNodePtr cur, aux; 
	long pai, i, id, PouR;
	long sizeP = com->sizeP;
	TAD_community r = com;

	if (!doc) { 
		fprintf(stderr,"Falha no parse no documento. \n"); 
	}

	cur = xmlDocGetRootElement(doc); 

	if (!cur) { 
		fprintf(stderr,"Documento não preenchido! \n");
	}																		 
	
	cur = cur->xmlChildrenNode; 
	cur = cur->next;
	aux = cur;
	
	while(aux->next!=NULL){

		if(!xmlStrcmp(aux->name,(const xmlChar *) "row")){
			i = strtol((const char* restrict) (xmlGetProp(aux, (const xmlChar *) "Id")), NULL, 0); 
			PouR = strtol ((const char* restrict) (xmlGetProp(aux, (const xmlChar *) "PostTypeId")), NULL, 0);

			if (PouR == 1 || PouR == 2){
				if(PouR==1){
					setPostPer(&(com->posts[i-1]), 
							xmlGetProp(aux, (const xmlChar *) "Title"), 
							xmlGetProp(aux, (const xmlChar *) "Tags"), 
							xmlGetProp(aux, (const xmlChar *) "CreationDate"));
				}
				else{
					setPostRes(&(com->posts[i-1]), 
						xmlGetProp(aux, (const xmlChar *) "ParentId"), 
						strtol((const char* restrict) (xmlGetProp(aux, (const xmlChar *) "Score")), NULL, 0), 
						strtol((const char* restrict) (xmlGetProp(aux, (const xmlChar *) "CommentCount")), NULL, 0));
				}
				xmlChar *d;
				setDate((&(com->datas)), i, d = xmlGetProp(aux, (const xmlChar *) "CreationDate"));
				xmlChar *u = xmlGetProp(aux, (const xmlChar *) "OwnerUserId");
				setPostU(&(com->posts[i-1]), u);

				id = strtol((const char* restrict) u, NULL, 0);
				xmlFree(u);

				if (id > 0) {
						if (com->users[id]) set_Post_User(&(com->users[id]), i, d);
				}
				else {		
					if (com->users[0]) set_Post_User(&(com->users[0]), i, d);
				}
			}
		}
	aux = aux->next;
	}

	for(long j = 1; j <= sizeP; j++){
		if (com->posts[j-1] && temParentID(com->posts[j-1])){
				//pai = GetParentId(com, j);
				pai = getParentID(com->posts[j-1]);
					if (com->posts[pai-1]){
						//adicionaResAPergunta(&com, j, pai);
						setRespAPer(&(com->posts[pai-1]), j);
					}
		}
	}
 
	xmlFreeDoc(doc);

	return r;

}

//Carrega a hash dos users
TAD_community loadUsers(TAD_community com, char* dump_path){
	
	char *stackover;
	stackover = mystrdup(dump_path);

	//Criacao do pointer para o documento
	xmlDocPtr doc = xmlParseFile(strcat(stackover, "Users.xml"));
	xmlNodePtr cur, aux; 
	long i;
	TAD_community r = com; 

	if (!doc) { 
		fprintf(stderr,"Falha no parse no documento. \n"); 
	}


	cur = xmlDocGetRootElement(doc); 

	if (!cur) { 
		fprintf(stderr,"Documento não preenchido! \n");
	}																		 
	
	cur = cur->xmlChildrenNode; 
	cur = cur->next;
	aux = cur;
	
	set_User(&(com->users[0]), 
		xmlGetProp(aux, (const xmlChar *) "AboutMe"), 
		xmlGetProp(aux, (const xmlChar *) "DisplayName"), 
		xmlGetProp(aux, (const xmlChar *) "Reputation"));

	aux = aux->next;

	while(aux->next != NULL){
		if(!xmlStrcmp(aux->name,(const xmlChar *) "row")){
			xmlChar *key = xmlGetProp(aux, (const xmlChar *) "Id");
			i = strtol((const char* restrict) key, NULL, 0);
			xmlFree(key);

			set_User(&(com->users[i]), 
					xmlGetProp(aux, (const xmlChar *) "AboutMe"), 
					xmlGetProp(aux, (const xmlChar *) "DisplayName"), 
					xmlGetProp(aux, (const xmlChar *) "Reputation"));
		}
		aux = aux->next;
	}

		xmlFreeDoc(doc);

		return r;
}

//Carrega a lista de tags 
TAD_community loadTags(TAD_community com, char* dump_path){


	char *stackover;
	stackover = mystrdup(dump_path);

	//Criacao do pointer para o documento
	xmlDocPtr doc = xmlParseFile(strcat(stackover, "Tags.xml"));
	xmlNodePtr cur, aux; 
	long i;

	if (!doc) { 
		fprintf(stderr,"Falha no parse no documento. \n"); 
	}


	cur = xmlDocGetRootElement(doc); 

	if (!cur) { 
		fprintf(stderr,"Documento não preenchido! \n");
	}																		 
	
	cur = cur->xmlChildrenNode; 
	cur = cur->next;
	aux = cur;

	while(aux->next != NULL){
		if(!xmlStrcmp(aux->name,(const xmlChar *) "row")){
			xmlChar *key = xmlGetProp(aux, (const xmlChar *) "Id");
			i = strtol((const char* restrict) key, NULL, 0);
			xmlFree(key);

			//setTag(&com, i, xmlGetProp(aux, (const xmlChar *) "TagName"));
			set_Tag(&(com->tags), i, xmlGetProp(aux, (const xmlChar *) "TagName"));
			com->sizeT++;
		}
		aux = aux->next;
	}

	xmlFreeDoc(doc);

	return com;

}

//Funcao que tem como resultado o id do ultimo user
long tamUsers(char* dump_path){

	char *stackover;
	stackover = mystrdup(dump_path);

	xmlDocPtr docU = xmlParseFile(strcat(stackover, "Users.xml"));
	xmlNodePtr curU, auxU; 
	xmlChar *keyU;
	long r;

	if (!docU) { 
		fprintf(stderr,"Falha no parse no documento. \n"); 
	}

	curU = xmlDocGetRootElement(docU); 

	if (!curU) { 
		fprintf(stderr,"Documento não preenchido! \n");
	}																		 
	
	curU = curU->xmlChildrenNode; 
	curU = curU->next;
	auxU = curU;

	while(auxU->next->next!=NULL) auxU = auxU->next;

	keyU = xmlGetProp(auxU, (const xmlChar *) "Id");

	r = strtol( (const char* restrict)keyU, NULL, 0);

	xmlFree(keyU);
	xmlFreeDoc(docU);

	return r;

}

//Funcao que retorna o id do ultimo post
long tamPosts(char* dump_path){
	char *stackover;
	stackover = mystrdup(dump_path);

	xmlDocPtr docP = xmlParseFile(strcat(stackover, "Posts.xml"));
	xmlNodePtr curP, auxP; 
	xmlChar *keyP;
	long r;

	if (!docP) { 
		fprintf(stderr,"Falha no parse no documento. \n"); 
	}

	curP = xmlDocGetRootElement(docP); 

	if (!curP) { 
		fprintf(stderr,"Documento não preenchido! \n");
	}																		 
	
	curP = curP->xmlChildrenNode; 
	curP = curP->next;
	auxP = curP; 

	while(auxP->next->next!=NULL) auxP = auxP->next;
	
	keyP = xmlGetProp(auxP, (const xmlChar *) "Id");

	r = strtol( (const char* restrict)keyP, NULL, 0);

	xmlFree(keyP);
	xmlFreeDoc(docP);

	return r;

}

TAD_community init()
{	
	TAD_community com;
	com = initMyEstrutura();
	return com;
}

TAD_community load(TAD_community com, char* dump_path) {
	long sizeU = tamUsers(dump_path);

	long sizeP = tamPosts(dump_path);

	com = loadMyEstrutura(sizeU+1, sizeP);

	com = loadUsers(com, dump_path); // Carregar a estrutura dos Users.
	
	com = loadPosts(com, dump_path); // Carregar a estrutra dos Posts e finalizar a dos Users.

	com = loadTags(com, dump_path);

	return com;	
}

