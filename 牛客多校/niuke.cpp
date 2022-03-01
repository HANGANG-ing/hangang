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
const int mod = 998244353;
const double eps = 1e-6;
const int inf = 0x3f3f3f3f;
const int N = 1e5 + 10;
int dp[5][15];
int a[N];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    memset(dp, 0, sizeof(dp));
    dp[0][a[1]]=1;
    for (int i = 2; i <= n;i++)
    {
        for (int j = 0; j <= 9;j++)
        {
            int k = (j + a[i]) % 10;
            int w = (j * a[i]) % 10;
            dp[1][k] += dp[0][j];
            dp[1][k] %= mod;
            dp[2][w] += dp[0][j];
            dp[2][w] %= mod;
        }
        for (int j = 0; j <= 9;j++)
        {
            dp[0][j] = dp[1][j] + dp[2][j];
            dp[1][j] = 0;
            dp[2][j] = 0;
            dp[0][j] %= mod;
        }
    }
    for (int i = 0; i <= 9;i++)
    {
        cout << dp[0][i] << endl;
    }
    return 0;
}
struct node {
    string s;
    vector<node *> aon;
    int id;
    
}