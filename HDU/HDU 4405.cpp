//概率dp求期望
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 100005

double dp[MAXN];   //dp[i]表示在位置i时，距离游戏结束还需要掷骰子次数的期望
int fly[MAXN];  //fly[i]=j表示从i点能够飞到的位置为j

int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        if(n==0 && m==0)
            break;
        memset(fly,-1,sizeof(fly));
        for(int i=1; i<=m; i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            fly[x]=y;
        }
        memset(dp,0.0,sizeof(dp));
        for(int i=n-1; i>=0; i--)
        {
            if(fly[i]==-1)  //没有直飞航线，需要掷一次骰子
            {
                for(int j=1; j<=6; j++)
                    dp[i]+=dp[i+j]/6.0;
                dp[i]+=1.0;   //掷一次骰子，期望数+1
            }
            else
                dp[i]=dp[fly[i]];   //有航线能直飞，则掷骰子的期望不需要增加
        }
        printf("%.4f\n",dp[0]);
    }
    return 0;
}
