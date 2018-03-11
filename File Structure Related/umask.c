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

    char path[]="umask.txt";


    printf("\n\nImplementing umask()\n\n");
    int mode;
    int mask;
    printf("Enter the mod_t for file to be created: ");
    scanf("%o",&mode);
    printf("The Effective mod = %o (mode) & ~umask\nEnter umask value (xxxx)[octal]: ", mode);
    scanf("%o", &mask);
  
    int t=umask(mask);

     int fd=open(path,O_RDONLY|O_CREAT,mode);    
     // IF mode_t is specified here in open(), effective mode = mode & ~umask
    if(fd<0){
        printf("\nError in opening file\n");exit(1);
    }
    else printf("\nFile opened with fd= %d and Effective mod= 0%o\n",fd,mode-mask);

    
    printf("Checking Access for Read.....\n");
    if(access(path, R_OK)==0) printf("\tFile can be read\n");
    else printf("\tFile cannot be read\n");

    printf("Checking Access for Write.....\n");
    if(access(path, W_OK)==0) printf("\tFile can be written\n");
    else printf("\tFile cannot be written\n");

}


