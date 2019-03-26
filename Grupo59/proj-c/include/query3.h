#ifndef __QUERY3_H__ 
#define __QUERY3_H__

#include "community.h"

/** @brief Função auxiliar cujo intuito serve responder a query3
 * 
 *  @param com TAD_community
 *  @param begin Date 
 *  @return end Date 
 *  @return LONG_pair com o número total de posts durante este período
 */
LONG_pair query3aux(TAD_community com, Date begin, Date end);

#endif