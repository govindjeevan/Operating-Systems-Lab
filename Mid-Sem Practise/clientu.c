#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>
#include <netinet/in.h>

int main()
    {
        int client_socket;
        client_socket= socket(AF_INET, SOCK_DGRAM, 0);

        struct sockaddr_in address;
        address.sin_family=AF_INET;
        address.sin_port=htons(9002);
        address.sin_addr.s_addr=INADDR_ANY;
        bzero(address.sin_zero,8);

        char message[256];
        
        gets(message);

        sendto(client_socket,message,strlen(message),0,(struct sockaddr*)&address,sizeof(address));
        
    }