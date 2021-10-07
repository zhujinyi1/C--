#include<iostream>
using namespace std;

class Point{
public:
    Point(int x = 0,int y = 0){
        X = x;
        Y = y;
        cout << "Constructor is called!";
        displayxy();
    }
    Point(const Point& p){
        X = p.X;
        Y = p.Y;
        cout << "Copy constructor is called!";
        displayxy();
    }
    ~Point(){
        cout << "Destructor is called!";
        displayxy();
    }
    void displayxy(){
        cout << "(" << X << "," << Y << ")" << endl;
    }
private:
    int X,Y;
};

Point func(Point p){
    int x = 10*2;
    int y = 10*2;
    Point pp(x,y);
    return pp;
}

int main(){
    Point p1(3,4);
    Point p2 = p1;
    p2 = func(p1);
    return 0;
}