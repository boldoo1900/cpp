/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   sortings.h
 * Author: mb
 *
 * Created on December 19, 2017, 12:37 PM
 */

#ifndef SORTINGS_H
#define SORTINGS_H
#include <iostream>
#include "common.h"

class sortings {
public:
    common comm;
    
    sortings();
    sortings(const sortings& orig);
    virtual ~sortings();
    
    void insertionsort(int arr[], int n);
    void selectionsort(int arr[], int n);
    void bubblesort(int arr[], int n);
    void shellsort(int arr[], int n);
    void heapify(int arr[], int n, int i);
    void heapsort(int arr[], int n);
    
    void swap(int *xp, int *yp);
    void execute();
private:

};

#endif /* SORTINGS_H */

