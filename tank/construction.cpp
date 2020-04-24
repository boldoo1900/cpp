#include "construction.h"
#include <iostream>

using namespace std;

construction::construction(char * str)
{
     for(int i=0;i<52;i++)
     for(int j=0;j<52;j++)
             {
                note[i][j]=0;             
             }          
}
void construction::printMap()
{
     for(int i=0;i<52;i++)
     {
     for(int j=0;j<52;j++)
                printf("%d ", note[j][i]);             
                printf("\n");
     }
}
void construction::begin_construction()
{    
     cout<<"const"<<endl;
     char a;
     void *data,*data1;
     
     int tolow=1,x=WIN_WIDTH-100+20,y=0,y1=100,x1=100,z=-1;
     data=malloc(imagesize(0,0,26,26));
     data1=malloc(imagesize(0,0,26,26));
    setfillstyle(SOLID_FILL,7);   
     bar(WIN_WIDTH-100,0,WIN_WIDTH,WIN_HEIGHT);
   //  songoj boloh dvrsvvd
     readimagefile("images\\ice.gif",x,y,x+26,y+26);
     
     readimagefile("images//brick00.gif",x,y+26,x+13,y+13+26);
     readimagefile("images//brick01.gif",x+13,y+26,x+26,y+13+26);
     readimagefile("images//brick10.gif",x,y+13+26,x+13,y+26*2);
     readimagefile("images//brick11.gif",x+13,y+13+26,x+26,y+26*2);
     setfillstyle(SOLID_FILL,BLUE);    
     //bar(x,y+26,x+26,x+26*2);
     readimagefile("images//water.gif",x,y+26*2,x+26,y+26*3);
     setfillstyle(SOLID_FILL,GREEN);    
     //bar(x,y+26*2,x+26,x+26*3);
     readimagefile("images\\bush.gif",x,y+26*3,x+26,y+26*4);
     readimagefile("images\\steel.gif",x,y+26*4,x+26,y+26*5);
     setfillstyle(SOLID_FILL,0);   
     readimagefile("images\\black.jpg",x,y+26*5,x+26,y+26*6);
     //bar(x,y+26*4,x+26,WIN_HEIGHT);
     
/*     for(int i=0;i<676;i+=13)
     for(int j=0;j<676;j+=13) //rectangle(i,j,i+13,j+13);*/
     while(1){
              
            // mousenii cursoriig songoson dvrseer daguulan ywuulah
                if(tolow==1&&mousex()>0&&mousey()>0)
                           {
                           putimage(x1,y1,data1,COPY_PUT);
                           x1=mousex();
                           y1=mousey();
                           getimage(x1,y1,x1+26,y1+26,data1);
                           putimage(x1,y1,data,COPY_PUT);                                          
                           delay(50);
                           // 
                           } 
           // budah dursee songoh
             /* if(1==ismouseclick(WM_LBUTTONDOWN)&&tolow==0)
                                                 {
                                                 for(int i=5;i>=0;i--) {
                                                                       if(mousey()>26*i&&mousex()>WIN_WIDTH-100+13) { 
                                                                                         getimage(x,26*i,x+26,26*(i+1),data);
                                                                                         putimage(x,WIN_WIDTH-100-26,data,COPY_PUT);
                                                                                         z=i;
                                                                                         //getimage(x1,y1,x1+26,y1+26,data1);
                                                                                         break;
                                                                                         }
                                                                       
                                                                       }
                                                  /*readimagefile("images\\brick00.gif",x,(y<26*5)*y,x+26,(y<26*5)*y+26);
                                                  readimagefile("images\\center.gif",x,(y<26*4)*(y+26)+ (y>=26*4)*(y-26*4),x+26,(y<26*4)*(y+26)+ (y>=26*4)*(y-26*4)+26);
                                                  readimagefile("images\\bot3.gif",x,(y<26*3)*(y+26*2) + (y>=26*3)*(y-26*43),x+26,(y<26*3)*(y+26*2) + (y>=26*3)*(y-26*3)+26);
                                                  readimagefile("images\\steel.gif",x,(y<26*2)*(y+26*3) + (y>=26*2)*(y-26*2),x+26,(y<26*2)*(y+26*3) + (y>=26*2)*(y-26*2)+26);
                                                  readimagefile("images\\tank1.gif",x,(y<26)*(y+26*4) + (y>=26)*(y-26),x+26,(y<26)*(y+26*4) + (y>=26)*(y-26)+26);
                                                  
                                                  clearmouseclick(WM_LBUTTONDOWN);
                                                  }
              */
              
              // songoson dvrseeree zurah
              if(1==ismouseclick(WM_LBUTTONDOWN)&&mousex()>0&&mousey()>0)
                                                         {
                                                         if(tolow==0) { 
                                                                      tolow=1; 
                                                                      clearmouseclick(WM_RBUTTONDOWN); 
                                                                      }
                                                          int i=(mousex()/13-(mousex()/13)%2)*13,j=(mousey()/13-(mousey()/13)%2)*13;
                                                          if(i<WIN_WIDTH-100-13&&j<WIN_HEIGHT-13) 
                                                                                             {
                                                                                              int pp=0;
                                                                                             /* for(int i1=i/13;i1<i/13+2&&i1<52;i1++)
                                                                                              for(int j1=j/13;j1<j/13+2&&j1<52;j1++) if(note[i1][j1]!=0) pp=1;
                                                                                              if(pp==0)
                                                                                              {
                                                                                              }
                                                                                              */
                                                                                              putimage(x1,y1,data1,COPY_PUT);
                                                                                              putimage(i,j,data,COPY_PUT);  
                                                                                              getimage(x1,y1,x1+26,y1+26,data1);          
                                                                                              printf("---------%d\n",z);
                                                                                              for(int i1=i/13;i1<i/13+2&&i1<52;i1++)
                                                                                              for(int j1=j/13;j1<j/13+2&&j1<52;j1++) if(z!=5) note[i1][j1]=40+z;  
                                                                                                                                     else note[i1][j1]=0; 
                                                                                              
                                                                                              clearmouseclick(WM_MBUTTONDOWN);
                                                                                              }
                                                          else if(i<WIN_WIDTH-100+39&&i>WIN_WIDTH-100+13&&j<26*6) 
                                                               {
                                                               for(int i=5;i>=0;i--) 
                                                                      {
                                                                       if(mousey()>26*i&&mousex()>WIN_WIDTH-100+13) 
                                                                                         {
                                                                                         putimage(x1,y1,data1,COPY_PUT);
                                                                                         getimage(x,26*i,x+25,26*(i+1)-1,data);
                                                                                         putimage(x,WIN_WIDTH-100-26,data,COPY_PUT);
                                                                                         z=i;
                                                                                         //getimage(x1,y1,x1+26,y1+26,data1);
                                                                                         break;
                                                                                         }
                                                                       }
                                                               }
                                                         clearmouseclick(WM_LBUTTONDOWN);
                                                         }
              //tolow==0 bol mousenii kursoriig daguulan zurna
              if(tolow==0&&mousex()<WIN_WIDTH-100-13&&mousey()<WIN_HEIGHT-13&&mousex()>0&&mousey()>0&&z!=-1) 
                          {  
                             int pp=0,i=(mousex()/13)*13,j=(mousey()/13)*13;
                             //i=i-i%2;
                             //j=j-j%2;
                           /*  for(int i1=i/13;i1<i/13+2&&i1<52;i1++) dawharlaj zurj boloh?
                           //  for(int j1=j/13;j1<j/13+2&&j1<52;j1++) if(note[i1][j1]!=0) pp=1;
                             if(pp==0)
                             {
                             }
                           */
                             int k=mousex()/13;
                             x1=(k-k%2)*13;
                             k=mousey()/13;
                             y1=(k-k%2)*13;
                             getimage(x1,y1,x1+26,y1+26,data1);
                             putimage(x1,y1,data,COPY_PUT);
                             for(int i1=x1/13;i1<x1/13+2&&i1<52;i1++)
                             for(int j1=y1/13;j1<y1/13+2&&j1<52;j1++) if(z!=5) note[i1][j1]=40+z;
                                                                       else note[i1][j1]=0;
                         
                           }
              // songoh tolwoos zurah tolow zurah tolwoos songoh tolow bolon oorchlogdoh 
              if (1==ismouseclick(WM_RBUTTONDOWN)) {
                                                       if(tolow==0 )
                                                       {
                                                         tolow=1;
                                                         putimage(x1,y1,data1,COPY_PUT);
                                                       //mousenii baruun towch daragdsan ved delgetsiin baruun hesgiin zuragnaas hamgiin deed taliihiig hadgalna
                                                        //getimage(mousex(),mousey(),mousex()+26,mousey()+26,data1);
                                                       }
                                                       else {
                                                            // cursor deerh zurgiig arilgana
                                                            putimage(x1,y1,data1,COPY_PUT);
                                                              tolow=0;
                                                            }
                                                       clearmouseclick(WM_RBUTTONDOWN);
                                                    }
            
             // map belen boloh || garah ved enter daran garah
             if(kbhit())
                         {
                         char a=getch();
                         if(a==13) break;
                         }
              }
          
}
void construction:: writeFile()
{
     FILE *mapFile;
     mapFile=fopen("data//custom.dat","w");
     if(mapFile!=NULL)
     {
      for(int i=0;i<52;i++)
      {
      for(int j=0;j<52;j++) fprintf(mapFile,"%d ",note[j][i]);               
      fprintf(mapFile,"\n");
      }
      
     }
     else printf("Error");  
     fclose(mapFile);
}
