#include "tank.h"

//#ifdef debug
#include <iostream>
//#endif

using namespace std;

tank::tank(int ptid,int px,int py,keyTable pkeys,int pd,void *pp[60],int pl,soundFPtr snd): machine(ptid,px,py,pd,pp,pl,snd){
             cout<<"tank "<<ptid<<" constructed"<<endl;
             for (int i=0;i<4;i++)
             imgdata[i]=pp[10+4*pl+i];
             keys=pkeys;
             score=0;
             //draw(1,1);
             active();
}
void tank::clock(int z){
//     cout<<"CLOCK: "<<z<<" "<<status<<endl;
/* 
   status 0-died(reactiving)
          1-active
          2-inactive
*/
       if (status==1){
     if (counter%4==0){
     for (int i=0;i<2;i++){
             if (bullets[i]!=NULL)
                if (bullets[i]->enabled==0){
                   delete bullets[i];
                   bullets[i]=NULL;
                   bcount--;
                }
                else bullets[i]->procedure();
           }
     }//4
     if (counter%6==0){
     if (key!=0){
//                       #ifdef debug
                       
//                       #endif
                        if (z!=1)
                        {
                                  //cout<<counter<<" user counter%6"<<endl;
                                  procedure(key,z);
                                  key=0;
                       }
     }
     }//6
     if (counter%59==0){
     if (qShoot){
                              shoot(z);
                              qShoot=0;
           }
     }//30
     counter++;
     if (counter==60) counter=0;
     }
     else if (status==0){
          counter++;
          if (counter==200) //{status=1; counter=0; draw(1,mode);}
          active();
     }
}
/*int tank::check(int px,int py,int w,int h){
     int x=px/13;
     int y=py/13;
     int i,j;
     int res=1;
     for (i=x;i<x+w&&res==1;i++)
     for (j=y;j<y+h&&res==1;j++){
         if (!((myMap->data[i][j]==0||myMap->data[i][j]==tid)&&(geomap->data[i][j]==0||(geomap->data[i][j]>=20&&geomap->data[i][j]<=29)||geomap->data[i][j]==40||geomap->data[i][j]==43))){
         res=0;
         break;
         }
     }
     return res;
}*/
void tank::procedure(int ch,int z){
     #ifdef debug_funtions 
     cout<<"tank::procedure"<<endl;
     #endif
     #ifdef debug
     cout<<"tank::::::::::::::::"<<ch<<endl;
     #endif
                            if (ch==keys.up){
										if (y>0)
                                                 if (check(x,y-TK_STEP,4,4))
                                                 {
                                                     y-=TK_STEP;
                                                     drawReq=1;
                                                 }
                                        dir=0;
                                 }
                            else if (ch==keys.down){
											if (y<AREA_HEIGHT-TK_HEIGHT)
											if (check(x,y+TK_STEP,4,4))
                                            {
                                                                        
                                                                              y+=TK_STEP;
                                                                              drawReq=1;
                                          }
                                          dir=2;
                                          }
                            else if (ch==keys.left){
											if (x>0)
											if(check(x-TK_STEP,y,4,4))
                                            {
                                                    x-=TK_STEP;
                                                    drawReq=1;
                                           }
                                           dir=3;
                                 }
                            else if (ch==keys.right){
											  if (x<AREA_WIDTH-TK_WIDTH)
											  if(check(x+TK_STEP,y,4,4))
                                              {
                                                                             x+=TK_STEP;
                                                                             drawReq=1;
                                          }
                                          dir=1;
                                 }
                            else if (ch==keys.shoot){
                                          if (bcount<2) shoot(z);
                                          else qShoot=1;
                               }
                  draw(0,z);
}
/*
void tank::shoot(){
                                       if (bcount<2){
                                                        #ifdef debug
                                                        cout<<tid<<" New bullet!"<<bcount<<endl;
                                                        #endif
                                                    int a_x,a_y;
    											   if (dir==1){
    												   a_x=x+TK_WIDTH;
    												   a_y=y+TK_HEIGHT/2-AW_W/2;
    											   }
    												else if (dir==2){
    												   a_x=x+TK_WIDTH/2-AW_W/2;
    												   a_y=y+TK_HEIGHT;
    											   }
    												else if (dir==3){
    												   a_x=x-TK_STEP;
    												   a_y=y+TK_HEIGHT/2-AW_W/2;
    											   }
    												else{
    												   a_x=x+TK_WIDTH/2-AW_W/2;
    												   a_y=y-TK_STEP;
    											   }
    											   int k=0;
    											   if (bullets[k]!=NULL) k++;
    											   
    											   if (bullets[k]==NULL){
    											                         //bullets[k]=new bullet(tid,0,a_x,a_y,dir,myMap,bulletmap,geomap,10);
    											                         bullets[k]=new bullet(tid,0,a_x,a_y,dir,pointers,10);
    											                         bcount++;
                                                   }
                                               }
}
void tank::draw(int p,int z){
     if (drawReq||odir!=dir||p==1)
                  {
                        if (z==0) sendstream->send(tid,0,x,y);
                        myMap->fillmap(ox,oy,0,4,4);
                        myMap->fillmap(x,y,tid,4,4);
                        putimage(ox+1,oy+1,imgdata[4],COPY_PUT);
						putimage(x+1,y+1,imgdata[dir],COPY_PUT);
						drawReq=0;
						 ox=x;
                         oy=y;
                         odir=dir;
				  }
}
void tank::die(){
     cout<<tid<<" died"<<endl;
     status=0;
          for (int i=0;i<2;i++){
             if (bullets[i]!=NULL)
                if (bullets[i]->enabled==0){
                   delete bullets[i];
                   bullets[i]=NULL;
                   bcount--;
                }
           }
           myMap->fillmap(x,y,0,4,4);
           putimage(x+1,y+1,imgdata[4],COPY_PUT);
}
*/
