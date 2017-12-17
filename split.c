#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **split(char *str, const char *delim, unsigned long *n_tok){
	char *tok;
	*(n_tok) = 1;
	char **res = malloc(sizeof(char*));

	tok = strtok(str, delim);
	while(tok != NULL){
		char *newtok = malloc(strlen(tok) + 1);
		strcpy(newtok, tok);
		*(res + *n_tok - 1) = newtok;
		(*n_tok)++;
		res = realloc(res,*n_tok*sizeof(char*));
		tok = strtok(NULL,delim);
	}
	(*n_tok)--;
	return res;
}

int *split_int(char *str, const char *delim, unsigned long *n_tok){
	char **linespl = split(str, delim, n_tok);
	int *intspl = malloc(*n_tok * sizeof(int));

	for (int i = 0; i < *n_tok; i++){
		*(intspl+i) = atoi(*(linespl+i));
	}

	free(intspl);
	return intspl;
}