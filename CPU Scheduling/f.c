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
    int bt_c[n];
    for(i=0;i<n;i++)
            {
               flag[i]=0;
               wt[i]=0;
               tt[i]=0;
               bt_c[i]=P[i].bt;
            }  
    int cur=-1;
    int time=0;
    while(x)
        { 
            printf("\nTime: %d\n", time);
            for(i=0;i<n;i++)
                {   
                    if(P[i].at<=time && P[i].bt)
                        {
                            flag[i]=1;
                            
                        }
                }
            if(cur==-1)
                { 
                    for(i=0;i<n;i++)
                        {   
                            if(flag[i])
                                {
                                    if(cur==-1)
                                        cur=i;
                                    if(P[i].at< P[cur].at)
                                        cur=i;
                                }
                        }
                }
        printf("\tFlags:");
        for(i=0;i<n;i++)
            {
               printf(" %d",flag[i]);
            }
        putchar('\n');
        printf("\tCurrent: %d\n",cur+1);

        for(i=0;i<n;i++)
            {
                if(flag[i] && i!=cur)
                    wt[i]++;
            }
        P[cur].bt--;

        if(P[cur].bt==0) 
            {
                x--;
                flag[cur]=0;
                cur=-1;
            }
        time++;
  
        printf("\n\tWAITING TIMES\n");
        for(i=0;i<n;i++)
            {
               printf("\tProcess %d: %d\n",i+1,wt[i]);
            }
        if(!x) {
            printf("\n****Process Ended*****\n\n\n");
            break;
        }
        getchar();
    }
   
   for(i=0;i<n;i++)
    {
        tt[i]=wt[i]+bt_c[i];
    }
    printf("\n\tTURN AROUND TIMES\n");
        for(i=0;i<n;i++)
            {
               printf("\tProcess %d: %d\n",i+1,tt[i]);
            }

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