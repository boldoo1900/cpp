#include "examQ.h"

using namespace std;

class Shape {
public:
    virtual int draw() = 0;
};

class Point : public Shape {
public:
    int draw() {
        cout << "+\n";
        return 0;
    }
};

class Rectangle : public Shape {
public:

    Rectangle(int a, int b) {
        height = a;
        width = b;
    }
    
    int draw() {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                cout << "*"; 
            }
            cout << "\n";
        }

        return 0;
    }
protected:
    int height;
    int width;
};

void examQ::execute20150202() {
    Shape *shape[5];
    
    shape[0] = new Point();
    shape[1] = new Point();
    shape[2] = new Rectangle(3,5);
    shape[3] = new Rectangle(6,9);
    shape[4] = new Rectangle(9,11);

    shape[0]->draw();
    shape[1]->draw();
    shape[2]->draw();
    shape[3]->draw();
    shape[4]->draw();
    
    delete shape[0];
    delete shape[1];
    delete shape[2];
    delete shape[3];
    delete shape[4];
}
