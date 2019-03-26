#ifndef __QUERY5_H__ 
#define __QUERY5_H__

#include "community.h"

/** @brief Função auxiliar cujo intuito serve responder a query5 
 * 
 *  @param com TAD_community  
 *  @param id do utilizador
 *  @return USER com a informação do perfil e os ids dos 10 últimos posts  
 */
USER query5aux(TAD_community com, long id);
#endif