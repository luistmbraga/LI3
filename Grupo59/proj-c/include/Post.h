#ifndef __POST_H__
#define __POST_H__
#include <libxml/parser.h>  
#include <libxml/xmlmemory.h>
#include "lligada.h"

/** 
 * @brief Declaração do tipo Posts, um tipo abstrato
 */
typedef struct posts *Posts;

/** @brief Inicia a estrutura Posts sem alocar espaço 
 *  
 *  @param p Posts
 *  @return void
 */
void initPost(Posts *p);

/** @brief Retorna o Parent ID da estrutura posts
 *  
 *  @param p Posts
 *  @return long parent id
 */
long getParentID(Posts p);

/** @brief Retorna o title da estrutura posts
 *  
 *  @param p Posts
 *  @return char title
 */
char* getTitle(Posts p);

/** @brief Retorna o User ID da estrutura posts
 *  
 *  @param p Posts
 *  @return long user id
 */
long getUserID(Posts p);

/** @brief Retorna o Score da estrutura posts
 *  
 *  @param p Posts
 *  @return long score 
 */
long getScr(Posts p);

/** @brief Retorna o número de comentários da estrutura posts
 *  
 *  @param p Posts
 *  @return long Ncom
 */
long getNcom(Posts p);

/** @brief Retorna a tag da estrutura posts  
 * 
 *  @param p Posts
 *  @return char Tag
 */
char* get_TagsP(Posts p);

/** @brief Retorna a data do Post 
 * 
 *  @param p Posts 
 *  @return char Data 
 */
char* get_DatePer(Posts p);

/** @brief Retorna no número de respostas do Post  
 * 
 *  @param p Posts 
 *  @return int Número de respostas
 */
int GetNResp(Posts p);

/** @brief Retorna a lista ligada com as respostas
 *  
 *  @param p Posts
 *  @return LInt 
 */
LInt getResp(Posts p);

/** @brief Preenche a estrutura posts alocando espaço onde necessário segundo um template de uma pergunta
 *  
 *  @param p Posts
 *  @param t Titulo 
 *  @param tag Tag 
 *  @return void 
 */
void setPostPer(Posts *p, xmlChar *t, xmlChar *tag, xmlChar *date);

/** @brief Preenche a estrutura posts alocando espaço onde necessário segundo um template de uma resposta
 *  
 *  @param p Posts
 *  @param t Titulo 
 *  @param tag Tag 
 *  @return void 
 */
void setPostRes(Posts *p, xmlChar *s, long scr, long ncom);

/** @brief Preenche a estrutura posts dado um user id
 *  
 *  @param p Posts
 *  @param u User ID
 *  @return void 
 */
void setPostU(Posts *p, xmlChar *u);

/** @brief Associa a resposta a pergunta
 *  
 *  @param p Posts
 *  @param j índice
 *  @return void 
 */
void setRespAPer(Posts *p, long j);

/** @brief Verifica se possui parent id 
 *  
 *  @param p Posts
 *  @return BOOL
 */
int temParentID (Posts p);

/** @brief Liberta o espaço alocado para a estrutura Posts
 *  
 *  @param p Posts
 *  @return void 
 */
void cleanPost(Posts *p);
#endif