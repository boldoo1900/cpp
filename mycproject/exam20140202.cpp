#include "examQ.h"

using namespace std;

class Student {
private:
    int id;
    double gpa;
public:
    string name;

    Student(string name, int id, double gpa) {
        this->name = name;
        this->id = id;
        this->gpa = gpa;
    }

    Student(const Student &st) {
    }

    double getGPA() {
        return gpa;
    }

    void setGPA(double gpa) {
        this->gpa = gpa;
    }

    void study(int x) {
        gpa += x / 100;
    }

    void status() {
        cout << "name: " << name << "\n";
        cout << "id: " << id << "\n";
        cout << "gpa: " << fixed << setprecision(2) << gpa << "\n";
    }
};

class SmartStudent : public Student {
public:
    SmartStudent(string name, int id, double gpa) : Student(name, id, gpa){
        // child class constructor
    }
    
    void study(int x){
        double gpa = getGPA() + x/50.0;
        setGPA(gpa+x/50);
    }
};

void examQ::execute20140202() {
    SmartStudent st("test", 123, 2.3);
    st.study(10);
    st.status();
}

