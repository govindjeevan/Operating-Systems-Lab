//chdir,chown
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<pwd.h>

int main()
{
    int fd,fd1;
    char *c="..";
    fd1=open("new.txt",O_CREAT|O_RDONLY,00700|00070|07000);
    if(chdir(c)==-1)
       printf("error\n");
    else
       printf("directory changed successfully\n");
      int fd2=open("new1.txt",O_CREAT|O_RDONLY,00700|00070|07000);
   return 0;
}
