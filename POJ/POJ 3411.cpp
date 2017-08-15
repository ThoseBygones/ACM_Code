#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

#define MAXN 10
#define INF 0x3f3f3f3f

struct Road
{
    int c;
    int p;
    int r;
};

vector <Road> road[MAXN][MAXN];
int dp[1<<MAXN][MAXN];

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0; i<m; i++)
    {
        int u,v,c,p,r;
        scanf("%d%d%d%d%d",&u,&v,&c,&p,&r);
        u--;
        v--;
        c--;
        Road temp;
        temp.c=c;
        temp.p=p;
        temp.r=r;
        road[u][v].push_back(temp);
    }

    for(int i=0; i<(1<<n); i++)
        fill(dp[i],dp[i]+n,INF);
    dp[1][0]=0;
    int ans=INF;
    for(int i=0; i<(1<<n); i++) //枚举现在的所有状态
    {
        for(int j=0; j<n; j++)  //枚举现在所在的点
        {
            for(int k=0; k<n; k++)  //枚举下一个要去的点
            {
                for(int h=0; h<road[j][k].size(); k++)
                {
                    if(j==road[j][k][h].c)
                        dp[i|(1<<j)][j]=min(dp[i|(1<<j)][j],dp[i][j]+road[j][k][h].p);
                }

                if(road[j][k].size())   //j,k两点之间连通
                {
                    for(int h=0; h<road[j][k].size(); h++)
                    {
                        if(i&(1<<road[j][k][h].c))  //预pay点之前经过了
                            dp[i][k]=min(dp[i][k],min(dp[i][j],dp[i][j]+road[j][k][h].r-road[j][k][h].p));
                        else
                            dp[i][k]=min(dp[i][k],dp[i][j]+road[j][k][h].r);
                    }
                }
            }
        }
        ans=min(ans,dp[i][n-1]);
    }

    if(ans==INF)
        puts("impossible");
    else
        printf("%d\n",ans);
    return 0;
}
