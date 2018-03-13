#include <stdio.h>
int last=0;

struct process{
    int size;
    int start;
    int end;
};

int size (int a, int b)
    {
        return a-b;
    }

void display(struct process p[], int n )
    {
        int i;
        printf("\n\tPARTITION TABLE\n\n");
        printf("\tProcess\t\tStart\t\tEnd\n");
        for(i=0;i<n;i++)
            {
                if(p[i].start==-1)
                    continue;
                printf("\t%d\t\t%d\t\t%d\n",i,p[i].start,p[i].end);
            }
    }

void fill(int *a, int start, int end)
    {
        int i=0;
        for(i=start; i<end; i++)
            a[i]=1;
    }

void empty(int *a, int start, int end)
    {
        int i=0;
        for(i=start; i<end; i++)
            a[i]=0;
    }

void mem(int *a, int s)
    {
        int i=0;
        puchar('\t');
        for(i=0; i<s; i++)
            printf("%d",a[i]);
    }
void allocation( struct process p[], int n, int s, int memory[])
    {
        int i,j,end;
        int max;
        int x=0;
        int flag;
        int count=0;
        for(i=0;i<n;i++)
            {
                if(p[i].size > s)
                    {
                        printf("\n\tProcess %d Larger Than Memory.\n",i);
                        continue;
                    }



                
                for(j=0;j<s;j++)
                    {
                        max=0;
                        count=0;
                        x=0;
                        if(memory[j]==1)
                            continue;

                        x=j;
                        
                        while(memory[j]!=1 && j<s)
                            {
                                j++;
                                count++;
                            }
                        if( count > max)
                            max=count;
                        if( count >= p[i].size)
                        {
                            p[i].start=x;
                            p[i].end=x+p[i].size;
                            fill(memory,p[i].start,p[i].end);
                            printf("\n\n\t Process %d: %d -> %d\n\n",i,p[i].start,p[i].end);
                            mem(memory,s);
                            break;
                        }       
                    }
                
                if (p[i].start==-1)
                    {
                        printf("\n\n\tLargest Contiguous Free Space: %d\n",max);                        
                        printf("\n\tProcess %d: NOT ALLOCATED. Swap? [1/0]\n",i);
                        scanf("%d", &x);
                        if(x)
                            {   
                                display(p, n);        
                                printf("\nProcess to swap:\n");
                                scanf("%d",&x);
                                empty(memory,p[x].start,p[x].end);
                                p[x].start=-1;
                                p[x].end=-1;
                                i=i-1;
                            }
                    }


                
            }
       


        display(p, n);
    }
int main()
    {
        int i=0;
        int n;
        int s;

        printf("\nEnter the Memory Size:\n");
        scanf("%d", &s);
           
        int memory[s];
        for(i=0;i<s;i++)
            memory[i]=0;
        
        printf("\nNumber of Proceses:\n");
        scanf("%d", &n);

        struct process p[n];

        for(i=0;i<n;i++)
            {
                p[i].start=-1;
                p[i].end=-1;
            }
        printf("\nSize of processes:\n");
        for(i=0;i<n;i++)
            scanf("%d", &p[i].size);
        mem(memory,s);

        allocation(p, n, s, memory);
    }



   
