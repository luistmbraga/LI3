#include "query10.h"

long GetBetterAnswer(TAD_community estrutura, long id){
		long iddamelhor = 0, usrid, resid, better, maybebetter;
		LInt new;
		better = maybebetter = LONG_MIN;
		Posts postaux = estrutura->posts[id-1];
		Users useraux = NULL;                             
                 
		if(postaux != NULL && !temParentID(postaux)){
			new = getResp(postaux);
			if(!new) iddamelhor = -1;
			else{
				postaux = estrutura->posts[(resid = getL_ID(new))-1];
				useraux = estrutura->users[usrid = getUserID(postaux)];
				while(new && useraux){	
					postaux = estrutura->posts[(resid = getL_ID(new))-1];
					useraux = estrutura->users[usrid = getUserID(postaux)];
					maybebetter = getReputation(useraux)*0.25 + getScr(postaux)*0.65 + getNcom(postaux)*0.1;
					if(maybebetter > better){ 
						better = maybebetter;
						iddamelhor = resid;
					}
				new = avancaL(new);
				}
			}
		}
	return iddamelhor;
}
	