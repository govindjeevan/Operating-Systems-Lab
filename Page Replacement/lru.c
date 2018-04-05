#include<stdio.h>

int i,j,k,f[10],p[100],pf=0,frames,flag=0,repeat=0,page,lru[10],count=0, min,pindex,minindex;

void display()
{
    for(j=0;j<frames;j++)
        {
            printf("%d\t",f[j]);
        }
        printf("\n");
}

int lru1(int pindex) 
{
    for(k=0;k<frames;k++)  
    {
        if(lru[k]==-1) 
        {
            lru[k]=pindex; 
            return k; 
        }
    }

    min=lru[0]; 
    minindex=0;
    for(k=1;k<frames;k++) 
    {
        if(lru[k]<min)
        {
            min=lru[k];
            minindex=k;
        }
    }
    lru[minindex]=pindex; 
    return minindex; 
}

int main()
{
    printf("enter the number of frames:\n");
    scanf("%d", &frames);
    printf("enter the number of pages:\n");
    scanf("%d",&page);
    printf("Enter the page details\n");
    for(i=0;i<page;i++)
        {
            scanf("%d",&p[i]);
        }
    for(j=0;j<frames;j++)
        {
            f[j]=-1;
        }
    for(j=0;j<frames;j++)
        {
            lru[j]=-1; 
        }
    display();
    for(i=0;i<page;i++)
    {
        repeat=0;
        for(j=0;j<frames;j++)
        {
            if(f[j]==p[i])
            {
                repeat=1;
                lru[j]=i; 
                display();
                break;
            }
            else
            continue;
        }
        if(repeat==0)
        {
            flag=lru1(i); 
            f[flag]=p[i];
            display();
            pf++;
        }
    }
    printf("Number of page fault = %d\n",pf);
}
