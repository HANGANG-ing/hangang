/*
 * @沉着，冷静！: 噗，这你都信！
 * @LastEditors: HANGNAG
 * @LastEditTime: 2020-12-11 10:35:01
 * @FilePath: \ACM_vscode\DP\DP.cpp
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
char s[150];
int dp[150][15][3]; 
int a[150];
int dfs(int pos,int limit,int now,int up,int ok)
{
    if(!pos)
    {
        return ok;
    }
    if(!limit&&dp[pos][now][ok]!=-1)
    {
        return dp[pos][now][ok];
    }
    LL ans = 0;
    int up1 = limit ? a[pos] : 9;
    for (int i = 0; i <= up1;i++)
    {
        int _up = up || (i > now);
        int _ok = ok;
        if(up&&(i<now))
        {
             _ok = 0;
        }
        ans += dfs(pos-1,limit&&i==a[pos],i,_up, _ok);
    }
    ans %= mod;
    if(!limit)
    {
        dp[pos][now][ok]= ans;
    }
    return ans;
}
int solve(char *s,int l)
{
    for (int i = 0; i < l;i++)
    {
        a[l-i] = s[i] - '0';
    }
    return dfs(l, 1, 11, 0, 1);
}
int main()
{
     memset(dp, -1, sizeof(dp));
    int t;
    scanf("%d", &t);
    while(t--)
    {
       
        scanf("%s", s);
        int l = strlen(s);
        printf("%d\n", (solve(s, l)-1+mod)%mod);
    }
    return 0;
}