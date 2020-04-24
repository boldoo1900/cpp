#include "etc.h"

void etc::animation(int x,int y,int type)
{
   switch(type)
   {
     case 0:
       Draw_Die(x,y);
       break;
     case 1:
       Draw_Born(x,y);   
       break;            
   }                     
}
void etc::Draw_Die(int x,int y)
{
   img = malloc(imagesize(0,0,50,50));
   getimage(x,y,x+50,y+50,img);
   readimagefile("images//animation//boom_large.gif",x+1,y+1,x+49,y+49);
   
   delay(25);
   putimage(x,y,img,COPY_PUT);
   readimagefile("images//animation//boom_medium.gif",x+1,y+1,x+49,y+49);
   
   delay(25);
   putimage(x,y,img,COPY_PUT);
   readimagefile("images//animation//boom_small.gif",x+1,y+1,x+49,y+49);
   delay(25);
   putimage(x,y,img,COPY_PUT);
   free(img);
}
void etc::Draw_Born(int x,int y)
{
   img = malloc(imagesize(0,0,50,50));
   getimage(x,y,x+50,y+50,img);
   readimagefile("images//animation//start_medium.gif",x+1,y+1,x+49,y+49);
   delay(100);   
   readimagefile("images//animation//start_large.gif",x+1,y+1,x+49,y+49);
   delay(100); 
   putimage(x,y,img,COPY_PUT);
   readimagefile("images//animation//start_medium.gif",x+1,y+1,x+49,y+49);
   delay(100); 
   readimagefile("images//animation//start_large.gif",x+1,y+1,x+49,y+49);
   delay(100); 
   putimage(x,y,img,COPY_PUT);
   readimagefile("images//animation//start_medium.gif",x+1,y+1,x+49,y+49);
   delay(100); 
   readimagefile("images//animation//start_large.gif",x+1,y+1,x+49,y+49);
   delay(100);
   putimage(x,y,img,COPY_PUT);
   free(img);
}
