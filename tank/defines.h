#ifndef defines_h
#define defines_h

#define WIN_HEIGHT 676
#define WIN_WIDTH 776
#define AREA_HEIGHT 676
#define AREA_WIDTH 676
#define TK_HEIGHT 52
#define TK_WIDTH 52
#define TK_IMG 40
#define TK_STEP 13

#define AW_H 14
#define AW_W 14

#define Space 0
#define P1 1
#define P2 2
#define I_Tank 20
#define I_Shield 21
#define I_Hurz 22
#define I_Star 24
#define I_Clock 25
#define I_Gun 26
#define I_Hast 27
#define I_Slow 28
#define I_Bomb 29
#define I_Illusion 30

#define E_Ice 40
#define E_Brick 41
#define E_Water 42
#define E_Grass 43
#define E_Steel 44
#define E_Center 45

#define GM_SINGLE_PLAYER 1
#define GM_MULTI_PLAYER 2
#define GM_NETWORK 3
#define GM_CONSTRUCTOR 4

#define BOT_CLK 15
//#define debug
//#define debug_all
//#define debug_functions
#define USER_CLK 10
//#define debug
//#define debugMap

typedef void (*soundFPtr)(int);
struct queueBot{
       bool bonus;
       short level;
       short dir; 
};
struct itemType{
       int x;
       int y;
};

#endif
