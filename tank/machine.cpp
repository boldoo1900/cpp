#include "machine.h"
#include "etc.h"
//machine::machine(int mid,int px,int py,int pd,void *pp[60],int pl,soundFPtr psnd)
machine::machine(int mid,int px,int py,void *pp[60],soundFPtr psnd,queueBot *queue)
{
//Constructor for Bots                     
             stage=(int*)pp[52];
             result=(int *)pp[4];
             items=pp[5];
             itemcounter=(int *)pp[6];
             snd=psnd;
             id=mid;
             for (int i=0;i<60;i++){
                 pointers[i]=pp[i];
             }
             myMap=(map*)pp[0];
             geomap=(map*)pp[1];
             bulletmap=(map*)pp[2];
             imgdata[4]=pp[9];
             mode=(int*)pp[46];
             
             if (mid<9)
             total=(int*)pp[47];
             else total=(int*)pp[48];
             alive=(int *)pp[49];
             level=queue[*total-1].level;
             counter=0;
             sendstream=(network *)pp[51];
             x=px;
             y=py;
             bx=px;
             by=py;
             ox=x;
             oy=y;
             dir=queue[*total-1].dir;
             bcount=0;
             drawReq=1;
             key=0;
             qShoot=0;
             //status=1;
             myMap->fillmap(x,y,id,4,4);
//             active();
             
             for (int i=0;i<2;i++)
             bullets[i]=NULL;
}
machine::machine(int mid,int px,int py,int pd,void *pp[60],int pl,soundFPtr psnd)
{
                     
             stage=(int*)pp[52];
             result=(int *)pp[4];
             items=pp[5];
             itemcounter=(int *)pp[6];
             snd=psnd;
//             itemcounter=0;
             id=mid;
             for (int i=0;i<60;i++){
                 pointers[i]=pp[i];
             }
             myMap=(map*)pp[0];
             geomap=(map*)pp[1];
             bulletmap=(map*)pp[2];
             imgdata[4]=pp[9];
             mode=(int*)pp[46];
             
             if (mid<9)
             total=(int*)pp[47];
             else total=(int*)pp[48];
             alive=(int *)pp[49];
             level=pl;
             counter=0;
             sendstream=(network *)pp[51];
             x=px;
             y=py;
             bx=px;
             by=py;
             ox=x;
             oy=y;
             dir=pd;
             bcount=0;
             drawReq=1;
             key=0;
             qShoot=0;
             //status=1;
             
//             active();
             
             for (int i=0;i<2;i++)
             bullets[i]=NULL;
}
int machine::checkBush(){
    #ifdef debug_funtions 
     cout<<"machine::checkBush"<<endl;
     #endif
    int p=0,i,j;
    for (i=x;i<x+4;i++)
     for (j=y;j<y+4;j++)
         if (geomap->data[i][j]==E_Grass) p++;
     return p;
}
bool machine::checkBack(int px,int py){
     #ifdef debug_funtions 
     cout<<"machine::checkBack"<<endl;
     #endif
     bool p=false;
     int x=px/13;
     int y=py/13;
     int i,j;
     for (i=x;i<x+4;i++)
     for (j=y;j<y+4;j++){
         //if (geomap->data[i][j]==40||geomap->data[i][j]==43)
//         {
            if (geomap->data[i][j]==E_Ice)
            {
                             p=true;
                             char path[20];
                             sprintf(path,"images\\ice.gif",i%2,j%2);
        					 readimagefile(path,i*13,j*13,(i+1)*13,(j+1)*13);
//                 if (i%2==0&&j%2==0) readimagefile("images\\bush2.gif",i*13,j*13,(i+2)*13,(j+2)*13);
//        					 readimagefile("images\\bush2.gif",i*13,j*13,(i+1)*13,(j+1)*13);
        					 
                     }
            //geomap->drawmap(i*13,j*13,0,0,pointers[8]);
//            cout<<"Bush: "<<i<<" "<<j<<endl;
//         }
              else if (geomap->data[i][j]==0&&myMap->data[i][j]==0){
                  putimage(i*13,j*13,pointers[8],COPY_PUT);
            }
     }
     return p;
//     if (i%2==1&&j%2==1) readimagefile("images\\bush2.gif",(i-1)*13,j*13,(i+1)*13,(j+1)*13);
}
bool machine::checkFront(int px,int py){
     #ifdef debug_funtions 
     cout<<"machine::checkFront"<<endl;
     #endif
     bool p=false;
     int x=px/13;
     int y=py/13;
     int i,j;
     for (i=x;i<x+4;i++)
     for (j=y;j<y+4;j++){
         //if (geomap->data[i][j]==40||geomap->data[i][j]==43)
//         {
            if (geomap->data[i][j]==E_Grass)
            {
                                            p=true;
                             char path[20];
                             sprintf(path,"images\\bush%d%d.gif",i%2,j%2);
        					 readimagefile(path,i*13,j*13,(i+1)*13,(j+1)*13);
//                 if (i%2==0&&j%2==0) readimagefile("images\\bush2.gif",i*13,j*13,(i+2)*13,(j+2)*13);
//        					 readimagefile("images\\bush2.gif",i*13,j*13,(i+1)*13,(j+1)*13);
        					 
                     }
            //geomap->drawmap(i*13,j*13,0,0,pointers[8]);
//            cout<<"Bush: "<<i<<" "<<j<<endl;
//         }
              else if (geomap->data[i][j]==0&&myMap->data[i][j]==0){
                  putimage(i*13,j*13,pointers[8],COPY_PUT);
            }
     }
     return p;
//     if (i%2==1&&j%2==1) readimagefile("images\\bush2.gif",(i-1)*13,j*13,(i+1)*13,(j+1)*13);
}
int machine::check(int px,int py,int w,int h){
    #ifdef debug_funtions 
    cout<<"machine::check"<<endl;
    #endif
     int x=px/13;
     int y=py/13;
     int i,j;
     int res=1;
     for (i=x;i<x+w&&res==1;i++)
     for (j=y;j<y+h&&res==1;j++){
         if (!((myMap->data[i][j]==0||myMap->data[i][j]==id||(myMap->data[i][j]>=I_Tank&&myMap->data[i][j]<=I_Illusion))&&(geomap->data[i][j]==0||(geomap->data[i][j]>=20&&geomap->data[i][j]<=29)||geomap->data[i][j]==40||geomap->data[i][j]==43))){
         res=0;
         break;
         }
     }
     return res;
}
void machine::shoot(int z){
     #ifdef debug_funtions 
     cout<<"machine::shoot"<<endl;
     #endif
//     if (id<10)
                                       if (bcount<2){
                                                        #ifdef debug
                                                        cout<<id<<" New bullet!"<<bcount<<endl;
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
                                                                         if (id<9) snd(2);
                                                                         if (z==0){
                                                                                 char d[20];
                                                                                 sprintf(d,"%d %d %d %d %d#",1,id,dir,x,y);
                                                                                 sendstream->send(d);
                                                                         }
    											                         bullets[k]=new bullet(id,0,a_x,a_y,dir,pointers,10);
    											                         bcount++;
                                                   }
                                               }
}
void machine::draw(int p,int z){
     #ifdef debug_funtions 
     cout<<"machine::draw"<<endl;
     #endif
//     cout<<sizeof(itemType)<<endl;
//     cout<<"OO:"<<*itemcounter<<endl;
     if (drawReq||odir!=dir||p==1)
                  {
                        if (z==0) //sendstream->send(tid,0,x,y);
                        {
                            char d[20];
                            sprintf(d,"%d %d %d %d %d#",0,id,dir,x,y);
                            sendstream->send(d);
                        }
                        
                        int i=x/13;
                        int j=y/13;
                        if (dir==0){
                                    if(myMap->data[i][j]>=I_Tank){
                                    cout<<"EVRIKA"<<endl;
                                    //for (int i=0;i<*itemcounter;i++)
                                    if (*itemcounter==1)
                                    {
//                                        if (x/13-((itemType *)items+i)->x<2&&y/13-((itemType *)items+i)->y<2)
//                                        if (abs(x/13-((itemType *)items+i)->x)<4&&abs(y-((itemType *)items+i)->y)<4)
                                        {
                                            cout<<"FOUND "<<myMap->data[i][j]<<endl;
                                            switch (myMap->data[i][j]){
                                                   case I_Tank:
                                                               (*total)++;
                                                               snd(10);
                                                        break;
                                                   case I_Clock:
                                                               snd(11);
                                                        break;
                                                   case I_Hurz:
                                                               snd(12);
                                                        break;
                                                   case I_Star:
                                                               if (level<3) level++;
//                                                               draw();
                                                        break;
                                            }
                                            myMap->data[((itemType *)items)->x][((itemType *)items)->y]=0;
                                            myMap->data[((itemType *)items)->x][((itemType *)items)->y+1]=0;
                                            myMap->data[((itemType *)items)->x+1][((itemType *)items)->y]=0;
                                            myMap->data[((itemType *)items)->x+1][((itemType *)items)->y+1]=0;
                                            geomap->drawmap(((itemType *)items)->x*13,((itemType *)items)->y*13,3,3,pointers[8]);
                                            (*itemcounter)=0;
//                                            break;
                                        }
                                    }
                                    }
                        }
                        else if (dir==1){
                                    if(myMap->data[i+3][j]>=I_Tank){
                                    cout<<"EVRIKA"<<endl;
                                    //for (int i=0;i<*itemcounter;i++)
                                    {
//                                        if (x/13-((itemType *)items+i)->x<2&&y/13-((itemType *)items+i)->y<2)
//                                        if (abs(x/13-((itemType *)items+i)->x)<4&&abs(y-((itemType *)items+i)->y)<4)
                                        {
                                             cout<<"FOUND "<<myMap->data[i+3][j]<<endl;
                                             switch (myMap->data[i+3][j]){
                                                   case I_Tank:
                                                               (*total)++;
                                                               snd(10);
                                                        break;
                                                   case I_Clock:
                                                               snd(11);
                                                        break;
                                                   case I_Hurz:
                                                               snd(12);
                                                        break;
                                                   case I_Star:
                                                               if (level<3) level++;
//                                                               draw();
                                                        break;
                                            }
                                            myMap->data[((itemType *)items)->x][((itemType *)items)->y]=0;
                                            myMap->data[((itemType *)items)->x][((itemType *)items)->y+1]=0;
                                            myMap->data[((itemType *)items)->x+1][((itemType *)items)->y]=0;
                                            myMap->data[((itemType *)items)->x+1][((itemType *)items)->y+1]=0;
                                            geomap->drawmap(((itemType *)items)->x*13,((itemType *)items)->y*13,3,3,pointers[8]);
                                            (*itemcounter)=0;
//                                            break;
                                        }
                                    }
                                    }
                        }
                        else if (dir==2){
                                    if(myMap->data[i][j+3]>=I_Tank){
                                    cout<<"EVRIKA"<<endl;
/*                                    for (int i=0;i<itemcounter;i++){
                                        items[]
                                    }
                                    system("pause");*/
                                    //for (int i=0;i<*itemcounter;i++)
                                    {
                                        //if (x-x%2==((itemType *)items+i)->x&&y-y%2==((itemType *)items+i)->y)
                                    //    if (x/13-((itemType *)items+i)->x<2&&y/13-((itemType *)items+i)->y<2)
                                        //if (abs(x/13-((itemType *)items+i)->x)<4&&abs(y-((itemType *)items+i)->y)<4)
                                        {
                                            cout<<"FOUND "<<myMap->data[i][j+3]<<endl;
                                            switch (myMap->data[i][j+3]){
                                                   case I_Tank:
                                                               (*total)++;
                                                               snd(10);
                                                        break;
                                                   case I_Clock:
                                                               snd(11);
                                                        break;
                                                   case I_Hurz:
                                                               snd(12);
                                                        break;
                                                   case I_Star:
                                                               if (level<3) level++;
//                                                               draw();
                                                        break;
                                            }
                                            myMap->data[((itemType *)items)->x][((itemType *)items)->y]=0;
                                            myMap->data[((itemType *)items)->x][((itemType *)items)->y+1]=0;
                                            myMap->data[((itemType *)items)->x+1][((itemType *)items)->y]=0;
                                            myMap->data[((itemType *)items)->x+1][((itemType *)items)->y+1]=0;
                                            geomap->drawmap(((itemType *)items)->x*13,((itemType *)items)->y*13,3,3,pointers[8]);
                                            (*itemcounter)=0;
//                                            break;
                                        }
                                    }
                                    }
                        }
                        else if (dir==3){
                                    if(myMap->data[i][j]>=I_Tank){
                                    cout<<"EVRIKA"<<endl;
                                    //for (int i=0;i<*itemcounter;i++)
                                    {
                                        //if (abs(x/13-((itemType *)items+i)->x)<4&&abs(y-((itemType *)items+i)->y)<4)
                                        //if (x/13-((itemType *)items+i)->x<2&&y/13-((itemType *)items+i)->y<2)
                                        {
                                            cout<<"FOUND "<<myMap->data[i][j]<<endl;
                                            switch (myMap->data[i][j]){
                                                   case I_Tank:
                                                               (*total)++;
                                                               snd(10);
                                                        break;
                                                   case I_Clock:
                                                               snd(11);
                                                        break;
                                                   case I_Hurz:
                                                               snd(12);
                                                        break;
                                                   case I_Star:
                                                               if (level<3) level++;
//                                                               draw();
                                                        break;
                                            }
                                            myMap->data[((itemType *)items)->x][((itemType *)items)->y]=0;
                                            myMap->data[((itemType *)items)->x][((itemType *)items)->y+1]=0;
                                            myMap->data[((itemType *)items)->x+1][((itemType *)items)->y]=0;
                                            myMap->data[((itemType *)items)->x+1][((itemType *)items)->y+1]=0;
                                            geomap->drawmap(((itemType *)items)->x*13,((itemType *)items)->y*13,3,3,pointers[8]);
                                            (*itemcounter)=0;
                                            /*
                                            myMap->data[((itemType *)items+i)->x][((itemType *)items+i)->y]=0;
                                            myMap->data[((itemType *)items+i)->x][((itemType *)items+i)->y+1]=0;
                                            myMap->data[((itemType *)items+i)->x+1][((itemType *)items+i)->y]=0;
                                            myMap->data[((itemType *)items+i)->x+1][((itemType *)items+i)->y+1]=0;
                                            
                                            myMap->drawmap(((itemType *)items+i)->x*13,((itemType *)items+i)->y*13,3,3,pointers[8]);
                                            
                                            for (int j=i;j<*itemcounter-1;j++){
                                                ((itemType *)items+j)->x=((itemType *)items+j+1)->x;
                                                ((itemType *)items+j)->y=((itemType *)items+j+1)->y;
                                            }*/
//                                            break;
                                        }
                                    }
                                    }
                        }
                        
//                        if (id<9) snd(6);
                        myMap->fillmap(ox,oy,0,4,4);
                        myMap->fillmap(x,y,id,4,4);
//                        if (checkBush()<16)

                        putimage(ox+1,oy+1,imgdata[4],COPY_PUT);
                        
                        bool k=checkBack(ox,oy);
                        checkFront(ox,oy);
                        
                        checkBack(x,y);
                        
                        if (k) {
                               char temp[30];
                               if (id<9) sprintf(temp,"images//tank%d.gif",level+1);
                               else sprintf(temp,"images//bot%d.gif",level+1);
                               readimagefile(temp,x+(TK_WIDTH-TK_IMG)/2,y+(TK_WIDTH-TK_IMG)/2,x+TK_WIDTH-(TK_WIDTH-TK_IMG)/2,y+TK_HEIGHT-(TK_WIDTH-TK_IMG)/2);
                        }
						else putimage(x+1,y+1,imgdata[dir],COPY_PUT);
						drawReq=0;
						
						checkFront(x,y);
						 ox=x;
                         oy=y;
                         odir=dir;
				  }
}
void machine::die(){
     #ifdef debug_funtions 
     cout<<"machine::die"<<endl;
     #endif
     if (status==1){
     cout<<id<<" died"<<endl;
     if (bonus) {
                srand(time(NULL));
                cout<<"*********************"<<endl;
                while(1){
                         int rx=rand()%52;
                         int ry=rand()%52;
                         if (myMap->data[rx][ry]==0&&geomap->data[rx][ry]!=E_Center)
                         {
                                if (*itemcounter==1){
                                    myMap->data[((itemType *)items)->x][((itemType *)items)->y]=0;
                                    myMap->data[((itemType *)items)->x][((itemType *)items)->y+1]=0;
                                    myMap->data[((itemType *)items)->x+1][((itemType *)items)->y]=0;
                                    myMap->data[((itemType *)items)->x+1][((itemType *)items)->y+1]=0;
                                    geomap->drawmap(((itemType *)items)->x*13,((itemType *)items)->y*13,3,3,pointers[8]);
                                }
                                int k;
                                k=rand()%11+20;
                                if (k%2==0) k=I_Clock;
                                else if (k%2==1) k=I_Tank;
//                                else if (k%3==2) k=I_Hurz;
//                                k=I_Hurz;
                                rx=rx-rx%2;
                                ry=ry-ry%2;
                                myMap->data[rx][ry]=k;
                                myMap->data[rx][ry+1]=k;
                                myMap->data[rx+1][ry]=k;
                                myMap->data[rx+1][ry+1]=k;
                                cout<<"ITEM: "<<rx<<" "<<ry<<" "<<k<<endl;
                                myMap->drawmap(rx*13,ry*13,1,1,pointers[8]);
                                
                                ((itemType *)items)->x=rx;
                                ((itemType *)items)->y=ry;
//                                ((itemType *)items+*itemcounter))).x=rx;
//                                ((itemType *)items+*itemcounter))).y=ry;
                                *itemcounter=1;
                                
                                break;
                         }
                }
     }
//     cout<<*alive<<endl;
     if (id>10) (*alive)--;
     status=0;
/*           for (int i=0;i<2;i++){
             if (bullets[i]!=NULL)
                if (bullets[i]->enabled==0)
                {
                   delete bullets[i];
                   bullets[i]=NULL;
                   bcount--;
                }
           }
*/           
//           bullets[0]=NULL;
//           bullets[1]=NULL;
           bcount=0;
           myMap->fillmap(x,y,0,4,4);
           putimage(x+1,y+1,imgdata[4],COPY_PUT);
           
           checkBack(x,y);
           
           etc temp;
           temp.animation(x,y,0);
           
     x=bx;
     y=by;
     if (id>10) dir=2;
     else dir=0;
     
     for (int i=0;i<2;i++){
             if (bullets[i]!=NULL)
                //if (bullets[i]->enabled==0)
                {
                   delete bullets[i];
                   bullets[i]=NULL;
                   bcount--;
                }
           }
           bullets[0]=NULL;
           bullets[1]=NULL;
           bcount=0;
           counter=0;
           
           
     counter=0;
     }
}
void machine::active(){
     #ifdef debug_funtions 
     cout<<"machine::active"<<endl;
     #endif
     if (status!=1){
             if ((*total)>0) {
                                          cout<<"Total: "<<*total<<" :"<<id<<endl;
                                          if (id>10){
                                                     snd(9);
                                                     (*alive)++;
                                                     force=(*stage)*3+level*5;
                                          }
                                          cout<<*alive<<endl;
                                          cout<<"OK"<<endl;
                                          
                              (*total)--;
                              if (id<10) snd(10);
                              status=1;
                              x=bx;
                              y=by;
                              if (*total>0){
                                 etc temp;
                                 temp.animation(x,y,1);
                              }
                             if (id>10) dir=2;
                             else dir=0;
                             draw(1,*mode);
             }
             else status=2;
     }
     counter=0;
}
void machine::deactive(){
     #ifdef debug_funtions 
     cout<<"machine::deactive"<<endl;
     #endif
     if (status==1){
           cout<<id<<" deactivated"<<endl;
           if (id>10) (*alive)--;
           cout<<*alive<<endl;
           status=2;
           for (int i=0;i<2;i++){
             if (bullets[i]!=NULL)
                //if (bullets[i]->enabled==0)
                {
                   delete bullets[i];
                   bullets[i]=NULL;
                   bcount--;
                }
           }
           bullets[0]=NULL;
           bullets[1]=NULL;
           bcount=0;
           counter=0;
     }
}
