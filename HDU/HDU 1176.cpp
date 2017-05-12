#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 100005

int a[MAXN][12];    //第i秒在第j点掉下的馅饼数
int dp[MAXN][12];   //前i秒在第j点能接到的最大馅饼数量

//类似数塔模型，但是数塔是自上往下，而此题因为起点在位置5，因此要从下往上

int main()
{
    int n,x,t;
    int maxtime;
    while(~scanf("%d",&n),n)
    {
        memset(a,0,sizeof(a));
        memset(dp,0,sizeof(dp));
        maxtime=0;
        for(int i=1; i<=n; i++)
        {
            scanf("%d%d",&x,&t);
            a[t][x]++;
            maxtime=max(maxtime,t);
        }
        for(int j=0; j<=10; j++)
            dp[maxtime][j]=a[maxtime][j];
        for(int i=maxtime-1; i>=0; i--)
        {
            for(int j=0; j<=10; j++)
            {
                if(j==0)
                    dp[i][j]=max(dp[i+1][j],dp[i+1][j+1]);
                else if(j==10)
                    dp[i][j]=max(dp[i+1][j],dp[i+1][j-1]);
                else
                    dp[i][j]=max(dp[i+1][j],max(dp[i+1][j-1],dp[i+1][j+1]));
                dp[i][j]+=a[i][j];
            }
        }
        printf("%d\n",dp[0][5]);
    }
    return 0;
}
