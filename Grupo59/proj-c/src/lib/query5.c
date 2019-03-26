#include "query5.h" 


USER query5aux(TAD_community com, long id)
{
	char* short_bio = mystrdup("O user nao existe");
	long post_history[10] = {0};
	USER r = create_user(short_bio, post_history);
	if(com->users[id]!=NULL){
		short_bio = getSBio(com->users[id]);
		for(int i = 0; i < 10; i++)
			post_history[i] = getPostDateID(com->users[id], i);
		r =  create_user(short_bio, post_history);
	}

	return r;
}