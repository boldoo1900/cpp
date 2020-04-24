#include "map.h"
#include <iostream>

using namespace std;

#if defined debug || defined debugMap
#include <iostream>
#endif

#include <fstream>

using namespace std;

void map::loadmap(char *str){
     ifstream input(str);

     int code,i=0,j=0;
    while (!input.eof()){
          input>>code;
          data[i][j]=code;
          i++;
          if (i==52) {
                        i=0,j++;
                        if (j==52) break;
                    }
    }
    input.close();
}
void map::drawmap(){
     setbkcolor(0);
     cleardevice();
    int x,y;
    char path[20];
    int i,j;
    for (i=0;i<52;i++){
         for (j=0;j<52;j++){
                     if (data[i][j]==E_Brick){
                             sprintf(path,"images\\brick%d%d.gif",i%2,j%2);
        					 readimagefile(path,i*13,j*13,(i+1)*13,(j+1)*13);
                     }
                     else if (data[i][j]==E_Steel){
                             sprintf(path,"images\\steel%d%d.gif",i%2,j%2);
        					 readimagefile(path,i*13,j*13,(i+1)*13,(j+1)*13);
        					 //if (i%2==0&&j%2==0) readimagefile("images\\steel.gif",i*13,j*13,(i+2)*13,(j+2)*13);
                     }
                     else if (data[i][j]==E_Center){
                                               if (i%4==0&&j%4==0)
                                               readimagefile("images\\center.gif",i*13,j*13,(i+4)*13,(j+4)*13);
                     }
                     else if (data[i][j]==E_Grass){
                             sprintf(path,"images\\bush%d%d.gif",i%2,j%2);
        					 readimagefile(path,i*13,j*13,(i+1)*13,(j+1)*13);
//        					 if (i%2==0&&j%2==0) readimagefile("images\\bush2.gif",i*13,j*13,(i+2)*13,(j+2)*13);
                     }
                     else if (data[i][j]==E_Ice){
//                             sprintf(path,"images\\ice%d%d.gif",i%2,j%2);
        					 readimagefile("images\\ice.gif",i*13,j*13,(i+1)*13,(j+1)*13);
//        					 if (i%2==0&&j%2==0) readimagefile("images\\bush2.gif",i*13,j*13,(i+2)*13,(j+2)*13);
                     }
                     else if (data[i][j]==E_Water){
//                             sprintf(path,"images\\ice%d%d.gif",i%2,j%2);
        					 readimagefile("images\\water.gif",i*13,j*13,(i+1)*13,(j+1)*13);
//        					 if (i%2==0&&j%2==0) readimagefile("images\\bush2.gif",i*13,j*13,(i+2)*13,(j+2)*13);
                     }
             }
     }
}
void map::drawmap(int px,int py,int w,int h,void *black){
//    cout<<"redraw: "<<px<<" "<<py<<" "<<w<<" "<<h<<endl;
    int i,j;
    char path[20];
    int x=px/13;
    int y=py/13;
    for (i=x;i<=x+w;i++){
//        cout<<x<<" "<<y<<endl;
         for (j=y;j<=y+h;j++){
//             if (w==3&&h==3) cout<<"values "<<i<<" "<<j<<endl;
                     putimage(i*13,j*13,black,COPY_PUT);
                     if (data[i][j]==E_Brick){
                             sprintf(path,"images\\brick%d%d.gif",i%2,j%2);
        					 readimagefile(path,i*13,j*13,(i+1)*13,(j+1)*13);
                     }
                     else if (data[i][j]==E_Steel){
                             sprintf(path,"images\\steel%d%d.gif",i%2,j%2);
        					 readimagefile(path,i*13,j*13,(i+1)*13,(j+1)*13);
        					 //if (i%2==0&&j%2==0) readimagefile("images\\steel.gif",i*13,j*13,(i+2)*13,(j+2)*13);
//        					 int i2=i-i%2,j2=j-j%2;
//        					 readimagefile("images\\steel.gif",i2*13,j2*13,(i2+2)*13,(j2+2)*13);
                     }
                     else if (data[i][j]==E_Center){
                                               if (i%4==0&&j%4==0)
                                               readimagefile("images\\center.gif",i*13,j*13,(i+4)*13,(j+4)*13);
                     }
                     else if (data[i][j]==E_Grass){
                             sprintf(path,"images\\bush%d%d.gif",i%2,j%2);
        					 readimagefile(path,i*13,j*13,(i+1)*13,(j+1)*13);
//        					 readimagefile("images\\bush2.gif",i*13,j*13,(i+1)*13,(j+1)*13);
                     }
                     else if (data[i][j]==E_Ice){
                             //sprintf(path,"images\\ice%d%d.gif",i%2,j%2);
        					 readimagefile("images\\ice.gif",i*13,j*13,(i+1)*13,(j+1)*13);
//        					 if (i%2==0&&j%2==0) readimagefile("images\\bush2.gif",i*13,j*13,(i+2)*13,(j+2)*13);
                     }
                     else if (data[i][j]==E_Water){
                             sprintf(path,"images\\center%d%d.gif",i%2,j%2);
        					 readimagefile(path,i*13,j*13,(i+1)*13,(j+1)*13);
//        					 readimagefile("images\\water.gif",i*13,j*13,(i+1)*13,(j+1)*13);
                     }
                     else if (data[i][j]>=I_Tank&&data[i][j]<=I_Illusion){
                          cout<<"item redraw:"<<data[i][j]<<endl;
                          if (data[i][j]==I_Tank){
                                       sprintf(path,"images\\tank%d%d.gif",i%2,j%2);
                                       readimagefile(path,i*13,j*13,(i+1)*13,(j+1)*13);
                          }
                          else if (data[i][j]==I_Shield){
                               sprintf(path,"images\\shield%d%d.gif",i%2,j%2);
                               readimagefile(path,i*13,j*13,(i+1)*13,(j+1)*13);
                          }
                          else if (data[i][j]==I_Hurz){
                               sprintf(path,"images\\shovel%d%d.gif",i%2,j%2);
                               readimagefile(path,i*13,j*13,(i+1)*13,(j+1)*13);
                          }
                          else if (data[i][j]==I_Star){
                               sprintf(path,"images\\star%d%d.gif",i%2,j%2);
                               readimagefile(path,i*13,j*13,(i+1)*13,(j+1)*13);
                          }
                          else if (data[i][j]==I_Clock){
                               sprintf(path,"images\\time%d%d.gif",i%2,j%2);
                               readimagefile(path,i*13,j*13,(i+1)*13,(j+1)*13);
                          }
                          else if (data[i][j]==I_Bomb){
                               sprintf(path,"images\\tank%d%d.gif",i%2,j%2);
                               readimagefile(path,i*13,j*13,(i+1)*13,(j+1)*13);
                          }
                          else if (data[i][j]==I_Gun){
                               sprintf(path,"images\\tank%d%d.gif",i%2,j%2);
                               readimagefile(path,i*13,j*13,(i+1)*13,(j+1)*13);
                          }
                          else if (data[i][j]==I_Hast){
                               sprintf(path,"images\\tank%d%d.gif",i%2,j%2);
                               readimagefile(path,i*13,j*13,(i+1)*13,(j+1)*13);
                          }
                          else if (data[i][j]==I_Slow){
                               sprintf(path,"images\\tank%d%d.gif",i%2,j%2);
                               readimagefile(path,i*13,j*13,(i+1)*13,(j+1)*13);
                          }
                          else if (data[i][j]==I_Illusion){
                               sprintf(path,"images\\tank%d%d.gif",i%2,j%2);
                               readimagefile(path,i*13,j*13,(i+1)*13,(j+1)*13);
                          }

                     }
             }
     }
}
void map::fillmap(int px,int py,int z,int w,int h){
     if (w>52) w=52;
     if (h>52) h=52;
     int x=px/13;
     int y=py/13;
     int i,j;
     for (i=x;i<x+w;i++)
     for (j=y;j<y+h;j++){
         data[i][j]=z;
         }
}
//#if defined debug || defined debugMap
void map::printmap(){
     int i,j;
     for (i=0;i<52;i++){
         cout<<i%10<<": ";
         for (j=0;j<52;j++)
             cout<<data[j][i]%10;
         cout<<endl;
     }
     cin.ignore();
}
//#endif
