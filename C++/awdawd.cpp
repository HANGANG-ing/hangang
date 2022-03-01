/*
 * @沉着，冷静！: 噗，这你都信！
 * @LastEditors: HANGNAG
 * @LastEditTime: 2021-11-24 22:41:01
 * @FilePath: \ACM_vscode\C++\awdawd.cpp
 */
#include <algorithm>
#include <iostream>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stack>
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#define emplace_back push_back
#define pb push_back
using namespace std;
typedef long long LL;
const int mod = 1e9 + 7;
const double eps = 1e-6;
const int inf = 0x3f3f3f3f;
const int N = 2e5 + 10;
class nowTime;
class data{
    private:
    int year, mouth, day;
    public:
        data(int y, int m, int d) : year(y), mouth(m), day(d){};
        void show();
        void extradata(nowTime &);
};
void data::show()
{
    cout << year << ":" << mouth << ":" << day << endl;
}
class nowTime
{
private:
    int h, m, s;

public:
    friend data;
    friend void print(nowTime &p)
    {
        cout << p.h << p.m << p.s << endl;
    }
    nowTime();
    nowTime(int h, int m, int s) : h(h), m(m), s(s){};
    void getNowtime();
};
void data::extradata(nowTime& p)
{
    cout << year << mouth << day << p.h << p.m << p.s << endl;
}
// nowTime::nowTime(int h,int m,int s)
// {
//     this->h = h;
//     this->m = m;
//     this->s = s;
// }
void nowTime::getNowtime()
{
    cout << h << ":" << m << ":" << s << endl;
}
class complexNumber{
    int real;
    int vul;
    public:
        complexNumber();
        complexNumber(int x, int y) : real(x), vul(y){};
        complexNumber operator+ (complexNumber& k);
        complexNumber operator+ (int k);
        void show();
};
void complexNumber::show()
{
    cout << real << "+" << vul <<"i"<< endl;
}
complexNumber complexNumber::operator+(complexNumber& k)
{
    complexNumber rs(0,0);
    rs.real = real + k.real;
    rs.vul = vul + k.vul;
    return rs;
}
complexNumber complexNumber::operator+(int x)
{
    return complexNumber(real + x, vul);
}
int main()
{
    nowTime t(1, 2, 3);
    data d(4, 5, 6);
    // t.getNowtime();
    // d.extradata(t);
    complexNumber b(1, 2);
    complexNumber c(2, 3);

    complexNumber dd;

    dd.show();

    return 0;
}
