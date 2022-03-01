/*
 * @你我各自努力，高处见
 * @LastEditors: HANGNAG
 * @LastEditTime: 2020-11-23 10:57:48
 * @FilePath: \ACM_vscode\算法设计\实验2归并排序.cpp
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
const int N=1e6+10;
int a[N],b[N];
void zhe(int l,int r)
{
	int mid=(l+r)/2;
	int i=l,j=mid+1;
	int k=l-1;
	while(i<=mid&&j<=r)
	{
		if(a[i]<a[j])
		{
			b[++k]=a[i++];
		}
		else
		{
			b[++k]=a[j++];
		}
	}
	while(i<=mid)
	{
		b[++k]=a[i++];
	}
	while(j<=r){
		b[++k]=a[j++];
	}
	for(int i=l;i<=r;i++)
	{
		a[i]=b[i];
	}
	return;
}
void qsort(int l,int r)
{
	if(l<r)
	{
		int mid=(l+r)/2;
		qsort(l,mid);
		qsort(mid+1,r);
		zhe(l,r);
	}
	return;
}
int main(void)
{
    double duration;
    clock_t start, finish;
	int n;
    //for(int n=100;n<=1000000;n+=10000){
	scanf("%d",&n);
    printf("数组a元素总个数%d\n", n);
    printf("数组a排序前\n");
    for(int i=1;i<=n;i++){
	a[i]=rand()%1000000+1;
    printf("%d ", a[i]);
    }
    start = clock();
    
   qsort(1,n);
   printf("\n数组a排序后\n");
   finish = clock();
   for (int i = 1; i <= n; i++)
   {
       printf("%d ", a[i]);
    }
	printf("\n");
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf( "排序用时:%.0fms\n", duration*1000 );
    //}
}
