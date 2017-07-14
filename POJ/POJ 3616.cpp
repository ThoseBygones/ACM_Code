#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 1005

struct Interval
{
    int st;
    int ed;
    int sum;
} in[MAXN];

int dp[MAXN];   //第i个时间段挤奶量的最大值

bool cmp(Interval a,Interval b)
{
    if(a.st==b.st)
        return a.ed<b.ed;
    return a.st<b.st;
}

int main()
{
    int n,m,r;
    scanf("%d%d%d",&n,&m,&r);
    for(int i=0; i<m; i++)
    {
        scanf("%d%d%d",&in[i].st,&in[i].ed,&in[i].sum);
        in[i].ed+=r;
    }
    sort(in,in+m,cmp);
    for(int i=0; i<m; i++)
    {
        dp[i]=in[i].sum;
        for(int j=0; j<i; j++)
        {
            if(in[j].ed<=in[i].st)
                dp[i]=max(dp[i],dp[j]+in[i].sum);
        }
    }
    int ans=dp[0];
    for(int i=1; i<m; i++)
        ans=max(ans,dp[i]);
    printf("%d\n",ans);
    return 0;
}
