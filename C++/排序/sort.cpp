/*
 * @沉着，冷静！: 噗，这你都信！
 * @LastEditors: HANGNAG
 * @LastEditTime: 2022-02-26 08:48:26
 * @FilePath: \ACM_vscode\C++\排序\sort.cpp
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
#include <vector>
#define emplace_back push_back
#define pb push_back
using namespace std;
typedef long long LL;
const int mod = 1e9 + 7;
const double eps = 1e-6;
const int inf = 0x3f3f3f3f;
const int N = 2e5 + 10;
int a[N];

int c[N];
void ssort(int a[], int f,int t)
{
    if(t-f<=0)
    {
        //cout << a[f]<<"*"<< endl;
        return;
    }
    int mid = (f + t) / 2;
    ssort(a,f,mid);
    ssort(a,mid+1,t);
    int i = f, j = mid + 1;
    int num = f;
    while (i <= mid && j <= t)
    {
        if (a[i] < a[j])
        {
            c[num++] = a[i];
            i++;
        }
        else
        {
            c[num++] = a[j];
            j++;
        }
    }
    while (i <= mid)
    {
        c[num++] = a[i++];
    }
    while (j <= t)
    {
        c[num++] = a[j++];
    }
    for (int i = f; i <= t; i++)
    {
        a[i] = c[i];
    }
    // for (int i = 1; i <= t;i++)
    // {
    //     cout << a[i] << "#";
    // }
    // cout << endl;
    return;
}
void ksort(int a[],int l,int r)
{
    if(l>=r)
    {
        return;
    }
    int k = l;
    int u = r;
    for (int i = l+1; i <= r;i++)
    {
        if(a[i]<a[l])
        {
            c[k++] = a[i];
        }
        else
        {
            c[u--] = a[i];
        }
    }
    c[k] = a[l];
    for (int i = l; i <= r;i++)
    {
        a[i] = c[i];
    }
    ksort(a, l, k);
    ksort(a, k + 1, r);
    return;
}
void tsort(int *a,int l,int r)
{
    memset(c, 0, sizeof(c));
    int maxx = 0;
    int minn = -1000000;
    for (int i = l; i < r;i++)
    {
        c[a[i]]++;
        maxx = max(maxx, a[i]);
        minn = min(minn, a[i]);
    }
    for (int i = minn; i <= maxx;i++)
    {
        for (int i = 0; i <= c[i];i++)
        {
            cout << i << endl;
        }
    }
    return;
}
void msort(int *a,int l,int r)
{
    for (int i = l; i <= r; i++)
    {
        for (int j = l; j < r;j++)
        {
            if(a[j]>a[j+1])
            {
                swap(a[j], a[j+1]);
            }
        }
    }
}
void dsort()
{
    
    return;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    msort(a,1,n);
    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << endl;
    }
    return 0;
}