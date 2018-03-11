#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
sem_t rw;
sem_t mutex;

pthread_t writer[2], reader[2];
int readcount=0;
void *wr(void *p)
{ 
    int *i;
    i=p;
    printf("\nWriter %d wants to write\n", *i);
    sem_wait(&rw);
    printf("\nwriter %d is writitng\n", *i);
    sleep(3);
    printf("\nwriter %d has finished writitng\n", *i);
    sem_post(&rw);

}

void *re( void * p)
{
    int *i;
    i=p;

    printf("\n Reader %d wants to read\n", *i);
    sem_wait(&mutex);
    printf("\n Reader %d has locked readlock\n", *i);
    readcount++;
    if(readcount==1)
        {
            printf("\n Reader %d is waiting on writelock\n", *i);
            sem_wait(&rw);
            printf("\n Reader %d locked writelock\n", *i);            
        }
    sem_post(&mutex);
    printf("\n Reader %d released readlock\n", *i);
    printf("\n Reader %d is reading\n", *i);
    sleep(3);
    printf("\n Reader %d finished reading\n", *i);
    
    printf("\n Reader %d waiting on readlock\n", *i);
    sem_wait(&mutex);
    printf("\n Reader %d has locked readlock\n", *i);
    readcount--;
      if(readcount==0)
        {
            
            sem_post(&rw);
            sleep(1);
            printf("\n Reader %d released writelock\n", *i);            
        }
    sem_post(&mutex);
    printf("\n Reader %d released readlock\n", *i);
    printf("\n Reader %d exits\n", *i);

}
    
    
    


int main()
    {
        sem_init (&rw,0,1);
        sem_init (&mutex,0,1);

        int i;

        int w[2]={1,2};
        int r[2]={1,2};
      
      while(1)
        {
            pthread_create(&writer[1],NULL, wr,&w[0]);
            sleep(1);
            pthread_create(&reader[2],NULL, re,&r[1]);
            pthread_create(&reader[1],NULL, re,&r[0]);
            pthread_create(&writer[2],NULL, wr,&w[1]);
            getchar();
        }

    }