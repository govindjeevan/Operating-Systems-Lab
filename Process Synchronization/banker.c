#include <stdio.h>



int main()
    {
        int counter=0, p, r, i, j;
        int safe, exec;
        printf("\nEnter the number of processes: ");
        scanf("%d", &p);
        printf("\nEnter the number of resources: ");
        scanf("%d", &r);

        
        int current[p][r];
        int claim[p][r];

        int maxRes[r];
        int available[r];
        int allocation[r];
        int running[p];

        for(i=0;i<r;i++)
            {
                available[i]=0;
                allocation[i]=0;
            }

        for(i=0;i<p;i++)
            {
                running[i]=1;
                counter++;
            }

        printf("\nEnter the number of each resource \n");
        for(i=0;i<r;i++)
            {
                scanf("%d",&maxRes[i]);
            }
        printf("\nEnter current allocation of resources to processes \n");
        for(i=0;i<p;i++)
            for(j=0;j<r;j++)
                scanf("%d", &current[i][j]);
        
        printf("\nEnter maximum claim of resources by each process \n");
        for(i=0;i<p;i++)
            for(j=0;j<r;j++)
                scanf("%d", &claim[i][j]);
        
        
        for(i=0;i<p;i++)
            for(j=0;j<r;j++)
                allocation[j]+=current[i][j];
        
        for(i=0;i<r;i++)
            available[i]=maxRes[i]-allocation[i];

        printf("\nThe Availability Vector is: ");
                for (i = 0; i < r; i++) 
        {
                printf("\t%d", maxRes[i]);
        }
        getchar();
        printf("\nThe Allocated Resource Table:\n");
        for (i = 0; i < p; i++) 
        {
            for (j = 0; j < r; j++) 
            {
                    printf("\t%d", current[i][j]);
            }
           printf("\n");
        }
        getchar();
        printf("\nThe Maximum Claim Table:\n");
        for (i = 0; i < p; i++) 
        {
            for (j = 0; j < r; j++) 
            {
                printf("\t%d", claim[i][j]);
            }
            printf("\n");
        }
        
        getchar();
        printf("\nAllocation resources:");
        for (i = 0; i < r; i++) 
        {
            printf("\t%d", allocation[i]);
        }
        printf("\nAvailable resources:");
        for (i = 0; i < r; i++) 
        {
            printf("\t%d", available[i]);
        }
 
    
        while(counter)
            {
                safe=0;

                for(i=0;i<p;i++)
                    {   
                        if(running[i])
                            { 
                                exec=1;
                                for(j=0;j<r;j++)
                                    {
                                        if(claim[i][j] - current[i][j] > available[j])
                                            {
                                                exec=0;
                                                break;
                                            }

                                    }
                            }
                        
                        if(exec)
                            {
                                printf("\n%d has finished\n",i);
                                running[i]=0;
                                counter--;
                                safe=1;

                                for(j=0;j<r;j++)
                                    available[j]+=current[i][j];
                                break;

                            }
                    }
                if(!safe)
                    printf("\nUNSAFE\n");
                else 
                    printf("\nSAFE\n");
            }
    }