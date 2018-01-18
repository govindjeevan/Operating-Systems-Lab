#include <stdio.h>

void sjfs(int n, int bt[])
    {
        int wt[n];
        int tt[n];
        int i; 
        float wt_avg=0;
        float tt_avg=0;
        int x=1;
        int shortest;
        for(i=0;i<n;i++)
            wt[i]=0;
        for(x=0;x<n;x++)
        {
            for(i=0;i<n; i++)
                if(bt[i]) 
                    {
                        shortest=i;
                        break;
                    }
            for(i=0;i<n;i++)
                {           
                    if(bt[i]<bt[shortest] && bt[i])
                        shortest=i;
                }

            
            for(i=0;i<n;i++)
                {
                    if(i!=shortest && bt[i])
                        wt[i]+=bt[shortest];
                }
            bt[shortest]=0;
        }
            
                
        for(i=0;i<n;i++) 
                printf("\n%d is the waiting time for process %d\n", wt[i],i+1);
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