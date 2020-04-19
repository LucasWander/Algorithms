#include <pthread.h>
#include <unistd.h>
#include <stdio.h>

pthread_mutex_t lock;
int j = 0;

void *wait(void *vargp)
{
	pthread_mutex_lock(&lock);

    printf("Start.\n");

	int i = 0;

    j++;

    while(i < 5) {

    	printf("%d",j);
    	sleep(1);
    	i++;
    }


    printf("...Done.\n");

    pthread_mutex_unlock(&lock);
}

int main(void)
{
    pthread_t thread, th2;
    int err,err2;
    
    // OBS: Mutex deve ser iniciado antes das threads serem criadas
    if(pthread_mutex_init(&lock, NULL) != 0){
    	printf("Mutex initialization failed. \n");
    }

    err = pthread_create(&thread, NULL, wait, NULL);
    err2 = pthread_create(&th2, NULL, wait,NULL);

    

    if (err)
    {
        printf("An error occured: %d", err);
        return 1;
    }

    if(err)
    {
    	printf("An error occured: %d", err2);
    }

    printf("Waiting for the thread to end...\n");

    pthread_join(thread, NULL);
    pthread_join(th2, NULL);

    printf("Thread ended.\n");    


    printf("%d\n",j);

    return 0;
}