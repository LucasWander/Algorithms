#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

#define true 1
#define false 0

pthread_mutex_t lock;

typedef struct
{
    double balance;
} Account;

typedef struct
{
    double value;
    Account *account;
} AccountAction;

void *saca(void *param)
{

    AccountAction *action = (AccountAction *)param;

    pthread_t a = pthread_self();

    double value = (action->value);
    Account *account = (Account *)(action->account);

    printf("\n------Start thread %ld-------\n", a);
    printf("\n------Valor saque %f-------\n", value);

    srand(time(NULL));
   pthread_mutex_lock(&lock);

   sched_yield();
    if (value <= account->balance)
    {
        sleep((rand() % 2) + 1);
        account->balance = account->balance - value;
        printf("Balance %ld: %.2f\n", a,account->balance);
        pthread_mutex_unlock(&lock);
        pthread_exit(false);
    }

    pthread_mutex_unlock(&lock);
    pthread_exit((void *)true);
}

void *deposita(AccountAction *param)
{

    AccountAction *action = (AccountAction *)param;

    double value = (action->value);
    Account *account = (Account *)(action->account);

    account->balance = account->balance + value;

    pthread_exit((void *)false);
}

AccountAction *createAcction(double value, Account *a)
{
    AccountAction *action = (AccountAction *)malloc(sizeof(AccountAction));

    action->value = value;
    action->account = a;

    return action;
}

int main()
{

    double withDraw = 7600;
    double deposit = 3000;


    Account account1;
    account1.balance = 8000;

    printf("Balance: %.2f\n", account1.balance);

    if (pthread_mutex_init(&lock, NULL) != 0)
    {
        printf("Mutex initialization failed. \n");
    }

    pthread_t thread1, thread2;
    int errThreadCreation1, errThreadCreation2;
    void *errSaca1, *errSaca2;

    AccountAction *action1 = createAcction(withDraw, &account1);

    withDraw = 513.16;

    AccountAction *action2 = createAcction(withDraw, &account1);

    errThreadCreation1 = pthread_create(&thread1, NULL, saca, action1);
    errThreadCreation2 = pthread_create(&thread2, NULL, saca, action2);

    if (errThreadCreation1)
    {
        printf("\nAn error occured(thread 1): %d\n", errThreadCreation1);
        return 1;
    }

    if (errThreadCreation2)
    {
        printf("\nAn error occured(thread 1): %d\n", errThreadCreation2);
        return 1;
    }

    printf("\nWaiting for the thread to end...\n");

    pthread_join(thread1, &errSaca1);
    pthread_join(thread2, &errSaca2);

    if (errSaca1)
    {
        printf("\nAn error occured on saca 1(thread 1): %p\n", errSaca1);
        return 1;
    }

    if (errSaca2)
    {
        printf("\nAn error occured on saca 2(thread 2): %p\n", errSaca2);
        return 1;
    }

    printf("Balance: %.2f\n", account1.balance);
}
