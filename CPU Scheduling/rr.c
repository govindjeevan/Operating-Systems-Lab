#include <stdio.h>

void waiting_time(int tq,int n, int bt[])
    {
        int wt[n];
        int tt[n];
        int i,j,k=0; 
        float wt_avg=0;
        float tt_avg=0;
        int del;
        int completed[n];
        int x=1;
        for(i=0;i<n;i++)
            wt[i]=0;
        while(bt[0] || bt[1] || bt[2])
        {
            for(i=0; i<n; i++)
                        {   
                            if(!bt[i]) continue;
                            if(bt[i]>tq)
                                    del=tq;
                            else
                                del=bt[i];
                            
                            bt[i]-=del;
        
                            for(j=0;j<n;j++)
                                if(j!=i && bt[j]) wt[j]+=del;       
                        }
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
        waiting_time(2,n,bt);
        return 0;
    }