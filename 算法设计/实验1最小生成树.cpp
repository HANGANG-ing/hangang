/*
 * @���Ҹ���Ŭ�����ߴ���
 * @LastEditors: HANGNAG
 * @LastEditTime: 2020-11-23 10:38:14
 * @FilePath: \ACM_vscode\�㷨���\ʵ��1��С������.cpp
 */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<bits/stdc++.h>
#include<time.h>
using namespace std;
struct zxc
{
    int i,j,v;
}mp[1000000];
bool cmp(zxc q,zxc w)
{
    return q.v<w.v;
}
int fa[1000000];
int fin(int x)
{
    if(x==fa[x])
    {
        return fa[x];
    }
    else
    {
        return fa[x]=fin(fa[x]);
    }
}
int main()
{
    int n;
    while(1)
    {
    scanf("%d",&n);
    //n=ii;
    int st,en;
    st=clock();
    for(int i=1;i<=n;i++)
    {
        fa[i]=i;
    }
    
    printf("������ɵ��ڽӾ���\n");
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            mp[i*n+j-n].v=rand()%10000+1;
            if(i==j)
            {
                mp[i*n+j-n].v=0;
            }
            mp[i*n+j-n].i=i;
            mp[i*n+j-n].j=j;
            printf("%6d ",mp[i*n+j-n].v);
        }
        printf("\n");
    }
    
    sort(mp+1,mp+n*n+1,cmp);
    int ans=0;
    for(int i=1;i<=n*n;i++)
    {
        int f1=fin(mp[i].i);
        int f2=fin(mp[i].j);
        if(f1!=f2)
        {
            ans+=mp[i].v;
            fa[f2]=f1;
        }
    }
    en=clock();
    double ti=double(en-st);
    printf("��С���������� %d\n",ans);
    printf("��ʱ%.0lfms\n",ti);
    }
    return 0;
}