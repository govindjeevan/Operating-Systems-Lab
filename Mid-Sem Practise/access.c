//Change mod

#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
#include <sys/types.h> 
#include <sys/stat.h> 
#include<unistd.h>
#include<string.h>
#include<stdlib.h>



void main(){

    char path[]="chmodfile.txt";
   
    int fd=open(path, O_RDONLY | O_CREAT, S_IWUSR);
    if(fd<0){
        printf("\nError in opening file\n");exit(1);
    }
    else printf("\nFile opened with fd= %d\n", fd);

    printf("Checking Access for Read.....\n");
    if(access(path, R_OK)==0) printf("\tFile can be read\n");
    else printf("\tFile cannot be read\n");

    printf("Checking Access for Write.....\n");
    if(access(path, W_OK)==0) printf("\tFile can be written\n");
    else printf("\tFile cannot be written\n");

    

    printf("\n\tCHANGING MODE...\n");
    if(chmod(path, S_IRWXU)==0)printf("\nChanged mode to 'can Read/Write by user'\n"); 
    else printf("\nCannot change mode to 'can Read/Write by user'\n"); 


}


