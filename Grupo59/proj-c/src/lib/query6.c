#include "commonligada.h"
#include "query6.h"  

LDLong GetTopNanswers(TAD_community estrutura, int N, char* begin, char* end){
		long size = 0;
		long nlint = 0;
		long scr = 0;
		long *aux = getIntervalo(estrutura->datas, begin, end, &size);
		LDLong r = NULL;
		Posts p = NULL;
		long ultimo_scr = 0;

		for(long i = 0; aux && i < size; i++){
			p = estrutura->posts[aux[i]-1];
			if (temParentID(p)){
				scr = getScr(p);
				if(nlint <= N ){
					ultimo_scr = inserOrdcommon(&r, aux[i], scr);
					nlint++;
				}
				else{
					if (scr > ultimo_scr){
					ultimo_scr = inserOrdcommon(&r, aux[i], scr);
					rmUltimol(&r);
					}
				}
			}
		}
		return r;
	}

LONG_list query6aux(TAD_community com, int N, Date begin, Date end)
{
	LONG_list r = create_list(N);
	LDLong ld = GetTopNanswers(com, N, dateConvert(begin), dateConvert(end));

	LDLtoLL(r, &ld, N);

	freeLcommon(ld);

	return r;
}