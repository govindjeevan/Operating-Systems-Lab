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
            network_socket=socket(AF_INET, SOCK_STREAM, 0);

            // specify address for the socket

            struct sockaddr_in server_address;
            server_address.sin_family=AF_INET;
            server_address.sin_port=htons(9002);

            server_address.sin_addr.s_addr= INADDR_ANY;

            int connection_status=connect(network_socket, (struct sockaddr *) &server_address, sizeof(server_address));
            if(connection_status==-1){
                printf("\nThere was an error making a connection with the remote socket\n");
                exit(1);
            }

            else printf("\nConnection to port 9002 succesful. Awaiting server message\n");
            // receive data from server
            char server_response[256];
            char client_message[256];
           
           while(recv(network_socket, &server_response, sizeof(server_response), 0)>0)
           {           
                                printf("\n%s\n",server_response);
                                sleep(1);
           }
        
            printf("\nConnection to server terminated\n\n");
            exit(1);

    }