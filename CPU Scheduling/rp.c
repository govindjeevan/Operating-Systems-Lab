#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
}*head=NULL,*rear=NULL,*temp=NULL ;


struct process{
    int bt;
    int at;
    int pt;
};


int count=0;

void enqueue(int data)
    {
        if(rear==NULL)
            {
                rear = (struct node *)malloc(1*sizeof(struct node));
                rear->next = NULL;
                rear->data = data;
                head= rear;
            }
        else
            {
                temp=(struct node *)malloc(1*sizeof(struct node));
                rear->next = temp;
                temp->data = data;
                temp->next = NULL;
                rear = temp;
            }
        count++;
    
    }
    
int dequeue()
{   

    int data;

    if(head==NULL) return -1;

    if(head->next!=NULL)
        {
            temp=head->next;
            data=head->data;
            free(head);
            head=temp;
            return data;
        }
    else
        {
            data=head->data;
            free(head);
            head=NULL;
            rear=NULL;
            return data;
        }
    count--;
}
void waiting_time(int tq,int n, struct process P[])
    {   
        int i;
        int time=0;
        int cur=-1;
        int del;
        int st=0;
        int bt_c[n];
        int flag[n];
        int wt[n];
        int tt[n];
        for(i=0;i<n;i++)
            {
               bt_c[i]=P[i].bt;
               flag[i]=0;
               wt[i]=0;
               tt[i]=0;
            }  

        while(1)
            {   
                printf("\nTime: %d\n", time);


                for(i=0;i<n;i++)
                    {
                        if( flag[i]!=1 && time==P[i].at && P[i].bt )
                            {
                                enqueue(i);
                                flag[i]=1;
                            }
                    }
                
                if( cur==-1 )
                    {
                        cur=dequeue();
                        if( cur==-1 )
                            break;
                        
                        if(P[cur].bt<tq)
                            del=P[cur].bt;
                        
                        else
                            del=tq;
                        
                        st=time;

                    }
                
                P[cur].bt--;
                for(i=0;i<n;i++)
                    {
                        if(flag[i] && i!=cur)
                        wt[i]++;
                    }
                
                printf("\tFlags:");
                for(i=0;i<n;i++)
                    {
                    printf(" %d",flag[i]);
                    }

                putchar('\n');
                printf("\tCurrent: %d\n",cur+1);
                
                printf("\n\tREMAINING BURST TIMES\n");
                for(i=0;i<n;i++)
                    {
                    printf("\tProcess %d: %d\n",i+1,P[i].bt);
                    }
                printf("\n\tWAITING TIMES\n");
                for(i=0;i<n;i++)
                    {
                    printf("\tProcess %d: %d\n",i+1,wt[i]);
                    }
  
                


                time++;
                if(time==st+del)
                    {   
                        if(!P[cur].bt)
                            flag[cur]=0;
                        else
                            enqueue(cur);
                        cur=-1;
                    }
                getchar();
            }
        for(i=0;i<n;i++)
            {
                tt[i]=wt[i]+bt_c[i];
            }
        printf("\n\tTURN AROUND TIMES\n");
        for(i=0;i<n;i++)
            {
               printf("\tProcess %d: %d\n",i+1,tt[i]);
            }
    }


void main()
    {
        int n,i;
        printf("\n\tEnter number of processes\n");
        scanf("%d",&n); 
        struct process P[n];
                
        for(i=1;i<=n;i++)
            {
                printf("\n\tEnter the arrival time of process %d\n",i);
                scanf("%d",&P[i-1].at);
                printf("\n\tEnter the burst time of process %d\n",i);
                scanf("%d",&P[i-1].bt);
            }
        waiting_time(2,n,P);
    }