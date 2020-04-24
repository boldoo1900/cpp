#include "examQ.h"

class Day {
private:
    int date;
public:
    int year;
    int month;
    
    Day(int year, int month, int date){
        this->year = year;
        this->month = month;
        this->date = date;
    }
    Day(const Day &d){
    }
    
    int getDate(){
        return date;
    }
    
    void setDate(int date){
        this->date = date;
    }
    
    static int hasXmonth(int month){
        switch(month){
            case 1:
            case 3:
            case 5:
            case 7:
            case 8: return 31;
            case 4:
            case 6:
            case 9:
            case 11: return 30;
            case 2: return 28;
        }
    }
    
    int hasXmonth(){
        switch(month){
            case 1:
            case 3:
            case 5:
            case 7:
            case 8: return 31;
            case 4:
            case 6:
            case 9:
            case 11: return 30;
            case 2: return 28;
        }
    }
};

void examQ::execute20160102(){
    Day d1(2018, 2, 13);
    Day d2 = d1;
    
    cout << Day::hasXmonth(2) << "\n";
    cout << d1.hasXmonth() << "\n"; 
}
