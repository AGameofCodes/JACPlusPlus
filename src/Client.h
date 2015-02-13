/* 
 * File:   Client.h
 * Author: jester
 *
 * Created on February 13, 2015, 11:19 AM
 */

#ifndef CLIENT_H
#define	CLIENT_H

#include <iostream>

#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <cstdlib> // atoi, memset
#include <cstring>
#include <string>


using std::cout;
using std::endl;


class Client {
private:
    static Client *instance;
    
    Client();
    Client(const Client& orig);
    virtual ~Client();
public:
    
    static Client *getInstance();
    unsigned int start();
    unsigned int stop();
    unsigned int run(int argc, char** argv);

};

#endif	/* CLIENT_H */

