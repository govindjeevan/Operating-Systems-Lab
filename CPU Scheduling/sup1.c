#include <stdio.h>
#include <stdlib.h>

// Node of priority queue that has index of a process as data
struct node 
{
    int p;
    int index;
    struct node *next;
}*head=NULL,*tail=NULL;


// Process details structure
struct process{
    int p;
    int wt;
    int bt;
    int at;
};

// Priority Queue Functions

void p_enqueue(int index, int p)
{
    struct node *newNode=(struct node*)malloc(sizeof(struct node));
    newNode->index=index;
    newNode->next=NULL;
    newNode->p=p;
    if(head==NULL && tail==NULL)
    {
        head=newNode;
        tail=head;
        return;
    }
    
    struct node *cur=head;
    
    if(cur->p < newNode->p)
        {
            head=newNode;
            head->next=cur;
            return;
        }
   
        while(cur->next!=NULL)
        {
            if((cur->next)->p > newNode->p)
                {
                    cur=cur->next;
                    continue;
                }
            else break;
        }
        
    struct node* temp=cur->next;
    cur->next=newNode;
    newNode->next=temp;
   
    }

void enqueue(int index, int p)
    {
        struct node *newNode=(struct node*)malloc(sizeof(struct node));
        newNode->index=index;
        newNode->p=p;
        newNode->next=NULL;
        if(head==NULL)
            {
                head=newNode;
                return;
            }
        
        struct node *cur=head;
        while(cur->next!=NULL)
            {   
                cur=cur->next;
            }
        cur->next=newNode;
    }
    
int dequeue()
    {
        if(head==NULL)
            return -1;
        struct node *temp=head;
        temp=head->next;
        int index=head->index;
        free(head);
        head=head->next;
        return index;
    }
int isEmpty()
    {
        if(head==NULL) return 1;
        else return 0;
    }
void display()
    {
        struct node *cur=head;

        printf("\n\t%d(%d)\t",(cur->index)+1, cur->p);
        while(cur->next!=NULL)
            {   
                cur=cur->next;
                printf("%d(%d)\t",(cur->index)+1, cur->p);
            }
        printf("\n");
    }

// The Scheduler
void schedule(struct process p[], int n, int t)
{
    int i=0;
    int cur;
    int clock=0;
    int del;
    int flag[n];
    for(i=0;i<n;i++)
            {
                p[i].wt=0;
            }
    
    while(isEmpty())
    {
        for(i=0;i<n;i++)
                    {
                        if(p[i].at==clock)
                            {
                                flag[i]=1;
                                p_enqueue(i,p[i].p);
                            }
                    }
        clock++;
    }
     printf("\n\n\t\t\tCLOCK: %d\n\n", clock);
     display();
    do
        {   
            del=1;
            cur=dequeue();
            if(cur==-1) break;
            
            if(p[cur].bt<t)
                del=p[cur].bt;
            else del=t;
            
            printf("\n\tProcess %d alloted %d s",cur+1,del);
            printf("\n\t( Remaining Times , Waiting Time ) :\n");
            
            for(i=0;i<n;i++)
                {
                    if(i!=cur)
                        {
                            if(flag[i]==1)p[i].wt+=del;
                        }
                    else
                        p[cur].bt-=del;
                    printf("\t\tProcess %d: (%d,%d)\n", i+1,p[i].bt,p[i].wt);
                }

            clock+=del;
            if(p[cur].bt)enqueue(cur,p[cur].p);
            if(p[cur].bt==0) flag[cur]=0;
           

            for(i=0;i<n;i++)
                {
                    if(p[i].at<=clock && !flag[i] && p[i].bt)
                        {
                            p_enqueue(i,p[i].p);
                            flag[i]=1;
                        }
                }
                 printf("\n\n\t\t\tCLOCK: %d\n\n", clock);
        if(!isEmpty())display();
        getchar();
            
        }   while(!isEmpty());
    
}
void main()
    {
        int i;
        int n=3;
        struct process p[n];
        
        p[0].bt=10;
        p[1].bt=7;
        p[2].bt=11;

        p[0].at=0;
        p[1].at=0;
        p[2].at=11;

        p[0].p=4;
        p[1].p=2;
        p[2].p=8;
        
     
        schedule(p,n,3);
    }