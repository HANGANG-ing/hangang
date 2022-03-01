/*
 * @沉着，冷静！: 噗，这你都信！
 * @LastEditors: HANGNAG
 * @LastEditTime: 2021-12-16 22:35:07
 * @FilePath: \ACM_vscode\C++\12.cpp
 */
#include <cmath>
#include <fstream>
#include <iostream>
using namespace std;
class A
{
    // int a, b;
    // char s,sa,sc,sx;
    double a;
    int c;
    virtual int getc()
    {
        cout << "c" << endl;
    }
};
int main()
{
    A a;
    //cout << sizeof(a) << endl;
    char *s;
    cin.getline(s, 10, '\n');
    cout << s << endl;
}
/*
template <class T>
T maxx(T a,T b)
{
    if(a>b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
class point
{
protected:
    int x;
    int y;

public:
    point(int xx = 0, int yy = 0) : x(xx), y(yy)
    {
        cout << "point" << endl;
    }
    virtual void C() = 0;
    virtual void S() = 0;
    virtual void V() = 0;
};
class line : public point
{
    int x2, y2;

public:
    line(int x1, int y1, int x2, int y2) : point(x1, y1), x2(x2), y2(y2)
    {
        cout << "line" << endl;
    }
    void C()
    {
        cout << "C=" << sqrt((x - x2) * (x - x2) + (y - y2) * (y - y2)) << endl;
    }
    void S()
    {
    }
    void V()
    {
    }
    int getc();
};
int line::getc()
{
    cout << "c" << endl;
}
 class A;
 class A{
    protected:
        int x;
        int y;
    public:
        A(int x = 0, int y = 0) : x(x), y(y) { cout << "A" << endl; }
        friend ostream& operator<<(ostream &ou, A &a);
        friend A& operator+(int &x, A &a);
};
ostream& operator <<(ostream &ou, A &a)
{
    ou<< a.x << " " << a.y << endl;
    return ou;
}
A& operator+(int &x, A &a)
{
    a.x += x;
    return a;
}
class B: public A{
    public:
    B(){
        cout << "B" << endl;
    }
};
class C: public A{
    public:
    C()
    {
        cout << "C" << endl;
    }
};
class dd{
    public:
    dd(){
        cout << "dd" << endl;
    }
};
class D:public C,public B{
    dd d1;
    public :
    D(){
        cout << "D" << endl;
        
    }
    void getx()
        {
            cout <<C::x << endl;
        }
};

int main()
{
    int b = 1;
    int &&p=1;
    p = 111;
    cout << p << endl;
    A a(1, 2);
    
    int x = 1;
    a = x+a;
    cout << a << endl;
    D d;
    d.getx();
    double xx, yy;
    xx = 1.12;
    yy = 1.11;
    cout << maxx(xx, yy) << endl;
    return 0;
}
*/