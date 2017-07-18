#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 210
#define MAXR 1005
#define INF 200000000

int dl[MAXN][MAXN]; //旱路邻接矩阵
int ds[MAXN][MAXN]; //水路邻接矩阵
int dp[MAXR][MAXN]; //dp[i][j]表示去了第i个镇子以后船放在第j个镇子
int a[MAXR];    //送货顺序
int n,m,r;

void floyd()
{
    for(int k = 0; k<n; k++)
    {
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<n; j++)
            {
                dl[i][j] = min(dl[i][j],dl[i][k]+dl[k][j]);
                ds[i][j] = min(ds[i][j],ds[i][k]+ds[k][j]);
            }
        }
    }
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        if(n==0 && m==0)
            break;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i==j)
                    dl[i][j]=ds[i][j]=0;
                else
                    dl[i][j]=ds[i][j]=INF;
            }
        }
        for(int i=0; i<m; i++)
        {
            int u,v,w;
            char s[2];
            scanf("%d%d%d%s",&u,&v,&w,s);
            u--;
            v--;
            if(s[0]=='L')
                dl[u][v]=dl[v][u]=min(dl[u][v],w);
            else if(s[0]=='S')
                ds[u][v]=ds[v][u]=min(ds[u][v],w);
        }
        scanf("%d",&r);
        for(int i=0; i<r; i++)
        {
            scanf("%d",&a[i]);
            a[i]--;
        }
        //分别求出旱路和水路上任意两点间的最短路径
        floyd();
        //dp，Rito每次可以选择直接走旱路去下一个点送货；或者先走回船停的地方，把船开到某个点k然后再走陆路到下一个点
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<n; j++)
                dp[i][j]=INF;
        }
        for(int i=0; i<n; i++)
        {
            //去了送货清单上的首个镇子（第a[0]个镇子），然后把船放在了第i个镇子
            dp[0][i]=ds[a[0]][i]+dl[i][a[0]];   //坐船去，走旱路回
        }
        for(int i=1; i<r; i++)  //开始送后面的货
        {
            for(int j=0; j<n; j++)  //枚举走回的这个船停的地方j
            {
                for(int k=0; k<n; k++)  //枚举去下一个点之前船停的地方k
                {
                    if(j!=k)
                    {
                        //先从第i-1站走旱路到船停的地方j，再走水路把船开到k，再走旱路到第i站送货
                        dp[i][k]=min(dp[i][k],dp[i-1][j]+dl[a[i-1]][j]+ds[j][k]+dl[k][a[i]]);
                    }
                    else
                    {
                        //直接走旱路到第i站送货
                        dp[i][j]=min(dp[i][j],dp[i-1][j]+dl[a[i-1]][a[i]]);
                    }
                }
            }
        }
        int ans=*min_element(dp[r-1],dp[r-1]+n);
        printf("%d\n",ans);
    }
    return 0;
}
