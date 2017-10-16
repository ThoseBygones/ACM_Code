#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 100010
#define LL long long

int a[MAXN];
int n,k;

bool check(LL val)
{
    LL sum=0;
    for(int i=1; i<=n; i++)
    {
        if(a[i]<=val)
            continue;
        if(k==1)
            sum=max(sum,(LL)a[i]);
        else
            sum+=(a[i]-val)/(k-1)+((a[i]-val)%(k-1)==0?0:1);    //题目的坑点，使用风干机的时候每分钟掉k-1的水分（即不会自然风干）
    }
    return sum<=val?true:false;
}

int main()
{
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%d",&a[i]);
    scanf("%d",&k);
    sort(a+1,a+1+n);
    LL l=0,r=0;
    for(int i=1; i<=n; i++)
        r+=a[i];
    LL ans;
    while(l<=r)
    {
        LL mid=(l+r)>>1;
        if(check(mid))
        {
            ans=mid;
            r=mid-1;
        }
        else
            l=mid+1;
    }
    printf("%lld\n",ans);
}
