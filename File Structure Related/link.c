#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
#include <sys/types.h> 
#include <sys/stat.h> 
#include<unistd.h>
#include<string.h>
#include<stdlib.h>

extern int errno;



void main(){

        int fd=open("govind.txt", O_RDWR | O_CREAT);

        if(fd<0){printf("Error");}

        if(write(fd,"Hello",strlen("Hello"))<0){
            printf("Error");}
        
        if(link("govind.txt","new.txt")<0){
            printf("error");}


        unlink("govind.txt");
      
    //      unlink("new.txt");

}