/*
 * @沉着，冷静！: 噗，这你都信！
 * @LastEditors: HANGNAG
 * @LastEditTime: 2020-12-16 10:46:10
 * @FilePath: \ACM_vscode\算法设计\编辑距离.cpp
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
const int N = 1e4 + 10;
char s1[N];
char s2[N];
int dp[N][N];
int main()
{
    double time;
    clock_t start, end;
    for (int l1 =5000; l1 <=5000; l1+=1000)
    {
        for (int l2 =500; l2 <= 5000; l2+=50)
        {
            for (int i = 1; i <= l1; i++)
            {
                s1[i] = rand() % 26 + 'a';
            }
            for (int i = 1; i <= l2; i++)
            {
                s2[i] = rand() % 26 + 'a';
            }
            printf("s1字符串长度：%d\ns2字符串长度：%d\n", l1, l2);
            memset(dp, 0x3f3f3f3f, sizeof(dp));
            dp[0][0] = 0;

            start = clock();
            for (int i = 1; i <= l1; i++)
            {
                for (int j = 1; j <= l2; j++)
                {
                    if (s1[i] == s2[j])
                    {
                        dp[i][j] = dp[i - 1][j - 1];
                    }
                    dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
                    dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);
                }
            }
            end = clock();
            time = (double)(end - start) / CLOCKS_PER_SEC;
            printf("运行时间：%.0lf\n",time*1000);
            printf("最下编辑距离长度：%d\n", dp[l1][l2]);
        }
    }
    return 0;
}