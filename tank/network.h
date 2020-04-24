#ifndef network_h
#define network_h

#include "mySocket.h"

class network{
      private:
              void *pointers[20];
              char data[20];
              bool cont;
      public:
             char partnerip[20];
             void setpartner(char *);
             network(char *,void *pp[20]);
             void send(char *);
             void recieve(char *);
             void auth(char *);
             bool check();
};
#endif
