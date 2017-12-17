#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **readlines(char *file, unsigned long *n_lines){
	size_t alloced = 32;
	char *p = malloc(alloced);
	size_t to_read = alloced;
	*n_lines = 1;
	char **lines = malloc(sizeof(char*));


	FILE *fp = fopen(file, "r");
	if (fp == NULL){
		fprintf(stderr, "readlines error: File \"%s\" not found.\n", file);
		exit(EXIT_FAILURE);
	}
	while(1) {
		ssize_t lineLen = getline( &p, &alloced, fp );

		if (lineLen == -1L)
	    	break;
	    if (alloced > to_read){
	    	fseek(fp, -lineLen, SEEK_CUR);
			p = realloc(p, alloced);
			to_read = alloced;
	    } else {
	    	char *newl = malloc(strlen(p) + 1);
			strcpy (newl,p);
			*(lines+(*n_lines-1)) = newl;
			//allocate an extra line
			(*n_lines)++;
			lines = realloc(lines, *n_lines*sizeof(char*));
	    }
	}
	(*n_lines)--;
	free(p);

	return lines;
}