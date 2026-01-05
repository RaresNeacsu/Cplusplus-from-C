#include <iostream>
#include <random>
#include <ctime>
using namespace std;

class point{
    public: 
    point(double x=0.0,double y=0.0):x(x),y(y){}
    double getx()const {return x;}
    double gety()const {return y;}
    void setx(double v){x=v;}
    void sety(double v){y=v;}
    private:
    double x,y;
};
point operator+(point &p1, point &p2){
    point p;
    p.setx(p1.getx()+p2.getx());
    p.sety(p1.gety()+p2.gety());
    return p;
}
ostream& operator<< (ostream &os,const point &p){
    os <<"(" << p.getx() << ", " << p.gety() << ")";
    return os;
}
int main()
{
    srand(time(0));
    point p(rand()%100,rand()%100);
    point p2(rand()%100,rand()%100);
    cout << p << endl;
    cout << p2 << endl;
    point p3=p+p2;
    cout << p3 << endl;
    return 0;
}