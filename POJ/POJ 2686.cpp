//TSP问题（状态压缩dp）
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 35
#define MAXM 15
#define INF 1e9+7

int t[MAXM];    //每张车票上马的匹数
int d[MAXN][MAXN];  //图的邻接矩阵
double dp[1<<MAXM][MAXN];  //dp[S][u]：到达 剩余车票集合为S（0表示车票已使用，1表示车票未使用），现在在城市u的状态 需要的最小花费
int n,m,p,a,b;

int main()
{
    while(~scanf("%d%d%d%d%d",&n,&m,&p,&a,&b))
    {
        if(n==0 && m==0 && p==0 && a==0 && b==0)
            break;
        memset(d,0,sizeof(d));
        for(int i=0; i<n; i++)
            scanf("%d",&t[i]);
        for(int i=0; i<p; i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            d[u][v]=d[v][u]=w;
        }
        for(int i=0; i<(1<<n); i++)
            fill(dp[i],dp[i]+m+1,INF);  //初始化

        dp[(1<<n)-1][a]=0;
        double ans=INF;
        for(int i=(1<<n)-1; i>=0; i--)  //枚举集合里剩下车票的情况
        {
            for(int v=1; v<=m; v++) //枚举下一站到达的点
            {
                for(int j=0; j<n; j++)  //枚举这一步使用的车票
                {
                    if(i&(1<<j))    //这张车票之前没有被用过
                    {
                        for(int u=1; u<=m; u++) //枚举当前所在的点
                        {
                            if(d[u][v]) //如果这两点连通（即可以从u到v）
                                dp[i & ~(1<<j)][u]=min(dp[i & ~(1<<j)][u],dp[i][v]+1.0*d[u][v]/t[j]);
                        }
                    }
                }
            }
        }

        for(int i=0; i<(1<<n); i++) //在所有能到达目标点b的方案中选一种费用最小的方案
            ans=min(ans,dp[i][b]);

        if(ans==INF)    //无法到达
            puts("Impossible");
        else
            printf("%.3f\n",ans);
    }
    return 0;
}
