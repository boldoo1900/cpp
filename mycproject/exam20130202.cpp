#include "examQ.h"

class Human {
private:
    string job;
    long balance;
public:
    string name;
    Human(string name, string job, long balance){
        this->name = name;
        this->job = job;
        this->balance = balance;
    }
    
    long getBalance(){
        return balance;
    }
    
    void setBalance(long balance){
        this->balance = balance;
    }
    
    void work(int x){
        balance += 1000*x;
    }
    
    void status(){
        cout << name << "\n";
        cout << job << "\n";
        cout << balance << "\n";
    }
};

void examQ::execute20130202(){
    Human hosei("test", "wd", 1000);
    hosei.work(10);
    hosei.status();
}




