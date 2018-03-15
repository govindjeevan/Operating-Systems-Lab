#include <stdio.h>
int last=0;
int n=0;
int cur=0;
struct process{
    int size;
    int start;
    int end;
};
int freespace[2][20];
int size (int a, int b)
    {
        return a-b;
    }

void display(struct process p[])
    {
        int i;
        printf("\n\tPARTITION TABLE\n\n");
        printf("\tProcess\t\tStart\t\tEnd\n");
        for(i=0;i<20;i++)
            {
                
                if(p[i].start==-1)
                    continue;
                printf("\t%d\t\t%d\t\t%d\n",i,p[i].start,p[i].end);
            }
    }

void fill(int *a, int start, int end, int p)
    {
        int i=0;
        for(i=start; i<end; i++)
            a[i]=1;
    }

void empty(int swap, int *a,struct process *p)
    {
        int i=0;
        for(i=p[swap].start; i< p[swap].end; i++)
            a[i]=0;
       
        p[swap].start=-1;  // CLEAR THE ALLOCATION IN PCB of SWAPPED PROCESS
        p[swap].end=-1;
        n--;
    }

void mem(int *a, int s)
    {
        int i=0;
        printf("\n\tMEMORY SPACE:\t");
        for(i=0; i<s; i++)
            printf("%d",a[i]);
        putchar('\n');
    }

/*
int freespace(int head,int memory[],int s)
    {
        int j=head;
        int count=0;
        while(memory[j]==0 && j<s)
            {
                j++;
                count++;
            }
        return count;
    }
*/
int select(int size)
    {
        int i=0;
        int best=-1;
        for(i=0;i<20;i++)
            {
                if(freespace[1][i]==-1)
                    continue;
                
                if(freespace[2][i] < size)
                    continue;
                
                if(best==-1)
                    {
                        best=i;
                        continue;
                    }
                
                if(freespace[2][best] < freespace[2][i])
                    best=i;                    
            }
        if(best==-1) return -1;
        else return freespace[1][best];
    }
int allocate(int n, struct process *p, int memory[], int s)
    {
        int i,j,count=0,x, head=-1;
        for(i=0;i<20;i++)
            {
            freespace[1][i]=-1;
            freespace[2][i]=0;
            }

        for(j=0;j<s;j++)
                    {
                        
                        x=0;
                        if(memory[j]==1)
                            continue;
                        freespace[1][count]=j;
                        while(memory[j]==0)
                            {
                                freespace[2][count]++;
                                j++;
                                if(j>=s) break;
                            }
                        count++;
                    }
                    head=select(p[n].size);
                    if(head==-1) return 0;
                            p[n].start=head;
                            p[n].end=head+p[n].size;
                            fill(memory,p[n].start,p[n].end,n);
                            printf("\n\n\t Process %d ( %d ) : \n\t%d -> %d\n\n",n,p[n].size,p[n].start,p[n].end);
                            mem(memory,s);
  
        if(p[n].start!=-1)
            return 1;
        else return 0;
    }

int main()
    {
        int i=0;
        int s;
        int x=1;


        printf("\nEnter the Memory Size:\n");
        scanf("%d", &s);
        int memory[s];
        for(i=0;i<s;i++)
            memory[i]=0;

        struct process p[20];
        for(i=0;i<20;i++)
            {
                
                p[i].size=-1;
                p[i].start=-1;
                p[i].end=-1;
            }

        while(x)
            {
                printf("\n\t1. ADD\n\t2. SWAP \n\t3. EXIT\n");
                scanf("%d", &x);

                switch(x)
                    {
                        case 1: 

                                printf("\nPROCESS SIZE: \n");
                                scanf("%d", &p[cur].size);
                                if( !allocate(cur,p,memory,s) )
                                    {
                                        printf("\nSPACE INSUFFICIENT\n");
                                        p[cur].size=-1;
                                    }
                                else {
                                    printf("n: %d",n);
                                    n++;
                                    cur++;
                                    display(p);
                                }

                                break;
                        case 2: 
                                display(p);
                                printf("\nSWAP PROCESS ID: \n");
                                scanf("%d",&i);
                                empty(i,memory,p);  // EMPTY THE MEMORY SEGMENT OF SWAPPED PROCESS
                                mem(memory,s);
                                display(p);                          
                                break;
                        case 3:
                                x=0;
                                break;

                        default: break;
                         
                    }
            }
        
    }