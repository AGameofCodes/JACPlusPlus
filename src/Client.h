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
#include <cstdlib> // atoi
using namespace std;


class Client {
public:
    Client();
    Client(const Client& orig);
    virtual ~Client();
private:
    unsigned int start();
    unsigned int stop();
    unsigned int run(int argc, char** argv);

};

#endif	/* CLIENT_H */

