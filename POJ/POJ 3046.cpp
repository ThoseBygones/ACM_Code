//dp:多重集组合数问题
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MOD 1000000

int f[1005];
int dp[2][100005]; //前i个family能配出元素个数为j的集合

int main()
{
    int t,a,s,b;
    scanf("%d%d%d%d",&t,&a,&s,&b);
    for(int i=0; i<a; i++)
    {
        int x;
        scanf("%d",&x);
        f[x]++;
    }
    dp[0][0]=1;
    int sum=0;
    for(int i=1; i<=t; i++)
    {
        sum+=f[i];  //前i个family一共有多少只蚂蚁
        int cur=i&1;
        int pre=(i-1)&1;
        memset(dp[cur],0,sizeof(dp[cur]));   //滚动数组，初始化当前状态的这一行为0
        for(int k=0; k<=f[i]; k++)
        {
            for(int j=k; j<=sum; j++)
                dp[cur][j]=(dp[cur][j]+dp[pre][j-k])%MOD;   //前i-1个family配成元素个数为j-k的集合；每一个集合都放入k只
        }
    }
    int ans=0;
    int cur=t&1;
    for(int i=s; i<=b; i++)
        ans=(ans+dp[cur][i])%MOD;
    printf("%d\n",ans);
    return 0;
}
