#ifndef __QUERY10_H__ 
#define __QUERY10_H__

#include "community.h"

/** @brief Função auxiliar da query10 que devolve o ID da melhor resposta usando uma função de média ponderada 
 *  
 *  @param estrutura TAD_community 
 *  @param id correspondente a resposta 
 *  @return long id da melhor resposta 
 */
long GetBetterAnswer(TAD_community estrutura, long id);

#endif