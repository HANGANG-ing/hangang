/*
 * @æ²‰ç€ï¼Œå†·é™ï¼: å™—ï¼Œè¿™ä½ éƒ½ä¿¡ï¼?
 * @LastEditors: HANGNAG
 * @LastEditTime: 2021-12-16 23:01:44
 * @FilePath: \ACM_vscode\C++\222.cpp
 */
#include <fstream>
#include <iostream>
using namespace std;
class A
{
public:
    void getA()
    {
        cout << name << " " << age << " " << sex << endl;
    }
    friend ostream& operator<<(ostream&, A&);
    A& operator++()
    {
        age++;
        return *this;
    }
    A() { cout << "ss" << endl; }
    A(A &b)
    {
        b.getA();
        cout << "a¸´ÖÆ¹¹Ôì" << endl;
    }
    A(string n, int a=22, string s="nan") : name(n), age(a), sex(s){};
    ~A()
    {
        //cout << "gg" << endl;
    }
private:
    string name;
    int age;
    string sex;
};
 ostream& operator <<(ostream& out,A& a)
{
    out << "name: " << a.name << '\n'
        << "age: " << a.age << '\n'
        << "sex: " << a.sex << endl;
    return out;
}
int main()
{
    A a[10];
    A b("li", 21, "nv");
    ++b;
    A c("hangang", 23, "nan");
    cout <<b << endl;

    return 0;
}
