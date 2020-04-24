// startGUI class
#include <cstdlib>
#include <iostream>
#include <string.h>
#include <graphics.h>
#include "defines.h"

using namespace std;
class GUI
{
  private:
          soundFPtr thrd;
          char* version;
          char* highScore;
          char* people1;
          char* people2;
          char* people3;
          char* team;
          char* p1;
          char* p2;
          char* con;
          char* network;
  public:
         bool cont;
         char IP[50];
         char IP2[50];
         GUI(soundFPtr);
         void draw(); 
         int startMenu(); 
         int lvl;   
};
