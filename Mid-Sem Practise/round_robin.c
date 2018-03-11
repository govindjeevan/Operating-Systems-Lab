#include <stdio.h>

struct process{
    int bt;
    int at;
};


void schedule( struct process p[], int n, int t)
    {
        int i, j;
        int cur=-1;
        int flag[n];
        int wt[10];
        int bt_c[10];

        for(i=0;i<n;i++)
            {
                wt[i]=0;
                bt_c[i]=p[i].bt;
                flag[i]=0;
            }

        int timer=0;
        int x=1;
        while(x)
            {
                x=0;
                for(i=0;i<n;i++)
                    {
                        if(p[i].at<=timer && !flag[i] && bt_c[i])
                            flag[i]=1;
                    }
                for(i=0;i<n;i++)
                    {
                        if(flag[i])
                            {   printf("%d", i+1);
                                bt_c[i]--;
                                timer++;
                                for(j=0;j<n;j++)
                                    {
                                        if(j!=i && flag[j])
                                            wt[j]++;
                                    }
                                if(bt_c[i]==0) flag[i]=0;
                            }
                    }
                
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
        p[2].at=3;

        p[0].bt=2;
        p[1].bt=4;
        p[2].bt=6;

        schedule( p, 3, 1);

    }