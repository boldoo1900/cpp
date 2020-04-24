#ifndef key_Table
#define key_Table
struct keyTable{
      public:
             int up;
             int left;
             int right;
             int down;
             int shoot;
             bool check(int k){
                  bool z=false;
                  if (k==up||k==left||k==right||k==down||k==shoot)
                  z=true;
                  return z;
             };
};
#endif
