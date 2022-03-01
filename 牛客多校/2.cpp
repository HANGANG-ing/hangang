#include<algorithm>
#include<string.h>
#include<iostream>
#include<stdio.h>
#include<string>
#include<math.h>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#define emplace_back push_back
#define pb push_back
using namespace std;
typedef long long LL;
const int mod = 1e9 + 7;
const double eps = 1e-6;
const int inf = 0x3f3f3f3f;
const int N = 5e3 + 10;
int a[N];
int b[N];
int numa[N];
int numb[N];
int main()
{
    int n;
    cin >> n;
    int maxx = 0;
    int f = 0;
    for (int i = 1; i <= n;i++)
    {
        cin >> a[i];
        numa[a[i]]++;
        if(numa[a[i]]==2)
        {
            f = 1;
        }
        maxx = max(maxx, a[i]);
    }
    for (int i = 1; i <= n;i++)
    {
        cin >> b[i];
        numb[b[i]]++;
    }
    int flog = 1;
    for (int i = 0; i <= maxx;i++)
    {
        if(numa[i]!=numb[i])
        {
            flog = 0;
            break;
        }
    }
    if(flog)
    {
        if(f)
        cout << "Yes" << endl;
        else
        {
            int fa = 0, fb = 0;
            for (int i = 1; i <= n;i++)
            {
                for (int j = i + 1; j <= n;j++)
                {
                    if(a[j]<a[i])
                    {
                        fa++;
                    }
                    if(b[j]<b[i])
                    {
                        fb++;
                    }
                }
            }
            if(fa%2==fb%2)
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }
    }
    else
    {
        cout << "No" << endl;
    }
        return 0;
}