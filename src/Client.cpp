/*
 * Client.cpp
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

//#include <bits/socket.h>

#include "Client.h"


using std::cout;
using std::endl;
//using std::thread;

Client *Client::instance;

Client::Client() : t(NULL), enabled(false)
{
}

Client::Client(const Client& orig)
{
}

Client::~Client()
{
}

Client* Client::getInstance()
{
  if (Client::instance == NULL)
  {
    Client::instance = new Client();
  }
  return Client::instance;
}



//------------------------------------------------------------------------------

void Client::start(int argc, char** argv)
{
  if (enabled)
  {
    return;
  }
  enabled = true;

  t = new std::thread(&Client::run, this, argc, argv);
}

//------------------------------------------------------------------------------

void Client::stop()
{
  if (!enabled)
  {
    return;
  }
  enabled = false;
}

void Client::awaitTermination()
{
  if (t != NULL)
  {
    t->join();
    t == NULL;
  }
}

//------------------------------------------------------------------------------

void Client::run(int argc, char** argv)
{
  int portnumber;
  char buffer[256];
  struct sockaddr_in server_addr;
  struct hostent *server;
  int status;

  if (argc < 3)
  {
    cout << "Usage: " << argv[0] << " Hostname port" << endl;
  }

  portnumber = atoi(argv[2]);
  libsockcpp::Socket *socket = new libsockcpp::Socket();

  try
  {
    socket->connect((127 << 24) | 1, portnumber);
  }
  catch (libsockcpp::IllegalStateException &e)
  {
    std::cerr << e.what() << endl;
  }

  while (enabled)
  {
    cout << "Please, enter a message: " << endl;
    std::cin.getline(buffer, 255);

    socket->write(buffer, 255);
    int read = socket->read(buffer, 255);
    buffer[read] = '\0';

    cout << buffer << endl;
  }

  socket->close();
}

//------------------------------------------------------------------------------
