#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct box
{
    int x;
    int y;
    int z;
} sz[1005],dp[1005];

int cmp(box a,box b)
{
    if(a.x!=b.x)
        return a.x<b.x;
    return a.y<b.y;
}

int main()
{
    int kase,a,b,c;
    while(cin >> kase)
    {
        if(kase==0)
            break;
        int cnt=0;
        for(int i=1; i<=kase; i++)
        {
            cin >> a >> b >> c;
            sz[cnt].x=a;
            sz[cnt].y=b;
            sz[cnt].z=c;
            cnt++;
            sz[cnt].x=a;
            sz[cnt].y=c;
            sz[cnt].z=b;
            cnt++;
            sz[cnt].x=b;
            sz[cnt].y=a;
            sz[cnt].z=c;
            cnt++;
            sz[cnt].x=b;
            sz[cnt].y=c;
            sz[cnt].z=a;
            cnt++;
            sz[cnt].x=c;
            sz[cnt].y=a;
            sz[cnt].z=b;
            cnt++;
            sz[cnt].x=c;
            sz[cnt].y=b;
            sz[cnt].z=a;
            cnt++;
        }
        sort(sz,sz+cnt,cmp);
        memset(dp,0,sizeof(dp));
        int sum=sz[0].z;
        for(int i=0;i<cnt;i++)
        {
            dp[i].x=sz[i].x;
            dp[i].y=sz[i].y;
            dp[i].z=sz[i].z;
            sum=max(dp[i].z,sum);
            for(int j=0;j<i;j++)
            {
                if(dp[j].x<dp[i].x && dp[j].y<dp[i].y)
                {
                    dp[i].z=max(dp[j].z+sz[i].z,dp[i].z);
                    sum=max(sum,dp[i].z);
                }
            }
        }
        printf("Case %d: maximum height = %d\n",kase,sum);
    }
    return 0;
}
