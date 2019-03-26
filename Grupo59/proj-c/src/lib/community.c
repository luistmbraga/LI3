#include <libxml/parser.h>
#include <libxml/xmlmemory.h>
#include <string.h>
#include "list.h"
#include "community.h" 
#include "interface.h"
#include "common.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "lligada.h"
#include "DateList.h"
#include "Users.h"
#include "Post.h"
#include "tagligada.h"

/*
metodos usados no parse.c:
SetPostsP
SetPostsR
SetPostsUser
temUsers
adicionaPostAoUser
temParent
GetParentId
temPosts
adicionaResAPergunta
SetUser
setTag

metodos usados na queries.c:
temPosts
temParent
GetParentId
GetTitulo
GetUsrID
temUsers
GetDispName
GetShortBio
*/

	/* Inicializador da estrutura */
	TAD_community initMyEstrutura() { 
		TAD_community r;
		TAD_community a = malloc(sizeof(struct TCD_community));
		
		a->posts = NULL;
		a->users = NULL;
		a->tags = NULL;
		a->datas = NULL;

		a->sizeP = 0; 
		a->sizeU = 0;
		a->sizeT = 0;

		r = a;
	
		return r;
	}

	TAD_community loadMyEstrutura(long sizeu, long sizep) { 
		TAD_community new = malloc(sizeof(struct TCD_community));

		new->posts = malloc(sizep * sizeof(Posts));
		new->users = malloc(sizeu * sizeof(Users));
		new->datas = NULL;

		new->sizeP = sizep;
		new->sizeU = sizeu;
		new->sizeT = 0;

		for (long i = 0; i < sizep; i++)
			new->posts[i] = NULL;
		
		for (long j = 0; j < sizeu; j++) 
			new->users[j] = NULL;

		new->tags = NULL;
		
		return new;
	}

	
	void cleanUsers(TAD_community *estrutura){
		long sizeusr = (*estrutura)->sizeU;

		for(long i = 0; i < sizeusr; ++i){
			cleanUser(&((*estrutura)->users[i]));
		}
		free((*estrutura)->users);
	}

	void cleanPosts(TAD_community *estrutura){
		long sizepst = (*estrutura)->sizeP;

		for(long i = 0; i < sizepst; ++i){
			cleanPost(&((*estrutura)->posts[i]));
		}

		free((*estrutura)->posts);
	}

	void cleanTags(TAD_community *estrutura){
		clean_Tags((*estrutura)->tags);
	}
	void cleanDatas(TAD_community *estrutura){
		freeLDate((*estrutura)->datas);
	}

