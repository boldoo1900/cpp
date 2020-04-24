#ifndef bullet_h
#define bullet_h

#include <graphics.h>
#include "defines.h"
#include "map.h"
#include <cmath>

using namespace std;

class bullet{
      public:
             void *pointers;
             void *objptr;
             void *black;
             void *black2;
             int *result;
             int *lostcenter;
             
             map *bulletmap;
             map *geomap;
             static int total2;
             int buid;
             map *myMap;
             void *data;
             bool enabled;
             int x,y,dir,step,bid;
             int hostId;
             
             bullet(int,int,int,int,int,void *pp[60],int);
             ~bullet();
             int check(int,int);
             int getit(int,int);
             void procedure();
};
#endif
