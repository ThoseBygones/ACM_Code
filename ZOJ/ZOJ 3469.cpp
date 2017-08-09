//区间dp
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 1005
#define INF 0x3f3f3f3f

struct Point
{
    int x;
    int b;
} p[MAXN];

int n,v,x;
int sum[MAXN];  //前缀和数组
int dp[MAXN][MAXN][2];  //dp[i][j][0]表示送完区间[i,j]内的外卖累计的最小不满值（送完后停在i点）；
                        //dp[i][j][1]表示送完区间[i,j]内的外卖累计的最小不满值（送完后停在j点）

bool cmp(Point a,Point b)
{
    return a.x<b.x;
}

int main()
{
    while(~scanf("%d%d%d",&n,&v,&x))
    {
        for(int i=1; i<=n; i++)
            scanf("%d%d",&p[i].x,&p[i].b);
        n++;
        p[n].x=x;   //外卖店也看做一个点
        p[n].b=0;

        sort(p+1,p+n+1,cmp);  //按照坐标顺序排序

        int temp;   //外卖店的次序标记
        for(int i=1; i<=n; i++)
        {
            if(p[i].x==x)
            {
                temp=i;
                break;
            }
        }

        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
                dp[i][j][0]=dp[i][j][1]=INF;
        }
        dp[temp][temp][0]=dp[temp][temp][1]=0;

        memset(sum,0,sizeof(sum));
        for(int i=1; i<=n; i++)
            sum[i]=sum[i-1]+p[i].b; //不满意值的前缀和

        for(int i=temp; i>=1; i--)  //从外卖店开始向坐标轴负方向扩展区间
        {
            for(int j=temp; j<=n; j++)  //从外卖店开始向坐标轴正方向扩展区间
            {
                if(i==j)
                    continue;
                dp[i][j][0]=min(dp[i][j][0],dp[i+1][j][0]+(sum[i]+(sum[n]-sum[j]))*(p[i+1].x-p[i].x));
                //区间内的最小不满意值+从i+1点跑到i点时间里区间外的顾客（[1,i]+[j+1,n]）积累的不满意值之和
                dp[i][j][0]=min(dp[i][j][0],dp[i+1][j][1]+(sum[i]+(sum[n]-sum[j]))*(p[j].x-p[i].x));
                //区间内的最小不满意值+从j点跑到i点时间里区间外的顾客（[1,i]+[j+1,n]）积累的不满意值之和
                dp[i][j][1]=min(dp[i][j][1],dp[i][j-1][0]+(sum[i-1]+(sum[n]-sum[j-1]))*(p[j].x-p[i].x));
                //区间内的最小不满意值+从i点跑到j点时间里区间外的顾客（[1,i]+[j+1,n]）积累的不满意值之和
                dp[i][j][1]=min(dp[i][j][1],dp[i][j-1][1]+(sum[i-1]+(sum[n]-sum[j-1]))*(p[j].x-p[j-1].x));
                //区间内的最小不满意值+从j-1点跑到j点时间里区间外的顾客（[1,i]+[j+1,n]）积累的不满意值之和
            }
        }
        int ans=min(dp[1][n][0],dp[1][n][1])*v;   //选择两种方案的最优值；v=V^(-1)所以直接乘v
        printf("%d\n",ans);
    }
    return 0;
}
