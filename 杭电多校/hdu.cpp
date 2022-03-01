/*
 * @沉着，冷静！: 噗，这你都信！
 * @LastEditors: HANGNAG
 * @LastEditTime: 2021-08-22 11:17:41
 * @FilePath: \ACM_vscode\杭电多校\hdu.cpp
 */
#include<algorithm>
#include<string.h>
#include<stdlib.h>
#include<iostream>
#include<stdio.h>
#include<string>
#include<math.h>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<random>
#define emplace_back push_back
#define pb push_back
using namespace std;
typedef long long LL;
const int mod = 1e9 + 7;
const double eps = 1e-6;
const int inf = 0x3f3f3f3f;
const int N = 2e5 + 10;
void _strcpy(char *s,char *y)
{
  while(s!=nullptr&&y!=nullptr)
  {
    y = s;
    s++;
    y++;
  }
  return;
}
int main()
{
  char *s = new char[100];
  char *x = s;
  char *y = new char[100];
  char *z = y;
  cin >> s;
  _strcpy(x, y);
  cout << z << endl;
  return 0;
}