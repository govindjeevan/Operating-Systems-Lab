#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>


int buffer[5];
int k=0;
pthread_t producer, consumer;
sem_t mutex;
void *produce()
    {
        sem_wait(&mutex);
        if(k==5)
        printf("Buffer full\n");
        else {
            k++;sleep(1);
            printf("\nProduced %d\n", k);
            }
        sem_post(&mutex); 
    }
void *consume()
    {
        sem_wait(&mutex);
        if(k==0)
            printf("Buffer empty\n");
        else {
            k--;sleep(1);
            printf("\nCosumed %d\n",k);
        }
        sem_post(&mutex); 
    }


int main()
    {
        sem_init(&mutex, 0, 1);

        while(1)
            {
                pthread_create(&producer, NULL, produce,NULL);

                pthread_create(&consumer, NULL, consume,NULL);
           
            }

    }