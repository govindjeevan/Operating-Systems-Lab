
#include<stdio.h> 
#include<stdio.h>
int i,j,f[10],p[100],pf=0,frames,flag=0,repeat=0,page;

void display()
{
    for(j=0;j<frames;j++)
        {
            printf("%d\t",f[j]);
        }
        printf("\n");
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
    display();
    for(i=0;i<page;i++)
    {
        repeat=0;  
        for(j=0;j<frames;j++) 
        {
            if(f[j]==p[i]) 
            {
                repeat=1;
                display();
                break;
            }
            else
            continue; 
        }
        if(repeat!=1)
        {
            f[flag]=p[i];
            display();
            flag++; 
            if(flag==frames) //if it is the last frame
            {
                flag=0; 
            }
            pf++; 
        }
    }
    printf("Number of page fault = %d\n",pf);

}


