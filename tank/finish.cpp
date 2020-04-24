#include "finish.h"
#include <graphics.h>
#include <iostream>

using namespace std;
finish::finish(int res[2][5])
{
        setbkcolor(0);
        setfillstyle(SOLID_FILL,BLACK);
        bar(0,0,776,676);
        setcolor(COLOR(216,40,0));
        settextstyle(3,0,3);
        outtextxy(200,50,"HI-SCORE");
        
        sprintf(highscore,"%d",res[0][5]);
        setcolor(COLOR(252,152,56));
        outtextxy(400,50,highscore);
        
        setcolor(COLOR(255,255,255));
        settextstyle(3,0,3);
        outtextxy(280,80,"STAGE");
        sprintf(lvl,"%d",res[0][4]);
        outtextxy(430,80,lvl);
        
        setcolor(COLOR(216,40,0));
        settextstyle(3,0,3);
        outtextxy(90,120,"1-PLAYER");
        
        setcolor(COLOR(255,255,255));
        settextstyle(3,0,3);
        outtextxy(195,240,"PTS");
        
        readimagefile("images//arrow.gif",370, 235,400,265);
        sprintf(p1[0][0],"%d",res[0][0]);
        outtextxy(320, 238,p1[0][0]);
        
        sprintf(p1[1][0],"%d",(res[0][0] * 100));
        outtextxy(100, 240,p1[1][0]);
        
        readimagefile("images//bot11.gif",410, 235,440,265);
        
        setcolor(COLOR(255,255,255));
        settextstyle(3,0,3);
        outtextxy(195,300,"PTS");
        
        readimagefile("images//arrow.gif",370, 295,400,325);
        sprintf(p1[0][1],"%d",res[0][1]);
        outtextxy(320, 295,p1[0][1]);
        
        sprintf(p1[1][1],"%d",(res[0][1] * 200));
        outtextxy(100, 295,p1[1][1]);
        readimagefile("images//bot22.gif",410, 295,440,325);
        
        setcolor(COLOR(255,255,255));
        settextstyle(3,0,3);
        outtextxy(195,360,"PTS");
        
        readimagefile("images//arrow.gif",370, 355,400,385);
        sprintf(p1[0][2],"%d",res[0][2]);
        outtextxy(320, 355,p1[0][2]);
        
        sprintf(p1[1][2],"%d",(res[0][2] * 300));
        outtextxy(100, 355,p1[1][2]);
        readimagefile("images//bot33.gif",410, 355,440,385);
        
        setcolor(COLOR(255,255,255));
        settextstyle(3,0,3);
        outtextxy(195,420,"PTS");
        
        readimagefile("images//arrow.gif",370, 415,400,445);
        sprintf(p1[0][3],"%d",res[0][3]);
        outtextxy(320, 415,p1[0][3]);
        
        sprintf(p1[1][3],"%d",(res[0][3] * 400));
        outtextxy(100, 415,p1[1][3]);
        readimagefile("images//bot44.gif",410, 415,440,445);
        
        setcolor(COLOR(255,255,255));
        settextstyle(3,0,3);
        outtextxy(145,470,"TOTAL");
        sprintf(bot_number,"%d",(res[0][0]+res[0][1]+res[0][2]+res[0][3]));
        outtextxy(360,470,bot_number);
        
        setfillstyle(SOLID_FILL,WHITE);           
        bar(300,455,500,460);
        int s=0,i=0;
        for( i=0; i<4; i++)
          s+= (res[0][i]* (i+1)*100);
         i=0; 
         //cout<<s;
        sprintf(total_point,"%d",s);
        setcolor(COLOR(252,152,56));
        outtextxy(150,150,total_point);
}
