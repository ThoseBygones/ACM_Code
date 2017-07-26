#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

#define MAXN 16
#define INF 0x3f3f3f3f

struct Point
{
    int x;
    int y;
} p[MAXN];

struct Rectangle
{
    int s;  //每个矩形包含的两个点的集合
    int area;
} r[1<<MAXN];

int dp[1<<MAXN];
int n;

bool isInside(int i,int j,int k)    //判断新的点坐标是否在矩形中（注意i,j,k顺序）
{
    if((p[k].x-p[i].x)*(p[k].x-p[j].x)<=0 && (p[k].y-p[i].y)*(p[k].y-p[j].y)<=0)
        return true;
    return false;
}

int main()
{
    while(~scanf("%d",&n),n)
    {
        for(int i=0; i<n; i++)
            scanf("%d%d",&p[i].x,&p[i].y);
        int cnt=0;
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                r[cnt].s=(1<<i)|(1<<j);
                for(int k=0; k<n; k++)
                {
                    if(isInside(i,j,k)) //如果某个第三个点也在这个矩形中，直接加进去
                        r[cnt].s|=(1<<k);
                }
                if(p[i].x==p[j].x)
                    r[cnt].area=1*abs(p[i].y-p[j].y);
                else if(p[i].y==p[j].y)
                    r[cnt].area=1*abs(p[i].x-p[j].x);
                else
                    r[cnt].area=abs(p[i].x-p[j].x)*abs(p[i].y-p[j].y);
                cnt++;
            }
        }

        fill(dp,dp+(1<<n),INF);
        //memset(dp,0x3f,sizeof(dp));
        dp[0]=0;
        for(int i=0; i<(1<<n); i++) //枚举加上新矩形之前的状态
        {
            for(int j=0; j<cnt; j++)    //枚举添加的新矩形
                dp[i|r[j].s]=min(dp[i|r[j].s],dp[i]+r[j].area);
        }
        printf("%d\n",dp[(1<<n)-1]);
    }
    return 0;
}
