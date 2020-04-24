#include "bot.h"

using namespace std;

bot::bot(int pbid,int px,int py,int pd,void *pp[60],int pl,soundFPtr snd,bool pbonus): machine(pbid,px,py,pd,pp,pl,snd){
             cout<<"bot "<<pbid<<" constructed"<<endl;
             force=0;
             for (int i=0;i<4;i++)
             imgdata[i]=pp[30+pl*4+i];
             //draw(1,1);
             bonus=pbonus;
             active();
}
bot::bot(int pbid,int px,int py,void *pp[60],soundFPtr snd,queueBot pqueue[10]):machine(pbid,px,py,pp,snd,pqueue){
             cout<<"bot "<<pbid<<" constructed"<<endl;
             force=0;
             for (int i=0;i<4;i++)
             imgdata[i]=pp[30+(pqueue[*total-1]).level*4+i];
             //draw(1,1);
             bonus=(pqueue[*total-1]).bonus;
             active();
}

void bot::clock(int z){
     #ifdef debug
                       cout<<counter<<"Bot clock: z="<<z<<endl;
     #endif
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
     }//3
     
     if (counter%10==0){
                       if (z!=1) procedure(z);
     }//10
     
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
          //if (counter>0) counter=0;
          counter++;
          if (counter==200) active();
     }
     else if (status==3){
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
             }//3
          counter++;
          if (counter==60) counter=0;
     }
}
void bot::procedure(int z){
     #ifdef debug
            cout<<"BOT PROCEDURE BEGIN"<<endl;
     #endif
     drawReq=1;
     
        if (z!=1) qShoot=1;
        
        int up_way = 0;
        int right_way = 0;
        int down_way = 0;
        int left_way = 0;
        srand ( time(NULL) );      
        int q = x/TK_STEP;
        int p = y/TK_STEP; 
        if(checker(q,p,3)) left_way = 1;
        else left_way = 0; 

        //Deesh ?
        if(checker(q,p,0)) up_way = 1;
        else up_way = 0;  

        //Baruun ?
        if(checker(q,p,1)) right_way = 1;
        else right_way = 0;

        //Doosh ?
        if(checker(q,p,2)) down_way = 1;
        else down_way = 0;
        switch(dir)
        {
          //Zuun                
          case 3:
          {
            if(left_way == 0 && up_way == 0 && down_way == 0)
            {
              int M = rand()%9 + 1;
              if(M == 1) dir = 0;
              else
              {
                if(M == 2) dir = 2;
                else
                {
                  x -= TK_STEP; 
                  drawReq=1;   
                }    
              }              
            }
            if(left_way == 0 && up_way == 0 && down_way == 1)
            {
              int M = rand()%7 + 1;  
              if(M == 1) dir = 0;
              else x -= TK_STEP,drawReq=1;         
            }
            if(left_way == 0 && up_way == 1 && down_way == 0)
            {
              int M = rand()%7 + 1;  
              if(M == 1) dir = 2;
              else x -= TK_STEP,drawReq=1;           
            }
            if(left_way == 0 && up_way == 1 && down_way == 1)
              x -= TK_STEP,drawReq=1;
            if(left_way == 1 && up_way == 0 && down_way == 0)
            {
              int M = rand()%1 + 1;
              if(M == 1) dir = 0;
              else dir = 2;            
            }
            if(left_way == 1 && up_way == 0 && down_way == 1)
              dir = 0; 
            if(left_way == 1 && up_way == 1 && down_way == 0)
              dir = 2;
            if(left_way == 1 && up_way == 1 && down_way == 1)
              dir = 1; 
              
            break;    
          }
          //Deeshe
          case 0:
          {
            if(up_way == 0 && left_way == 0 && right_way == 0)
            {
              int M = rand()%9 + 1;
              if(M == 1) dir = 3;
              else
              {
                if(M == 2) dir = 1;
                else
                {
                  y -= TK_STEP;
                  drawReq=1;    
                }    
              }              
            }
            if(up_way == 0 && left_way == 0 && right_way == 1)
            {
              int M = rand()%7 + 1;  
              if(M == 1) dir = 3;
              else y -= TK_STEP,drawReq=1;          
            }
            if(up_way == 0 && left_way == 1 && right_way == 0)
            {
              int M = rand()%7 + 1;  
              if(M == 1) dir = 1;
              else y -= TK_STEP,drawReq=1;            
            }
            if(up_way == 0 && left_way == 1 && right_way == 1)
              y -= TK_STEP,drawReq=1;
            if(up_way == 1 && left_way == 0 && right_way == 0)
            {
              int M = rand()%1 + 1;
              if(M == 1) dir = 3;
              else dir = 1;            
            }
            if(up_way == 1 && left_way == 0 && right_way == 1)
              dir = 3; 
            if(up_way == 1 && left_way == 1 && right_way == 0)
              dir = 1;
            if(up_way == 1 && left_way == 1 && right_way == 1)
              dir = 2;   
            break;    
          }
          
          //Baruun
          case 1:
          {
            if(right_way == 0 && up_way == 0 && down_way == 0)
            {
              int M = rand()%9 + 1;
              if(M == 1) dir = 0;
              else
              {
                if(M == 2) dir = 2;
                else
                {
                  x += TK_STEP;  
                  drawReq=1;  
                }    
              }              
            }
            if(right_way == 0 && up_way == 0 && down_way == 1)
            {
              int M = rand()%7 + 1;  
              if(M == 1) dir = 0;
              else x += TK_STEP,drawReq=1;          
            }
            if(right_way == 0 && up_way == 1 && down_way == 0)
            {
              int M = rand()%7 + 1;  
              if(M == 1) dir = 2;
              else x += TK_STEP,drawReq=1;            
            }
            if(right_way == 0 && up_way == 1 && down_way == 1)
              x += TK_STEP,drawReq=1;
            if(right_way == 1 && up_way == 0 && down_way == 0)
            {
              int M = rand()%1 + 1;
              if(M == 1) dir = 0;
              else dir = 2;            
            }
            if(right_way == 1 && up_way == 0 && down_way == 1)
              dir = 0; 
            if(right_way == 1 && up_way == 1 && down_way == 0)
              dir = 2;
            if(right_way == 1 && up_way == 1 && down_way == 1)
              dir = 3;  
            break;    
          }
          
          //Dooshoo
          case 2:
          {
            if(down_way == 0 && left_way == 0 && right_way == 0)
            {
              int M = rand()%9 + 1;
              if(M == 1) dir = 3;
              else
              {
                if(M == 2) dir = 1;
                else
                {
                  y += TK_STEP;   
                  drawReq=1; 
                }    
              }              
            }
            if(down_way == 0 && left_way == 0 && right_way == 1)
            {
              int M = rand()%7 + 1;  
              if(M == 1) dir = 3;
              else y += TK_STEP,drawReq=1;          
            }
            if(down_way == 0 && left_way == 1 && right_way == 0)
            {
              int M = rand()%7 + 1;  
              if(M == 1) dir = 1;
              else y += TK_STEP,drawReq=1;            
            }
            if(down_way == 0 && left_way == 1 && right_way == 1)
              y += TK_STEP,drawReq=1;
            if(down_way == 1 && left_way == 0 && right_way == 0)
            {
              int M = rand()%1 + 1;
              if(M == 1) dir = 3;
              else dir = 1;            
            }
            if(down_way == 1 && left_way == 0 && right_way == 1)
              dir = 3; 
            if(down_way == 1 && left_way == 1 && right_way == 0)
              dir = 1;
            if(down_way == 1 && left_way == 1 && right_way == 1)
              dir = 0;   
            break;     
          }                  
        }
        //draw(0,z);
        draw(1,z);
        #ifdef debug
        cout<<"BOT PROCEDURE END"<<endl;
        #endif
}
int bot::checker(int m,int n,int T)
{
  switch(T) 
  {
      case 0:
           if(n == 0) return 1;             
           break;
      case 1:
           if(m == (51-3)) return 1;
           break;
      case 2:
           if(n == (51-3)) return 1;
           break;
      case 3:    
           if(m == 0) return 1;
           break;  
  }        
  if(T == 0)
  {
    for(int j = 0; j <= 3; j++) 
      if( !((geomap->data[m + j][n - 1] == 0 ||
                 (
                   geomap->data[m + j][n - 1] >= 20 && 
                   geomap->data[m + j][n - 1] <= 29 
                 )||
                 (
                   geomap->data[m + j][n - 1] == 40 ||
                   geomap->data[m + j][n - 1] == 43
                 )
               )&& myMap->data[m + j][n - 1] == 0)
             ) return 1;  
  }
  if(T == 1)
  {
    for(int j = 0; j <= 3; j++)
    {
     if( !((geomap->data[m+4][n + j] == 0 ||
                 (
                   geomap->data[m+4][n + j] >= 20 && 
                   geomap->data[m+4][n + j] <= 29 
                 )||
                 (
                   geomap->data[m+4][n + j] == 40 ||
                   geomap->data[m+4][n + j] == 43
                 )
               )&& myMap->data[m+4][n + j] == 0)
             ) return 1;            
  }
  }
  if(T == 2)
  {
    for(int j=0; j<=3; j++)
     { if( !((geomap->data[m + j][n+4] == 0 ||
                 (
                   geomap->data[m + j][n+4] >= 20 && 
                   geomap->data[m + j][n+4] <= 29 
                 )||
                 (
                   geomap->data[m + j][n+4] == 40 ||
                   geomap->data[m + j][n+4] == 43
                 )
               )&& myMap->data[m + j][n+4] == 0)
             ) return 1;
             }
  }
  if(T == 3)
  {
    for(int j=0; j<=3; j++)
      if( !((geomap->data[m-1][n + j] == 0 ||
                 (
                   geomap->data[m-1][n + j] >= 20 && 
                   geomap->data[m-1][n + j] <= 29 
                 )||
                 (
                   geomap->data[m-1][n + j] == 40 ||
                   geomap->data[m-1][n + j] == 43
                 )
               )&& myMap->data[m-1][n + j] == 0)
             ) return 1;   
  }
  return 0;
}
