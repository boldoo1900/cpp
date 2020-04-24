/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Account.h
 * Author: mb
 *
 * Created on January 5, 2018, 12:48 PM
 */

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iomanip>

class Account {
public:
    long id;

    Account(long id, double balance, string name){
        this->id = id;
        this->balance = balance;
        this->name = name;
    }
    ~Account(){
    }
    double getBalance(){
        return balance;
    }
    void setBalance(double balance){
        this->balance = balance;
    }
    void addInterest(double rate){
        this->balance = this->balance*rate/100+this->balance;
    }
private:
    string name;
    double balance;
};

class AccountTester{
public:
    execute(){
        Account ac(1234, 5000, "test");
        //ac = new Account(1, "test", 5000);
        ac.addInterest(1);
        
        cout<<ac.id<<"\n";
        cout<<fixed<<setprecision(2)<<ac.getBalance()<<"\n";
    }
};

#endif /* ACCOUNT_H */

