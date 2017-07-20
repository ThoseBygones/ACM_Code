#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 10005
#define MOD 1000000007
#define LL long long

LL a[MAXN],b[MAXN];

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
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        LL t,k;
        scanf("%d%lld%lld",&n,&t,&k);
        LL temp=quickPow(k,t,MOD);
        for(int i=0; i<n; i++)
            scanf("%lld",&a[i]);
        for(int i=0; i<n; i++)
        {
            if(i-(t%n)>=0)
                b[i]=a[i-(t%n)]*temp%MOD;
            else
                b[i]=a[i+n-(t%n)]*temp%MOD;
        }
        for(int i=0; i<n-1; i++)
            printf("%lld ",b[i]);
        printf("%lld\n",b[n-1]);
    }
    return 0;
}
