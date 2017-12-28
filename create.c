#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
#include <sys/types.h> 
#include <sys/stat.h> 
#include<unistd.h>
#include<string.h>
#include<stdlib.h>

extern int errno;

void main()
    {
        char string[20];
        char string2[20];
        char message[20]="DUPLICATED ENTITY";

        printf("Enter string");
        gets(string2);
        int fd1=creat("govind.txt",S_IRWXU|S_IRWXG|S_IRWXO);

        if(fd1<0)
            {
                    printf("Error Number: %d", errno);
                    exit(1);
            }

        write(fd1,string2,strlen(string2));
        int fd2=open("govind.txt",O_RDWR);
        
        if( fd2<0 )
           {
            printf("Error Number: %d", errno);
            exit(1);
           }

        
        int dup1=dup(fd2);
        write(dup1,message,strlen(message));
        //read(fd2,string,5); 
     
        lseek(fd2,4,SEEK_CUR);
        read(fd2,string,6);
        write(1,string,5);

     



        close(fd2);
        close(fd1);
    }