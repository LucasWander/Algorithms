# Multithreading

**Multithreading** examples using **pthread.h** library

# Notes

## Methods

- `pthread_create`: Cria a thread.

- `pthread_join`: Linka a thread atual a nova thread. Faz o programar esperar o nova thread acabar.

## Concepts

>Mutex

Fazer varias operações no mesmo rescurso em threads diferentes é um problema. Corre o risco do recurso ser corrompido.

Mutex impede que outras thread alterem os recursos que a thread atual está alterando.

OBS: Mutex deve ser iniciado antes das threads serem criadas.

## Compile

```bash
# -lpthead tells the compiler to link the thread library
gcc main.c -lpthread
```
