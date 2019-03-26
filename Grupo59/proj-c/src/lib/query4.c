#include "query4.h"


LONG_list query4aux(TAD_community estrutura, char* tag, char* begin, char* end){
	long size = 0;
	long *aux = getIntervalo(estrutura->datas, begin, end, &size);
	LInt r = NULL;
	LInt *cauda = &r;
	int n = 0;
	LONG_list resultado;

	for(long i = 0; aux && i < size; i++){
		if (!(temParentID(estrutura->posts[aux[i]-1])) && (strstr(get_TagsP(estrutura->posts[aux[i]-1]), tag) != NULL)){
			if (n==0) cauda = setCaixa_Cauda(&r, aux[i]);
			else cauda = setCaixa_Cauda(cauda, aux[i]);
			n++;
		}		 
	}
		resultado = create_list(n);
		if (n != 0){
			 LItoLDL(resultado, &r);
		}
		return resultado;
	}


