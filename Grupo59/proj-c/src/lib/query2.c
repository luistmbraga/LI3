#include "commonligada.h"
#include "query2.h"



LDLong GetNTopUsr(TAD_community estrutura, int N){
		LDLong r = NULL;
		long sizeu = estrutura->sizeU;
		int nlint, np, ultimo_np;
		nlint = np = ultimo_np = 0;
		Users aux;

		for(long i = 0; i < sizeu; i++){
			aux = estrutura->users[i];
			if(aux != NULL){
				//criar getNPosts np = getNPosts(estrutura->users[i]);
				np = getNPosts(aux);
				if(nlint <= N ){
					ultimo_np = inserOrdcommon(&r, i, np);
					nlint++;
				}
				else{
					if (np > ultimo_np){
						ultimo_np = inserOrdcommon(&r, i, np);
						rmUltimol(&r);
					}
				}
			}
		}
		return r;
	}

LONG_list query2aux(TAD_community com, int N)
{
	LONG_list r = create_list(N);
	LDLong ld = GetNTopUsr(com, N);

	LDLtoLL(r, &ld, N);

	freeLcommon(ld);

	return r;
}