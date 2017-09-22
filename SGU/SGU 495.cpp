#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 100005

double dp[MAXN];    //第i个人拿到礼物的概率

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    dp[1]=1.0;
    for(int i=2; i<=m; i++)
    {
        //第i个人得到礼物的概率：假如第i-1个人没有得到礼物，那么i得到礼物的概率和i-1一样；假如第i-1个人得到了礼物，那么i得到礼物的概率是i-1得到礼物概率减去1/n
        dp[i]=(1-dp[i-1])*dp[i-1]+dp[i-1]*(dp[i-1]-1.0/n);
    }
    double ans=0;
    for(int i=1; i<=m; i++)
        ans+=dp[i];
    printf("%.10f\n",ans);
    return 0;
}
