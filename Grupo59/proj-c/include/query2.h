#ifndef __QUERY2_H__ 
#define __QUERY2_H__

#include "community.h"

/** @brief Função auxiliar cujo intuito serve responder a query2 
 * 
 *  @param com TAD_community
 *  @param N utilizadores 
 *  @return LONG_list com os N utilizadores com maior número de posts de sempre  
 */
LONG_list query2aux(TAD_community com, int N);

#endif
