#include<stdio.h>
#include <sys/types.h>
#include<unistd.h>
# include <stdlib.h>
int main()
{ putchar('\n');
int id;
   int i;
   for(i=0;i<2;i++)
   	{
   		id=fork();
   	}
   printf("\t\tProcess id=%d\n",id);
   printf("\t\tOne printf, but four prints. Because, exponential reproduction\n");
   putchar('\n');

printf("Using exit on all parent processes....\n All alive processes will say hi now\n");

if(id) {exit(1);}

printf("\n\tHi There, %d is still alive!\n",id);
putchar('\n');

}
