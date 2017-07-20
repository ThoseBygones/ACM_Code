#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define LL long long

LL quickPow(LL x,LL k,LL mod)
{
    LL res = 1;
    while(k > 0)
    {
        if(k & 1)
            res = res * x % mod;
        x = x * x % mod;
        k >>= 1;
    }
    return res;
}

int main()
{
    int z;
    scanf("%d",&z);
    while(z--)
    {
        LL m;
        int h;
        scanf("%lld%d",&m,&h);
        LL ans=0;
        while(h--)
        {
            LL a,b;
            scanf("%lld%lld",&a,&b);
            ans+=quickPow(a,b,m);
            ans%=m;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
