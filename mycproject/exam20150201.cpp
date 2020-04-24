#include "examQ.h"

using namespace std;

void examQ::execute20150201() {
    int number = 4;
    
    cin>>number;
    
    //create dynamic variable (in c malloc/free)
    double *fa = new double[number];
    
    for (int i = 0; i < number; i++) {
        fa[i] = i;
    }
    
    triple(fa, number);
    comm.printArray(fa, number);
    
    //release memory
    delete [] fa;
    comm.printArray(fa, number);
}

void examQ::triple(double a[], int n){
    for (int i = 0; i < n; i++) {
        a[i] = a[i]*3;
    }
}
