#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define INF 0x3f3f3f3f
#define MAXN 200010
#define LL long long

int L[MAXN/2],R[MAXN/2];
int n;

LL conquer(int a[],int left,int mid,int right)
{
    int p,q;
    LL cnt=0;
    int n1=mid-left;
    int n2=right-mid;
    for(int i=0; i<n1; i++)
        L[i]=a[left+i];
    for(int i=0; i<n2; i++)
        R[i]=a[mid+i];
    L[n1]=R[n2]=INF;
    p=q=0;
    for(int i=left; i<right; i++)
    {
        if(L[p]<=R[q])
            a[i]=L[p++];
        else
        {
            a[i]=R[q++];
            cnt+=n1-p;   //L中还没来得及复制到a中的数就是逆序数
        }
    }
    //cout << cnt << endl;
    return cnt;
}

LL mergesort(int a[],int left,int right)
{
    int mid;
    LL sum=0;
    if(left+1<right)
    {
        mid=(left+right)>>1;
        sum+=mergesort(a,left,mid);
        sum+=mergesort(a,mid,right);
        sum+=conquer(a,left,mid,right);
    }
    return sum;
}

int main()
{
    int a[MAXN];
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%d",&a[i]);
    LL ans=mergesort(a,0,n);
    printf("%lld\n",ans);
    return 0;
}
