/* 
 * File:   Client.h
 * Author: jester
 *
 * Created on February 13, 2015, 10:09 AM
 */

#ifndef CLIENT_H
#define	CLIENT_H

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>


class Client {
private:
    Client();
    Client(const Client& orig);
    virtual ~Client();
public:

};

#endif	/* CLIENT_H */

