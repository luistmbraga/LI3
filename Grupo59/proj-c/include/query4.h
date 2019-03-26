#ifndef __QUERY4_H__ 
#define __QUERY4_H__

#include "community.h"

/** @brief Função auxiliar cujo intuito serve responder a query4
 * 
 *  @param estrutura TAD_community
 *  @param tag Tag para ser procurada  
 *  @param begin Data inicial 
 *  @param end Data final
 *  @return LONG_list com os ids das perguntas que contêm essa tag  
 */
LONG_list query4aux(TAD_community estrutura, char* tag, char* begin, char* end);
#endif