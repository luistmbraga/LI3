#include "query9.h"

int intercepcao9(TAD_community estrutura, long* a1, long* a2, long size1, long size2, LDate* r){
	long parentId;
	int n = 0;
	Posts aux_user1 = NULL, aux_user2 = NULL;

	for(long i = 0; i < size1; i++){  //Percorre os posts do user 1
				aux_user1 = estrutura->posts[a1[i]-1];
				for(long j = 0; aux_user1 && j < size2; j++){       //Percorre os posts do user 2 para fazer a intercepcao dos conjuntos de perguntas e respostas
					aux_user2 = estrutura->posts[a2[j]-1];
					if (temParentID(aux_user1) && estrutura->posts[(parentId = getParentID(aux_user1))-1]){ // Testa se o post atual do user 1 e uma pergunta e, se sim, testa se essa pergunta existe 
						if (!pertence(parentId, *r)){                                                        //Testa se o id da pergunta ja foi passada para a lista de datas final
							if (parentId == a2[j] || (aux_user2 && temParentID(aux_user2) && getParentID(aux_user2) == parentId)) { // testa se o user 1 responde a alguma pergunta do user 2 ou se respondem a umapergunta em comum
								setDate(r, parentId, (xmlChar *) get_DatePer(estrutura->posts[parentId -1]));
								n++;
							}
						}
					}
					else{
						if(!pertence(a1[i], *r)){ //Testa se o id da resposta ja foi passado para a lista final de datas
							if (aux_user2 && temParentID(aux_user2) && getParentID(aux_user2) == a1[i]){ // Testa se o post do user 2 e uma resposta e se e uma resposta a pergunta do user 1
								setDate(r, a1[i], (xmlChar *) get_DatePer(estrutura->posts[a1[i] - 1]));
								n++;
							}
						}
					}
				}
			}
	return n;
}

void query9aux(TAD_community estrutura, long id1, long id2, int N, LONG_list *resultado){
		if(estrutura->users[id1] != NULL && estrutura->users[id2] != NULL){ //Testa se os users sao validos
			long size1, size2, *res;
			int n = 0;
			LDate r = NULL;
			size1 = getNPosts(estrutura->users[id1]); //Variavel que guarda o numero de posts do user 1
			size2 = getNPosts(estrutura->users[id2]);  //Variavel que guarda o numero de posts do user 2
			long *a1 = dateToArray(getPosts_user(estrutura->users[id1]), size1); //Array com os posts do user 1
			long *a2 = dateToArray(getPosts_user(estrutura->users[id2]), size2); //Array com os posts do user 2
			
			n = intercepcao9(estrutura, a1, a2, size1, size2, &r);

			res = (n<N) ? dateToArray(r, n) : dateToArray(r, (n=N));
			freeLDate(r);
			free(a1);
			free(a2);
			for (int t = 0; t < n; t++)
				set_list(*resultado, t, res[t]);
			while(n<N)
				set_list(*resultado, n++, -2);
			free(res);
		}
	}