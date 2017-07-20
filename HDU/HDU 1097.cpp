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
    LL a,b;
    while(~scanf("%lld%lld",&a,&b))
    {
        LL ans=quickPow(a,b,10);
        printf("%lld\n",ans);
    }
    return 0;
}
