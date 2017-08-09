#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 100005
#define MAXM 1005
#define INF 1e18
#define LL long long

int a[MAXN],b[MAXN];    //怪兽的生命力、怪兽的防御力
int k[MAXM],p[MAXM];    //消耗晶石数目、技能造成的伤害
LL dp[15][MAXM]; //dp[i][j]打掉防御力i消耗怪兽j生命值需要的最小花费

int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=1; i<=n; i++)
            scanf("%d%d",&a[i],&b[i]);
        for(int i=1; i<=m; i++)
            scanf("%d%d",&k[i],&p[i]);
        for(int i=0; i<=10; i++)
            fill(dp[i]+1,dp[i]+1001,INF);
        for(int i=0; i<=10; i++)
            dp[i][0]=0;
        for(int i=0; i<=10; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(p[j]>i)  //能打得动怪兽
                {
                    for(int l=1; l<=1000; l++)
                        dp[i][l]=min(dp[i][l],dp[i][max(l-(p[j]-i),0)]+(LL)k[j]);   //怪兽剩余血量不能为负（最低为零）
                }
            }
        }
        LL ans=0;
        for(int i=1; i<=n; i++)
        {
            if(dp[b[i]][a[i]]==INF)
            {
                ans=-1;
                break;
            }
            ans+=dp[b[i]][a[i]];
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
