#include <semaphore.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>


sem_t mutex;
sem_t rw;
int readcount=0;
pthread_t reader1, writer1, reader2, writer2;


void *reader(void *p)
    {
        printf("\n\t\tReader %s is waiting on Mutex Lock. %d\n",p,mutex);
        sem_wait(&mutex);
        printf("\n\t\tReader %s aquires Mutex Lock %d.\n",p,mutex);
        readcount++;
      
        if(readcount==1)
            {
                printf("\n\t\tReader %s is waiting on Write Lock.\n",p);
                sem_wait(&rw);
                printf("\n\t\tReader %s locks out writers\n",p);
            }
        printf("\nReaders Active: %d\n", readcount);
        sem_post(&mutex);
        printf("\n\t\tReader %s releases Mutex lock\n", p);
        printf("\n\t\tReader %s is reading\n", p);
        sleep(3);
        printf("\n\t\tReader %s is waiting to exit...\n",p);
        sem_wait(&mutex);
        readcount--;

        if(readcount==0)
            {
                sem_post(&rw);
                printf("\n\t\tWrite Lock is released by reader %s\n",p);
            }
        printf("\nReaders Active: %d\n", readcount);
        sem_post(&mutex);
        printf("\n\t\tReader %s unlocks and exits...\n",p);
    }

void *writer(void *p)
    {
        printf("\n\t\t\t\t\t\tWriter %s is waiting to write\n",p);
        sem_wait(&rw);
        printf("\nWriter %s Active\n",p);
        sleep(3);
        printf("\n\t\t\t\t\t\tWriter %s Finishes writing\n",p);
        sem_post(&rw);
        printf("\nWriter %s Inactive\n", p);
    }

int main()

    {
        sem_init(&mutex,0,1);
        sem_init(&rw,0,1);
        while(1)
            {
                pthread_create(&reader1,NULL,reader,"1");
                pthread_create(&writer1,NULL,writer,"1");
                pthread_create(&reader2,NULL,reader,"2");
                pthread_create(&writer2,NULL,writer,"2");
                getchar();
            }
    }
