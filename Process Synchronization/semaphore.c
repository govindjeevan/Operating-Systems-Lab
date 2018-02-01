#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>


sem_t mutex;

int main()
    {
        sem_init(&mutex, 0, 1);
    }