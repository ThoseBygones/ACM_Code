#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 105
#define INF 1e9

int p[MAXN];    //p[i]表示第i个加油站的位置
double dp[MAXN];   //dp[i]表示到达第i个加油站需要的最短时间

int main()
{
    int l;
    int n,c,t;
    int vr,v1,v2;
    double t1,t2;   //兔子用时乌龟用时
    while(~scanf("%d",&l))
    {
        scanf("%d%d%d",&n,&c,&t);
        scanf("%d%d%d",&vr,&v1,&v2);
        for(int i=1; i<=n; i++)
            scanf("%d",&p[i]);
        p[0]=0;    //起点当做一个加油站
        p[n+1]=l;  //终点也当做一个加油站
        dp[0]=0.0;
        for(int i=1; i<=n+1; i++)
        {
            double mintime=INF;
            for(int j=0; j<i; j++)
            {
                int temp=p[i]-p[j];
                if(temp>c)
                    t2=1.0*c/v1+1.0*(temp-c)/v2;
                else
                    t2=1.0*temp/v1;
                t2+=dp[j];
                if(j)
                    t2+=t;
                mintime=min(t2,mintime);
            }
            dp[i]=mintime;
        }
        //cout << dp[n+1] << endl;
        t1=1.0*l/vr;
        //cout << t1 << endl;
        if(t1<dp[n+1])
            puts("Good job,rabbit!");
        else
            puts("What a pity rabbit!");
    }
    return 0;
}
