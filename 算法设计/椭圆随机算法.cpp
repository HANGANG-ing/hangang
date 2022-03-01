/*
 * @沉着，冷静！: 噗，这你都信！
 * @LastEditors: HANGNAG
 * @LastEditTime: 2020-12-16 11:05:35
 * @FilePath: \ACM_vscode\算法设计\椭圆随机算法.cpp
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
#define PI acos(-1.0)
int main()
{
  int a, b;
  int n;
  //printf("输入椭圆的长边和短边长度：\n");
  scanf("%d%d", &a, &b);
  //printf("公式得出椭圆的面积：%lf\n", PI * a * b);
  //printf("包括椭圆的矩形面积：%d\n", a * b*4);
  int ans = 0;
  for (int i = 10; i <= 1000;i+=10)
  {
   // printf("当前所随机的点数：%d\n", i);
    for (int j = 1; j <= 10;j++)
    {
      int x = rand() % (a + 1);
      int y = rand() % (b + 1);
      if(sqrt((x-sqrt(a*a-b*b))*(x-sqrt(a*a-b*b))+y*y)+sqrt((x+sqrt(a*a-b*b))*(x+sqrt(a*a-b*b))+y*y)<=2*a)
      {
        ans++;
      }
    }
    //printf("落在椭圆内的点数：%d\n", ans);
    double S = ans * 1.0*4 / i * a * b;
    //printf("随机数测得椭圆面积为：%lf\n", S);
    //printf("测试值和标准面积比值：%lf\n", S * 1.0 / (PI * a * b));
    printf("%lf\n",ans * 1.0*4 / i/PI);
  }
    return 0;
}