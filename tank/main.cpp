#include "defines.h"
#include <graphics.h>
#include <windows.h>
#include <mmsystem.h>
#include <process.h>
#include <string>
#include <iostream>
#include "construction.h"
#include "bullet.h"
#include "tank.h"
#include "bot.h"
#include "keyTable.h"
#include "map.h"
#include "network.h"
#include "GUI.h"
#include "finish.h"
#include "panel.h"

char PARTNER_IP[20]="192.168.1.7";

using namespace std;

void *objPtr[20];
bool cont=true;
tank *tankUser2=NULL;
tank *tankUser1=NULL;
tank *joyUser=NULL;
map *myMap;
map *bulletMap;
map *geoMap;
bot *bot1,*bot2,*bot3,*bot4;
network *recvstream,*sendstream;
panel *rightpanel=NULL;
void *mainptr[60];
void threads(int type);
GUI gui(threads);
void joy_handle(){
             static JOYINFO joy;
             static int last;
             static int counter=0;
             if (counter%10==0)
             if (joyUser!=NULL){
                         joyGetPos(0,&joy);
                         if (joy.wXpos!=32511){
                                               if (joy.wXpos==0){
                                                                 if (joyUser->key==0) joyUser->key=KEY_LEFT;
                                               }
                                               else if(joy.wXpos==65535)
                                                    if (joyUser->key==0) joyUser->key=KEY_RIGHT;
                         }
                         if (joy.wYpos!=32511){
                                               if (joy.wYpos==0){
                                                                 if (joyUser->key==0) joyUser->key=KEY_UP;
                                               }
                                               else if(joy.wYpos==65535)
                                                    if (joyUser->key==0) joyUser->key=KEY_DOWN;
                         }
                         if (joy.wButtons!=0&&last!=joy.wButtons){
                                              if (joy.wButtons==1)
                                                                   //if (tankUser1->key==0)
                                                                   joyUser->key=32;
                         }
                         if (joy.wButtons==2){
                                                                   //if (tankUser1->key==0)
                                                                   joyUser->key=32;
                                              }
                         last=joy.wButtons;
             }
             counter++;
             if (counter==100) counter=0;
}
int tx,ty,ttarget,tdir,ttargetbullet,mode,remainingBot=10,totalLive=3,aliveBot=0,level,lostcenter=0;
//totalLive is a total number of reborn of tanks and first born also included.
//aliveBot total number of bots which is alive now
queueBot queue[10];
int gamemode=0;
void objectHandler(void *arg);
void objectHandlerBullet(void *arg);
void netStreamHandler(void *arg){
     char dat[20];
     int i,target,dir,type,x,y;
     while (1){
//           cout<<".";a
           recvstream->recieve(dat);
//           i=0;
//           while (((dat[i]>='0'&&dat[i]<='9')||dat[i]==' ')&&i<20){
//                                           i++;
//           }
//           dat[i]=0;
           //cout<<"Truncated data "<<dat<<endl;
           
           sscanf(dat,"%d %d %d %d %d",&type,&target,&dir,&x,&y);
           if (type==0){
               tx=x;
               ty=y;
               tdir=dir;
               ttarget=target;
               _beginthread(objectHandler,0,0);
           }
           else if(type==1){
//               tx=x;
//               ty=y;
//               tdir=dir;
                 cout<<"Truncated data "<<dat<<endl;
                 ttargetbullet=target;
               _beginthread(objectHandlerBullet,0,0);
           }
           
           //if (x>720) x=x/10;
           //if (y>720) y=y/10;
//           tankUser1->ox=tankUser1->x;
//           tankUser1->oy=tankUser1->y;
//             (machine *)(objPtr[hostid])->x=x;
//             (machine *)(objPtr[hostid])->y=y;
//           tankUser1->x=x;
//           tankUser1->y=y;
//             ((machine *)((int)objPtr[hostid])->draw(1,1);
             //Sleep(10);
     }
     _endthread();
}
void objectHandler(void *arg){
     try {
             ((machine *)(*((int *)objPtr+ttarget)))->x=tx;
             //((machine *)(*((int *)objPtr+ttarget)))->qShoot=1;
             ((machine *)(*((int *)objPtr+ttarget)))->dir=tdir;
             ((machine *)(*((int *)objPtr+ttarget)))->y=ty;
             ((machine *)(*((int *)objPtr+ttarget)))->draw(1,1);
             
             
                     }
        catch (int param) { cout << "int exception"; }
        catch (char param) { cout << "char exception"; }
        catch (...) { cout << "default exception"; }

_endthread();

}
void objectHandlerBullet(void *arg){
     try{
/*             ((machine *)(*((int *)objPtr+ttarget)))->x=tx;
             ((machine *)(*((int *)objPtr+ttarget)))->dir=tdir;
             ((machine *)(*((int *)objPtr+ttarget)))->y=ty;*/
//             if (ttargetbullet<10)
             ((machine *)(*((int *)objPtr+ttargetbullet)))->shoot(1);
                                  }
        catch (int param) { cout << "int exception"; }
        catch (char param) { cout << "char exception"; }
        catch (...) { cout << "default exception"; }

             _endthread();
}
void user1Controller(void *arg){
     try{
     while (cont){
               tankUser1->clock(mode);
               Sleep(USER_CLK);
     }
                          }
        catch (int param) { cout << "int exception"; }
        catch (char param) { cout << "char exception"; }
        catch (...) { cout << "default exception"; }

     _endthread();
}
int mode2=0;
void user2Controller(void *arg){
     try{
     while (cont){
               tankUser2->clock(mode2);
               Sleep(USER_CLK);
     }
                          }
        catch (int param) { cout << "int exception"; }
        catch (char param) { cout << "char exception"; }
        catch (...) { cout << "default exception"; }

     _endthread();
}
void botController1(void *arg){
     try{
     while (cont){
               bot1->clock(mode);
               Sleep(BOT_CLK);
     }
                          }
        catch (int param) { cout << "int exception"; }
        catch (char param) { cout << "char exception"; }
        catch (...) { cout << "default exception"; }

     _endthread();
}
void botController2(void *arg){
     try{
     while (cont){
               bot2->clock(mode);
               Sleep(BOT_CLK);
     }
                          }
        catch (int param) { cout << "int exception"; }
        catch (char param) { cout << "char exception"; }
        catch (...) { cout << "default exception"; }

     _endthread();
}
void botController3(void *arg){
     try{
     while (cont){
               bot3->clock(mode);
               Sleep(BOT_CLK);
     }
                          }
        catch (int param) { cout << "int exception"; }
        catch (char param) { cout << "char exception"; }
        catch (...) { cout << "default exception"; }

     _endthread();
}
void botController4(void *arg){
     try{
     while (cont){
               bot4->clock(mode);
               Sleep(BOT_CLK);
     }
                          }
        catch (int param) { cout << "int exception"; }
        catch (char param) { cout << "char exception"; }
        catch (...) { cout << "default exception"; }

     _endthread();
}

