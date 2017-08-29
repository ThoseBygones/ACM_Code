#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 100005
#define MAXM 300005
#define LL long long

struct Pack
{
    LL val;
    LL s1,s2;
} dp[MAXM]; //dp[i]表示重量为i的情况下的最大总价值为val，重量为1的物品选择的数量为s1，重量为2的物品选择的数量为s2

LL cnt[5];  //重量为1,2,3物品的数量
LL sum[MAXN];   //重量为3的物品价值的前缀和
LL cost[5][MAXN];  //记录各个重量为1,2,3物品的花费

bool cmp(LL a,LL b)
{
    return a>b;
}

int main()
{
    LL n,m;
    scanf("%I64d%I64d",&n,&m);
    memset(cnt,0,sizeof(cnt));
    memset(dp,0,sizeof(dp));
    memset(cost,0,sizeof(cost));
    for(LL i=1; i<=n; i++)
    {
        LL w,c;
        scanf("%I64d%I64d",&w,&c);
        cost[w][++cnt[w]]=c;
    }
    for(LL i=1; i<=3; i++) //每种重量的物品按照价值由大到小排序
        sort(cost[i]+1,cost[i]+1+cnt[i],cmp);
    for(LL i=1; i<=cnt[3]; i++)    //求出重量为3的物品价值的前缀和
        sum[i]=sum[i-1]+cost[3][i];
    dp[0].val=0;
    dp[0].s1=0;
    dp[0].s2=0;
    for(LL i=1; i<=m; i++)
    {
        dp[i]=dp[i-1];
        if(dp[i-1].val+cost[1][dp[i-1].s1+1]>dp[i].val) //取下一个重量为1的物品的方案更优
        {
            dp[i].val=dp[i-1].val+cost[1][dp[i-1].s1+1];
            dp[i].s1=dp[i-1].s1+1;
            dp[i].s2=dp[i-1].s2;
        }
        if(i>=2 && dp[i-2].val+cost[2][dp[i-2].s2+1]>dp[i].val) //拿下一个重量为2的物品的方案更优
        {
            dp[i].val=dp[i-2].val+cost[2][dp[i-2].s2+1];
            dp[i].s1=dp[i-2].s1;
            dp[i].s2=dp[i-2].s2+1;
        }
    }
    LL ans=0;
    for(LL i=0; i<=cnt[3] && i*3<=m; i++)  //枚举剩余空间，考虑剩余空间拿重量为3的物品的方案
        ans=max(ans,dp[m-i*3].val+sum[i]);
    printf("%I64d\n",ans);
    return 0;
}
