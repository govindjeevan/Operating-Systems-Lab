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
        server_socket=socket(AF_INET, SOCK_DGRAM, 0);

        struct sockaddr_in server_address;
       

        server_address.sin_family = AF_INET;
        server_address.sin_port=htons(9002);
        server_address.sin_addr.s_addr= INADDR_ANY;

        //binding the socket to the specified IP and port

        bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address));


        struct sockaddr_in cli;
        int clen=sizeof(cli);

            while(recvfrom(server_socket,&client_response,sizeof(client_response),0,(struct sockaddr *)&cli,&clen))

            {
                 
                       printf("\n\t %s\n\n\t",client_response);
                       sleep(1);
            }   
       
    }