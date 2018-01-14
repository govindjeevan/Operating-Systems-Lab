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
            //create socket
            int network_socket;
            network_socket=socket(AF_INET, SOCK_DGRAM, 0);

            // specify address for the socket

            struct sockaddr_in server_address;
            server_address.sin_family=AF_INET;
            server_address.sin_port=htons(9002);

            server_address.sin_addr.s_addr= INADDR_ANY;

       
            // receive data from server
            char server_response[256];
            char client_message[256];
      
      while(1){
                    printf("\n\t");
                    gets(client_message);
                    sendto(network_socket,client_message,sizeof(client_message),0,(struct sockaddr *)&server_address,sizeof(server_address));
                    bzero(client_message,256);
                    sleep(1);
                    }
        
            printf("\nConnection to server terminated\n\n");
            exit(1);

    }