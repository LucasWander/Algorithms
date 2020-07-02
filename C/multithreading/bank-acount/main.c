#include <stdio.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

typedef struct {
    double balance;
}Account;

int saca(double *value, Account *acc) {

    if(*value <=  acc->balance) {
         acc->balance =  acc->balance - *value;
         return 0;
    }

    return 1;
}


int deposita(double *value, Account *acc) {
    acc->balance =  acc->balance + *value;

    return 0;
}


int main() {

    double withDraw = 5000;
    double deposit = 3000;
    Account account1;
    account1.balance = 8000;

    printf("Balance: %.2f\n", account1.balance);

    while(true){

        int ok1 = deposita(&deposit, &account1);
        int ok = saca(&withDraw, &account1);


        if(ok) {
            printf("Saldo menor que %.2f\n", withDraw);
            break;
        }
    }

    printf("Balance: %.2f\n", account1.balance);
}
