#ifndef tank_h
#define tank_h

#include <graphics.h>
#include <process.h>
#include "defines.h"
#include "bullet.h"
#include "keyTable.h"
#include "map.h"
#include "network.h"
#include "machine.h"

using namespace std;

class tank:public machine
{
      private:
              int score;
      public:
             keyTable keys;
             tank(int,int,int,keyTable,int pd,void *pp[60],int,soundFPtr);
             void clock(int z=0);
             void procedure(int,int z=0);
};
#endif
