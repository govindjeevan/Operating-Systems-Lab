#include<stdio.h>
void main()
{
int memsize;
int lmemsize;
int pagesize,nofpage;
int p[100];
int frameno,offset;
int logadd,phyadd;
int i;
int choice=0;
printf("\nYour physical memsize is: ");
scanf("%d",&memsize);
printf("\nYour logical memsize is: ");
scanf("%d",&lmemsize);
printf("\nEnter page size:");
scanf("%d",&pagesize);

nofpage=lmemsize/pagesize;

for(i=0;i<nofpage;i++)
{
printf("\nEnter the frame of page%d:",i+1);
scanf("%d",&p[i]);
}

do
{
printf("\nEnter a logical address:");
scanf("%d",&logadd);
if(logadd>lmemsize) printf("\nInvalid Logical Address\n");
frameno=logadd/pagesize;
offset=logadd%pagesize;
phyadd=(p[frameno]*pagesize)+offset;
printf("\nPhysical address is:%d",phyadd);
printf("\nDo you want to continue(1/0)?:");
scanf("%d",&choice);
}while(choice==1);
}