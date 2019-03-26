#include "query8.h"

void query8aux(TAD_community estrutura, char* word, int N, LONG_list* r){
		int n = 0;
		long id;
		LDate *pointer = &(estrutura->datas);
		pointer = GetheadID(pointer, &id);
		while(n < N && id!=-1){
			if(!temParentID(estrutura->posts[id-1]) && strstr(getTitle(estrutura->posts[id-1]), word))
				set_list(*r, n++, id);
			pointer = GetheadID(pointer, &id);
		}
		while(n < N) set_list(*r, n++, -1);
}