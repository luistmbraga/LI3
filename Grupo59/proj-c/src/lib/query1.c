#include "query1.h"


STR_pair query1aux(TAD_community com, long id){

	char* fst;
	char* snd;
	fst = mystrdup("Vazio");
	snd = mystrdup("Vazio");
	STR_pair resp;
	long usrid;
	int r = 1;
	Posts p = com->posts[id-1];
	Users aux;

	while(r && p != NULL){   //Testa se o post com id dado existe 
		if(temParentID(p)){ id = getParentID(p); p = com->posts[id-1];} //Se o post for uma pergunta guarda o id da pergunta a que responde
		else{             //Caso seja uma pergunta vai-se a estrutura para carregar as informacoes dessa pergunta
			fst = getTitle(p);
			usrid = getUserID(p);
			aux = com->users[usrid];
			if(aux!=NULL){ snd = getDisplayName(aux);}
			r = 0;
		}
	}
	resp = create_str_pair(fst, snd);
	
	return resp;
}
