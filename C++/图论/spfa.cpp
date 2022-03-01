/*
 * @沉着，冷静！: 噗，这你都信！
 * @LastEditors: HANGNAG
 * @LastEditTime: 2022-02-26 15:50:58
 * @FilePath: \ACM_vscode\C++\图论\spfa.cpp
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
int mp[100][100];
int dis[100];
int vis[100];
queue<int> q;
void spfa(int n)
{
    dis[1] = 0;
    q.push(1);
    vis[1] = 1;
    while(!q.empty())
    {
        int k = q.front();
        q.pop();
        vis[k] = 0;
        for (int i = 1; i <= n;i++)
        {
            if(dis[i]>(dis[k]+mp[k][i]))
            {
                dis[i] = dis[k] + mp[k][i];
                if(vis[i]==0)
                {
                    q.push(i);
                    vis[i] = 1;
                }
            }
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    int a, b, v;
    memset(mp, 0x3f3f3f3f, sizeof(mp));
    memset(vis, 0, sizeof(vis));
    memset(dis, 0x3f3f3f3f, sizeof(dis));
    for (int i = 0; i <= n;i++)
    {
        mp[i][i] = 0;
    }
        for (int i = 1; i <= m; i++)
        {
            cin >> a >> b >> v;
            mp[a][b] = v;
        }
    spfa(n);
    for (int i = 1; i <= n;i++)
    {
        cout << dis[i]<<endl;
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