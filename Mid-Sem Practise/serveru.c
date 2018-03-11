#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>
#include <netinet/in.h>


int main()
    {
        int server_socket=socket(AF_INET, SOCK_DGRAM,0);

        struct sockaddr_in server_address;
        
        server_address.sin_family=AF_INET;
        server_address.sin_port=htons(9002);
        server_address.sin_addr.s_addr=INADDR_ANY;

        bind(server_socket, (struct sock_addr *) &server_address, sizeof(server_address));

        struct sockaddr_in from;
        char buffer[256];
        int fromlen=sizeof(struct sockaddr_in);
        recvfrom(server_socket, buffer,sizeof(buffer), 0, (struct sockaddr *)&from, &fromlen );
        printf("server connected");
        printf("%s", buffer);

    }