// SHORTEST SEEK TIME FIRST DISK SCHEDULING

#include <stdio.h>

int mod(int x)
    {
        if (x>=0)
            return x;
        else return -x;
    }

int shortest_seek( int c, int cyllinder[], int n)
    {
        int i=0;
        int min=-1;
        for(i=0; i<n; i++)
            {
                if(i==c)
                    continue;
                if( cyllinder[i]== -1)
                    continue;

                if (min==-1)
                    min=i;
                if( mod(cyllinder[i]-cyllinder[c]) < mod(cyllinder[min]-cyllinder[c]) )
                    min=i;       
            }
        return min;
    }

int main()
    {
        printf("%d",mod(5-10));
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
                next=shortest_seek(head, cyllinder, n);
                seekNext=mod(cyllinder[head]-cyllinder[next]);
                seek=seek+ seekNext;
                printf( "\n\tHEAD FROM %d to %d SEEK TIME: %d\n", cyllinder[head], cyllinder[next], seekNext);
                cyllinder[head]=-1;
                head=next;
            }
        printf("\n\n\t\tTOTAL SEEK TIME: %d\n", seek);

    }