#ifndef __COMMUNITY_H__
#define __COMMUNITY_H__
#include <libxml/parser.h>  
#include <libxml/xmlmemory.h>
#include "common.h"
#include "string.h"
#include "user.h"
#include "pair.h"
#include "date.h"
#include "list.h"
#include "lligada.h"
#include "DateList.h"
#include "Users.h"
#include "Post.h"
#include "tagligada.h"

/* Estrutura TAD_instruct com array para posts e users e os respetivos tamanhos */
typedef struct TCD_community{
		Posts *posts;  				/* Array respetivo aos Posts */
		Users *users;   			/* Array respetivo aos Users */
		LTag tags;					/* Lista ligada respetiva as Tags */
		LDate datas;				/* Lista ligada respetiva as Datas */
		long sizeP; 				/* Tamanho do Posts */ 
		long sizeU;					/* Tamanho do Users */
		long sizeT;					/* Tamanho das Tags */
}*TAD_community;


/** @brief Inicia a estrutura TAD_community sem alocar espaço 
 *  
 *  @return TAD_community estrutura inicializada vazia 
 */
TAD_community initMyEstrutura();

/** @brief Carrega para a estrutura a posts e users com o dado tamanho  
 *  
 *  @param sizep tamanho destinado para os Posts 
 *  @param sizeu tamanho destinado para os Users 
 *  @return TAD_community estrutura carregada 
 */
TAD_community loadMyEstrutura(long sizep, long sizeu);

/** @brief Retorna tamanho posts  
 *  
 *  @param estrutura TAD_community 
 *  @return long Tamanho usado posts
 */
long GetSizeP (TAD_community estrutura); 

/** @brief Retorna tamanho users  
 *  
 *  @param estrutura TAD_community 
 *  @return long Tamanho usado users
 */
long GetSizeU (TAD_community estrutura); 

/** @brief Retorna tamanho tag  
 *  
 *  @param estrutura TAD_community 
 *  @return longTamanho usado tag
 */
long GetSizeT (TAD_community estrutura);

/** @brief Converte uma lista ligada numa LONG_list
 *  
 *  @param l LInt  
 *  @param r LONG_list 
 *  @return void 
 */
void LItoLDL(LONG_list r, LInt *l);


/** @brief Altera o tamanho na estrutura posts 
 *  
 *  @param estrutura TAD_community 
 *  @param size tamanho para alterar
 *  @return TAD_community com o tamanho já alterado no Posts
 */
TAD_community SetSizeP (TAD_community estrutura, long size); 

/** @brief Altera o tamanho na estrutura users 
 *  
 *  @param estrutura TAD_community  
 *  @param size tamanho para alterar 
 *  @return TAD_community com o tamanho já alterado no Users
 */
TAD_community SetSizeU (TAD_community estrutura, long size); 

/** @brief Altera o tamanho na estrutura tag
 *  
 *  @param estrutura TAD_community  
 *  @param size tamanho para alterar 
 *  @return TAD_community com o tamanho já alterado na estrutura Tag
 */
TAD_community SetSizeT (TAD_community estrutura, long size);

/** @brief Liberta o espaço alocado a estrutura Posts 
 *  
 *  @param estrutura TAD_community 
 *  @return void 
 */
void cleanPosts(TAD_community *estrutura);

/** @brief Liberta o espaço alocado a estrutura do Users
 *  
 *  @param estrutura TAD_community  
 *  @return void
 */
void cleanUsers(TAD_community *estrutura);

/** @brief Liberta o espaço alocada a estrutura Tags
 *  
 *  @param estrutura TAD_community  
 *  @return void 
 */
void cleanTags(TAD_community *estrutura);

/** @brief Liberta o espaço alocado a estrutura LDate 
 * 
 *  @param estrutura TAD_community 
 *  @return void 
 */
void cleanDatas(TAD_community *estrutura);
#endif