void joyController(void *arg){
    JOYINFOEX joyInfoEx;
    joyInfoEx.dwSize = sizeof(joyInfoEx);
    BOOL JoyPresent=true;
     while (JoyPresent){
           joy_handle();
           Sleep(USER_CLK);
           JoyPresent = (joyGetPosEx(JOYSTICKID1, &joyInfoEx) == JOYERR_NOERROR);
     }
     _endthread();
}
void rotateimg(void *src,void *&dest,int w,int angle){
    dest=malloc(imagesize(0,0,w-2,w-2));
    getimage(600,600,600+w-2,600+w-2,dest);
    int *srcptr,i,j;
    int *srcptr2=(int *)src+6;
    int *destptr;
    int *destptr2=(int *)dest+6;
    w-=2;
    for (i=0;i<=w;i++){
    for (j=0;j<=w;j++){
          srcptr=srcptr2+(w+1)*i+j;
          if (angle==270){
             destptr=destptr2+(w+1)*(w-j)+i;
          }
          else if (angle==90){
               destptr=destptr2+(w+1)*j+i;
          }
          else if (angle==180){
               destptr=destptr2+(w+1)*i+(w-j);
          }
          *destptr=*srcptr;
    }
    }
}
char path[50];
void sound_thread(void *arg)
{
   PlaySound(path, NULL, SND_APPLICATION);
  _endthread();
}
void threads_thread(void *arg)
{
   char dat[20];
   cout<<"WAITING"<<endl;
   recvstream->auth(dat);
   cout<<"RECV IP:"<<dat<<endl;
   strcpy(PARTNER_IP,dat);
   cout<<"RART IP:"<<PARTNER_IP<<endl;
//   strcpy(sendstream->partnerip,dat);
   sendstream->setpartner(dat);
   cout<<"SEND STREAM:"<<sendstream->partnerip<<endl;
   gui.cont=false;
   cout<<"DONE"<<endl;
  _endthread();
}
void threads(int type){
     switch(type){
                  case 0:
                       _beginthread(threads_thread,0,0);
                       break;
     }
}
int ps1,ps2,ps3,ps4;
void freeze_thread(void *arg)
{
     delay(5000);
     bot1->status=ps1;
     bot2->status=ps2;
     bot3->status=ps3;
     bot4->status=ps4;
  _endthread();
}
void shovel_thread(void *arg)
{
//     for ()
/*
       for (int i=47;i<52;i++)
       for (int j=27;j<36;j++)
       {
           if (geoMap->data[i][j]!=E_Center){
                       geoMap->data[i][j]=E_Steel;
           }
       }
       geoMap->drawmap(47,27,4,8,mainptr[8]);
       
       geoMap->printmap();
       
       delay(20000);
     
       for (int i=47;i<52;i++)
       for (int j=27;j<36;j++)
       {
           if (geoMap->data[i][j]!=E_Center){
                       geoMap->data[i][j]=E_Brick;
           }
       }
       geoMap->drawmap(47,27,4,8,mainptr[8]);
       */
  _endthread();
}

