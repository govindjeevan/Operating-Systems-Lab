#include <stdio.h>


struct process{
    int p;
    int at;
    int bt;
};

void schedule( struct process p[], int n)
    {
        int wt[n];
        int flag[n];
        int i,j;
        int cur=-1;

        int timer=0;
        int x=1;
        int bt_c[n];

        for(i=0;i<n;i++)
            {
                wt[i]=0;
                bt_c[i]=p[i].bt;
                flag[i]=0;
            }
        while(x)
        {   
            x=0;
            for(i=0;i<n;i++)
                {
                    if(p[i].at<=timer && bt_c[i]>0 && !flag[i])
                        flag[i]=1;
                }
            for(i=0;i<n;i++)
                {
                    if(cur==-1)
                        {
                            if(flag[i])
                                cur=i;
                        }
                    else if( p[cur].p < p[i].p && flag[i])
                            cur=i;
                }
            
            printf("%d", cur+1);

            bt_c[cur]--;
            for(i=0;i<n;i++)
                {
                    if(cur!=i && flag[i])
                        wt[i]++;
                }
            
            if(bt_c[cur]==0) {
                
                    flag[cur]=0;
                    cur=-1;
            }
            timer++;
            for(i=0;i<n;i++)
                {
                    x=x+bt_c[i];
                }
        }
    
        for(i=0;i<n;i++)
                    {
                        printf("\n %d wt: %d bt: %d", i+1, wt[i], bt_c[i]);
                    }
    }

int main()
    {
        struct process p[3];

        p[0].at=0;
        p[1].at=0;    
        p[2].at=2;    

        p[0].bt=6;    
        p[1].bt=3;    
        p[2].bt=8;        

        p[0].p=2;   
        p[1].p=1;    
        p[2].p=5;        
                      
        schedule(p,3);      
    }