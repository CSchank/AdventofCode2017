#include <stdio.h>
#include <stdlib.h>
#include "readlines.h"
#include <string.h>
#define SIZE 4096

int find_sum(const char *str);
int find_sum2(const char *str);

int main(){
	FILE *in = fopen("day1a.txt", "r");

	char *buf = malloc(SIZE);

	fgets(buf, SIZE, in);

	find_sum(buf);
	find_sum2(buf);

	free(buf);
}