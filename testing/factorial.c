#include "factorial.h"

int Factorial(int num) {

    if(num < 0){
        return 0;
    }

    int i = 1,fat = 1;

    for(;i<=num;++i) {
        fat = fat * i;
    }

    return fat;
}

