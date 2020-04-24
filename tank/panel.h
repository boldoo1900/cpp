#include <graphics.h>
class panel
{
      private:
              int tanks;
              int level;
              int life;
      public :
             panel(int,int,int);
             void setLife(int);
             void setTanks(int);
             void setLevel(int);
             void drawTank();
             void decTank();
             void drawLevel();
             void drawLife();
};
