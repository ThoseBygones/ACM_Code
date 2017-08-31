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
    int b;
    int c;
    int p;
    int r;
};

vector <Road> g[MAXN];
int dp[1<<MAXN][MAXN];

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0; i<m; i++)
    {
        int u;
        Road temp;
        scanf("%d%d%d%d%d",&u,&temp.b,&temp.c,&temp.p,&temp.r);
        u--;
        temp.b--;
        temp.c--;
        g[u].push_back(temp);
    }
    for(int i=0; i<(1<<n); i++)
        fill(dp[i],dp[i]+n,INF);
    dp[1][0]=0;
    int ans=INF;
    for(int i=0; i<(1<<n); i++) //枚举现在的所有状态
    {
        bool flag=true;
        while(flag)
        {
            flag=false;
            for(int j=0; j<n; j++)  //枚举现在所在的点
            {
                if(i&(1<<j))    //该点之前访问过
                {
                    for(int k=0; k<g[j].size(); k++)  //枚举下一个要去的点
                    {
                        int v=g[j][k].b;
                        int temp=INF;
                        if(i&(1<<g[j][k].c))
                            temp=min(temp,dp[i][j]+g[j][k].p);  //第一种pay法
                        temp=min(temp,dp[i][j]+g[j][k].r);  //第二种pay法
                        if(temp<dp[i|(1<<v)][v])    //如果这次循环又找到了更省的pay法，则继续进行；否则结束
                        {
                            dp[i|(1<<v)][v]=temp;
                            flag=true;
                        }
                    }
                }
            }
        }
        if(i&1) //可以不加这一句
            ans=min(ans,dp[i][n-1]);
    }
    if(ans==INF)
        puts("impossible");
    else
        printf("%d\n",ans);
    return 0;
}
