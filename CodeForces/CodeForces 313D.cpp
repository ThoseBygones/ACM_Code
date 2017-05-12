#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define LL long long
using namespace std;

#define MAXN 305
#define INF 1000000000000000LL

LL cost[MAXN][MAXN];    //记录每个公司的花费
LL dp[MAXN][MAXN];  //前i个点覆盖j个需要的花费
int n,m,k;

int main()
{
    while(~scanf("%d%d%d",&n,&m,&k))
    {
        for(int i=0; i<=n+1; i++)
        {
            for(int j=0; j<=n+1; j++)
            {
                dp[i][j]=INF;
                cost[i][j]=INF;
            }
        }
        for(int i=1; i<=m; i++)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            cost[a][b]=min(cost[a][b],(LL)c);
        }
        for(int i=1; i<=n; i++)
        {
            for(int j=n; j>=i; j--)
                cost[i][j]=min(cost[i][j],cost[i][j+1]);    //是否存在方案使填补第i个坑到第j+1个坑比原来的填补第i到第j个坑更便宜
        }
        dp[0][0]=0;
        for(int i=0; i<=n; i++)
        {
            for(int j=0; j<=i; j++)
            {
                if(dp[i][j]!=INF)
                {
                    dp[i+1][j]=min(dp[i][j],dp[i+1][j]);    //是否存在方案使填补前i个坑中的j个坑比填补前i+1个坑中的j个坑更便宜
                    for(int l=1; l<=k-j; l++)   //还需要填的坑剩k-j个
                    {
                        if(i+l<=n)
                            dp[i+l][j+l]=min(dp[i+l][j+l],dp[i][j]+cost[i+1][i+l]); //是否存在方案使再多使用一个公司填i+1到i+l的cost[i+1][i+l]个坑会比原来的方案更便宜
                    }
                }
            }
        }
        if(dp[n][k]==INF)
            cout << "-1" << endl;
        else
            cout << dp[n][k] << endl;
    }
}
