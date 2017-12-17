#include <stdlib.h>
#include <stdio.h>
#include "readlines.h"

void aocday(int n){
	char input[1000];
	FILE *fp = popen("ls ascii/ | wc -l", "r");
	fgets(input, 1000, fp);
	pclose(fp);
	int nn = atoi(input);

	char fname[20];
	sprintf(fname, "ascii/%d.txt", n % nn);

	unsigned long nlines;
	char **picture= readlines(fname, &nlines);


	printf("+++++++++ ADVENT OF CODE 2017 DAY %d +++++++++\n", n);
	for (int l = 0; l < nlines; l++)
		printf("%s", picture[l]);
}