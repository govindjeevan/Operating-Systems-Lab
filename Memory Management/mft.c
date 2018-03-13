#include <stdio.h>

struct partition{
    int size;
    int process;
    int fragment;
};

int count=0;

int freespace(struct partition p[], int n)
    {
        int i;
        int space=0;
        for(i=0;i<n;i++)
            {
                if(p[i].process!=-1)
                    continue;
                space=space+p[i].size;
            }
        return space;
    }
int select(int size, struct partition p[], int pa)
    {
        int i;
        int select=-1;
        for(i=0;i<pa;i++)
            {
                if(p[i].process != -1)
                    {
                       continue;
                    }
                if(p[i].size < size)
                    continue;
                if(select==-1)
                    {
                        select=i;
                        continue;
                    }
                if(p[select].size > p[i].size)
                    select=i;
            }
   
        return select;
    }

void display(struct partition p[], int pa)
    {
        int i;
        printf("\n\tPARTITION TABLE:\n\n");
        printf("\tPartition\tProcess\t\tSize\tInternalFragment\n");
        for(i=0;i<pa;i++)
            {   
                if(p[i].process==-1)
                    continue;
                printf("\t%d\t\t%d\t\t%d\t\t%d\n", i+1, p[i].process+1,p[i].size, p[i].fragment);
            }
    }
void allocation(struct partition p[], int pa, int process[], int pr)
    {
        int i;
        int selection;
        int x=0;
        for(i=0;i<pr;i++)
            {
                if(count==pa)
                    {
                        display(p, pa);
                        printf("\nProcess: %d \tSize: %d\n",i+1, process[i]);  
                        printf("\nAll partitions are occupied. Swap? [1/0]\n");
                        scanf("%d", &x);
                        if(x)
                            {
                                printf("Which Parition to Swap?\n");
                                scanf("%d", &x);
                                p[x-1].process=-1;
                                printf("%d is -1",x);                        
                                count--;
                            }
                        else break;
                    }
                selection=select(process[i], p, pa);
                if ( selection == -1)
                    {
                        printf("\n ALLOCATION NOT POSSIBLE:\n Process: %d \tSize: %d\n External Fragmentation size: %d\n\n",i+1, process[i], freespace(p, pa));
                        continue;
                    }
                else
                    {
                        printf("\n AllOCATION:\n Process: %d \tSize: %d\n Parition: %d \tSize: %d\n\n",i+1, process[i], selection+1, p[selection].size);
                        count++;
                        p[selection].process=i;
                        p[selection].fragment=p[selection].size-process[i];
                    }
                printf("%d\n",count);
            }
            display(p, pa);

    }

int main()
    {
        int i=0;
        int pr;
        int pa;

        printf("\nEnter the number of partitions");
        scanf("%d", &pa);
        struct partition p[pa];

        printf("\nEnter the size of partitions");
        for(i=0;i<pa;i++)
            {
                scanf("%d", &p[i].size);
                p[i].process=-1;
                p[i].fragment=0;
            }
     
 
        printf("\nEnter the number of proceses");
        scanf("%d", &pr);

        int process[pr];
        printf("\nEnter the size of processes");
        for(i=0;i<pr;i++)
            scanf("%d", &process[i]);


        allocation(p, pa, process, pr);
    }



   
