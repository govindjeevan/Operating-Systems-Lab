//wait,getpid,getppid,getuid,geteuid,getgid,getegid,exit,fork
#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>
#include<pwd.h> 
int main()
{
   int l,fd;
   if(fork()!=0)
    {
         printf("1\n");
         l=getpid();
         printf("real process id =%d\neffective process id =%d\n",getpid(),getppid());
         wait(NULL);
         printf("2\n");
         exit(2);
    }
   else
         printf("3\n");
   //fd=chdir("chown.txt");
   //printf("fd of changed directory=%d\n",fd);
   printf("default\n");
   printf("real user id=%d\neffective user id=%d\n",getuid(),geteuid());
  
   printf("real group id=%d\neffective group id=%d\n",getgid(),getegid());
}
