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
            loop:
            printf("Do you want to exit? [1/0]\n");
            int x;
            scanf("%d",&x);
            if(x) exit(2);
            else goto loop;           
    }