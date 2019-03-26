#ifndef __COMMONLIGADA_H__ 
#define __COMMONLIGADA_H__

#include "list.h"

/** 
 *  @brief declaração do tipo LDLong, um tipo abstrato 
 */
typedef struct commonligada *LDLong;

/** @brief Aloca o espaço para a estrutura LDLong 
 *
 *  @param l LDLong 
 *  @return void  
 */
void create_LDLong(LDLong* l);

/** @brief Retorna o id da estrutura LDLong 
 * 
 *  @param u LDLong 
 *  @return long id  
 */
long get_id_common(LDLong u);

/** @brief Retorna o common da estrutura LDLong 
 * 
 *  @param u LDLong 
 *  @return long common 
 */
long get_common(LDLong u);

/** @brief Retorna o último common da estrutura 
 * 
 *  @param l LDLong 
 *  @return long common
 */
long get_ultimoCommon(LDLong l);

/** @brief Altera o id da estrutura LDLong num dado índice
 * 
 *  @param u LDLong 
 *  @param id para colocar 
 *  @return void 
 */
void set_id_common(LDLong* u, long id);
 
/** @brief Altera o common da estrutura LDLong  
 * 
 *  @param u LDLong 
 *  @param common para colocar 
 *  @return void
 */
void set_common(LDLong* u, long common);

/** @brief Altera a proximo da estrutura da estrutura LDLong 
 * 
 *  @param l LDLong 
 *  @param proxi LDLong próximo 
 *  @return void  
 */
void set_LDLprox(LDLong* l, LDLong proxi);

/** @brief Avança a estrutura LDLong 
 * 
 *  @param u LDLong 
 *  @return LDLong uma casa avançada  
 */
LDLong avancaCommon(LDLong u);

/** @brief Avança o endereço do LDLong  
 * 
 *  @param u LDLong 
 *  @return LDLong 
 */
LDLong* avancaEndCommon(LDLong* u);

/** @brief Insere o common ordenadamente na estrutura LDLong
 *
 *  @param l LDLong
 *  @param i índice 
 *  @param common para colocar  
 *  @return long 
 */
long inserOrdcommon(LDLong* l, long i, int common);

/** @brief Remove a última casa do LDLong 
 * 
 *  @param l LDLong 
 *  @return void 
 */
void rmUltimol(LDLong* l);

/** @brief Transforma LDLong numa LONG_list 
 *  
 *  @param r LONG_list 
 *  @param l LDLong 
 *  @param N  
 *  @return void 
 */
void LDLtoLL(LONG_list r, LDLong *l, int N);

/** @brief Liberta o espaço alocado ao LDLong 
 * 
 *  @param l LDLong 
 *  @return void  
 */
void freeLcommon(LDLong l);
#endif
