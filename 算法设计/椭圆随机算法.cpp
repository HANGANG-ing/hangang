/*
 * @���ţ��侲��: �ۣ����㶼�ţ�
 * @LastEditors: HANGNAG
 * @LastEditTime: 2020-12-16 11:05:35
 * @FilePath: \ACM_vscode\�㷨���\��Բ����㷨.cpp
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
  //printf("������Բ�ĳ��ߺͶ̱߳��ȣ�\n");
  scanf("%d%d", &a, &b);
  //printf("��ʽ�ó���Բ�������%lf\n", PI * a * b);
  //printf("������Բ�ľ��������%d\n", a * b*4);
  int ans = 0;
  for (int i = 10; i <= 1000;i+=10)
  {
   // printf("��ǰ������ĵ�����%d\n", i);
    for (int j = 1; j <= 10;j++)
    {
      int x = rand() % (a + 1);
      int y = rand() % (b + 1);
      if(sqrt((x-sqrt(a*a-b*b))*(x-sqrt(a*a-b*b))+y*y)+sqrt((x+sqrt(a*a-b*b))*(x+sqrt(a*a-b*b))+y*y)<=2*a)
      {
        ans++;
      }
    }
    //printf("������Բ�ڵĵ�����%d\n", ans);
    double S = ans * 1.0*4 / i * a * b;
    //printf("����������Բ���Ϊ��%lf\n", S);
    //printf("����ֵ�ͱ�׼�����ֵ��%lf\n", S * 1.0 / (PI * a * b));
    printf("%lf\n",ans * 1.0*4 / i/PI);
  }
    return 0;
}