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
            struct sockaddr_in from;
            

            struct hostent *hp;
            hp = gethostbyname("127.0.0.1");  

            server_address.sin_family=AF_INET;
            server_address.sin_port=htons(9002);
            server_address.sin_addr = *((struct in_addr *)hp->h_addr);
            bzero(&(server_address.sin_zero),8);
       
            // receive data from server
            char server_response[256];
            char client_message[256];
    
        int fromlen = sizeof(struct sockaddr_in);
    
                        printf("\n\t");
                        gets(client_message);
                        sendto(network_socket,client_message,sizeof(client_message),0,(struct sockaddr *)&server_address,sizeof(server_address));
                        bzero(client_message,256);
                        sleep(1);


       recvfrom(network_socket,server_response,sizeof(server_response),0,(struct sockaddr *)&from,&fromlen);
       
                printf("\n\t%s\n\n\t",server_response);
                sleep(1);
               
        
            printf("\nConnection to server terminated\n\n");
            exit(1);

    }