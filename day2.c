#include <stdio.h>
#include <stdlib.h>
#include "readlines.h"
#include <string.h>
#include <limits.h>
#include "split.h"

void q1(char **file, unsigned long nlines);
void q2(char **file, unsigned long nlines);

int main(){
	printf("+++++++++ ADVENT OF CODE 2017 DAY 2 +++++++++\n");
	unsigned long nlines;
	char **file = readlines("day2.txt", &nlines);

	q1(file, nlines);
	q2(file, nlines);
}

void q1(char **file, unsigned long nlines){
	unsigned int sum = 0;
	for (int i = 0; i < nlines; i++){
		char *line = file[i];
		unsigned long n;
		int *nums = split_int(line, "\t", &n);

		unsigned int max = 0;
		unsigned int min = INT_MAX;

		for (int i = 0; i < n; i++){
			if (nums[i] > max)
				max = nums[i];
			if (nums[i] < min)
				min = nums[i];
		}
		sum += max - min;
	}
	printf("1) %u\n", sum);
}

void q2(char **file, unsigned long nlines){
	unsigned int sum = 0;
	for (int i = 0; i < nlines; i++){
		char *line = file[i];
		unsigned long n;
		int *nums = split_int(line, "\t", &n);

		for (int j = 0; j < n; j++){
			for (int k = 0; k < n; k++){
				printf("%d, %d %d\n", n, nums[j], nums[k]);
				if ((k != j) && (nums[j] % nums[k] == 0)){
					sum += nums[j] / nums[k];
				}
			}
		}
	}
	printf("2) %u\n", sum);
}