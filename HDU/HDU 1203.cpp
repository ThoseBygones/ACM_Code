#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int c[10005];
double p[10005];
double dp[10005];
int n,m;

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        if(n==0 && m==0)
            break;
        for(int i=1; i<=m; i++)
            scanf("%d%lf",&c[i],&p[i]);
        for(int i=0; i<=n; i++)
            dp[i]=1.0;
        for(int i=1; i<=m; i++)
        {
            for(int j=n; j>=c[i]; j--)
                dp[j]=min(dp[j],dp[j-c[i]]*(1.0-p[i]));
        }
        printf("%.1lf%%\n",(1.0-dp[n])*100);
    }
    return 0;
}
