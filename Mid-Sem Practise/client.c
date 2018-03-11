#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h> 
int main()
    {
        int client_socket;

        client_socket=socket(AF_INET, SOCK_STREAM, 0);

        struct sockaddr_in server_address;

        server_address.sin_family=AF_INET;
        server_address.sin_port=htons(9002);
        server_address.sin_addr.s_addr=inet_addr("127.0.0.1");
        memset(server_address.sin_zero, '\0', sizeof(server_address.sin_zero));

        int connection_status;

        connection_status=connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address));
        if(connection_status!=-1) printf("\nServer Connected..\n");

        int message;
        recv(client_socket, message, 256, 0);
        printf("\n%d", message);
    }