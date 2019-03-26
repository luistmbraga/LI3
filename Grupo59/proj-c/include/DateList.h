#ifndef __DATELIST_H__
#define __DATELIST_H__
#include <libxml/parser.h>  
#include <libxml/xmlmemory.h>

/** 
 *  @brief declaração do tipo LDate, um tipo abstrato 
 */
typedef struct datelist *LDate;

/** @brief Inicia a estrutura LDate sem alocar espaço 
 *  
 *  @param data LDate
 *  @return void
 */
void initDate(LDate *data);

/** @brief Retorna o LDate com o id da cabeça 
 * 
 *  @param data LDate 
 *  @param id índice 
 *  @return LDate 
 */
LDate* GetheadID(LDate *data, long *id);

/** @brief Retorna o id da estrutura LDate
 *  
 *  @param data LDate
 *  @param i índice 
 *  @return void
 */
long getID(LDate data, int i);

/** @brief Retorna a data da estrutura LDate
 *  
 *  @param data LDate
 *  @param i índice 
 *  @return xmlChar data
 */
xmlChar* getDate(LDate data, long i);

/** @brief Altera a data da estrutura LDate
 *  
 *  @param data LDate
 *  @param i índice 
 *  @param d nova data a inserir
 *  @return xmlChar data
 */
void setDate(LDate *data, long i, xmlChar* d);

/** @brief Verifica se o dado id pertence a estrutura LDate 
 * 
 *  @param id índice  
 *  @param d LDate 
 *  @return BOOL
 */
int pertence(long id, LDate d);

/** @brief Copia uma estrutura LDate para uma nova  
 * 
 *  @param d LDate 
 *  @return LDate clone da estrutura d
 */
LDate datecpy(LDate d);

/** @brief Retorna o array do id das datas do LDate 
 * 
 *  @param beg LDate 
 *  @param size tamanho 
 *  @return long Array  
 */
long* dateToArray(LDate beg, long size);

/** @brief Retorna o array do id das datas do intervalo entre as duas datas  
 * 
 *  @param d LDate 
 *  @param begin data inicial 
 *  @param end data final 
 *  @param size tamanho 
 *  @return long Array
 */
long* getIntervalo(LDate d, char* begin, char* end, long *size);

/** @brief Liberta o espaço alocado a estrutura LDate  
 * 
 *  @param posts LDate 
 *  @return void  
 */
void freeLDate(LDate posts);

#endif