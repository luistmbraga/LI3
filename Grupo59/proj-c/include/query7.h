#ifndef __QUERY7_H__ 
#define __QUERY7_H__

#include "community.h"

/** @brief Função auxiliar cujo intuito serve responder a query6 
 * 
 *  @param com TAD_comunnity 
 *  @param N perguntas 
 *  @param begin Date 
 *  @param end Date 
 *  @return LONG_list com os ids das N perguntas com mais respostas em ordem decrescente
 */
LONG_list query7aux(TAD_community com, int N, Date begin, Date end);
#endif