#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "printart.h"

int main(int argc,char *argv[]){
	int n = atoi(argv[1]);
	int nsq = sqrt(n);

	int x, y;
	x = y = n / 2;
	int rem = n - nsq * nsq;

	for (int r = rem; r > 0; r--){
		
	}
	aocday(3);

}

int manhattan(x1,y1,x2,y2){
	return y2 - y1 + x2 - x1; 
}