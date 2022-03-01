/*
 * @沉着，冷静！: 噗，这你都信！
 * @LastEditors: HANGNAG
 * @LastEditTime: 2021-09-06 17:44:53
 * @FilePath: \ACM_vscode\C++\vir.h
 */
#include<cstdio>
#include<string>
#include<iostream>
using namespace std;
class A{
    public:
    int x;
    A(){
        cout << "a" << endl;
    };
    ~A()
    {
        cout << x << endl;
    }
};
void f();