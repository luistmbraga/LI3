#ifndef __MY_COMMON__
#define __MY_COMMON__

/** @brief Implementação personalizada da função strdup da libraria do C  
 *
 *  @param s String para ser duplicado  
 *  @return char string duplicada
 */
char * mystrdup (const char *s);

/** @brief Implementação personalizada da função xmlStrsub da libraria do XML
 * 
 *  @param s char Array (palheiro) 
 *  @param int Start índice inicial
 *  @param length Comprimento
 *  @return a sub string da string inicial (agulha)
 */
char* mystrsub(char *s, int start, int length);
#endif
