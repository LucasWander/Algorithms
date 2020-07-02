#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

pthread_mutex_t lock;
int j = 0;

void *wait1(void *vargp)
{
    pthread_mutex_lock(&lock);

    pthread_t a = pthread_self();

    printf("\nStart wait1 %ld\n", a);

    int i = 0;

    j++;

    while (i < 5)
    {

        printf("\n--%d--\n", j);
        sleep(1);
        j++;
        i++;
    }

    printf("\n...Done wait1 %ld\n", a);

   pthread_mutex_unlock(&lock);
}

void *wait2(void *vargp) {

    pthread_t a = pthread_self();
    srand(time(NULL));
    printf("\nStart wait2 %ld\n", a);

    pthread_mutex_lock(&lock);
    j = j * rand();
    pthread_mutex_unlock(&lock);

    printf("\n...Done wait2.\n");
}

int main(void)
{
    pthread_t thread1, thread2;
    int err1, err2;

    // OBS: Mutex deve ser iniciado antes das threads serem criadas
    if (pthread_mutex_init(&lock, NULL) != 0)
    {
        printf("Mutex initialization failed. \n");
    }

    err2 = pthread_create(&thread2, NULL, wait1, NULL);
    err1 = pthread_create(&thread1, NULL, wait1, NULL);


    if (err1)
    {
        printf("\nAn error occured(thread 1): %d\n", err1);
        return 1;
    }

    if (err2)
    {
        printf("\nAn error occured(thread 2): %d\n", err2);
    }

    printf("\nWaiting for the thread to end...\n");

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("\nThread ended.\n");

    printf("Valor %d\n", j);

    return 0;
}
