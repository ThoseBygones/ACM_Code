#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 500010
#define INF 0x3f3f3f3f

int L[MAXN/2],R[MAXN/2];
int n;
int cnt;

void Union(int a[],int left,int mid,int right)
{
    int n1=mid-left;
    int n2=right-mid;
    for(int i=0; i<n1; i++)
        L[i]=a[left+i];
    for(int i=0; i<n2; i++)
        R[i]=a[mid+i];
    L[n1]=R[n2]=INF;
    int p=0,q=0;
    for(int i=left; i<right; i++)
    {
        cnt++;
        if(L[p]<=R[q])
            a[i]=L[p++];
        else
            a[i]=R[q++];
    }
}

void mergesort(int a[],int left,int right)
{
    if(left+1<right)
    {
        int mid=(left+right)>>1;
        mergesort(a,left,mid);
        mergesort(a,mid,right);
        Union(a,left,mid,right);
    }
}

int main()
{
    int a[MAXN];
    cnt=0;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%d",&a[i]);
    mergesort(a,0,n);
    for(int i=0; i<n-1; i++)
        printf("%d ",a[i]);
    printf("%d\n",a[n-1]);
    printf("%d\n",cnt);
    return 0;
}
