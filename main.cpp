#include <sys/types.h>
#include <iostream>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <string>
#include <unistd.h>
#include <sys/socket.h>
#include <sstream>

#define PORT 5000

//Goal -> I will follow the following tutorial
//https://www.youtube.com/watch?v=F3iIGUiW27Q&t=2141s
//and try to recreate it while writing comments, and then use the code to playground socket stuff.

int main(){

    //Represents an endpoint address for IPv4
    struct sockaddr_in saddr = {
        .sin_family = AF_INET, 
        .sin_addr.s_addr = INADDR_ANY,
        .sin_port = htons(PORT)
    };

    int option = 1;
    int srv_addr_size = sizeof(saddr); //Server address size
    int socketServer = socket(AF_INET, SOCK_STREAM, 0);
    setsockopt(socketServer, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &option, sizeof(option));

    return 0;

}