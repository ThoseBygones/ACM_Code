//概率dp+二进制运算
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 205

double p[MAXN][MAXN];
double dp[10][MAXN];  //表示第i轮比赛中j胜出的概率

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        if(n==-1)
            break;
        memset(dp,0,sizeof(dp));
        for(int i=0; i<(1<<n); i++)
        {
            for(int j=0; j<(1<<n); j++)
                scanf("%lf",&p[i][j]);
        }
        for(int i=0; i<(1<<n); i++)
            dp[0][i]=1.0;
        for(int i=1; i<=n; i++) //2^n支队伍需要进行n轮淘汰赛
        {
            for(int j=0; j<(1<<n); j++) //枚举其中一支球队
            {
                for(int k=0; k<(1<<n); k++) //枚举另一支球队
                {
                    if(((j>>(i-1))^1)==(k>>(i-1)))  //巧妙利用位运算判断两支队伍在第i轮的时候是否可能交手（假设两支队都存活到第i轮）
                        dp[i][j]+=dp[i-1][j]*dp[i-1][k]*p[j][k];    //两队前i-1轮都存活且第i轮j战胜k
                }
            }
        }
        double Max=0.0;
        int ans=-1;
        for(int i=0; i<(1<<n); i++)
        {
            if(dp[n][i]>Max)
            {
                Max=dp[n][i];
                ans=i+1;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

//0000000
//0000001
