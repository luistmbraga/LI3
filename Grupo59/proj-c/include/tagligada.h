#ifndef __TAGLIGADA_H__
#define __TAGLIGADA_H__
#include <libxml/parser.h>  
#include <libxml/xmlmemory.h>
#include "list.h"

/** 
 * @brief Declaração do tipo LTag, um tipo abstrato
 */
typedef struct tag *LTag;

/** @brief Retorna a estrutura tag num dado índice 
 *  
 *  @param t Tag 
 *  @param i índice 
 *  @return LTag
 */
LTag get_Tag (LTag t, long i);

/** @brief Retorna o nome da tag num dado índice  
 *  
 *  @param t Tag 
 *  @param i índice 
 *  @return char Tag Name
 */
char* get_TagName (LTag t, long i);

/** @brief Altera a estrutura tag com um novo tag name num dado índice
 *  
 *  @param t Tag 
 *  @param i índice  
 *  @param tn Tag Name 
 *  @return void 
 */
void set_Tag(LTag *t, long i, xmlChar *tn);

/** @brief Liberta o espaço alocado para a estrutura Tag 
 *  
 *  @param l Tag  
 *  @return void
 */
void clean_Tags(LTag l);

/** @brief Insera na estruta LTag uma nova tag name 
 * 
 *  @param t LTag  
 *  @param aux nova tag a ser inserida 
 *  @return void
 */
void insert_Tag(LTag *t, char *aux);

/** @brief Insere na estrutura a tag mais usada ordenadamente 
 * 
 *  @param resultado LTag 
 *  @param tag LTag 
 *  @param N n tags 
 *  @return void 
 */
void insertOrd_tagused(LTag *resultado, LTag tag, int N);

/** @brief Procura na estrutura LTag e insere o ID  
 * 
 *  @param tags LTag 
 *  @param maisusadas LTag 
 *  @param N n tags 
 *  @param r LONG_list 
 *  @return void 
 */
void procura_insert_ID(LTag tags, LTag maisusadas, int N, LONG_list *r);
#endif