#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 105
#define MAXM 100005

int w[MAXN],cnt[MAXN];
int dp[MAXM];
int n,m;

void MultiPack(int v,int w,int c)
{
    if(w*c>=m)  //转化为完全背包
    {
        for(int i=w; i<=m; i++)
            dp[i]=max(dp[i],dp[i-w]+v);
    }
    else    //转化为01背包
    {
        int k=1;
        while(k<=c) //二进制优化：因为不管最优策略选几件第i种物品，总可以表示成若干个2^k件物品的和。这样把每种物品拆成O(log(V/c[i]))件物品——例如13可以拆成1 2 4 6
        {
            for(int i=m; i>=k*w; i--)
                dp[i]=max(dp[i],dp[i-k*w]+k*v);
            c-=k;
            k*=2;
        }
        for(int i=m; i>=c*w; i--)
            dp[i]=max(dp[i],dp[i-c*w]+c*v);
    }
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        if(n==0 && m==0)
            break;
        memset(dp,0,sizeof(dp));
        for(int i=0; i<n; i++)
            scanf("%d",&w[i]);
        for(int i=0; i<n; i++)
            scanf("%d",&cnt[i]);
        for(int i=0; i<=n; i++)
            MultiPack(w[i],w[i],cnt[i]);
        int sum=0;
        for(int i=1; i<=m; i++)
        {
            if(dp[i]==i)
                sum++;
        }
        printf("%d\n",sum);
    }
    return 0;
}


//模板版
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 105
#define MAXM 100005

int w[MAXN],cnt[MAXN];
int dp[MAXM];
int cash,n;

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
    while(~scanf("%d%d",&cash,&n))
    {
        memset(dp,0,sizeof(dp));
        for(int i=0; i<n; i++)
            scanf("%d",&w[i]);
        for(int i=0; i<n; i++)
            scanf("%d",&cnt[i]);
        for(int i=0; i<=n; i++)
            MultiPack(w[i],w[i],cnt[i]);
        int sum=0;
        /*for(int i=1; i<=m; i++)
        {
            if(dp[i]==i)
                sum++;
        }*/
        printf("%d\n",dp[n]);
    }
    return 0;
}
