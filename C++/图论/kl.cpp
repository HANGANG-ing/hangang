/*
 * @沉着，冷静！: 噗，这你都信！
 * @LastEditors: HANGNAG
 * @LastEditTime: 2022-02-27 09:25:11
 * @FilePath: \ACM_vscode\C++\图论\kl.cpp
 */
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
const int N = 2e5 + 10;
int f[10000];
struct zxc
{
    int u, v, w;
}edge[1000];
int fin(int x)
{
    if(f[x]!=x)
    {
        return f[x]=fin(f[x]);
    }
    return f[x];
}
bool cmp(zxc q,zxc z)
{
    return q.w < z.w;
}
int main()
{
    int n, m;
    cin >> n >> m;
    
    int a, b, c;
    for (int i = 1; i <= n;i++)
    {
        f[i] = i;
    }
    for (int i = 1; i <= m;i++)
    {
        cin >> a >> b >> c;
        edge[i].u = a;
        edge[i].v = b;
        edge[i].w = c;
    }
    sort(edge + 1, edge + m + 1, cmp);
    zxc ans[1000];
    int num = 0;
    int k = 0;
    for (int i = 1; i <=m;i++)
    {
        int fu = fin(edge[i].u);
        int fv = fin(edge[i].v);
        //cout << fu << "*" << fv << endl;
        if(fu!=fv)
        {
            ans[++k] = edge[i];
            f[fv] = fu;
            num += edge[i].w;
        }
    }
    cout << num << endl;
    for (int i = 1; i < n;i++)
    {
        cout << ans[i].u << " " << ans[i].v << " " << ans[i].w << endl;
    }
    return 0;
}
/*
4 5
1 2 1
2 3 1
1 3 4
2 4 6
3 4 3
*/