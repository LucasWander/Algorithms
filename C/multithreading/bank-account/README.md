# Bank Account
> :warning: **Incomplete code**

Back Account **multithreading** example

```c
sched_yield();
if (value <= account->balance)
{
    sleep((rand() % 2) + 1);
    account->balance = account->balance - value;
    printf("Balance %ld: %.2f\n", a, account->balance);
    pthread_mutex_unlock(&lock);
    pthread_exit(false);
}

pthread_mutex_unlock(&lock);
pthread_exit((void *)true);
```


# Usage

## Command to run the example

```bash
gcc main.c -pthread
```
