/*
 * @LastEditors: HANGNAG
 * @LastEditTime: 2022-03-21 09:39:45
 * @FilePath: \ACM_vscode\C++\数据结构\表达式求值.cpp
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
string s;
int zhua(char s1)
{
    if (s1 == '+' || s1 == '-')
    {
        return 1;
    }
    else if (s1 == '*' || s1 == '/')
    {
        return 2;
    }
    else if (s1 == '(')
    {
        return 0;
    }
}
int yunsuan(int a,int b,char ss)
{
    if(ss=='+')
    {
        return (a + b);
    }
    else if(ss=='-')
    {
        return (a - b);
    }
    else if(ss=='*')
    {
        return (a * b);
    }
    else
    {
        return (a / b);
    }
}
int main()
{
    cin >> s;
    stack<char> q;
    stack<char> hzui;
    stack<char> hz;
    stack<int> num;
    int k = 0, flog = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            flog = 1;
            hzui.push(s[i]);
        }
        else
        {
            if(flog)
            {
                hzui.push('|');
                flog = 0;
            }
            if (s[i] == '(')
            {
                q.push(s[i]);
            }
            else if (s[i] == ')')
            {
                while (1)
                {
                    char k = q.top();
                    q.pop();
                    if (k == '(')
                    {
                        break;
                    }
                    hzui.push(k);
                }
            }
            else
            {
                while (!q.empty())
                {
                    char k = q.top();
                    if (zhua(s[i]) > zhua(k))
                    {
                        break;
                    }
                    else
                    {
                        q.pop();
                        hzui.push(k);
                    }
                }
                q.push(s[i]);
            }
        }
    }
    while (!q.empty())
    {
        hzui.push(q.top());
        q.pop();
    }
    while (!hzui.empty())
    {
        hz.push(hzui.top());
         cout << hzui.top();
        hzui.pop();
    }
    cout << endl;
    int ans = 0;
    while(!hz.empty())
    {
        char ch = hz.top();
        hz.pop();
        if(ch>='0'&&ch<='9')
        {
            k = k * 10 + ch - '0';
        }
        else if(ch=='|')
        {
            num.push(k);
            k = 0;
        }
        else
        {
            int a = num.top();
            num.pop();
            int b = num.top();
            num.pop();
            cout << a << " " << b << " " << ch << endl;
            b = yunsuan(a, b, ch);
            num.push(b);

        }
    }
    cout << num.top() << endl;
    return 0;
}
/*
测试栗子
(1+82+37)*51+64*(2+3)
(1+2+3)*5+6*(2+3)
*/