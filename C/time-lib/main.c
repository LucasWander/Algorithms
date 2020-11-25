#include <stdio.h>
#include <time.h>


void timeOutExample() {
    time_t prevResult = time(NULL);

    while(1) {
        time_t result = time(NULL);

        if(difftime(result, prevResult) == 10){
            printf("%ld \n", result);
            prevResult = result;
        }

    }

}

int main() {

    timeOutExample();

    return 0;
}
