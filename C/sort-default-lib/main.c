#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 6

void printArray(int *array, int arraySize) {

    int count;

    for(count = 0; count < arraySize; ++count) {
        printf("%d ", array[count]);
    }

    printf("\n");
}

int comparation(const void *a, const void *b) {

    int num1 = *(const int*) a;
    int num2 = *(const int*) b;

    if(num1 < num2) return -1;
    if(num1 > num2) return 1;

    return 0;
}

int main() {

    int array[ARRAY_SIZE] = {6,4,5,2,1,3};

    printArray(array, ARRAY_SIZE);

    qsort(array, ARRAY_SIZE, sizeof(int), comparation);

    printArray(array, ARRAY_SIZE);

    return 0;
}
