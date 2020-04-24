#include "examQ.h"
#include <fstream>

using namespace std;

void func(int a[], int n, int times);

void examQ::execute20140100() {
    
    // QUESTION ONE
    static int aa[5];
    
    for (int i = 0; i < 5; i++) {
        aa[i] = i;
    }

    comm.printArray(aa, 5);
    func(aa, 5, 3);
    comm.printArray(aa, 5);
    
    // QUESTION THREE    
    int number;
    ofstream file;
    
    cin >> number;
    
    double *a = new double[number];
    
    file.open("test.txt");
    for (int i = 0; i < number; i++) {
        a[i] = number*2;
        file << fixed << setprecision(2) << a[i] << " ";
    }
    
    file.close();
    comm.printArray(a, number);
    delete[] a;
}

void func(int a[], int n, int times){
    for (int i = 0; i < n; i++) {
        a[i] = a[i]*3;
    }
    
}



