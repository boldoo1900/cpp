#include <string.h>
#include "defines.h"
#include <graphics.h>
#include <iostream>
class construction
{
      private: 
               int note[52][52];
      public:
             construction(char *);
             void begin_construction();
             void printMap();
             void writeFile();
};
