#ifndef __QUERY9_H__ 
#define __QUERY9_H__

#include "community.h"

/** @brief Função auxiliar cujo intuito serve responder a query9
 * 
 *  @param com TAD_comunnity 
 *  @param id1 identificador do primeiro utilizador  
 *  @param id2 identificador do segundo utilizador 
 *  @param N utilizadores 
 *  @param resultado LONG_list para inserir as N perguntas em que participaram os 2 utilizadores, lista essa ordenada por cronologia inversa
 *  @return void 
 */
void query9aux(TAD_community estrutura, long id1, long id2, int N, LONG_list *resultado);
#endif