#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
#include <sys/types.h> 
#include <sys/stat.h> 
#include<unistd.h>
#include<string.h>
#include<stdlib.h>

int main(int argc, char *argv[])
    {   
        int fd=open("ioctl.txt",O_CREAT|O_RDONLY,0600);


        return 0;
    }