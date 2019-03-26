#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

//Include de headers locais
#include <interface.h>
#include <date.h>
#include <list.h>
#include <pair.h>
#include <user.h>

int main(){
	char stackover[100];
	int opcao, N, ano_inicio, ano_fim, mes_inicio, mes_fim, dia_inicio, dia_fim;
	time_t begin, end;
	long id, ten_id;
	long *query_5;
	STR_pair strpair;
	LONG_pair longpair;
	LONG_list longlist;
	USER usr;
	Date date_begin;
	Date date_end;
	TAD_community r;

	printf("Path para os ficheiros xml : ");
	scanf("%s", stackover);
	//Carregamento de dados
	begin = clock();
	//strcpy(stackover, "../android/");
	r = init();

	printf("\n\n");
	r = load(r, stackover);

	//Tempo de carregamento de dados
	printf("The loading time was: %.6f s\n\n", (double) (clock() - begin) / CLOCKS_PER_SEC);
	
	printf("********Laboratorios de Informatica 3********\n");
	printf("*                                           *\n");
	printf("*               Carregue em:                *\n");
	printf("*                                           *\n");
	printf("*            (1) para Query 1               *\n");
	printf("*                                           *\n");
	printf("*            (2) para Query 2               *\n");
	printf("*                                           *\n");
	printf("*            (3) para Query 3               *\n");
	printf("*                                           *\n");
	printf("*            (4) para Query 4               *\n");
	printf("*                                           *\n");
	printf("*            (5) para Query 5               *\n");
	printf("*                                           *\n");
	printf("*            (6) para Query 6               *\n");
	printf("*                                           *\n");
	printf("*            (7) para Query 7               *\n");
	printf("*                                           *\n");
	printf("*            (8) para Query 8               *\n");
	printf("*                                           *\n");
	printf("*            (9) para Query 9               *\n");
	printf("*                                           *\n");
	printf("*            (10) para Query 10             *\n");
	printf("*                                           *\n");
	printf("*            (11) para Query 11             *\n");
	printf("*                                           *\n");
	printf("*                                           *\n");
	printf("*********************************************\n");

	//scanf da opcao
	printf("Se pretende responder a uma query escreva o numero correspondente, se quer sair escreva 0 : ");
	scanf("%d", &opcao);
	printf("\n");
	
	while(opcao){
		switch (opcao)
				{
				case(1):
					printf("Id do post que pretende pesquisar: ");
					scanf("%ld", &id);
					printf("\n");
					begin = clock();
					strpair = info_from_post(r, id); //164103
					end = clock();
					printf("titulo = %s\nname = %s\n",get_fst_str(strpair), get_snd_str(strpair));
					free_str_pair(strpair);
					break;
				case(2):
					printf("Numero de utilizadores mais activos: ");
					scanf("%d", &N);
					printf("\n");
					begin = clock();
					longlist = top_most_active(r, N);
					end = clock();
					for(int i = 0; i < N; i++)
						printf("%d - %ld\n", i+1, get_list(longlist, i));
					free_list(longlist);
					break;
				case(3):
					printf("Data de inicio:\nAno: ");
					scanf("%d", &ano_inicio);
					printf("\nMes: ");
					scanf("%d", &mes_inicio);
					printf("\nDia: ");
					scanf("%d", &dia_inicio);

					printf("\nData de fim:\nAno: ");
					scanf("%d", &ano_fim);
					printf("\nMes: ");
					scanf("%d", &mes_fim);
					printf("\nDia: ");
					scanf("%d", &dia_fim);
					printf("\n");
					date_begin = createDate(dia_inicio, mes_inicio, ano_inicio);
					date_end = createDate(dia_fim, mes_fim, ano_fim);
					begin = clock();
					longpair = total_posts(r, date_begin, date_end);
					end = clock();
					printf("Numero de perguntas: %ld\nNUmero de respostas: %ld\n",get_fst_long(longpair), get_snd_long(longpair));
					free_date(date_begin);
					free_date(date_end);
					free_long_pair(longpair);
					break;
				case(4):
					printf("Data de inicio:\nAno: ");
					scanf("%d", &ano_inicio);
					printf("\nMes: ");
					scanf("%d", &mes_inicio);
					printf("\nDia: ");
					scanf("%d", &dia_inicio);

					printf("\nData de fim:\nAno: ");
					scanf("%d", &ano_fim);
					printf("\nMes: ");
					scanf("%d", &mes_fim);
					printf("\nDia: ");
					scanf("%d", &dia_fim);
					printf("\n");
					printf("Introduza a tag desejada: ");
					scanf("%s", stackover);
					printf("\n");
					date_begin = createDate(dia_inicio, mes_inicio, ano_inicio);
					date_end = createDate(dia_fim, mes_fim, ano_fim);
					begin = clock();
					longlist = questions_with_tag(r, stackover, date_begin, date_end);
					end = clock();
					N = get_size(longlist);
					for(int i = 0; i < N; i++)
						printf("%d - %ld\n", i+1, get_list(longlist, i));
					free_date(date_end);
					free_date(date_begin);
					free_list(longlist);
					break;
				case(5):
					printf("Id do user que pretende consultar: ");
					scanf("%ld", &id);
					printf("\n");
					begin = clock();
					usr = get_user_info(r, id);
					end = clock();
					printf("ShortBio = %s\n", get_bio(usr));
					query_5 =  get_10_latest_posts(usr);
					for(int i = 0; i < 10; i++)
						printf("%d - %ld\n", i+1, query_5[i]);
					free_user(usr);
					break;
				case(6):
					printf("Data de inicio:\nAno: ");
					scanf("%d", &ano_inicio);
					printf("\nMes: ");
					scanf("%d", &mes_inicio);
					printf("\nDia: ");
					scanf("%d", &dia_inicio);

					printf("\nData de fim:\nAno: ");
					scanf("%d", &ano_fim);
					printf("\nMes: ");
					scanf("%d", &mes_fim);
					printf("\nDia: ");
					scanf("%d", &dia_fim);
					printf("\n");
					printf("Numero de respostas com mais score: ");
					scanf("%d", &N);
					printf("\n");
					date_begin = createDate(dia_inicio, mes_inicio, ano_inicio);
					date_end = createDate(dia_fim, mes_fim, ano_fim);
					begin = clock();
					longlist = most_voted_answers(r, N, date_begin, date_end);
					end = clock();
					for(int i = 0; i < N; i++)
						printf("%d - %ld\n", i+1, get_list(longlist, i));

					free_date(date_end);
					free_date(date_begin);
					free_list(longlist);
					break;
				case(7):
					printf("Data de inicio:\nAno: ");
					scanf("%d", &ano_inicio);
					printf("\nMes: ");
					scanf("%d", &mes_inicio);
					printf("\nDia: ");
					scanf("%d", &dia_inicio);

					printf("\nData de fim:\nAno: ");
					scanf("%d", &ano_fim);
					printf("\nMes: ");
					scanf("%d", &mes_fim);
					printf("\nDia: ");
					scanf("%d", &dia_fim);
					printf("\n");
					printf("Numero de perguntas com mais respostas: ");
					scanf("%d", &N);
					printf("\n");
					date_begin = createDate(dia_inicio, mes_inicio, ano_inicio);
					date_end = createDate(dia_fim, mes_fim, ano_fim);
					begin = clock();
					longlist = most_answered_questions(r, N, date_begin, date_end);
					end = clock();
					for(int i = 0; i < N; i++)
						printf("%d - %ld\n", i+1, get_list(longlist, i));
					
					free_date(date_end);
					free_date(date_begin);
					free_list(longlist);
					break;
				case(8):
					printf("Introduza a tag desejada: ");
					scanf("%s", stackover);
					printf("\n");
					printf("Numero de perguntas que contem a word: ");
					scanf("%d", &N);
					printf("\n");
					begin = clock();
					longlist = contains_word(r, stackover, N);
					end = clock();
					for(int i = 0; i < N; i++)
						printf("%d - %ld\n", i+1, get_list(longlist, i));
					free_list(longlist);
					break;
				case(9):
					printf("ID do user1: ");
					scanf("%ld", &id);
					printf("\n");
					printf("ID do user2: ");
					scanf("%ld", &ten_id);
					printf("\nNumero de perguntas em comum com os dois users: ");
					scanf("%d", &N);
					printf("\n");
					begin = clock();
					longlist = both_participated(r, id, ten_id, N);
					end = clock();
					for(int i = 0; i < N; i++)
						printf("%d - %ld\n", i+1, get_list(longlist, i));
					free_list(longlist);
					break;
				case(10):
					printf("Id da pergunta que pretende pesquisar: ");
					scanf("%ld", &id);
					printf("\n");
					begin = clock();
					ten_id = better_answer(r, id);
					end = clock();
					if(ten_id > 0) printf("Id da melhor resposta: %ld\n", ten_id);
					else if (ten_id == -1) printf("A pergunta nao tem respostas\n");
						 else printf("O Id dado ou nao existe, pertence a uma resposta ou o utilizador nao existe\n");
					break;
				case(11):
					printf("Data de inicio:\nAno: ");
					scanf("%d", &ano_inicio);
					printf("\nMes: ");
					scanf("%d", &mes_inicio);
					printf("\nDia: ");
					scanf("%d", &dia_inicio);

					printf("\nData de fim:\nAno: ");
					scanf("%d", &ano_fim);
					printf("\nMes: ");
					scanf("%d", &mes_fim);
					printf("\nDia: ");
					scanf("%d", &dia_fim);
					printf("\n");
					printf("Numero de tags mais usadas: ");
					scanf("%d", &N);
					printf("\n");
					date_begin = createDate(dia_inicio, mes_inicio, ano_inicio);
					date_end = createDate(dia_fim, mes_fim, ano_fim);
					begin = clock();
					longlist = most_used_best_rep(r, N, date_begin, date_end);
					end = clock();
					for(int i = 0; i < N; i++)
						printf("%d - %ld\n", i+1, get_list(longlist, i));
					free_list(longlist);
					free_date(date_end);
					free_date(date_begin);
					break;
				default:
					printf("Query invalida!!!\n");
				}
			//Medir o tempo de procura na estrutura
  			if(opcao > 0 && opcao <= 11) printf("\nO tempo de procura foi: %.6f s\n\n", (double) (end - begin) / CLOCKS_PER_SEC);
			printf("\nSe pretende responder a uma nova query escreva o numero correspondente, se quer sair escreva 0 : ");
			scanf("%d", &opcao);
			printf("\n");
	}

  	//funcao clean, depois passar para o fim
	r = clean(r);
	
  	return 0;
}