void sound(int type)
{
  cout<<"Sound: "<<type<<endl;
  switch(type)
  {
    case 0:
         strcpy(path,"sounds//start.wav");
         break;
    case 1:
         strcpy(path,"sounds//gameover.wav");    
         break;
    case 2:
         strcpy(path,"sounds//fire.wav");    
         break;
    case 3:
         strcpy(path,"sounds//die.wav");    
         break;
    case 4:
         strcpy(path,"sounds//score.wav");
         break;
    case 5:
         strcpy(path,"sounds//item.wav");
         break;
    case 6:  
         strcpy(path,"sounds//move.wav");
         break;
    case 7:  
         strcpy(path,"sounds//steel.wav");
         break;
    case 8:
         strcpy(path,"sounds//background.wav");
         break;
    case 9:
         if (rightpanel!=NULL) rightpanel->decTank();
         break;
    case 10:
         if (rightpanel!=NULL) rightpanel->setLife(totalLive);
         break;
    case 11:
             ps1=bot1->status;
             ps2=bot2->status;
             ps3=bot3->status;
             ps4=bot4->status;
             bot1->status=3;
             bot2->status=3;
             bot3->status=3;
             bot4->status=3;       
         break;
  }
  if (type<9) _beginthread(sound_thread,0,0);
  else if(type==11) _beginthread(freeze_thread,0,0);
  else if(type==12) _beginthread(shovel_thread,0,0);
}
//
int main(int argc, char *argv[]){
    
    int sorc=1;
    
   	recvstream=new network(PARTNER_IP,mainptr);
	sendstream=new network(PARTNER_IP,mainptr);
//    cout<<"Game mode:";
    //cin>>sorc;
//    cin>>gamemode;
   initwindow(WIN_WIDTH,WIN_HEIGHT,"BATTLE CITY",400,10);
   gui.draw();
   gamemode=gui.startMenu();
   cleardevice();
//   cout<<"IP: "<<gui.IP<<endl;
   char *ip;
   
   ip=gui.IP2+14;
//   cout<<PARTNER_IP<<endl;
//     cout<<gamemode<<endl;
//   cout<<"IP: "<<gui.IP2<<endl;
//   cout<<"truncated IP: "<<ip<<endl;

//client =0 , host=1
    mode=2;
    if (gamemode==31){
         mode=0;
         sorc=1;
         gamemode=3;
    }
    if (gamemode==32){
         mode=1;
         sorc=0;
         gamemode=3;
         strcpy(PARTNER_IP,ip);
         sendstream->setpartner(ip);
    }
//    if(sorc==0) mode=1;
//    if (sorc==0) mode=1;
//    if (argc>1) strcpy(PARTNER_IP,"192.168.1.5");
    //cout<<sorc<<endl;
    //cout<<PARTNER_IP<<endl;
    
    //readimagefile("images\\Winter.jpg",0,0,WIN_WIDTH,WIN_HEIGHT);
	//for (int i=TK_WIDTH;i<=WIN_WIDTH;i+=TK_WIDTH){
//		line(0,i,800,i);
//		line(i,0,i,700);
	//}
	
	cout<<"BEGIN"<<endl;
	
	myMap=new map();
	bulletMap=new map();
	geoMap=new map();
	
	myMap->fillmap(0,0,0,52,52);
	bulletMap->fillmap(0,0,0,52,52);
	geoMap->fillmap(0,0,0,52,52);
	
	void *data,*data2;
	for (int i=0;i<20;i++)
	mainptr[i]=NULL;
	mainptr[0]=myMap;
	mainptr[1]=geoMap;
	mainptr[2]=bulletMap;
	
	for (int i=0;i<20;i++)
	objPtr[i]=NULL;
	
	mainptr[3]=objPtr;
	
	int result[5][5]={0,0,0,0,0,0,0,0,0,0};
	mainptr[4]=result;
	
	itemType items[20];
	mainptr[5]=items;
	
	items[1].x=10;
	
	int itemcounter=0;
	mainptr[6]=&itemcounter;
	
	//cout<<"Res:"<<result<<endl;
	
	int x=0,y=0;
	data=malloc(imagesize(0,0,AW_W,AW_H));
	getimage(x,y,x+AW_W,y+AW_H,data);
	mainptr[7]=data;
	
    data=malloc(imagesize(0,0,TK_WIDTH-2,TK_HEIGHT-2));
	getimage(x,y,x+TK_WIDTH-2,y+TK_HEIGHT-2,data);
	mainptr[9]=data;

    data=malloc(imagesize(0,0,TK_STEP,TK_STEP));
	getimage(x,y,x+TK_STEP,y+TK_STEP,data);
	mainptr[8]=data;
	
	//cout<<"BLACK: "<<data<<endl;
	
	x=0,y=100;
	data=malloc(imagesize(0,0,TK_WIDTH-2,TK_HEIGHT-2));
	readimagefile("images/tank1.gif",x+(TK_WIDTH-TK_IMG)/2,y+(TK_WIDTH-TK_IMG)/2,x+TK_WIDTH-(TK_WIDTH-TK_IMG)/2,y+TK_HEIGHT-(TK_WIDTH-TK_IMG)/2);
	getimage(x+1,y+1,x+TK_WIDTH-1,y+TK_HEIGHT-1,data);
	mainptr[11]=data;
	
	rotateimg(data,data2,TK_HEIGHT,90);
	mainptr[12]=data2;
	rotateimg(data,data2,TK_HEIGHT,180);
	mainptr[13]=data2;
	rotateimg(data,data2,TK_HEIGHT,270);
	mainptr[10]=data2;
	
	x=100,y=0;
	data=malloc(imagesize(0,0,TK_WIDTH-2,TK_HEIGHT-2));
	readimagefile("images/tank2.gif",x+(TK_WIDTH-TK_IMG)/2,y+(TK_WIDTH-TK_IMG)/2,x+TK_WIDTH-(TK_WIDTH-TK_IMG)/2,y+TK_HEIGHT-(TK_WIDTH-TK_IMG)/2);
	getimage(x+1,y+1,x+TK_WIDTH-1,y+TK_HEIGHT-1,data);
	mainptr[15]=data;
	
	rotateimg(data,data2,TK_HEIGHT,90);
	mainptr[16]=data2;
	rotateimg(data,data2,TK_HEIGHT,180);
	mainptr[17]=data2;
	rotateimg(data,data2,TK_HEIGHT,270);
	mainptr[14]=data2;
	
	x=100,y=100;
	data=malloc(imagesize(0,0,TK_WIDTH-2,TK_HEIGHT-2));
	readimagefile("images/tank3.gif",x+(TK_WIDTH-TK_IMG)/2,y+(TK_WIDTH-TK_IMG)/2,x+TK_WIDTH-(TK_WIDTH-TK_IMG)/2,y+TK_HEIGHT-(TK_WIDTH-TK_IMG)/2);
	getimage(x+1,y+1,x+TK_WIDTH-1,y+TK_HEIGHT-1,data);
	mainptr[19]=data;
	
	rotateimg(data,data2,TK_HEIGHT,90);
	mainptr[20]=data2;
	rotateimg(data,data2,TK_HEIGHT,180);
	mainptr[21]=data2;
	rotateimg(data,data2,TK_HEIGHT,270);
	mainptr[18]=data2;
	
	x=100,y=200;
	data=malloc(imagesize(0,0,TK_WIDTH-2,TK_HEIGHT-2));
	readimagefile("images/tank4.gif",x+(TK_WIDTH-TK_IMG)/2,y+(TK_WIDTH-TK_IMG)/2,x+TK_WIDTH-(TK_WIDTH-TK_IMG)/2,y+TK_HEIGHT-(TK_WIDTH-TK_IMG)/2);
	getimage(x+1,y+1,x+TK_WIDTH-1,y+TK_HEIGHT-1,data);
	mainptr[23]=data;
	
	rotateimg(data,data2,TK_HEIGHT,90);
	mainptr[24]=data2;
	rotateimg(data,data2,TK_HEIGHT,180);
	mainptr[25]=data2;
	rotateimg(data,data2,TK_HEIGHT,270);
	mainptr[22]=data2;
	
	x=0,y=200;
	data=malloc(imagesize(0,0,TK_WIDTH-2,TK_HEIGHT-2));
	readimagefile("images/bot1.gif",x+(TK_WIDTH-TK_IMG)/2,y+(TK_WIDTH-TK_IMG)/2,x+TK_WIDTH-(TK_WIDTH-TK_IMG)/2,y+TK_HEIGHT-(TK_WIDTH-TK_IMG)/2);
	getimage(x+1,y+1,x+TK_WIDTH-1,y+TK_HEIGHT-1,data);
	mainptr[31]=data;
	
	rotateimg(data,data2,TK_HEIGHT,90);
	mainptr[32]=data2;
	rotateimg(data,data2,TK_HEIGHT,180);
	mainptr[33]=data2;
	rotateimg(data,data2,TK_HEIGHT,270);
	mainptr[30]=data2;
	
	x=0,y=300;
	data=malloc(imagesize(0,0,TK_WIDTH-2,TK_HEIGHT-2));
	readimagefile("images/bot2.gif",x+(TK_WIDTH-TK_IMG)/2,y+(TK_WIDTH-TK_IMG)/2,x+TK_WIDTH-(TK_WIDTH-TK_IMG)/2,y+TK_HEIGHT-(TK_WIDTH-TK_IMG)/2);
	getimage(x+1,y+1,x+TK_WIDTH-1,y+TK_HEIGHT-1,data);
	mainptr[35]=data;
	
	rotateimg(data,data2,TK_HEIGHT,90);
	mainptr[36]=data2;
	rotateimg(data,data2,TK_HEIGHT,180);
	mainptr[37]=data2;
	rotateimg(data,data2,TK_HEIGHT,270);
	mainptr[34]=data2;
	
	x=0,y=400;
	data=malloc(imagesize(0,0,TK_WIDTH-2,TK_HEIGHT-2));
	readimagefile("images/bot3.gif",x+(TK_WIDTH-TK_IMG)/2,y+(TK_WIDTH-TK_IMG)/2,x+TK_WIDTH-(TK_WIDTH-TK_IMG)/2,y+TK_HEIGHT-(TK_WIDTH-TK_IMG)/2);
	getimage(x+1,y+1,x+TK_WIDTH-1,y+TK_HEIGHT-1,data);
	mainptr[39]=data;
	
	rotateimg(data,data2,TK_HEIGHT,90);
	mainptr[40]=data2;
	rotateimg(data,data2,TK_HEIGHT,180);
	mainptr[41]=data2;
	rotateimg(data,data2,TK_HEIGHT,270);
	mainptr[38]=data2;
	
	x=0,y=500;
	data=malloc(imagesize(0,0,TK_WIDTH-2,TK_HEIGHT-2));
	readimagefile("images/bot4.gif",x+(TK_WIDTH-TK_IMG)/2,y+(TK_WIDTH-TK_IMG)/2,x+TK_WIDTH-(TK_WIDTH-TK_IMG)/2,y+TK_HEIGHT-(TK_WIDTH-TK_IMG)/2);
	getimage(x+1,y+1,x+TK_WIDTH-1,y+TK_HEIGHT-1,data);
	mainptr[43]=data;
	
	rotateimg(data,data2,TK_HEIGHT,90);
	mainptr[44]=data2;
	rotateimg(data,data2,TK_HEIGHT,180);
	mainptr[45]=data2;
	rotateimg(data,data2,TK_HEIGHT,270);
	mainptr[42]=data2;
	
	mainptr[46]=&mode;
	mainptr[47]=&totalLive;
	mainptr[48]=&remainingBot;
	mainptr[49]=&aliveBot;
	
	keyTable keyUser1;
	keyUser1.up=72;
	keyUser1.left=75;
	keyUser1.right=77;
	keyUser1.down=80;
	keyUser1.shoot=32;
	
	keyTable keyUser2;
	keyUser2.up=119;
	keyUser2.left=97;
	keyUser2.right=100;
	keyUser2.down=115;
	keyUser2.shoot=9;

	mainptr[50]=recvstream;
	mainptr[51]=sendstream;
	
	mainptr[52]=&level;
	mainptr[53]=&lostcenter;
	
    char ch;
    setfillstyle(SOLID_FILL,0);
    bar(0,0,getmaxx(),getmaxy());
    if (gamemode!=GM_CONSTRUCTOR){
        char path[20];
        sprintf(path,"data\\lvl%d.txt",gui.lvl);
        geoMap->loadmap(path);
        geoMap->drawmap();
    }
    
   	queue[0].bonus=false;
	queue[0].level=0;
	queue[0].dir=1;
	queue[1].bonus=false;
	queue[1].level=1;
	queue[1].dir=2;
	queue[2].bonus=false;
	queue[2].level=2;
	queue[2].dir=3;
	queue[3].bonus=false;
	queue[3].level=3;
	queue[3].dir=4;
	queue[4].bonus=false;
	queue[4].level=0;
	queue[4].dir=1;
	queue[5].bonus=true;
	queue[5].level=1;
	queue[5].dir=2;
	queue[6].bonus=false;
	queue[6].level=3;
	queue[6].dir=3;
	queue[7].bonus=true;
	queue[7].level=2;
	queue[7].dir=4;
	queue[8].bonus=true;
	queue[8].level=1;
	queue[8].dir=1;
	queue[9].bonus=true;
	queue[9].level=0;
	queue[9].dir=2;
    
    
    //bot1=new bot(11,0,0,1,mainptr,0,sound,false);
    
    //bot1=new bot(11,0,0,1,mainptr,0,sound,false);
    if (gamemode!=GM_CONSTRUCTOR){
    bot1=new bot(11,0,0,mainptr,sound,queue);
    bot2=new bot(12,208,0,mainptr,sound,queue);
    bot3=new bot(13,416,0,mainptr,sound,queue);
    bot4=new bot(14,624,0,mainptr,sound,queue);
    //bot3=new bot(13,416,0,2,mainptr,2,sound,false);
    //bot4=new bot(14,624,0,3,mainptr,3,sound,false);
    
    cout<<"\n\n\nITEMs: "<<items<<endl;
	
	tankUser1=new tank(1,208,624,keyUser1,0,mainptr,0,sound);
	if (gamemode==GM_MULTI_PLAYER||gamemode==GM_NETWORK)
	tankUser2=new tank(2,416,624,keyUser2,0,mainptr,0,sound);

	objPtr[1]=tankUser1;
	objPtr[2]=tankUser2;
	
	objPtr[11]=bot1;
	objPtr[12]=bot2;
	objPtr[13]=bot3;
	objPtr[14]=bot4;
    }
    bool cont2;
    cout<<"MAIN SS: "<<sendstream<<endl;
    cout<<"MAIN ARRAY SS: "<<mainptr[51]<<endl;
	joyUser=tankUser1;
    if (gamemode==GM_NETWORK)
    {
                totalLive+=2;
                cout<<"NETWORK"<<endl;
                cout<<"IP: "<<PARTNER_IP<<endl;
                cout<<"SORC: "<<sorc<<endl;
                cout<<"MODE: "<<mode<<endl;
                cout<<"GAMEMODE: "<<gamemode<<endl;
                
                cont=1;
                cont2=true;
                
                if (sorc==0)
                {
                            sendstream->send("1");
                            //cout<<gethostbyname("localhost")<<endl;
                            cout<<"LISTENING"<<endl;
                            joyUser=tankUser2;
                }
                else{
//                     char p[2];
//                     cout<<
//                     recvstream->auth(p);
                }
                
                rightpanel=new panel(8,1,3);
         
                _beginthread(user1Controller, 0,0);
                _beginthread(user2Controller, 0,0);
                _beginthread(joyController, 0,0);
                _beginthread(netStreamHandler, 0,0);
                _beginthread(botController1, 0,0);
                _beginthread(botController2, 0,0);
                _beginthread(botController3, 0,0);
                _beginthread(botController4, 0,0);
                //sound(0);
                
                //for (level=gui.lvl;level<20;level++)
                    
                    aliveBot=4;
                    
                    remainingBot=4;
                    totalLive++;
                    cont=1;

                    rightpanel->setTanks(remainingBot);
                    rightpanel->setLife(totalLive);
                    rightpanel->setLevel(level);
                    
                    bot1->active();
                    bot2->active();
                    bot3->active();
                    bot4->active();
                    
                    tankUser1->active();       
//                    tankUser2->active(); 
                    
                    
                    
                    for (int i=1;i<5;i++)
                    result[i][0]=0,result[i][1]=0;
                    
                    if (sorc==1){
                        while(cont2){
                                if (kbhit())
                    			{
                                      ch=getch();
                                      if (keyUser1.check(ch)) if (tankUser1->key==0) tankUser1->key=ch;
                                }//kbhit
                                //if (tankUser1->status==0) cont=0;
                                if (totalLive==0||(remainingBot==0&&aliveBot==0)||lostcenter==1) {
                                                                                                 if (lostcenter)
                                                                                                                 sound(1);
                                                                                                 delay(2000);
                                                                                                 cont2=false;
                                }
                                delay(10);
                        }//cont2
                    }//sorc==1
                    else{
                         cont2=true;
                        cout<<"PLAYER 2"<<endl;
                        while(cont2){
                                if (kbhit())
                    			{
                                      ch=getch();
                                      if (keyUser2.check(ch)) if (tankUser2->key==0) tankUser2->key=ch;
                                }//kbhit
                                //if (tankUser1->status==0) cont=0;
                                if (totalLive==0||(remainingBot==0&&aliveBot==0)||lostcenter==1) {
                                                                                                 if (lostcenter)
                                                                                                                 sound(1);
                                                                                                 delay(2000);
                                                                                                 cont2=false;
                                                                                                 cont=false;
                                }
                                delay(10);
                        }//while cont2
                        
                       if (totalLive==0||lostcenter){
                             bot1->status=2;
                             bot2->status=2;
                             bot3->status=2;
                             bot4->status=2;
                             tankUser1->status=2;
                    }
                    bot1->deactive();
                    bot2->deactive();
                    bot3->deactive();
                    bot4->deactive();
                    tankUser1->deactive();

                        
                        finish tempfinish(result);
                  }//else
    }
    else if(gamemode==GM_SINGLE_PLAYER){
                rightpanel=new panel(10,1,totalLive);
         
                _beginthread(botController1, 0,0);
                _beginthread(botController2, 0,0);
                _beginthread(botController3, 0,0);
                _beginthread(botController4, 0,0);
                _beginthread(user1Controller, 0,0);;
                _beginthread(joyController, 0,0);
                sound(0);
                for (level=gui.lvl;level<20;level++){
                    
                    cont=true;
                    cont2=true;
//                    aliveBot=4;
                    
                    if (level==gui.lvl) aliveBot=4;
                    else aliveBot=0;
                    
                    remainingBot=4;
                    totalLive++;
                    cont=1;

                    rightpanel->setTanks(remainingBot);
                    rightpanel->setLife(totalLive);
                    rightpanel->setLevel(level);
                    
                    bot1->active();
                    bot2->active();
                    bot3->active();
                    bot4->active();
                    
                    tankUser1->active();
                            
                    for (int i=1;i<5;i++)
                    result[i][0]=0,result[i][1]=0;
                    
//                    cout<<"LC"<<&lostcenter<<endl;
                    while(cont2){
                            if (kbhit())
                			{
                                  ch=getch();
                                  if (keyUser1.check(ch)) if (tankUser1->key==0) tankUser1->key=ch;
                                  if (ch==13){
                                              for (int i=0;i<2;i++){
                                                  for (int j=0;j<5;j++)
                                                  cout<<result[i][j]<<" ";
                                                  cout<<endl<<endl;
                                                  cout<<"Remaining Bot:"<<remainingBot<<endl;
                                                  cout<<"Alive Bot:"<<aliveBot<<endl;
                                                  
                                                  _beginthread(shovel_thread,0,0);
//                                                  cout<<" Bot:"<<remaininBot<<endl;
                                              }
                                  }
                            }//kbhit
                            //if (tankUser1->status==0) cont=0;
                            if (totalLive==0||(remainingBot==0&&aliveBot==0)||lostcenter==1) {
                                                                                             if (lostcenter){
                                                                                                             sound(1);
                                                                                             }
                                                                                             delay(2000);
                                                                                             cont2=false;
                                                                                             cont=false;
                            }
                            delay(USER_CLK);
                    }//while cont2
                    if (totalLive==0||lostcenter==1){
                             bot1->status=2;
                             bot2->status=2;
                             bot3->status=2;
                             bot4->status=2;
                             tankUser1->status=2;
                    }
                    bot1->deactive();
                    bot2->deactive();
                    bot3->deactive();
                    bot4->deactive();
                    tankUser1->deactive();
                    
                    finish tempfinish(result);
                    
                    if (totalLive==0||lostcenter==1) break;
                            char path[20];
                            sprintf(path,"data\\lvl%d.txt",level+1);
                            geoMap->loadmap(path);
                            geoMap->drawmap();
              }
    }
    else if(gamemode==GM_MULTI_PLAYER){
                rightpanel=new panel(10,1,totalLive);
         
                _beginthread(botController1, 0,0);
                _beginthread(botController2, 0,0);
                _beginthread(botController3, 0,0);
                _beginthread(botController4, 0,0);
                _beginthread(user1Controller, 0,0);
                _beginthread(user2Controller, 0,0);
                _beginthread(joyController, 0,0);
                sound(0);
                for (level=gui.lvl;level<20;level++){
                    
                    cont2=true;
//                    aliveBot=4;
                    
                    if (level==gui.lvl) aliveBot=4;
                    else aliveBot=0;
                    
                    remainingBot=4;
                    totalLive+=2;
                    cont=1;

                    rightpanel->setTanks(remainingBot);
                    rightpanel->setLife(totalLive);
                    rightpanel->setLevel(level);
                    
                    bot1->active();
                    bot2->active();
                    bot3->active();
                    bot4->active();
                    
                    tankUser1->active();
                    tankUser2->active();
                            
                    for (int i=1;i<5;i++)
                    result[0][i]=0,result[1][i]=0;
                    
                    
                    cout<<"LC"<<&lostcenter<<endl;
                    while(cont2){
                            if (kbhit())
                			{
                                  ch=getch();
                                  if (keyUser1.check(ch)) if (tankUser1->key==0) tankUser1->key=ch;
                                  if (keyUser2.check(ch)) if (tankUser2->key==0) tankUser2->key=ch;
                                  if (ch==13){
                                              for (int i=0;i<2;i++){
                                                  for (int j=0;j<5;j++)
                                                  cout<<result[i][j]<<" ";
                                                  cout<<endl<<endl;
                                                  cout<<"Remaining Bot:"<<remainingBot<<endl;
                                                  cout<<"Alive Bot:"<<aliveBot<<endl;
                                                  
//                                                  cout<<" Bot:"<<remaininBot<<endl;
                                              }
                                  }
                            }//kbhit
                            //if (tankUser1->status==0) cont=0;
                            if (totalLive==0||(remainingBot==0&&aliveBot==0)||lostcenter==1) {
                                                                                             if (lostcenter){
                                                                                                             sound(1);
                                                                                             }
                                                                                             delay(2000);
                                                                                             cont2=false;
                            }
                            delay(10);
                    }
                    if (totalLive==0||lostcenter==1){
                             bot1->status=2;
                             bot2->status=2;
                             bot3->status=2;
                             bot4->status=2;
                             tankUser1->status=2;
                    }
                    bot1->deactive();
                    bot2->deactive();
                    bot3->deactive();
                    bot4->deactive();
                    tankUser1->deactive();
                    tankUser2->deactive();
                    
                    finish tempfinish(result);
                    
                    if (totalLive==0||lostcenter==1) break;
                            char path[20];
                            sprintf(path,"data\\lvl%d.txt",level+1);
                            geoMap->loadmap(path);
                            geoMap->drawmap();
              }
               /* rightpanel=new panel(10,1,totalLive);
         
                _beginthread(botController1, 0,0);
                _beginthread(botController2, 0,0);
                _beginthread(botController3, 0,0);
                _beginthread(botController4, 0,0);
                _beginthread(user1Controller, 0,0);
                _beginthread(user2Controller,0,0);
                sound(0);
                for (level=gui.lvl;level<20;level++){
                    cont2=true;
                    aliveBot=4;
                    remainingBot=4;
                    totalLive++;
                    cont=1;

                    rightpanel->setTanks(remainingBot-4);
                    rightpanel->setLife(totalLive);
                    rightpanel->setLevel(level);
                    
                    bot1->active();
                    bot2->active();
                    bot3->active();
                    bot4->active();
                    
                    tankUser1->active();
                    tankUser2->active();
                            
                    for (int i=1;i<5;i++)
                    result[i][0]=0,result[i][1]=0;
                    
                    
                    //cout<<"LC"<<&lostcenter<<endl;
                    while(cont2){
                            if (kbhit())
                			{
                                  ch=getch();
                                  if (keyUser1.check(ch)) if (tankUser1->key==0) tankUser1->key=ch;
                                  if (keyUser2.check(ch)) if (tankUser2->key==0) tankUser2->key=ch;
                                  if (ch==13){
                                              for (int i=0;i<2;i++){
                                                  for (int j=0;j<5;j++)
                                                  cout<<result[i][j]<<" ";
                                                  cout<<endl<<endl;
                                                  cout<<"Remaining Bot:"<<remainingBot<<endl;
                                                  cout<<"Alive Bot:"<<aliveBot<<endl;
                                                  
//                                                  cout<<" Bot:"<<remaininBot<<endl;
                                              }
                                  }
                            }//kbhit
                            //if (tankUser1->status==0) cont=0;
                            if (totalLive==0||(remainingBot==0&&aliveBot==0)||lostcenter==1) {
                                                                                             if (lostcenter){
                                                                                                             sound(1);
                                                                                             }
                                                                                             delay(2000);
                                                                                             cont2=false;
                            }
                            delay(10);
                    }
                    bot1->deactive();
                    bot2->deactive();
                    bot3->deactive();
                    bot4->deactive();
                    finish tempfinish(result);
                    delay(2000);
                    if (totalLive==0||lostcenter==1) break;
                       char path[20];
                        sprintf(path,"data\\level%d.dat",level+1);
                        geoMap->loadmap(path);
                        geoMap->drawmap();

                }*/

    }
    else if(gamemode==GM_CONSTRUCTOR){
                construction constr("const");
                constr.begin_construction();
                constr.printMap();
                constr.writeFile();
                
                cleardevice();
                
                geoMap->loadmap("data\\custom.dat");
                geoMap->drawmap();
                
                
                bot1=new bot(11,0,0,mainptr,sound,queue);
                bot2=new bot(12,208,0,mainptr,sound,queue);
                bot3=new bot(13,416,0,mainptr,sound,queue);
                bot4=new bot(14,624,0,mainptr,sound,queue);
                //bot3=new bot(13,416,0,2,mainptr,2,sound,false);
                //bot4=new bot(14,624,0,3,mainptr,3,sound,false);
            	
            	tankUser1=new tank(1,208,624,keyUser1,0,mainptr,0,sound);
            	
                joyUser=tankUser1;
//            	if (gamemode==GM_MULTI_PLAYER||gamemode==GM_NETWORK)
//            	tankUser2=new tank(2,416,624,keyUser2,0,mainptr,0,sound);
            
            	objPtr[1]=tankUser1;
            	objPtr[2]=tankUser2;
            	
            	objPtr[11]=bot1;
            	objPtr[12]=bot2;
            	objPtr[13]=bot3;
            	objPtr[14]=bot4;
                
                _beginthread(botController1, 0,0);
                _beginthread(botController2, 0,0);
                _beginthread(botController3, 0,0);
                _beginthread(botController4, 0,0);
                _beginthread(user1Controller, 0,0);
                _beginthread(joyController, 0,0);
                
                if (level==gui.lvl) aliveBot=4;
                    else aliveBot=0;
                    
                    remainingBot=4;
                    totalLive++;
                    cont=1;
                    
                    rightpanel=new panel(10,1,totalLive);
                    
                    rightpanel->setTanks(remainingBot);
                    rightpanel->setLife(totalLive);
                    rightpanel->setLevel(level);
                
                
                sound(0);
                /*while(cont){
                        if (kbhit())
            			{
                              ch=getch();
                              if (keyUser1.check(ch)) if (tankUser1->key==0) tankUser1->key=ch;
                        }//kbhit
                        if (tankUser1->status==0) cont=0;
                        delay(10);
                }*/
                for (int i=1;i<5;i++)
                    result[i][0]=0,result[i][1]=0;
                    
                    
                    cout<<"LC"<<&lostcenter<<endl;
                    cont2=true;
                    while(cont2)
                    {
                            if (kbhit())
                			{
                                  ch=getch();
                                  if (keyUser1.check(ch)) if (tankUser1->key==0) tankUser1->key=ch;
                                  if (ch==13){
                                              for (int i=0;i<2;i++){
                                                  for (int j=0;j<5;j++)
                                                  cout<<result[i][j]<<" ";
                                                  cout<<endl<<endl;
                                                  cout<<"Remaining Bot:"<<remainingBot<<endl;
                                                  cout<<"Alive Bot:"<<aliveBot<<endl;
                                                  
//                                                  cout<<" Bot:"<<remaininBot<<endl;
                                              }
                                  }
                            }//kbhit
                            //if (tankUser1->status==0) cont=0;
                            if (totalLive==0||(remainingBot==0&&aliveBot==0)||lostcenter==1) {
                                                                                             if (lostcenter){
                                                                                                             sound(1);
                                                                                             }
                                                                                             delay(2000);
                                                                                             cont2=false;
                            }
                            delay(10);
                    }//wh
                    finish tempfinish(result);                    
//                    if (totalLive==0||lostcenter==1) break;

              //}
    }
    cin.ignore();
    system("pause");
}
