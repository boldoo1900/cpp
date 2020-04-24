#include "mySocket.h"
#include <iostream>
#define Max_Lenght 40 

mySocket::mySocket()
{
    //ctor
    if(WSAStartup(MAKEWORD(2,2),& this->m_WsaData)!=0)
	{
		perror("Winsock error - Winsock initialization failed\r\n");
		WSACleanup();
		system("PAUSE");
		exit(1);
	}

    // Create our socket
	this->m_hSocket = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	//this->m_hSocket = socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP);
	if(this->m_hSocket==INVALID_SOCKET)
	{
        perror("Winsock error - Socket creation Failed!\r\n");
		WSACleanup();
		system("PAUSE");
		exit(1);
	}
}

mySocket::mySocket(int port){
    this->m_port = port;
    if(WSAStartup(MAKEWORD(2,2),& this->m_WsaData)!=0)
	{
		perror("Winsock error - Winsock initialization failed\r\n");
		WSACleanup();
		system("PAUSE");
		exit(1);
	}

    // Create our socket
	this->m_hSocket = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	//this->m_hSocket = socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP);
	if(this->m_hSocket==INVALID_SOCKET)
	{
        perror("Winsock error - Socket creation Failed!\r\n");
		WSACleanup();
		system("PAUSE");
		exit(1);
	}

    memset(&this->m_sockAddr, 0, sizeof(this->m_sockAddr));
    this->m_sockAddr.sin_family = AF_INET;
	this->m_sockAddr.sin_addr.s_addr = INADDR_ANY;
	this->m_sockAddr.sin_port = htons(this->m_port);

    /* bind the socket to the port number */
	if (bind(this->m_hSocket, (struct sockaddr *) &this->m_sockAddr, sizeof(this->m_sockAddr)) == -1) {
		perror("bind");
		exit(1);
	}
}

mySocket::~mySocket()
{
   	// Shutdown our socket
	shutdown(this->m_hSocket,SD_SEND);

	// Close our socket entirely
	closesocket(this->m_hSocket);

	// Cleanup Winsock
	WSACleanup();
}

mySocket::mySocket(const mySocket& other)
{
    //copy ctor
}

SOCKET mySocket::recieveFromClient(char * data)
{
    /* show that we are willing to listen */
	if (listen(this->m_hSocket, 5) == -1)
    {
		perror("listen");
		system("PAUSE");
		Sleep(2000);
		exit(1);
	}

    sockaddr_in pin;
    SOCKET sd_current;
	/* wait for a client to talk to us */
    int addrlen = sizeof(pin);
//    cout<<"C";
	if ((sd_current = accept(this->m_hSocket, (struct sockaddr *)  &pin, &addrlen)) == -1) 
    {
		perror("accept");
		system("PAUSE");
		Sleep(2000);
		exit(1);
	}

//	printf("Request from  %s #\n", inet_ntoa(pin.sin_addr));
//    cout<<inet_ntoa(pin.sin_addr)<<endl;

    /* get a message from the client */

    if (recv(sd_current, data, Max_Lenght, 0) == -1)
    {
		perror("recv");
		system("PAUSE");
		exit(1);
	}
	else 
      {
          char *temp = (char *) malloc(Max_Lenght * sizeof(char));
          int n=strlen(data);
          for(int i=0;i<n;i++)
          { 
             if(data[i]!='#') temp[i]=data[i]; 
             else {  temp[i]=0; break; }
          }
          strcpy(data,temp);
          free(temp);  
      }
    return sd_current;
}
SOCKET mySocket::authenticate(char * data)
{
	if (listen(this->m_hSocket, 5) == -1) 
    {
		perror("listen");
		system("PAUSE");
		Sleep(2000);
		exit(1);
	}

    sockaddr_in pin;
    SOCKET sd_current;
	/* wait for a client to talk to us */
    int addrlen = sizeof(pin);
//    cout<<"C";
	if ((sd_current = accept(this->m_hSocket, (struct sockaddr *)  &pin, &addrlen)) == -1) 
    {
		perror("accept");
		system("PAUSE");
		Sleep(2000);
		exit(1);
	}

//	printf("Request from  %s #\n", inet_ntoa(pin.sin_addr));
//    cout<<inet_ntoa(pin.sin_addr)<<endl;

    /* get a message from the client */

    if (recv(sd_current, data, Max_Lenght, 0) == -1)
    {
		perror("recv");
		system("PAUSE");
		exit(1);
	}
	else 
      {
          char *temp = (char *) malloc(Max_Lenght * sizeof(char));
          int n=strlen(data);
          for(int i=0;i<n;i++)
          { 
             if(data[i]!='#') temp[i]=data[i]; 
             else {  temp[i]=0; break; }
          }
          strcpy(data,inet_ntoa(pin.sin_addr));
//          strcpy(data,temp);
          free(temp);  
      }
    return sd_current;
}


int mySocket::recieveFromServer(char *data){
	return recv(this->m_hSocket, data, Max_Lenght, 0);

}
bool mySocket::sendToClient(SOCKET cleient_socket, char * data){
    if (send(cleient_socket, data, Max_Lenght, 0) == -1) 
    {
		perror("send");
		return false;
	}
	//sleep(1);
    return true;
}

bool mySocket::sendToServer(char* ipAddress, int port, char* data)
{
    // Resolve IP address for hostname
	struct hostent *host;
	if((host=gethostbyname(ipAddress))==NULL)
	{
		perror("Failed to resolve hostname.\r\n");
		WSACleanup();
		return false;
	}

    // Setup our socket address structure
	SOCKADDR_IN SockAddr;
	SockAddr.sin_port=htons(port);
	SockAddr.sin_family=AF_INET;
	SockAddr.sin_addr.s_addr=*((unsigned long*)host->h_addr);


	// Attempt to connect to server
	if(connect(this->m_hSocket,(SOCKADDR*)(&SockAddr),sizeof(SockAddr))!=0)
	{
		printf("Failed to establish connection with server\n");
		//WSACleanup();
		return false;
	}
    
    if (send(this->m_hSocket, data, strlen(data), 0) == -1) {
		perror("send");
		return false;
	}
    return true;
}
