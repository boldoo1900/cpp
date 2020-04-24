#include "examQ.h"

using namespace std;

void examQ::execute20150100() {
    static int a[33];

    // ---- one 
    int n = sizeof (a) / sizeof (*a);
    for (int i = 0; i < n; i++) {
        a[i] = i;
    }
    comm.printArray(a, n);
    
    // ---- two
    int aa[] = {5,7,15,34};
    int len = sizeof(aa) / sizeof(aa[0]);
    float arrAvg = ntimes(aa, len, 3);
    
    comm.printArray(aa, 4);
    cout << fixed << setprecision( 2 ) << arrAvg << endl;
    
    // ---- four
    int times = 4;
    //cin>>times;
    
    float aaa[times];
    for (int i = 0; i < sizeof(aaa)/sizeof(aaa[0]); i++) {
        aaa[i] = 0;
    }
    
    cout<<times<<"\n";
    comm.printArray(aaa, times);
    
    cout<<"------------- five -------------\n";
    int *ptr;
    //ptr = (int*) malloc(5*sizeof(int));
    for (int i=0; i<5; i++)
    {
        ptr[i] = i*2+1;
    }
    
    comm.printArray(ptr, 5);
    //free(ptr);
    comm.printArray(ptr, 5);
}

float examQ::ntimes(int a[], int n, int ntimes) {
    float sum = 0;
    
    for (int i = 0; i < n; i++) {        
        sum +=a[i];        // n dahin vrjvvlhees omnoh niilberiin dundaj
        a[i] = a[i]*ntimes;        
    }
    
    return sum/n;
}

