#include <common.h>
#include <string.h>
#include <stdlib.h>

// definido par nao dar warnings ao usar a funcao da GNU
char * mystrdup (const char *s) {
    if(s == NULL) return NULL;          
    char *d = malloc (strlen (s) + 1); 
    if (d == NULL) return NULL;       
    strcpy (d,s);                    
    return d;                       
}

char* mystrsub(char *s, int start, int length){
	int n;
	if(s == NULL) return NULL;
	char *d = malloc (length+1);
	for(n = 0; n < length  && s[start+n] != '\0'; n++)
		d[n] = s[start+n];
	d[n] = '\0';
	return d;
}

