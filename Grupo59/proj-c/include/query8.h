#ifndef __QUERY8_H__ 
#define __QUERY8_H__

#include "community.h"

/** @brief Função auxiliar cujo intuito serve responder a query8 
 * 
 *  @param com TAD_community
 *  @param N perguntas 
 *  @param word palavra dada 
 *  @param r LONG_list para inserir os ids cujos títulos contêm a palavra ordenados por cronologia inversa
 *  @return void
 */
void query8aux(TAD_community estrutura, char* word, int N, LONG_list* r);
#endif