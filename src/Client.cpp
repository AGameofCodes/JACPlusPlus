/* 
 * File:   Client.cpp
 * Author: jester
 * 
 * Created on February 13, 2015, 11:19 AM
 */

//#include <bits/socket.h>

#include <string.h>

#include "Client.h"

Client::Client() {
}




Client::Client(const Client& orig) {
}

Client::~Client() {
}


//------------------------------------------------------------------------------
unsigned int Client::start() {}

//------------------------------------------------------------------------------
unsigned int Client::stop() {}

//------------------------------------------------------------------------------
unsigned int Client::run(int argc, char** argv)
{
    int socketfd, newsocketfd;
    int portnumber;
    int response;
    char buffer[256];
    struct sockaddr_in server_addr;
    struct hostent *server;
    int status;
    
    if(argc < 3)
    {
        cout << "Usage: " << argv[0] << " Hostname port" << endl;
    }
    
    portnumber = atoi(argv[2]);
    
    socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if(socketfd < 0)
    {
        cout << "Error: Opening Socket!" << endl;
        return -1;
    }
    
    // server = getaddrinfo(argv[1], NULL, NULL, NULL);
    server = gethostbyname(argv[1]); // The gethostbyname function has been deprecated by the introduction of the getaddrinfo function. 
    if(server == NULL)
    {
        cout << "Error: No such host!" << endl;
        return -1;
    }
    // AF_INET is the address family that is used for the socket you're creating (in this case an Internet Protocol address). The Linux kernel, for example, supports 29 other address families such as UNIX 
    server_addr.sin_family = AF_INET;
    memset(&server_addr, (int) server_addr, sizeof(server_addr));
    status = connect(socketfd, &server_addr, sizeof(server_addr));
    if(status < 0)
    {
        cout << "Error: Connecting!" << endl;
        return -1;
    }
    
      
    
}
