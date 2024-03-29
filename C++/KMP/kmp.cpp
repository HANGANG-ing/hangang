// /*
//  * @LastEditors: HANGNAG
//  * @LastEditTime: 2022-03-03 16:57:47
//  * @FilePath: \ACM_vscode\C++\KMP\kmp.cpp
//  */
// #include<cstdio>
// #include<cstring>
// #include<iostream>
// #include<algorithm>
// using namespace std;
// int n,k,len1,len2;
// int next1[1000001];
// char s1[1000001];
// char s2[1000001];
// int net[1000001];
// inline void get_next() //求出next数组 
// { //next数组是从 S[0到i-1]前子串 的前缀后缀最大值
//     int t1=0,t2;
//     next1[0]=t2=-1;
//     while(t1<len2) 
//         if(t2==-1 || s2[t1]==s2[t2]) //类似于KMP的匹配 
//             next1[++t1]=++t2;
//         else t2=next1[t2];//失配 
// }
// inline void KMP() //KMP 
// { 
//     int t1=0,t2=0;//从0位开始匹配 
//     while(t1<len1) //临界值 
//     { 
//         if(t2==-1 || s1[t1]==s2[t2]) //匹配成功，继续 
//             t1++,t2++;
//         else t2=next1[t2]; //失配 
//         if(t2==len2) printf("%d\n",t1-len2+1),t2=next1[t2];//t2==lenn2时，匹配成功；t1-len2+1即为第一个字母的位置 
//     } //匹配成功后，t2置为next[t2] 
// } 
// int main(){ 
//     scanf("%s",s1);
//     scanf("%s",s2);
//     len1=strlen(s1);
//     len2=strlen(s2);
//     get_next();
//     KMP();
//     for(int i=1;i<=len2;++i) 
//         printf("%d ",next1[i]);//输出next数组
//     return 0;
// }

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
int nxt[N];
void getnext(string &m)
{
    int i = 0, j = -1;
    nxt[0] = -1;
    while(i<m.size())
    {
        if(j==-1||m[i]==m[j])
        {
            i++;
            j++;
            nxt[i] = j;
        }
        else
        {
            j = nxt[j];
        }
    }
}
void kmp(string &s,string &m)
{
    getnext(m);
    int i = 0, j = 0;
    while(i<s.size())
    {
        if(j==-1||s[i]==m[j])
        {
            i++, j++;
        }
        else
        {
            j = nxt[j];
        }
        if(j==m.size())
        {
            cout << i - j + 1 << endl;
            
        }
    }
}
int main()
{
    string s, m;
    cin >> s >> m;
    kmp(s, m);
    return 0;
}