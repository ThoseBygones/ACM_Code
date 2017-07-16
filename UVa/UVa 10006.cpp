#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

#define LL long long
#define MAXN 65005

int a[MAXN];

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

void judgePrime()   //筛法求素数
{
    int m=sqrt(MAXN);
    memset(a,0,sizeof(a));
    for(int i=2; i<=m; i++)
    {
        if(!a[i])
        {
            for(int j=i*i; j<MAXN; j+=i)
                a[j]=1;
        }
    }
}

int main()
{
    judgePrime();
    LL n;
    while(~scanf("%lld",&n),n)
    {
        if(!a[n])
        {
            printf("%lld is normal.\n",n);
            continue;
        }
        bool flag=true;
        for(int i=2; i<n; i++)
        {
            if(quickPow(i,n,n)!=i)
            {
                flag=false;
                break;
            }
        }
        if(flag)
            printf("The number %lld is a Carmichael number.\n",n);
        else
            printf("%lld is normal.\n",n);
    }
    return 0;
}
