#include "search.h"

int binarySearch(float *arr, int size, float value) {

	int middle;

	int start = 0;
	int end = size-1;

	while(start <= end) {

		middle = (start + end) / 2;

		if(arr[middle] == value) {
			return middle;
		}

		if(arr[middle] > value) {
			end = middle - 1;
		}

		if(arr[middle] < value) {
			start = middle + 1;
		}

	}


	return -1;
}
