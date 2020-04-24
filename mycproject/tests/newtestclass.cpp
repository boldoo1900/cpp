/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   newtestclass.cpp
 * Author: mb
 *
 * Created on Dec 5, 2017, 5:43:24 PM
 */

#include "newtestclass.h"


CPPUNIT_TEST_SUITE_REGISTRATION(newtestclass);

newtestclass::newtestclass() {
}

newtestclass::~newtestclass() {
}

void newtestclass::setUp() {
}

void newtestclass::tearDown() {
}

void ntimes(int a[], int n);

void newtestclass::testNtimes() {
    int* a;
    int n;
    ntimes(a, n);
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

void printArray(int arr[], int size);

void newtestclass::testPrintArray() {
    int* arr;
    int size;
    printArray(arr, size);
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

