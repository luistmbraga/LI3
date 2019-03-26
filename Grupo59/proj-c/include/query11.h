#ifndef __QUERY11_H__ 
#define __QUERY11_H__

#include "community.h"

/** @brief Função auxiliar cujo intuito serve responder a query11
 * 
 *  @param estrutura TAD_comunnity 
 *  @param N utilizadores 
 *  @param begin data inicial 
 *  @param end data final 
 *  @param r LONG_list no qual vai ser inserido os identificadores em ordem decrescente
 *  @return void
 */
void query11aux(TAD_community estrutura, int N, char *begin, char *end, LONG_list *r);
#endif