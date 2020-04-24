#include<winsock.h>
#include<stdio.h>
#include<string>
#include <cstdio>
using namespace std;

//#ifdef MYSOCKET_H
//#define MYSOCKET_H

#define MAX_BUFFER_SIZE = 1024;

const int iReqWinsockVer = 2;

class mySocket
{
protected:
    WSADATA m_WsaData;
    SOCKET m_hSocket;
    SOCKADDR_IN m_sockAddr;
    int m_port;
public:
    mySocket();
    mySocket(int port);
    virtual ~mySocket();
    mySocket(const mySocket& other);

    SOCKET recieveFromClient(char *data);
    SOCKET authenticate(char *data);
    int recieveFromServer(char *data);
    bool sendToClient(SOCKET client_socket, char * data);
    bool sendToServer(char* ipAddress, int port, char* data);

};
//#endif // MYSOCKET_H
