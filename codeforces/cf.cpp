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
const int N = 5e5 + 10;
vector<int> num[N];
int main()
{
    int x = 0,y;
    for (int i = 1; i <= 500000;i++)
    {
        x = 0;
        y = i;
        while(y)
        {
            x += y % 10;
            y /= 10;
        }
        num[x].push_back(i);
    }
    int n;
    scanf("%d", &n);
    LL ans = 1e18;
    for (int i = 1; i < 100;i++)
    {
        LL aa = 0;
        if(num[i].size()>=n)
        {
            for (int j = 0; j < n;j++)
            {
                aa += num[i][j];
            }
            ans = min(ans, aa);
        }
    }
    printf("%lld\n", ans);
    return 0;
}