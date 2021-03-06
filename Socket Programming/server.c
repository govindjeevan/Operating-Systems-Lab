#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h> 


int main()
    {
     
        //create the server socket;
        int server_socket;  char server_message[256];
        char client_response[256];
        server_socket=socket(AF_INET, SOCK_STREAM, 0);

        struct sockaddr_in server_address, client_address;
       
     

        server_address.sin_family = AF_INET;
        server_address.sin_port=htons(9002);
        server_address.sin_addr.s_addr= INADDR_ANY;
           


        //binding the socket to the specified IP and port

        bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address));

        if(listen(server_socket, 5)!=-1)printf("\nServer listening..\n");
        
        int client_socket=1;
        int l=sizeof(client_address);

        client_socket=accept(server_socket, (struct sockaddr *) &client_address ,&l); 
           
        if(client_socket!=-1)
            printf("Server is connected with IP address %s and port %d\n",inet_ntoa(client_address.sin_addr),ntohs(client_address.sin_port));

        int id=fork();

        if(id){
            while(recv(client_socket, &client_response, sizeof(client_response), 0)>0)
            {           
                  
                       printf("\n\t %s\n\n\t",client_response);
                       sleep(1);
            }   
        }
        else while(1){
                    printf("\n\t ");
                    gets(server_message);
                    send(client_socket, server_message, sizeof(server_message), 0);
                    bzero(server_message,256);
                    sleep(1);
                    }  

    }