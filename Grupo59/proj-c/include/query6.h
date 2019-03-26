#ifndef __QUERY6_H__ 
#define __QUERY6_H__

#include "community.h"

/** @brief Função auxiliar cujo intuito serve responder a query6
 * 
 *  @param com TAD_community 
 *  @param N respostas 
 *  @param begin Date 
 *  @param end Date
 *  @return LONG_list com as N respostas com mais votos
 */
LONG_list query6aux(TAD_community com, int N, Date begin, Date end);
#endif