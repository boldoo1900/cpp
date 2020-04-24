#ifndef map_h
#define map_h

#include "defines.h"
#include <string>
#include <graphics.h>

using namespace std;

class map{
      public:
      short data[70][70];
      void fillmap(int,int,int,int,int);
      void loadmap(char *);
      void printmap();
      void drawmap();
      void drawmap(int,int,int,int,void *);
};
#endif
