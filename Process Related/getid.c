#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
#include <sys/types.h> 
#include <sys/stat.h> 
#include<unistd.h>
#include<string.h>
#include<stdlib.h>



void main()
    {
        printf("\nUserId: %d\nGroupId: %d\nEffective GroupId: %d\nProcessId: %d\nParent Process Id: %d\n", getuid(),
        getgid(),getegid(),getpid(),getppid());


    }