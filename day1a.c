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

int find_sum(const char *str){
	const char *tbu = str;
	unsigned int sum = 0;
	while(*tbu != '\0'){
		if (*tbu == *(tbu-1))
			sum += (unsigned int)(*tbu - '0');
		tbu++;
	}
	if (*(tbu-1) == *str)
		sum += (unsigned int)(*str - '0');

	printf("1) Sum: %d\n", sum);

	return sum;
}

int find_sum2(const char *str){
	const int half = strlen(str) / 2;
	const char *tbu = str;
	const char *tp2 = str + half;
	unsigned int sum = 0;
	while(*tbu != '\0'){
		if (*tbu == *tp2){
			sum += (unsigned int)(*tbu - '0');
		}
		tp2++;
		tbu++;
		if (*tp2 == '\0')
			tp2 = str;
	}

	printf("2) Sum: %d\n", sum);

	return sum;
}