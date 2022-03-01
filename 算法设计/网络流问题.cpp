/*
 * @沉着，冷静！: 噗，这你都信！
 * @LastEditors: HANGNAG
 * @LastEditTime: 2020-12-17 19:35:32
 * @FilePath: \ACM_vscode\算法设计\网络流问题.cpp
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
#include <time.h>
#include <vector>
#define emplace_back push_back
#define pb push_back
using namespace std;
typedef long long LL;
const int mod = 1e9 + 7;
const double eps = 1e-6;
const int inf = 0x3f3f3f3f;
const int N = 2e6 + 10;
int n, m, s, t;
struct zxc
{
    int to, net, w;
} e[N * 2];
int tot = 0;
int head[N];
int dep[N];
int vis[N];
int mp[2000][2000];
int maxflow = 0;
void add(int u, int v, int w)
{
    e[tot] = {v, head[u], w};
    head[u] = tot++;
    e[tot] = {u, head[v], 0};
    head[v] = tot++;
}
void init()
{
    memset(head, -1, sizeof(head));
    tot = 0;
    maxflow = 0;
}
int bfs() //分层
{
    queue<int> q;
    memset(vis, 0, sizeof(vis));
    memset(dep, 0x3f3f3f3f, sizeof(dep));
    q.push(s);
    vis[s] = 1;
    dep[s] = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for (int i = head[u]; i != -1; i = e[i].net)
        {
            int y = e[i].to;
            if (dep[y] > dep[u] + 1 && e[i].w > 0)
            {
                dep[y] = dep[u] + 1;
                if (!vis[y])
                {
                    vis[y] = 1;
                    q.push(y);
                }
            }
        }
    }
    if (dep[t] == 0x3f3f3f3f)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
int dfs(int x, int flow) //多次增广
{
    int row = 0;
    if (x == t)
        return flow;
    for (int i = head[x]; i != -1; i = e[i].net)
    {
        int y = e[i].to;
        if (dep[y] == dep[x] + 1 && e[i].w > 0)
        {
            if (row = dfs(y, min(flow, e[i].w)))
            {
                e[i].w -= row;
                e[i ^ 1].w += row;
                return row;
            }
        }
    }
    return 0;
}
void Dinic()
{
    while (bfs())
    {
        int flow;
        while (flow = dfs(s, 0x3f3f3f3f))
        {
            maxflow += flow;
        }
    }
}
int main()
{
    s = 1, t = n;
    for (n = 10; n <= 200; n += 10)
    {
        printf("生成的顶点个数：%d\n", n);
        init();
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                mp[i][j] = mp[j][i] = rand() % 1000;
                add(i, j, mp[i][j]);
            }
        }
        printf("生成的邻接矩阵：\n");
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                printf("%4d ", mp[i][j]);
            }
            printf("\n");
        }
        clock_t st, en;
        st = clock();
        Dinic();
        en = clock();
        double time = (double)en - st/CLOCKS_PER_SEC;
        printf("最大流Dinic算法用时：%.0lf\n", time);
        //printf("最大流：%d\n", maxflow);
        
    }
    return 0;
}
