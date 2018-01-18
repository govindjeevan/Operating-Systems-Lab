#include <stdio.h>

void sjfs(int n, int bt[])
    {
        int wt[n];
        int tt[n];
        int rt[n];
        int i; 
        float wt_avg=0;
        float tt_avg=0;
        int x=1;
        int shortest;
        for(i=0;i<n;i++)
            {
                wt[i]=0;
                rt[i]=bt[i];
            }
        for(x=0;x<n;x++)
            {
                for(i=0;i<n; i++)
                    if(rt[i]) 
                        {
                            shortest=i;
                            break;
                        }
                for(i=0;i<n;i++)
                    {           
                        if(rt[i]<rt[shortest] && rt[i])
                            shortest=i;
                    }
                
                
                for(i=0;i<n;i++)
                    {
                        if(i!=shortest && rt[i])
                            wt[i]+=rt[shortest];
                            tt[i]=wt[i]+bt[i];
                    }
                rt[shortest]=0;
            }
            
                
        for(i=0;i<n;i++)
        {
                printf("\nWaiting time Process %d = %d\n",i+1, wt[i]);
                printf("\nTurn Around time Process %d = %d\n", i+1, tt[i]);
        }
    }

int main()
    {
        int n;
        printf("\n\tEnter number of processes\n");
        scanf("%d",&n); 
        int bt[n];
        int i;
        for(i=1;i<=n;i++)
            {
                printf("\n\tEnter the burst time of process %d\n",i);
                scanf("%d",bt+i-1);
            }
        sjfs(n,bt);
        return 0;
    }