/*
 * @沉着，冷静！: 噗，这你都信！
 * @LastEditors: HANGNAG
 * @LastEditTime: 2022-02-24 17:36:59
 * @FilePath: \ACM_vscode\C++\虚函数.cpp
 */
#include <iostream>
using namespace std;
class shape
{
protected:
    int a;
public:
    shape(int x = 3) : a(x){};
    virtual double area() = 0;
};
class T : public shape
{
public:
    double area()
    {
        return 0.5 * a * a;
    }
};
class Z:public shape
{
    public:
    double area()
    {
        return a * a;
    }
};
class C:public shape
{
    public:
    double area()
    {
        return 3.14 * a * a;
    }
};
int main()
{
    shape *p[4];
    p[0] = new T();
    p[1] = new Z();
    p[2] = new C();
    double ans = 0;
    for (int i = 0; i < 3;i++)
    {
        ans += p[i]->area();
    }
    cout << ans << endl;
    return 0;
}