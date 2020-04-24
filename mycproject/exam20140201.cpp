#include "examQ.h"

using namespace std;

void max_min(double a[], int n, double *min, double *max);

void examQ::execute20140201() {
    
    // QUESTION ONE
    double a[100];
    
    for (int i = 0; i < 100; i++) {
        a[i] = 3*i;
    }
    
    // QUESTION TWO
    double *p;
    int number;
    
    cin >> number;
    p = new double[number];
    
    for (int i = 0; i < number; i++) {
        p[i] = i;
    }
    
    // QUESTION THREE, FOUR
    int n;
    double min, max;
    
    max_min(a, 100, &min, &max);
    cout << min << "\n";
    cout << max << "\n\n";
    
    max_min(p, number, &min, &max);
    cout << min << "\n";
    cout << max << "\n";
}

void max_min(double a[], int n, double *min, double *max){
    
    for (int i = n-1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if(a[j] > a[j+1]){
                double temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    
    *min = a[0];
    *max = a[n-1];
}
