#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
extern int errno;
int main()
{
   //kill is used to send signal to a process. if second argument is 0 it is just used to check whether a process with this id exists
   int fd=open("kill.txt",O_WRONLY|O_CREAT|O_TRUNC,0644);
   if(kill(getpid(),0)==0)
     printf("process with %d exists\n",getpid());
   else
     printf("process does not exist\n");
   return 0;
}
