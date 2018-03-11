#include <stdio.h>
#include <stdlib.h>

struct process{
    int p;
    int wt;
    int bt;
};

void swap(struct process *a, struct process *b)
{
    struct process *temp;    
    temp->p=a->p;
    temp->wt=a->wt;
    temp->bt=a->bt;

    a->p=b->p;
    a->bt=b->bt;
    a->wt=b->wt;

    b->p=temp->p;
    b->wt=temp->wt;
    b->bt=temp->bt;

    free(temp);
}

int maximum(struct process p[], int n )
    {
        int i=0;
        int max=0;
        for(i=0;i<n;i++)
            {
                if(p[i].wt > p[max].wt)
                    if(p[i].bt>0) max=i;
            }
        return max;
    }

void schedule(struct process p[], int n, int T)
    {   
        int time=0;
        int cur;
        int i;
        int x=1;
        int del;
        for(i=0;i<n;i++)
            {
                p[i].wt=0;
            }
        while(x)
            {   x=0;
                del=0;
                cur=maximum(p,n);
                if(p[cur].bt<T)
                        del=p[cur].bt;
                else del=T;
                printf("\n\tProcess %d alloted %d s",cur+1,del);
                printf("\n\t( Remaining Times , Waiting Time ) :\n");
                for(i=0;i<n;i++)
                    {
                        if(i!=cur)
                            {
                                if(p[i].bt)
                                    p[i].wt+=del;
                            }
                        else 
                            p[cur].bt-=del;

                        printf("\t\tProcess %d: (%d,%d)\n", i+1,p[i].bt,p[i].wt);
                        x+=p[i].bt;    
                    }
                putchar('\n');
                getchar();
            }
    }

void main()
    {

                int n=4;
                struct process p[n];
                p[0].bt=10;
                p[1].bt=12;
                p[2].bt=2;
                p[3].bt=7;
                schedule(p,n,3);
            
   
    }