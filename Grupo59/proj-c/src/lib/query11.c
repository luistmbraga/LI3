#include "query11.h"

	int inserOrd_rep(TAD_community estrutura, LInt *l, long i, long rep){
		LInt new;
		int r = 1;

		while(*l && (r = (i != getL_ID(*l))) && getReputation(estrutura->users[getL_ID(*l)]) >= rep)
			l = avancaLEnder(l);
		if(r){
			create_List(&new);
			setL_ID(&new, i);
			setL_prox(&new, *l);
			*l = new;
			/*
			printf("escrevi alguma coisa no new: %ld\n",getL_ID(new)); 
			printf("esvrevi alguma coisa no l: %ld",getL_ID(*l));
			*/
		}
		return r;
	}

	LInt topN_users_rep(TAD_community estrutura, long *array, long size, int N){
		LInt r = NULL;
		int nlint = 0;
		long rep = 0;
		long userid;  
		int teste = 1;

		for(long i = 0; i < size; i++){
			if(!temParentID(estrutura->posts[array[i]-1])){
				userid = getUserID(estrutura->posts[array[i]-1]);
				if(estrutura->users[userid] != NULL){
					//printf("chega aqui");
					rep = getReputation(estrutura->users[userid]);
					if(nlint <= N ){
						teste = inserOrd_rep(estrutura, &r, userid, rep);
						nlint++; 
						//printf("Cheguei aqui\n");
 					}
					else{
					 	teste = inserOrd_rep(estrutura, &r, userid, rep);
						if(teste) rmUltimo(&r); 
					}
				}
			}
		}
		// r não está preenchido
		/*
		for(long j=0; j<N && r; j++){ 
			printf("imprimo resultado do r: %ld\n",getL_ID(r));
			r = avancaL(r);
		}
		*/
		return r;
	}

	char* fazTag(char* tag, int *i){
		int j = *i;
		int n = 0;
		int inicio = 0;
		while(tag[j] != '>' && tag[j] != '\0'){
			if(tag[j] == '<') inicio = j+1;
			else n++;
			j++;
		}

		if (tag[j] != '\0') *i = j+1;
		else *i = j;

		if (n!=0) return mystrsub(tag, inicio, n);
		else return NULL;

	}

	void div_add_Tag(LTag *t, char* tag){
		for(int i = 0; tag[i] != '\0';){
			char *aux = fazTag(tag, &i);
			insert_Tag(t, aux);
		}
	}

	void Tags_usadas(TAD_community estrutura, char *begin, char *end, LTag *t, long id){
		long size;
		long *aux = getIntervalo(getPosts_user(estrutura->users[id]), begin, end, &size);
		printf("size: %ld\n",size);
		for(long i = 0; i < size; i++){
			Posts paux = estrutura->posts[aux[i] - 1];
			if(!temParentID(paux)){
				char* tag = get_TagsP(paux); 
				printf("aux: %ld\n",aux[i]);
				//printf("tag na tags_usadas: %s\n",tag);
				div_add_Tag(t, tag);
			}
		}
		free(aux);
	}

	void query11aux(TAD_community estrutura, int N, char *begin, char *end, LONG_list *r){
		long size;
		long *aux = getIntervalo(estrutura->datas, begin, end, &size);
		LInt topNUsers = topN_users_rep(estrutura, aux, size, N);
		free(aux);
		long i;
		LInt cleanlist = topNUsers;
		LTag tagsusadas = NULL;
						
		for(i = 0; topNUsers && i < N; i++){
			Tags_usadas(estrutura, begin, end, &tagsusadas, getL_ID(topNUsers));
			topNUsers = avancaL(topNUsers);
		}
	 	
	 	freeL(cleanlist);
	 	LTag tagsmaisusadas = NULL;
	 	insertOrd_tagused(&tagsmaisusadas, tagsusadas, N);
	 	procura_insert_ID(estrutura->tags, tagsmaisusadas, N, r);
	 	clean_Tags(tagsmaisusadas);
	 	clean_Tags(tagsusadas);
	} 
