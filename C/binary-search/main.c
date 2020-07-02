#include <stdio.h>
#include "search.h"

void printArray(float *arr,int size) {

	int i = 0;

	for(;i < size; ++i){
		printf("%f\n", arr[i]);
	}

	return;
}



int main() {

	int size = 5;
	float a[5] = {1,2,3,4,5};

	printf("%d\n",binarySearch(a,size, 9));
	printf("%d\n",binarySearch(a,size, 1));
	printf("%d\n",binarySearch(a,size, 4));
}