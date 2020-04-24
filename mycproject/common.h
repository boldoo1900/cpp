/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iomanip>


/* 
 * File:   common.h
 * Author: mb
 *
 * Created on December 19, 2017, 12:50 PM
 */
using namespace std;

#ifndef COMMON_H
#define COMMON_H

class common {
public:

    void printArray(int arr[], int n) {
        int i;
        
        for (i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << "\n";
    }
    
    void printArray(float arr[], int n){
        int i;
        
        for (i = 0; i < n; i++)
            cout << fixed << setprecision(2) << arr[i] << " ";
        cout << "\n";
    }
    
    void printArray(double arr[], int n){
        int i;
        
        for (i = 0; i < n; i++)
            cout << fixed << setprecision(2) << arr[i] << " ";
        cout << "\n";
    }
};

#endif /* COMMON_H */

