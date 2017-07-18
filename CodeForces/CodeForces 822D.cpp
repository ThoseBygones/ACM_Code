#include <bits/stdc++.h>
using namespace std;

#define MAXN 5000005
#define INF 0x7fffffff
#define MOD 1000000007
#define LL long long

int a[MAXN];    //素数标记
LL f[MAXN];    //f函数
int t,l,r;
vector <LL> fac;

void judgePrime()
{
    memset(a,0,sizeof(a));
    for(int i=2; i*i<=MAXN; i++)
    {
        if(!a[i])
        {
            fac.push_back(i);
            for(int j=i*i; j<MAXN; j+=i)
                a[j]=1;
        }
    }
}

int main()
{
    judgePrime();
    f[1]=0;
    for(int i=2; i<MAXN; i++)
    {
        if(!a[i])   //是素数
            f[i]=((LL)i*(LL)(i-1)/2)%MOD;
        else    //非素数
        {
            LL minFac;
            for(int j=0; j<fac.size(); j++)
            {
                if(i%fac[j]==0)
                {
                    minFac=fac[j];
                    break;
                }
            }
            f[i]=(i/minFac*f[minFac]+f[i/minFac])%MOD;
        }
    }
    scanf("%d%d%d",&t,&l,&r);
    LL ans=0;
    LL temp=1;
    for(int i=l; i<=r; i++)
    {
        ans=(ans+temp*f[i])%MOD;
        temp=(temp*t)%MOD;
    }
    printf("%I64d\n",ans);
    return 0;
}
