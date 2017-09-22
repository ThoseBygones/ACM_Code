#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define LL long long

LL prime[1<<21];
bool vis[1<<21];
LL fac[25];
LL len;

void init() //计算阶乘
{
    fac[0]=1;
    for(LL i=1; i<=21; i++)
        fac[i]=i*fac[i-1];
}

void judge()
{
    for(LL i=0; i<(1<<21); i++)
        vis[i]=true;
    prime[0]=prime[1]=false;
    for(LL i=2; i<(1<<21); i++)
    {
        if(vis[i])
        {
            prime[len++]=i;
            for(LL j=i*i; j<(1<<21); j+=i)
                vis[j]=false;
        }
    }
}

int main()
{
    LL n;
    len=0;
    init();
    judge();
    while(~scanf("%lld",&n))
    {
        if(vis[n])
            printf("1 1\n");
        else
        {
            LL ans=0;
            LL base=1;
            for(LL i=0; i<len && prime[i]<=n; i++)
            {
                LL cnt=0;
                if(n%prime[i]==0)
                {
                    while(n%prime[i]==0)
                    {
                        cnt++;
                        n/=prime[i];
                    }
                }
                ans+=cnt;
                base*=fac[cnt];
            }
            printf("%lld %lld\n",ans,fac[ans]/base);
        }
    }
    return 0;
}
