#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

int main()
    {
        int server_socket;
        server_socket=socket(AF_INET, SOCK_STREAM, 0);
        
        struct sockaddr_in server_address, client_address;

        server_address.sin_family= AF_INET;
        server_address.sin_port=htons(9002);
        server_address.sin_addr.s_addr=INADDR_ANY;

        bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address));

        if(listen(server_socket, 5)!=-1) printf("\n Server Listening..");   

        int client_socket=1;
        int l=sizeof(client_address);

        client_socket= accept(server_socket, (struct sockaddr*)&client_address, &l);


        if (client_socket!=-1) printf("\nServer is connected to client\n");

        int t=time();
        send(client_socket,t, sizeof(t),0);
    }