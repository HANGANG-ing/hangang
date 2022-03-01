/*
 * @沉着，冷静！: 噗，这你都信！
 * @LastEditors: HANGNAG
 * @LastEditTime: 2021-12-15 23:37:33
 * @FilePath: \ACM_vscode\C++\test.cpp
 */
#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
int index(char *s1, char *s2)
{
    int k = strlen(s1);
    int m = strlen(s2);
    for (int i = 0; i < m;i++)
    {
        int flog = 0;
        for (int j = 0; j <k;j++)
        {
            if(i+j<m&&s1[j]!=s2[i+j])
            {
                flog = 1;
                break;
            }
        }
        if(!flog)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    //cout << index(s1, s2) << endl;
    ofstream ou;
    ou.open("a.txt",ios::out);
    char s[1024];
    char ss[] ="";
    while(1)
    {
        cin.getline(s,1000,'\n');
        cout << s<<"++++++++" << endl;
        if(strcmp(ss,s)==0)
        {
            break;
        }
        
        ou << s << '\n';
    }
    ou.close();
    //in.open("a.txt");

    return 0;
}