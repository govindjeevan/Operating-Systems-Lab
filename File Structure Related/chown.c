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
    
    int fd=open(path, O_RDONLY | O_CREAT, S_IRUSR);
    if(fd<0){
        printf("\nError in opening file\n\n");exit(1);
    }
    else printf("\nFile opened with fd= %d\n\n", fd);

    printf("Current User ID = %d\t\t", getuid());
    printf("User Name = %s\n\n", getpwuid(getuid())->pw_name);
    printf("Alternate User ID = %d\t\t", getuid()+1);
    printf("User Name = %s\n", getpwuid(getuid()+1)->pw_name);

    if(chown(path,getuid()+1,getuid()+1)==0)printf("Owner changed to %s\n",getpwuid(getuid()+1)->pw_name);
    else printf("Change of owner unsuccesful ( Try using sudo ./a.out )\n");



    }