#ifndef __USERS_H__
#define __USERS_H__
#include <libxml/parser.h>  
#include <libxml/xmlmemory.h>
#include "DateList.h"

/** 
 * @brief Declaração do tipo Users, um tipo abstrato
 */
typedef struct users *Users;

/** @brief Retorna o Short Bio da estrutura users 
 *  
 *  @param u Users
 *  @return char Short Bio
 */
char* getSBio(Users u);

/** @brief Retorna o Display Name da estrutura users 
 *  
 *  @param u Users
 *  @return char Display Name
 */
char* getDisplayName(Users u);

/** @brief Retorna a Reputation da estrutura users 
 *  
 *  @param u Users
 *  @return long Reputation
 */
long getReputation(Users u);

/** @brief Retorna o número de posts da estrutura users 
 *  
 *  @param u Users
 *  @return int Nposts
 */
int getNPosts(Users u);

/** @brief Retorna os posts do User ordenado por data 
 *
 *  @param u Users 
 *  @return LDate lista ligada ordenada dos users por data 
 */
LDate getPosts_user(Users u);

/** @brief Retorna o ID da lista ligada dos posts 
 * 
 *  @param u Users 
 *  @param i índice  
 *  @return long id 
 */
long getPostDateID(Users u, int i);

/** @brief Altera a estrutura Post colocando data na lista ligada  
 * 
 *  @param u Users 
 *  @param i índice 
 *  @param d data nova a inserir 
 *  @return void  
 */
void set_Post_User(Users *u, long i, xmlChar* d);

/** @brief Altera a estrutura users carregando novos dados
 *  
 *  @param u Users
 *  @param a Short Bio 
 *  @param b Display Name 
 *  @param c Reputation 
 *  @return void
 */
void set_User(Users *u, xmlChar* a, xmlChar* b, xmlChar* c);

/** @brief Liberta o espaço alocado a estrutura USERS
 *  
 *  @param u Users
 *  @return void 
 */
void cleanUser(Users *u);
#endif