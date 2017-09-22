//概率dp+记忆化搜索求期望
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

#define MAXN 105
#define MAXM 2000005

int n;
int c[MAXN];
double dp[MAXM];    //dp[i]表示吸血鬼能力为i的时候走出迷宫需要的天数的期望

double dfs(int val)
{
    if(dp[val]) //已经搜索并记录过的路径不再重复搜索
        return dp[val];
    for(int i=1; i<=n; i++)
    {
        if(val>c[i])    //吸血鬼当前能力能走出这个迷宫
        {
            int t=(int)((1.0+sqrt(5.0))/2.0*c[i]*c[i]);
            dp[val]+=(double)t/(double)n;
        }
        else    //不能走出则花费一天时间提高c[i]能力
            dp[val]+=(1.0+dfs(val+c[i]))/(double)n;
    }
    return dp[val];
}

int main()
{
    int f;
    while(~scanf("%d%d",&n,&f))
    {
        for(int i=1; i<=n; i++)
            scanf("%d",&c[i]);
        memset(dp,0.0,sizeof(dp));
        printf("%.3f\n",dfs(f));
    }
    return 0;
}
