#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

#define MAXN 15
#define MOD 100000000

vector <int> sta;   //记录可行的状态
int dp[MAXN][1<<13];    //第i行j状态下的种植方案总数
int f[MAXN][MAXN];
int n,m;

void init()
{
    for(int i=0; i<(1<<12); i++)
    {
        if(!(i&(i<<1)))
            sta.push_back(i);
    }
}

bool ok(int x,int val)
{
    for(int i=1; i<=m; i++)
    {
        if(val&(1<<(i-1)) && !f[x][i])  //不能够种植的地方种了
            return false;
    }
    return true;
}

int main()
{
    init();
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
            scanf("%d",&f[i][j]);
    }
    memset(dp,0,sizeof(dp));
    for(int i=1; i<=n; i++)
    {
        for(int j=0; sta[j]<(1<<m); j++)
        {
            if(ok(i,sta[j]))    //判断状态是否符合要求
            {
                if(i==1)    //初始化第一行
                {
                    dp[i][j]=1;
                    continue;
                }
                for(int k=0; sta[k]<(1<<m); k++)  //枚举上一行状态
                {
                    if(!(sta[j]&sta[k]))    //与上一行状态没有冲突
                        dp[i][j]=(dp[i][j]+dp[i-1][k])%MOD;
                }
            }
        }
    }
    int ans=0;
    for(int i=0; sta[i]<(1<<m); i++)
        ans=(ans+dp[n][i])%MOD;
    printf("%d\n",ans);
    return 0;
}
