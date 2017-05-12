#include <bits/stdc++.h>
#define LL long long
using namespace std;

#define INF 2e9+7

int main()
{
    LL n,m;
    scanf("%I64d%I64d",&n,&m);
    if(n<=m)
    {
        printf("%I64d\n",n);
        return 0;
    }
    LL ans;
    LL l=0,r=INF;
    while(l<=r)
    {
        LL mid=(l+r)>>1;
        if((mid+1)*mid/2+m>=n)
        {
            ans=mid;
            r=mid-1;
        }
        else
            l=mid+1;
    }
    printf("%I64d\n",ans+m);
    return 0;
}
