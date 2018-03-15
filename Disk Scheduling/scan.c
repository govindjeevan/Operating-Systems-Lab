// SHORTEST SEEK TIME FIRST DISK SCHEDULING

#include <stdio.h>

int mod(int x)
    {
        if (x>=0)
            return x;
        else return -x;
    }

int next_cyl( int c, int cyllinder[], int n)
    {
        int i;
        int next;
        if( c == n-1)
            {
                for(i=c-1;i>0;i--)
                    {
                        printf("1 %d ",i);
                        
                        if(cyllinder[i]==-1)
                            continue;
                        next=i;
                        printf("2 %d ",i);
                        
                    }
                return next;
            }
        if( cyllinder[c+1]==-1)
            {
                next=c-1;
                return next;
            }
        
        return c+1;
    }
void sort(int *cyllinder, int n)
    {
        int i,j,temp;
        for(i=0;i<n;i++)
            for(j=0;j<i;j++)
                {
                    if(cyllinder[j]>cyllinder[i])
                        {
                            temp=cyllinder[j];
                            cyllinder[j]=cyllinder[i];
                            cyllinder[i]=temp;
                        }
                }     
            
    }
int main()
    {
        int n,i;
        printf("\n\tENTER NUMBER OF CYLLINDERS: ");
        scanf("%d", &n);
        int cyllinder[n];
        int head;
        printf("\n\tENTER CYLLINDER NUMBERS: ");
        for(i=0;i<n;i++)
            {
                scanf("%d", &cyllinder[i]);
            }
        
        sort(cyllinder,n);
        for(i=0;i<n;i++)
            printf("%d ",cyllinder[i]); 
        printf("\n\tENTER START HEAD: ");
        scanf("%d", &head);

        for(i=0;i<n;i++)
            {
                if(cyllinder[i]==head)
                    {
                        head=i;
                        break;
                    }
            }

        int seek=0;
        int next;
        int seekNext;
        
        for(i=0;i<n-1;i++)
            {
                next=next_cyl(head,cyllinder,n);
                seekNext=mod(cyllinder[head]-cyllinder[next]);
                seek=seek+ seekNext;
                printf( "\n\tHEAD FROM %d to %d SEEK TIME: %d\n", cyllinder[head], cyllinder[next], seekNext);
                cyllinder[head]=-1;
                head=next;
            }
        printf("\n\n\t\tTOTAL SEEK TIME: %d\n", seek);

    }