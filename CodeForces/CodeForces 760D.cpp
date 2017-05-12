#include <bits/stdc++.h>
#define LL long long
using namespace std;

#define INF 1e9
#define MAXN 100005

int n;
LL a[MAXN]; //累计旅行时间
LL dp[MAXN];    //前i次旅行的最小花费

int main()
{
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%I64d",a+i);
    dp[0]=0;
    for(int i=1; i<=n; i++)
    {
        dp[i]=dp[i-1]+20;   //每多旅行一次按照正常票价要多交20
        int x=upper_bound(a,a+n+1,a[i]-90)-a-1;  //找到最接近90分钟的一次旅行花费
        dp[i]=min(dp[i],dp[x]+50);  //在之前得到的最优方式和全天票中选择最低的价格
        int y=upper_bound(a,a+n+1,a[i]-1440)-a-1;   ////找到最接近1440分钟的一次旅行花费
        dp[i]=min(dp[i],dp[y]+120); //在之前得到的最优方式和全天票中选择最低的价格
        printf("%I64d\n",dp[i]-dp[i-1]);   //进行最新的一次旅行还要补交多少钱
    }
}
