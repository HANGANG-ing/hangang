#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;
#define PI acos(-1.0);
class Shape
{
    protected:
    double r;
    public:
    Shape(double x=3.0):r(x){};
    virtual void show()=0;
    virtual double Perimeter()=0;
    virtual double Area()=0;
};
class Circle:public Shape
{
    public:
    double Perimeter()
    {
        return r * 2.0 * PI;
    }
    double Area()
    {
        return r * r * PI;
    }
    void show()
    {
        cout<<r<<" "<<Perimeter()<<" "<<Area()<<endl;
    }
};
class Square:public Shape
{
    double Perimeter()
    {
        return 4.0 * r;
    }
    double Area()
    {
        return r * r;
    }
    void show()
    {
        cout<<r<<" "<<Perimeter()<<" "<<Area()<<endl;
    }
};
class Triangle:public Shape
{
    double Perimeter()
    {
        return 3.0 * r;
    }
    double Area()
    {
        return sqrt(3.0) * r * r * 0.5;
    }
    void show()
    {
        cout<<r<<" "<<Perimeter()<<" "<<Area()<<endl;
    }
};
int main()
{
    Shape *C = new Circle();
    Shape *S=new Square();
    Shape *T=new Triangle();
    C->show();
    S->show();
    T->show();

    return 0;
}