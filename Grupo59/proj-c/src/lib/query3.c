#include "query3.h"


void query3SND(TAD_community estrutura, char* begin, char* end, long *r1, long *r2){
	long size = 0;

	long *aux = getIntervalo(estrutura->datas, begin, end, &size);  //Tira os ids dos posts feitos dentro do intervalo dado
	for(long i = 0; aux && i < size; i++)
		if (temParentID(estrutura->posts[aux[i]-1])) (*r2)++; //Verifica se o post e uma resposta, se sim, incrementa a variavel associada as respostas, caso contrario incrementa na variavel associada as perguntas
		else (*r1)++;
}



LONG_pair query3aux(TAD_community com, Date begin, Date end)
{
	long fst, snd;
	fst = snd = 0;
	query3SND(com, dateConvert(begin), dateConvert(end), &fst, &snd);
	LONG_pair r = create_long_pair(fst, snd);
	return r;
}
