#ifndef __LLIGADA_H__
#define __LLIGADA_H__

#include "list.h"

/** 
 * @brief Declaração do tipo LInt, um tipo abstrato
 */
typedef struct lligada *LInt; 

/** @brief Altera o id na estrutura LInt 
 *  
 *  @param l LInt 
 *  @param i valor novo 
 *  @return void 
 */
void setL_ID(LInt *l, long i);

/** @brief Aponta para estrutura LInt com o intuito de avançar uma casa
 *  
 *  @param l LInt 
 *  @param proxi LInt  
 *  @return void 
 */
void setL_prox(LInt *l, LInt proxi);

/** @brief Cria uma cauda de uma lista ligada alocando o espaço necessário 
 * 
 *  @param l Lista ligada  
 *  @param id que será posto na cauda 
 *  @return LInt Lista ligada com cauda nova  
 */
LInt* setCaixa_Cauda(LInt *l, long id);

/** @brief Retorna o apontador para a estrutura LInt uma casa avançada
 *  
 *  @param l LInt  
 *  @return LInt  
 */
LInt* avancaLEnder(LInt *l);

/** @brief Retorna a estrutura LInt avançando uma casa
 *  
 *  @param l LInt  
 *  @return LInt  
 */
LInt avancaL(LInt l);

/** @brief Retorna o id da estrutura LInt
 *  
 *  @param l LInt 
 *  @return long id 
 */
long getL_ID(LInt l);

/** @brief Aloca o espaço necessário para a estrutura LInt  
 *   
 *  @param l LInt 
 *  @return void 
 */
void create_List(LInt *l);

/** @brief Remove o último elemento da estrutura LInt
 *
 *  @param l LInt 
 *  @return void  
 */
void rmUltimo(LInt* l);

/** @brief Copia a LInt dada para uma nova LInt alocando o espaço necessário 
 * 
 *  @param l LInt 
 *  @return LInt 
 */
LInt listacpy(LInt l);

/** @brief Insere na cabeça da LInt um novo valor  
 * 
 *  @param l LInt 
 *  @param j long valor a inserir 
 *  @return void 
 */
void insertHead(LInt *l, long j);

/** @brief Liberta o espaço alocado para a LInt  
 * 
 *  @param l LInt 
 *  @return void 
 */
void freeL(LInt l);
#endif