#include "commonligada.h"
#include "query7.h"



LDLong GetTopNanswersQuestions(TAD_community estrutura, int N, char* begin, char* end){
		long size = 0;
		long nlint = 0;
		long nresp = 0;
		long *aux = getIntervalo(estrutura->datas, begin, end, &size);
		LDLong r = NULL;
		Posts p = NULL;
		long ultimo_nresp = 0;

		for(long i = 0; aux && i < size; i++){
			p = estrutura->posts[aux[i]-1];
			if (!temParentID(p)){
				nresp = GetNResp(p);
				if(nlint <= N ){
					ultimo_nresp = inserOrdcommon(&r, aux[i], nresp);
					nlint++;
				}
				else{
					if(nresp > ultimo_nresp){
					ultimo_nresp = inserOrdcommon(&r, aux[i], nresp);
					rmUltimol(&r);
					}
				}
			}
		}
		return r;
	}


LONG_list query7aux(TAD_community com, int N, Date begin, Date end)
{
	LONG_list r = create_list(N);
	LDLong ld = GetTopNanswersQuestions(com, N, dateConvert(begin), dateConvert(end));

	LDLtoLL(r, &ld, N);

	freeLcommon(ld);

	return r;
}