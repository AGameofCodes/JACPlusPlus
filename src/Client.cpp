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

Client *Client::instance;

Client::Client()
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

unsigned int Client::start()
{

}

//------------------------------------------------------------------------------

unsigned int Client::stop()
{
}

//------------------------------------------------------------------------------

unsigned int Client::run(int argc, char** argv)
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
  //    if(socket->getSocketFD() < 0)
  //    {
  //        cout << "Error: Opening Socket!" << endl;
  //        
  //    }

  try
  {
    socket->connect((1 << 24) | 127, portnumber);
  }
  catch (libsockcpp::IllegalStateException &e)
  {
    std::cerr << e.what() << endl;
  }
  cout << "Please, enter a message: " << endl;
  std::cin.getline(buffer, 255);

  socket->write(buffer, 255);
  int read = socket->read(buffer, 255);
  buffer[read] = '\0';
  
  cout << buffer << endl;


  /*
   * 
   * 
   *     int socketfd, newsocketfd;
          int portnumber;
          int response;
          char buffer[256];
          struct sockaddr_in server_addr;
          struct hostent *server;
          int status;

              portnumber = atoi(argv[2]);

             // socketfd = socket(AF_INET, SOCK_STREAM, 0);
              if(socketfd < 0)
      {
          cout << "Error: Opening Socket!" << endl;
          return -1;
      }

      server = gethostbyname(argv[1]); // The gethostbyname function has been deprecated by the introduction of the getaddrinfo function.
      if(server == NULL)
      {
          cout << "Error: No such host!" << endl;
          return -1;
      }
      // AF_INET is the address family that is used for the socket you're creating (in this case an Internet Protocol address). The Linux kernel, for example, supports 29 other address families such as UNIX
      memset(&server_addr, 0, sizeof(server_addr));
      server_addr.sin_family = AF_INET;

      memcpy((char *)&server_addr.sin_addr.s_addr, (char *)server->h_addr, server->h_length);
      server_addr.sin_port = htons(portnumber);

      status = connect(socketfd, (sockaddr*)&server_addr, sizeof(server_addr));
      if(status < 0)
      {
          cout << "Error: Connecting!" << endl;
          return -1;
      }



      cout << "Please, enter a message: " << endl;
      memset(buffer, 0, 256);
      std::cin.getline(buffer,256);

      status = send(socketfd, buffer, strlen(buffer), 0);
      if(status < 0)
      {
          cout << "Error: Writing to socket!" << endl;
          return -1;
      }

      //-------------------------
      // read server response
      memset(buffer, 0, sizeof(buffer));
      status = recv(socketfd, buffer, 255, 0);
      if(status < 0)
      {
          cout << "Error: Reading from Socket!" << endl;
          return -1;
      }
      cout << buffer << endl;
   */
  return 0;

}
