/*
 * @沉着，冷静！: 噗，这你都信！
 * @LastEditors: HANGNAG
 * @LastEditTime: 2022-02-26 15:25:45
 * @FilePath: \ACM_vscode\C++\图论\dj.cpp
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
int mp[100][100];
int dis[100];
 int mk[100];
void dj(int n)
{
    for (int i = 1; i <= n; i++)
    {
        dis[i] = mp[1][i];
    }
    int u = 1;
    mk[1] = 1;
    for (int i = 2; i <=n;i++)
    {
        int minn = 0x3f3f3f3f;
        for (int j = 1; j <= n;j++)
        {
            if(mk[j]==0&&dis[j]<=minn)
            {
                u = j;
                minn = dis[j];
            }
        }
        mk[u] = 1;
        for (int i = 1; i <= n;i++)
        {
            dis[i] = min(dis[i], dis[u] + mp[u][i]);
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    int a, b, v;
    memset(mp, 0x3f3f3f3f, sizeof(mp));
    for (int i = 1; i <= n; i++)
    {
        mp[i][i] = 0;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> v;
        mp[a][b] = v;
    }
    dj(n);
    for (int i = 1; i <= n;i++)
    {
        cout << dis[i] << endl;
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