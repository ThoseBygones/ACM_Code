#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define LL long long
#define INF 0x3f3f3f3f
#define MAXN 300005
#define MAXM 2000005

struct Waves
{
    int s;
    int r;
    int e;
} w[MAXN];

LL dp[MAXM];

bool cmp(Waves a,Waves b)
{
    return a.e<b.e;
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        int templen;
        scanf("%d%d%d",&w[i].s,&w[i].r,&templen);
        w[i].e=w[i].s+templen;
    }
    sort(w+1,w+n+1,cmp);
    memset(dp,0,sizeof(dp));
    for(int i=1; i<=n; i++)
    {
        for(int j=w[i-1].e; j<=w[i].e; j++)
            dp[j]=max(dp[j-1],dp[j]);
        dp[w[i].e]=max(dp[w[i].e],dp[w[i].s]+w[i].r);
    }
    printf("%I64d\n",dp[w[n].e]);
    return 0;
}
