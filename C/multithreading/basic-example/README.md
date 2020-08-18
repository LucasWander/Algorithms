# Basic example

Basic **multithreading** example using **mutex** to protect shared resources

```c
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
```


# Usage

## Command to run the example

```bash
make
```
