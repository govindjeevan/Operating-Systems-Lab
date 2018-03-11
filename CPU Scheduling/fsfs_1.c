#include <stdio.h>

struct process{
    int bt;
    int at;
};

void fcfs(struct process *P, int n){
    int i,j,k,x=n;
    int flag[n];
    int wt[n];
    int tt[n];
    int cur=0;


}


void main()
    {
        int n,i;
        printf("\n\tEnter number of processes\n");
        scanf("%d",&n); 
        struct process P[n];
                
        for(i=1;i<=n;i++)
            {
                printf("\n\tEnter the arrival time of process %d\n",i);
                scanf("%d",&P[i-1].at);
                printf("\n\tEnter the burst time of process %d\n",i);
                scanf("%d",&P[i-1].bt);
            }




        fcfs(P,n);
    }