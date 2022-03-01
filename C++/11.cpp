/*
 * @沉着，冷静！: 噗，这你都信！
 * @LastEditors: HANGNAG
 * @LastEditTime: 2021-12-10 11:28:08
 * @FilePath: \ACM_vscode\C++\11.cpp
 */
#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    fstream ff;
    ff.open("D://a.txt", ios::out);
    string s;
    do{
        cin >> s;
        if(s=="!q")
            break;
        ff << s;
        ff <<'\n';
    }while (s != "!q");
    ff.close();
    ff.open("D://a.txt", ios::in);
    string ss;
    while(ff>>ss)
    {
        cout << ss << endl;
    }
    ff.close();
    return 0;
}