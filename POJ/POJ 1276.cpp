#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 1005
#define MAXM 100005

int w[MAXN],cnt[MAXN];
int dp[MAXM];
int n,m;

void ZeroOnePack(int value,int weight)  //01背包
{
    for(int i=m; i>=weight; i--)
    {
        dp[i]=max(dp[i],dp[i-weight]+value);
    }
}

void CompletePack(int value,int weight) //完全背包
{
    for(int i=weight; i<=m; i++)
    {
        dp[i]=max(dp[i],dp[i-weight]+value);
    }
}

void MultiPack(int value,int weight,int cnt)
{
    if(weight*cnt>=m)  //转化为完全背包
        CompletePack(value,weight);
    else    //转化为01背包
    {
        int k=1;
        while(k<=cnt) //二进制优化
        {
            ZeroOnePack(value*k,weight*k);
            cnt-=k;
            k*=2;
        }
        for(int i=m; i>=cnt*weight; i--)
            dp[i]=max(dp[i],dp[i-cnt*weight]+cnt*value);
    }
}

int main()
{
    while(~scanf("%d%d",&m,&n))
    {
        memset(dp,0,sizeof(dp));
        for(int i=1; i<=n; i++)
            scanf("%d%d",&cnt[i],&w[i]);
        for(int i=1; i<=n; i++)
            MultiPack(w[i],w[i],cnt[i]);
        printf("%d\n",dp[m]);
    }
    return 0;
}
