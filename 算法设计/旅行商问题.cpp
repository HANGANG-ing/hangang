/*
 * @沉着，冷静！: 噗，这你都信！
 * @LastEditors: HANGNAG
 * @LastEditTime: 2020-12-17 11:06:53
 * @FilePath: \ACM_vscode\算法设计\旅行商问题.cpp
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
const int N = 2e3 + 10;
int vis[N];
int mp[N][N];
int num;
int ans;
int n;
void dfs(int x,int v)
{
    if(v>=ans)
        return;
    if(num<n)
    {
        for (int i = 1; i <= n;i++)
        {
            if(!vis[i])
            {
                num++;
                vis[i] = 1;
                dfs(i,v+mp[x][i]);
                num--;
                vis[i] = 0;
            }
        }
    }
    else
    {
        ans = min(ans, v + mp[x][1]);
    }
    return;
}
int main()
{
    for (n = 1; n <= 20; n++)
    {
        printf("图的顶点数：%d\n", n);
        printf("生成的邻接矩阵：\n");
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i == j)
                {
                    mp[i][i] = 0;
                }
                else
                {
                    mp[i][j] = rand() % 10000 + 1;
                }
                 printf("%5d ", mp[i][j]);
            }
            printf("\n");
        }
        num = 1;
        double ti;
        clock_t st, en;
        st = clock();
        memset(vis, 0, sizeof(vis));
        vis[1] = 1;
        ans = 0x3f3f3f3f;
        dfs(1, 0);
        en = clock();
        ti = double(en - st) / CLOCKS_PER_SEC;
        printf("用时：%.0lfms\n", ti * 1000);
        printf("最短的路长：%d\n", ans);
    }
    return 0;
}