#ifndef __QUERY1_H__ 
#define __QUERY1_H__

#include "community.h"

/** @brief Função auxiliar cujo intuito serve responder a query1 
 * 
 *  @param com TAD_community
 *  @param id Identificador do post 
 *  @return STR_pair título do post e nome 
 */
STR_pair query1aux(TAD_community com, long id);
#endif