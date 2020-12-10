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

void testFormatConversion() {
    time_t currentTime = time(NULL);
    struct tm *t1 = gmtime(&currentTime);


    printf("%ld\n", currentTime);
    printf("GM: %d\n", t1->tm_hour);
    printf("%s", asctime(t1));
    printf("%s", ctime(&currentTime));
}

void testingClock() {

    clock_t clockTime = clock();

    printf("%ld\n", clockTime);
    printf("%ld\n", CLOCKS_PER_SEC);
    printf("%ld\n", clockTime/CLOCKS_PER_SEC);
}

void timeOutExampleClock() {
    clock_t prevClock = clock();

    while(1) {
        time_t result = clock();

        if(difftime(result, prevClock) == 500000){
            printf("%f\n", difftime(result, prevClock));
            printf("%ld \n", result);
            prevClock = result;
        }

    }

}

int main() {

    //timeOutExample();
    //testFormatConversion();
    //testingClock();
    timeOutExampleClock();
    return 0;
}
