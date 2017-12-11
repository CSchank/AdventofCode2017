#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **readlines(char *file, unsigned long *n_lines){
	size_t alloced = 128;
	char *p = malloc(alloced);
	size_t to_read = alloced;
	size_t nlines = 1;
	char **lines = malloc(nlines*sizeof(char*));


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
	    	char *newl = malloc(strlen(p));
			strcpy (newl,p);
			*(lines+(nlines-1)) = newl;

			//allocate an extra line
			nlines++;
			lines = realloc(lines, nlines*sizeof(char*));
	    }
	}

	*n_lines = nlines - 1;
	free(p);

	return lines;
}