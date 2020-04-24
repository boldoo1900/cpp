#ifndef bot_h
#define bot_h

#include <graphics.h>
#include "defines.h"
#include "bullet.h"
#include "map.h"
#include "machine.h"

using namespace std;

class bot:public machine
{
      private:
              float force;
      public:
             bot(int,int,int,int,void *pp[60],int,soundFPtr,bool);
             bot(int,int,int,void *pp[60],soundFPtr,queueBot pqueue[10]);
             void clock(int z=0);
             void procedure(int z=0);
             int checker(int,int,int);
};
#endif
