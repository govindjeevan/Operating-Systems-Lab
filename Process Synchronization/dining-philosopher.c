#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>

sem_t spoon[2];

pthread_t philosopher[2];


void pickup(int i, int p)
    {
        printf("\n%d tries spoon %d. %d\n",p,i,spoon[i]);
        sem_wait(&spoon[i]);
        printf("\n%d takes spoon %d. %d \n",p,i,spoon[i]);
    }

void putdown(int i, int p)
    {
        sem_post(&spoon[i]);
        printf("\n%d is done with spoon %d. %d\n",p,i,spoon[i]);
    }
void *p(void *i)
    {
        char *s=i;
        int p=atoi(s);
        int a=(p-1)%2;
        int b=p%2;
        int a_flag,b_flag;

        printf("\n%d Wants to eat\n",p);
        do
            {
                sem_getvalue(&spoon[a], &a_flag);
                sem_getvalue(&spoon[b], &b_flag);
                printf("\n%d %d\n",a_flag,b_flag);
                sleep(1);

            }   while(!a_flag || !b_flag);
        pickup(a, p);
        pickup(b, p);
        printf("\n\t%d is eating\n",p);
        sleep(3);
        putdown(a,p);
        putdown(b,p);
        printf("\n%d finishes eating\n",p);
    }

int main()
    {

        sem_init(&spoon[0],0,1);
        sem_init(&spoon[1],0,1);
        int i;
        int n=2;
        for(i=0;i<n;i++)
            {
            char s=i+'0';
            pthread_create(&philosopher[i],NULL,p,&s);
            }
        getchar();


    }
