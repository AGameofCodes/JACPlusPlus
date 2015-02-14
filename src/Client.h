/*
 * Client.h
 * Copyright (C) 2015 A Game of Codes <>
 *
 * JACPlusPlus is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * JACPlusPlus is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
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
#include "../../libsockcpp/Socket.h"
#include "../../libsockcpp/IllegalStateException.h"




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
