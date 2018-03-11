#include <stdio.h>

void fcfs(int n, int bt[])
    {
        int wt[n];
        int tt[n];
        int i; 
        float wt_avg=0;
        float tt_avg=0;

       
        for(i=0;i<n;i++)
            {   
                if(!i)  wt[i]=0;
                else    wt[i]=wt[i-1]+bt[i-1];
                printf("\n%d is the waiting time for process %d\n", wt[i],i+1);
                wt_avg+=wt[i];
            }
        for(i=0;i<n;i++)
            {
                if(!i)  tt[i]=bt[i];
                else    tt[i]=wt[i]+bt[i];
                printf("\n%d is the turn around time for process %d\n", tt[i],i+1);
                tt_avg+=tt[i];
            }
       
        wt_avg/=n;
        tt_avg/=n;
        printf("Average Waiting time= %f\n",wt_avg);
        printf("Average Turn Around time= %f\n",tt_avg);
    
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
        waiting_time(n,bt);
        return 0;
    }