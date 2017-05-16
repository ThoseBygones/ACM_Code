#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 1005

int v[MAXN];    //菜的价格
int dp[MAXN];

int main()
{
    int n;
    int left;   //卡的余额
    while(~scanf("%d",&n),n)
    {
        memset(dp,0,sizeof(dp));
        for(int i=1; i<=n; i++)
            scanf("%d",&v[i]);
        scanf("%d",&left);
        if(left<5)
        {
            printf("%d\n",left);
            continue;
        }
        sort(v+1,v+n+1);
        for(int i=1; i<n; i++)  //最贵的那个菜不参与dp，因为最后只要卡里钱还>=5，再买这个最贵的菜一定能使卡内余额最小
        {
            for(int j=left-5; j>=v[i]; j--) //少于5元时无法消费，相当于dp只需要5~1000
                dp[j]=max(dp[j],dp[j-v[i]]+v[i]);
        }
        printf("%d\n",left-dp[left-5]-v[n]);    //卡里剩的钱
    }
    return 0;
}
