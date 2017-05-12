#include <bits/stdc++.h>
#define LL long long
using namespace std;

#define INF 1e9
#define MAXN 200005

LL n,m,k;

bool check(LL mid)
{
    LL sum=0;
    if(k>=mid)
    {
        sum+=(1+mid)*mid/2;
        sum+=k-mid;
    }
    if(k<mid)
        sum+=(mid-k+1+mid)*k/2;
    if(k+mid-1<=n)
    {
        sum+=(1+mid)*mid/2;
        sum+=n-(k+mid-1);
    }
    if(k+mid-1>n)
        sum+=(mid+mid-n+k)*(n-k+1)/2;
    if(sum-mid<=m)
        return true;
    else
        return false;
}

int main()
{
    scanf("%d%d%d",&n,&m,&k);
    LL ans=0;
    LL l=1,r=m;
    while(l<=r)
    {
        LL mid=(l+r)>>1LL;
        if(check(mid))
        {
            ans=mid;
            l=mid+1;
        }
        else
            r=mid-1;
    }
    printf("%I64d\n",ans);
    return 0;
}
