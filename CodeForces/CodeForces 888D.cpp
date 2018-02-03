#include <bits/stdc++.h>
using namespace std;

#define MAXN 1005
#define LL long long

LL p[5]={1,0,1,2,9};
LL c[MAXN][MAXN];

int main()
{
    for(int i=0; i<=1000; i++)
    {
        c[i][0]=1;
        for(int j=1; j<=i; j++)
            c[i][j]=c[i-1][j-1]+c[i-1][j];
    }
    int n,k;
    scanf("%d%d",&n,&k);
    LL ans=0;
    for(int i=0; i<=k; i++)
        ans+=c[n][i]*p[i];
    printf("%I64d\n",ans);
    return 0;
}
