//alarm
#include <stdio.h>
#include <signal.h>
 #include <unistd.h>
 #include<stdlib.h>
void handler()
	{
	printf("Stopping this\n");
	exit(1);
	}
 
void main()
	{
	
	int i;
	signal(SIGALRM,handler);
	alarm(5);
	for(i=1;;i++)
		printf("hey\n");
	
	}
