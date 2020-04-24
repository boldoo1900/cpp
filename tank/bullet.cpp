#include "bullet.h"
//#include "bot.h"
#include "machine.h"
#include "tank.h"
#include <iostream>

using namespace std;

bullet::bullet(int hid,int pbid,int px,int py,int pd,void *pp[20],int ps=10){
               hostId=hid;
               lostcenter=(int *)pp[53];
               objptr=pp[3];
               bulletmap=(map *)pp[2];
               myMap=(map *)pp[0];
               geomap=(map *)pp[1];
               result=(int *)pp[4];
               black=pp[8];
               //data=malloc(imagesize(0,0,AW_W,AW_H));
               data=pp[7];
               x=px;
               y=py;
               dir=pd;
               step=ps;
               enabled=1;
               //getimage(770,670,770+AW_W,670+AW_H,data);
               //getimage(x,y,x+AW_W,y+AW_H,data);
               if (((int)(bulletmap->data[x/13][y/13]/10))!=((int)hostId/10)&&bulletmap->data[x/13][y/13]>0)
               enabled=0;
               if (!check(x,y)){
                       enabled=0;
                       int target=getit(x,y);
                       if (target>0&&target<I_Tank) {
                                     if ((int)((machine *)(*((int *)objptr+target)))->id/10!=(int)hostId/10)
                                     ((machine *)(*((int *)objptr+target)))->die();
                                          if (target>10) {
                                                        *((int *)(result+hostId-1+(target-10)*2))=*((int *)(result+hostId-1+(target-10)*2))+1;
                                                    }
                                     cout<<hostId<<"shooted "<<((machine *)(*((int *)objptr+target)))->id<<endl;
                                     }
                       else if (target==0){
                            if (dir==0||dir==2){
                                                cout<<hostId<<" "<<x<<" "<<y<<endl;
                                                if (geomap->data[x/13-1][y/13]==41) geomap->data[x/13-1][y/13]=0;
                                                if (geomap->data[x/13][y/13]==41) geomap->data[x/13][y/13]=0;
                                                if (geomap->data[x/13+1][y/13]==41) geomap->data[x/13+1][y/13]=0;
                                                if (geomap->data[x/13+2][y/13]==41) geomap->data[x/13+2][y/13]=0;
                                                geomap->drawmap(x-13,y+dir,3,0,black);
                            }
                            else{
                                                if (geomap->data[x/13][y/13-1]==41) geomap->data[x/13][y/13-1]=0;
                                                if (geomap->data[x/13][y/13]==41) geomap->data[x/13][y/13]=0;
                                                if (geomap->data[x/13][y/13+1]==41) geomap->data[x/13][y/13+1]=0;
                                                if (geomap->data[x/13][y/13+2]==41) geomap->data[x/13][y/13+2]=0;
                                                geomap->drawmap(x,y-13,0,3,black);
                            }
                       }
               }
               else bulletmap->data[x/13][y/13]=hostId;
}
bullet::~bullet(){
                  if (enabled) putimage(x,y,data,COPY_PUT);
                  bulletmap->data[x/13][y/13]=0;
                  enabled=0;
}
void bullet::procedure(){
     if(enabled){
                         if (bulletmap->data[x/13][y/13]==0)
                         enabled=0;
                         else if(bulletmap->data[x/13][y/13]==hostId){
                              bulletmap->data[x/13][y/13]=0;
                         }
                         
                         putimage(x,y,data,COPY_PUT);
                          
                          if (x>=AREA_WIDTH-AW_W*2||y>=AREA_HEIGHT||x<-AW_W/2||y<-AW_H/2)
                          enabled=0;
                          else{
    						  if (dir==0)
                              if(check(x,y-step)){
                              y-=step;
                              }
                              else {
                                   enabled=0;
                                   int target=getit(x,y-step);
                                   if (target>0&&target<I_Tank) {
                                   if ((int)((machine *)(*((int *)objptr+target)))->id/10!=(int)hostId/10)
                                     ((machine *)(*((int *)objptr+target)))->die();
                                          if (target>10) {
                                                        *((int *)(result+hostId-1+(target-10)*2))=*((int *)(result+hostId-1+(target-10)*2))+1;
                                                    }
                                     cout<<hostId<<"shooted "<<((machine *)(*((int *)objptr+target)))->id<<endl;
                                     }
                                                else if (target==0){
                                                                    if (geomap->data[x/13-1][y/13-1]==41) geomap->data[x/13-1][y/13-1]=0;
                                                                    if (geomap->data[x/13][y/13-1]==41) geomap->data[x/13][y/13-1]=0;
                                                                    if (geomap->data[x/13+1][y/13-1]==41) geomap->data[x/13+1][y/13-1]=0;
                                                                    if (geomap->data[x/13+2][y/13-1]==41) geomap->data[x/13+2][y/13-1]=0;
                                                                    geomap->drawmap(x-13,y-13,3,0,black);
                                                }
                                   }

    						  if (dir==1)
    						  if(check(x+step,y))
                              {
                              x+=step;
                              }
                              else {
                                   enabled=0;
                                   int target=getit(x+step,y);
                                   if (target>0) {
                                   if ((int)((machine *)(*((int *)objptr+target)))->id/10!=(int)hostId/10)
                                     ((machine *)(*((int *)objptr+target)))->die();
                                          if (target>10&&target<I_Tank) {
                                                        *((int *)(result+hostId-1+(target-10)*2))=*((int *)(result+hostId-1+(target-10)*2))+1;
                                                    }
                                     cout<<hostId<<"shooted "<<((machine *)(*((int *)objptr+target)))->id<<endl;
                                     }
                                                else if (target==0){
                                                                    if (geomap->data[x/13+1][y/13-1]==41) geomap->data[x/13+1][y/13-1]=0;
                                                                    if (geomap->data[x/13+1][y/13]==41) geomap->data[x/13+1][y/13]=0;
                                                                    if (geomap->data[x/13+1][y/13+1]==41) geomap->data[x/13+1][y/13+1]=0;
                                                                    if (geomap->data[x/13+1][y/13+2]==41) geomap->data[x/13+1][y/13+2]=0;
                                                                    geomap->drawmap(x+13,y-13,0,3,black);
                                   }
                                   }
                              
    						  if (dir==2)
    						  if(check(x,y+step))
                              {
                              y+=step;
                              }
                              else {
                                   enabled=0;
                                   int target=getit(x,y+step);
                                   if (target>0&&target<I_Tank) {
                                   if ((int)((machine *)(*((int *)objptr+target)))->id/10!=(int)hostId/10)
                                     ((machine *)(*((int *)objptr+target)))->die();
                                                                               if (target>10) {
                                                        *((int *)(result+hostId-1+(target-10)*2))=*((int *)(result+hostId-1+(target-10)*2))+1;
                                                    }
                                     cout<<hostId<<"shooted "<<((machine *)(*((int *)objptr+target)))->id<<endl;
                                     }
                                                else if (target==0){
                                                                    if (geomap->data[x/13-1][y/13+1]==41) geomap->data[x/13-1][y/13+1]=0;
                                                                    if (geomap->data[x/13][y/13+1]==41) geomap->data[x/13][y/13+1]=0;
                                                                    if (geomap->data[x/13+1][y/13+1]==41) geomap->data[x/13+1][y/13+1]=0;
                                                                    if (geomap->data[x/13+2][y/13+1]==41) geomap->data[x/13+2][y/13+1]=0;
                                                                    geomap->drawmap(x-13,y+13,3,0,black);
                                   }
                                   }
    						  if (dir==3)
    						  if(check(x-step,y))
                              {
                              x-=step;
                              }
                              else {
                                   enabled=0;
                                   int target=getit(x-step,y);
                                   if (target>0&&target<I_Tank) {
                                   if ((int)((machine *)(*((int *)objptr+target)))->id/10!=(int)hostId/10)
                                     ((machine *)(*((int *)objptr+target)))->die();
                                                                               if (target>10) {
                                                        *((int *)(result+hostId-1+(target-10)*2))=*((int *)(result+hostId-1+(target-10)*2))+1;
                                                    }

                                     cout<<hostId<<"shooted "<<((machine *)(*((int *)objptr+target)))->id<<endl;
                                     }
                                                else if (target==0){
                                                                    if (geomap->data[x/13-1][y/13-1]==41) geomap->data[x/13-1][y/13-1]=0;
                                                                    if (geomap->data[x/13-1][y/13]==41) geomap->data[x/13-1][y/13]=0;
                                                                    if (geomap->data[x/13-1][y/13+1]==41) geomap->data[x/13-1][y/13+1]=0;
                                                                    if (geomap->data[x/13-1][y/13+2]==41) geomap->data[x/13-1][y/13+2]=0;
                                                                    geomap->drawmap(x-13,y-13,0,3,black);
                                   }
                                   }
                              if (bulletmap->data[x/13][y/13]!=0){
                                                      if (((int)(bulletmap->data[x/13][y/13]/10))!=((int)hostId/10)){
                                                         enabled=0;
                                                         bulletmap->data[x/13][y/13]=0;
                                                         }
                                                         else bulletmap->data[x/13][y/13]=hostId;
                              }
                              else{
                                   bulletmap->data[x/13][y/13]=hostId;
                              }
                              
                              //getimage(x,y,x+AW_W,y+AW_H,data);
                              if (enabled){
                                 readimagefile("images\\bullet.gif",x,y,x+AW_W,y+AW_H);
                              }
                          }
          }
}
int bullet::getit(int px,int py){
        int w=1;
    int h=1;
     int x=px/13;
     int y=py/13;
     
     if (dir==0||dir==2) w=2;
     else {h=2;}
     
     int i,j;
     int res=-1;
     for (i=x;i<x+w;i++)
     for (j=y;j<y+h;j++){
         if (i>=0&&j>=0)
         if (myMap->data[i][j]!=0&&i<52&&j<52){
         res=myMap->data[i][j];
         break;
         }
         }
         
     if (res==-1){
     for (i=x;i<x+w;i++)
     for (j=y;j<y+h;j++)    
         if (!(geomap->data[i][j]==0||(geomap->data[i][j]>=20&&geomap->data[i][j]<=29)||geomap->data[i][j]==40||geomap->data[i][j]==42||geomap->data[i][j]==43))
         {
         res=0;
         break;
         }         
     }
     return res;
}
int bullet::check(int px,int py){
    int w=1;
    int h=1;
     int x=px/13;
     int y=py/13;
     
     if (dir==0||dir==2) w=2;
     else {h=2;}
     
     int i,j;
     int res=1;
     for (i=x;i<x+w&&res==1;i++)
     for (j=y;j<y+h&&res==1;j++){
         if (!(myMap->data[i][j]==0&&(geomap->data[i][j]==0||(geomap->data[i][j]>=20&&geomap->data[i][j]<=29)||geomap->data[i][j]==40||geomap->data[i][j]==42||geomap->data[i][j]==43)))
//           if (!(myMap->data[i][j]==0&&(geomap->data[j][i]==0||(geomap->data[j][i]>=20&&geomap->data[j][i]<=29)||geomap->data[j][i]==40||geomap->data[j][i]==42||geomap->data[j][i]==43)))
         res=0;
         if (geomap->data[i][j]==E_Center){
                        cout<<"LOST CENTER:"<<lostcenter<<endl;
                        *lostcenter=1;
            }
     }
     return res;
}
