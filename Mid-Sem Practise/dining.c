#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>
#define N 5
#define THINKING 2
#define HUNGRY 1
#define EATING 0
#define LEFT (p + 4) % N
#define RIGHT (p + 1) % N
 
int state[N];
int phil[N] = { 0, 1, 2, 3, 4 };
 
sem_t mutex;
sem_t S[N];
 

void test(p)
    {
        if(state[p]==HUNGRY && state[LEFT]!=EATING && state[RIGHT]!=EATING)
            {state[p]=EATING;
        sleep(2);
        printf("%d takes %d and %d fork\n", p+1, LEFT+1, p+1);
        printf("%d eating\n",p+1);

        sem_post(&S[p]);
    }}
void takefork(int p)
    {
        sem_wait(&mutex);
        printf("%d is hungry\n", p+1);
        state[p]=HUNGRY;
        test(p);
        sem_post(&mutex);

        sem_wait(&S[p]);
        sleep(1);

    }
void *philosopher(void *p)
    {
        int *i=p;

        while(1)
            {
                sleep(1);
                takefork(*i);
                sleep(0);
                putfork(*i);

            }

    }
int main()
{
 
    int i;
    pthread_t thread_id[N];
 
    // initialize the semaphores
    sem_init(&mutex, 0, 1);
 
    for (i = 0; i < N; i++)
 
        sem_init(&S[i], 0, 0);
 
    for (i = 0; i < N; i++) {
 
        // create philosopher processes
        pthread_create(&thread_id[i], NULL,
                       philospher, &phil[i]);
 
        printf("Philosopher %d is thinking\n", i + 1);
    }
 
    for (i = 0; i < N; i++)
 
        pthread_join(thread_id[i], NULL);
}