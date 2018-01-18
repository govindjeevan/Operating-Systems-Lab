#include <stdio.h>

void sjfs(int n, int bt[], int p[])
    {
        int wt[n];
        int tt[n];
        int i;
        int rt[n]; 
        float wt_avg=0;
        float tt_avg=0;
        int x=1;
        int highest=1;

        for(i=0;i<n;i++)
            {
                wt[i]=0;
                rt[i]=bt[i];
            }
        for(x=0;x<n;x++)
        {   
     

            for(i=0;i<n;i++)
                {           
                    if(p[highest]<p[i] && p[i]!=-1)
                        highest=i;
                }

            
            for(i=0;i<n;i++)
                {
                    if(i!=highest && bt[i])
                        {
                            wt[i]+=bt[highest];
                        }
                }
            bt[highest]=0;
            p[highest]=-1;
        }

            
                
       for(i=0;i<n;i++)
        {       tt[i]=wt[i]+rt[i];
                printf("\nWaiting time Process %d = %d\n",i+1, wt[i]);
                printf("\nTurn Around time Process %d = %d\n\n", i+1, tt[i]);
        }
    }
int main()
    {
        int n;
        printf("\n\tEnter number of processes\n");
        scanf("%d",&n); 
        int bt[n];
        int p[n];
        int i;
        for(i=1;i<=n;i++)
            {
                printf("\n\tEnter the burst time of process %d\n",i);
                scanf("%d",bt+i-1);
                printf("\n\tEnter the priority of process %d\n",i);
                scanf("%d",p+i-1);
            }
        sjfs(n,bt,p);
        return 0;
    }