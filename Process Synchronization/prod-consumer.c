#include <stdio.h>
#include <stdlib.h>


int mutex=1;
int empty=3;
int full=0;

int wait(int s)
    {
        return --s;
    }
int signal(int s)
    {
        return ++s;
    }

void producer()
    {
        mutex=wait(mutex);
        full=signal(full);
        empty=wait(empty);
        printf("\n\tProducer produces item %d\n", full);
        mutex=signal(mutex);

    }

void consumer()
    {
        mutex=wait(mutex);
        printf("\n\tConsumer consumes item %d\n", full);
        full=wait(full);
        empty=signal(empty);
        mutex=signal(mutex);
    }
int main()
    {
        int n;
        while(1)
        {
            printf("\nEnter Choice\n\t1.Produce\n\t2.Consume\n\t3.Exit\n");
            scanf("%d",&n);
            switch(n)
                {
                    case 1: if(mutex==1 && empty!=0)
                            producer();
                            else printf("\n\tBuffer is full\n");
                            break;
                    case 2: if(mutex==1 && full!=0)
                            consumer();
                            else printf("\n\tBuffer is empty\n");
                            break;
                    case 3: exit(1);
                }
        }
        return 0;
    }