#include "network.h"
#include <iostream>

network::network(char *pip,void *pp[20]){
                   strcpy(partnerip,pip);
                   for (int i=0;i<20;i++){
                       pointers[i]=pp[i];
                   }
                   cont=true;
}
void network::setpartner(char *pip){
                   strcpy(partnerip,pip);
}

void network::send(char *data1){
     if (cont){
                cout<<"Sending data:"<<data1<<" TO:"<<partnerip<<endl;
//                cout<<"Sending "
                mySocket * client = new mySocket();
              /*  struct hostent *server;
                 server = gethostbyname("192.168.1.2");
                 if (server == NULL)
                  {
                 printf("ERROR, no such host\n");
                 system("pause");
                  }
                /*
                
                //cout<<"Tring to:"<<partnerip<<endl;
               /* int sd=1;
                struct sockaddr_in serveraddr;
                int rc = connect(sd,(struct sockaddr *)&serveraddr,sizeof(serveraddr));
                if (rc< 0)
                {  
                perror("connect() failed");
                //close(sd);
                system("pause");
                exit(-1);
                }
                */
                if (client->sendToServer(partnerip,24742,data1)!=0)
                {
                //
                }
                else cout<<"can't send"<<endl;
                client->~mySocket();
        }
}
bool network::check()
{
     mySocket * client = new mySocket();
     if (client->sendToServer(partnerip,24742,"#")!=0)
                {
                return true;
                }
                else return false;
     //client->~mySocket();
}
void network::recieve(char *ret)
{
     if (cont){
        char *data = (char *) malloc(30 * sizeof(char));
        mySocket * server = new mySocket(24742);
        SOCKET client_socket;
        client_socket = server->recieveFromClient(data);
        //cout<<ret<<endl;
        strcpy(ret,data);
        free(data);
        server->~mySocket();
        }
}
void network::auth(char *ret)
{
     if (cont){
        char *data = (char *) malloc(30 * sizeof(char));
        mySocket * server = new mySocket(24742);
        SOCKET client_socket;
        client_socket = server->authenticate(data);
        //cout<<ret<<endl;
        strcpy(ret,data);
        free(data);
        server->~mySocket();
        }
}
