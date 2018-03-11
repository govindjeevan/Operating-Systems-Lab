//Change owner
// run ./a.out as super user
// sudo ./a.out

#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
#include <sys/types.h> 
#include <sys/stat.h> 
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include <pwd.h>

void main(){

    char path[]="chownfile.txt";
    
    int fd=open(path, O_WRONLY | O_CREAT, S_IRUSR);
    if(fd<0){
                printf("\nError in opening file\n\n");exit(1);
            }
    else printf("\nFile opened with fd= %d\n\n", fd);
    char buffer[]="helo";
    write(fd, "hello\n",strlen("Hello"));

    }