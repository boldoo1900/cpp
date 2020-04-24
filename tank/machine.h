#ifndef machine_h
#define machine_h

#include <graphics.h>
#include <iostream>
#include "defines.h"
#include "bullet.h"
#include "map.h"
#include "network.h"

class machine{
      public:
             machine(int,int,int,int,void *pp[60],int,soundFPtr);
             machine(int,int,int,void *pp[60],soundFPtr,queueBot *);
             
             soundFPtr snd;
             void *pointers[60];
             
             network *sendstream;
             
             void *imgdata[5];
             map *myMap;
             map *bulletmap;
             map *geomap;
             
             int x,y,dir,drawReq,ox,oy,odir,bcount,key,qShoot,counter,level,status,id,*mode,*total,*alive,*itemcounter,*stage;
             int force;
             void *items;
             int *result;
             bool bonus;
             int bx,by;
             bullet *bullets[2];
             
             virtual void clock(int z=0)=0;
             virtual void procedure(int z=0){};
             int check(int,int,int,int);
             bool checkBack(int,int);
             bool checkFront(int,int);
             int checkBush();
             void draw(int p=0,int z=0);
             void shoot(int z=0);
             void die();
             void active();
             void deactive();
      
};

#endif
