#include "GUI.h"
GUI::GUI(soundFPtr pthrd)
{   
    thrd=pthrd;
    cont=true;
    lvl=1;
    version="V. 1.0.0";
    highScore="Highscore 20000";
    p1="1 player";
    p2="2 player";
    network="Network";
    con="Construction"; 
    team="2012 TTM ";             
    people1="A.Uuganjargal";
    people2="Ts.Batkhongor";
    people3="G.Tuwshinbat";
}
void GUI::draw()
{
     int x=200,y=350,k=0;
     readimagefile("images//start.jpg",0,0,WIN_WIDTH,WIN_HEIGHT);
      //settextsize(10);
     settextstyle(3,0,3);
     outtextxy(150,40,highScore);
     outtextxy(500,40,version);
     outtextxy(x,y+k,p1);
     readimagefile("images//tank1.gif",x-50,y,x-20,y+30);
     k+=30;
     outtextxy(x,y+k,p2);
     k+=30;
     outtextxy(x,y+k,network);
     k+=30;
     outtextxy(x,y+k,con);
     k+=50;
     outtextxy(x-60,y+k,team);
     settextstyle(7,0,3);
     outtextxy(x+200,y+k,people1);
     k+=30;
     outtextxy(x+200,y+k,people2);
     k+=30;
     outtextxy(x+200,y+k,people3);
     settextstyle(1,0,3);
}
int GUI::startMenu()
{
    int i=1,x=150,y=350;
    char ch;
    while(1){
             //readimagefile("tank1.gif",x,y,x+30,y+30);       
             ch=getch();
             readimagefile("images//black.jpg",x,y,x+30,y+30);       
             if(ch==80)  
             {
                 if(i!=4) y+=30,i++;
                 else  i=1,y=350;
             }
             else 
             if(ch==72) 
                  {
                  if(i!=1) y-=30,i--;
                  else i=4,y=440;
                  }
             readimagefile("images//tank1.gif",x,y,x+30,y+30);       
             if(ch==13) break;
             }
             
    if(i==3){            i=31;
                         setfillstyle(0,0);
                         x=250,y=300;
                         bar(0,0,676,676);
                         outtextxy(300,300,"HOST");
                         outtextxy(300,330,"CLIENT");
                         readimagefile("images//tank1.gif",x,y,x+30,y+30);
                         while(1)
                         {    ch=getch();
                              readimagefile("images//black.jpg",x,y,x+30,y+30);
                              if(ch==80||ch==72)
                                        {
                                         if(y==300) { i=32; y=330; }
                                         else { i=31; y=300;}
                                         
                                         //y+=30;
                                         }
                              else if(ch==13) break;
                              readimagefile("images//tank1.gif",x,y,x+30,y+30);                            
                         }
             }
    int p=1;
    char *chars="Waiting for player";
    strcpy(IP,"");
    strcpy(IP2,"Enter host IP:192.168.197.130");
    if(i==31||i==32)
    { 
                        readimagefile("images//black.jpg",200,200,500,450);
                        
    }
    if(i==32) {
              int kk=0;
              outtextxy(180,300,IP2); 
              while(kk<20)
                          { 
                        ch=getch();
                        setcolor(0);
                        outtextxy(180,300,IP2);
                        setcolor(15);
                        if(ch==13) break;
                        //strcat(IP2,IP);
                        if(ch==8){
                                  if(IP2[strlen(IP2)-1]!=':')
                                  {
                                  sprintf(IP,"");
                                  int ii=0;
                                  for(ii=0;ii<strlen(IP2)-1;ii++) ;
                                  IP2[ii]=0;
                                  //for(int ii=0;ii<strlen(IP);ii++) IP2[ii]=IP[ii];
                                  //strcpy(IP2,IP);
                                  }
                                  outtextxy(180,300,IP2);
                                  }
                        else 
                        {
                        sprintf(IP,"%c",ch);
                        strcat(IP2,IP);
                        outtextxy(180,300,IP2);
                        kk++;
                        }
                        }
              }
    else if(i==31){
                   thrd(0);
                   while(cont){
                           setcolor(0);
                           outtextxy(180,300,chars);
                           if(p==1)     { p=2; chars="Waiting for player";}
                           else if(p==2){ p=3; chars="Waiting for player .";}
                           else if(p==3){ p=4; chars="Waiting for player ..";}
                           else if(p==4){ p=1; chars="Waiting for player ...";}
                           setcolor(15);
                           outtextxy(180,300,chars);
                           delay(300);
                            } 
                 }
    if(i==1||i==2){ lvl=1;
                    sprintf(IP,"%s","LEVEL");
                    sprintf(IP2,"%d",lvl);
                    setbkcolor(7);
                    setfillstyle(0,7);
                    bar(0,0,WIN_WIDTH,WIN_HEIGHT);
                    setcolor(0);
                    outtextxy(240,300,IP);
                    outtextxy(380,300,IP2);
                    while(1)
                           {
                           ch=getch();
                           if(ch==13) break;
                           if(ch==80) if(lvl==1) lvl=20;
                                      else lvl--;
                           if(ch==72) if(lvl==20) lvl=1; 
                                      else lvl++;
                           setcolor(7);
                           outtextxy(380,300,IP2);
                           sprintf(IP2,"%d",lvl);
                           setcolor(0);          
                           outtextxy(380,300,IP2);
                          // getch();
                           }
                    setbkcolor(0);       
                    setfillstyle(0,0);
                    bar(0,0,WIN_WIDTH,WIN_HEIGHT);
                   }
    return i;
}
int startNwork()
{
        
}
