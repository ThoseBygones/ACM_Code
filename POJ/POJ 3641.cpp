#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define LL long long

bool isPrime(LL x)
{
    if((x>2 && x%2==0) || x==1)
        return false;
    bool flag=true;
    for(int i=3; i*i<=x; i+=2)
    {
        if(x%i==0)
        {
            flag=false;
            break;
        }
    }
    return flag;
}

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
    LL p,a;
    while(~scanf("%lld%lld",&p,&a))
    {
        if(p==0 && a==0)
            break;
        if(!isPrime(p) && quickPow(a,p,p)==a)
            puts("yes");
        else
            puts("no");
    }
    return 0;
}
