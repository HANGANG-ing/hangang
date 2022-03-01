/*
 * @沉着，冷静！: 噗，这你都信！
 * @LastEditors: HANGNAG
 * @LastEditTime: 2021-12-16 22:43:21
 * @FilePath: \ACM_vscode\C++\111.cpp
 */
#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
using namespace std;
void fun1(string s1,string s2)
{
    fstream f1,f2;
    f1.open(s1,ios::out|ios::binary);
    f2.open(s2,ios::out|ios::binary);
    int a[20];
    for (int i = 0; i < 10;i++)
    {
        cin >> a[i];
        // f1 << x<<" ";
    }
    f1.write((char *)a, sizeof(a));
    for (int i = 0; i < 10;i++)
    {
        cin >> a[i];
        //f2 << x<<" ";
    }
    f2.write((char *)a, sizeof(a));
    f1.close();
    f2.close();
}
void fun2(string s1, string s2)
{
    fstream f1;
    fstream f2;
    f1.open(s1, ios::in|ios::binary);
    f2.open(s2, ios::app|ios::binary);
    int a[20];
    // for (int i = 1; i <= 10;i++)
    // {
    //     f1 >> x;
    //     f2 << x<<" ";
    // }
    f1.read((char *)a, sizeof(a));
    for (int i = 0; i < 10;i++)
    {
       cout << a[i] << endl;
        // f << a[i] << " ";
    }
     cout << "**_______________**" << endl;
    f2.write((char *)a, sizeof(a));
    f2.read((char *)a, sizeof(a));
    for (int i = 0; i < 20;i++)
    {
       cout << a[i] << endl;
        // f << a[i] << " ";
    }
     cout << "&&_______________&&" << endl;
    f1.close();
    f2.close();
}
void fun3(string s)
{
    fstream f;
    f.open(s, ios::in|ios::out|ios::binary);
    int a[20];
    f.read((char*)a, sizeof(a));
    // for (int i = 1; i <= 20;i++)
    // {
    //     f >> a[i];
    // }
    // f.close();
    // f.open(s, ios::out);
    sort(a, a + 20);
    for (int i = 0; i < 20;i++)
    {
       cout << a[i] << endl;
        // f << a[i] << " ";
    }
    cout << "_______________" << endl;
    cout << sizeof(a) << endl;
    f.write((char *)a, sizeof(a));
    f.close();
}
int main()
{
    string s1, s2;
    s1 = "1.dat";
    s2 = "2.dat";
    fun1(s1,s2);
    fun2(s1, s2);
    fun3(s2);
    return 0;
}
/*
1 2 3 4 5 6 7 8 9 10
11 12 13 14 15 16 17 18 19 20
*/