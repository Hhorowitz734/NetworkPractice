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

int main(){

    //Represents an endpoint address for IPv4
    struct sockaddr_in saddr = {
        .sin_family = AF_INET, 
        .sin_addr.s_addr = INADDR_ANY,
        .sin_port = htons(PORT)
    };

    return 0;

}