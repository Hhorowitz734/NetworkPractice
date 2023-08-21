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

    //Creates socket
    int option = 1;
    int srv_addr_size = sizeof(saddr); //Server address size
    int socketServer = socket(AF_INET, SOCK_STREAM, 0);
    setsockopt(socketServer, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &option, sizeof(option));

    if (socketServer == -1){ //Handles case that socket is not created
        std::cerr << "Not able to create socket." << std::endl;
        return 0;
    }

    //Client setup
    struct sockaddr_in caddr;
    socklen_t caddrSize = sizeof(caddr);
    int socketClient;

    //Binding our socket to the ip+port
    bind(socketServer, (struct sockaddr*)&saddr, srv_addr_size);


    //Listening
    listen(socketServer, SOMAXCONN); //Max available connections that socket gets (128)
    std::stringstream ss;
    ss << PORT;
    std::cout << "[SERVER]: Now listening on port" << ss.str() << ".\n";

    char buff[4096];
    int recievedDataSize; //Size of recieved data in bytes

    //Main loop for waiting for clients
    while (true){

        //Accept any connections from clients here
        socketClient = accept(socketServer, (struct sockaddr*)&caddr, (socklen_t*)&caddr);
        std::cout << "[SERVER]: Client connected successfully.\n";

        //Identifying the client
        char hostClient[NI_MAXHOST];
        char portClient[NI_MAXSERV];
        memset(hostClient, 0, NI_MAXHOST);


    }



    return 0;

}