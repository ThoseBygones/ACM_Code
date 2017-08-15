//dp+01背包变形
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 105
#define MAXM 200010   //2*1000*100注意到值可能为负数，因此范围*2，且整体+1000
#define INF 0x3f3f3f3f

int s[MAXN];    //smart值
int f[MAXN];    //funny值
int dp[MAXM];   //dp[i]表示总的smart值为i时能得到的最大的funny值

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%d%d",&s[i],&f[i]);
    for(int i=0; i<MAXM; i++)
        dp[i]=-INF;
    dp[100000]=0;   //相当于未扩大100000时的dp[0]=0，即初始化smart值为0时能得到的最大funny值为0
    for(int i=1; i<=n; i++)
    {
        if(s[i]<0 && f[i]<0)
            continue;
        if(s[i]>0)  //smart值为正时
        {
            for(int j=200000; j>=s[i]; j--)
            {
                if(dp[j-s[i]]>-INF)
                    dp[j]=max(dp[j],dp[j-s[i]]+f[i]);
            }
        }
        else    //smart值为负时
        {
            for(int j=0; j<=200000+s[i]; j++)
            {
                if(dp[j-s[i]]>-INF)
                    dp[j]=max(dp[j],dp[j-s[i]]+f[i]);
            }
        }
    }
    int ans=0;
    for(int i=100000; i<=200000; i++)   //因为整体扩大了100000，因此100000~200000对应0~100000
    {
        if(dp[i]>=0)
            ans=max(ans,dp[i]+i-100000);
    }
    printf("%d\n",ans);
    return 0;
}
