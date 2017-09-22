#include <bits/stdc++.h>
using namespace std;

#define MAXN 55
#define LL long long

int g[MAXN][MAXN];

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
            scanf("%d",&g[i][j]);
    }
    LL ans=0;
    for(int i=1; i<=n; i++)
    {
        int cnt0=0,cnt1=0;
        for(int j=1; j<=m; j++)
        {
            if(g[i][j])
                cnt1++;
            else
                cnt0++;
        }
        ans+=(1LL<<cnt0)-1LL;
        ans+=(1LL<<cnt1)-1LL;
    }
    for(int j=1; j<=m; j++)
    {
        int cnt0=0,cnt1=0;
        for(int i=1; i<=n; i++)
        {
            if(g[i][j])
                cnt1++;
            else
                cnt0++;
        }
        ans+=(1LL<<cnt0)-1LL;
        ans+=(1LL<<cnt1)-1LL;
    }
    printf("%I64d\n",(LL)(ans-n*m));
    return 0;
}

