#include "panel.h"
#include "defines.h"
panel::panel(int a,int b,int c)
{
     tanks=a;
     level=b;
     life=c;
     drawLife();
     drawTank();
     drawLevel();
}
void panel::setLife(int a)
{
     life=a;
     drawLife();
}
void panel::setTanks(int a)
{
     tanks=a;
     drawTank();
}
void panel::setLevel(int a)
{
     level=a;
     drawLevel();
}
void panel::drawTank()
{    
     setbkcolor(COLOR(100,100,100));
      setfillstyle(1,COLOR(100, 100, 100));
      setcolor(0);
      settextstyle(3,0,4);
     bar(WIN_WIDTH-100,0,WIN_WIDTH,WIN_HEIGHT);
     int i=0;
     while(tanks/2>i){
                      readimagefile("images//tanks.jpg",WIN_WIDTH-45,(i+1)*20,WIN_WIDTH-15,(1+i)*20+20);
                      readimagefile("images//tanks.jpg",WIN_WIDTH-85,(i+1)*20,WIN_WIDTH-55,(i+1)*20+20);
                      i+=1;
                      }
     if(tanks%2==1) readimagefile("images//tanks.jpg",WIN_WIDTH-85,(i+1)*20,WIN_WIDTH-55,(i+1)*20+20);
}
void panel::decTank()
{
     if(tanks>0)
     {
     int i=0,x,y;
     printf("tank=%d\n",tanks);
     y=(tanks/2)*20;
     x=WIN_WIDTH-45;
     if(tanks%2==1) { x=WIN_WIDTH-85; y+=20;}
    // outtextxy(x,y,"1");
     setfillstyle(1,COLOR(100, 100, 100));
     bar(x,y,x+31,y+21);
     tanks-=1;
     }
}
void panel::drawLevel()
{    
      setfillstyle(1,COLOR(100, 100, 100));
     bar(WIN_WIDTH-50,440,WIN_WIDTH,480);
     char a[3];
     sprintf(a,"%d",level);
     readimagefile("images//flag.jpg",WIN_WIDTH-80,400,WIN_WIDTH-30,440);
     outtextxy(WIN_WIDTH-50,440,a);
}
void panel::drawLife()
{
     setfillstyle(1,COLOR(100, 100, 100));
     bar(WIN_WIDTH-50,495,WIN_WIDTH,540);
     char a[3];
     sprintf(a,"%d",life);
     readimagefile("images//lifes.jpg",WIN_WIDTH-80,500,WIN_WIDTH-50,520);
     outtextxy(WIN_WIDTH-50,495,a);
    // outtextxy(WIN_WIDTH-80,500,"LIFE");          
}
