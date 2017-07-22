//LIS问题... 参考《挑战程序设计竞赛（第二版）》第65页的方法
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 40005
#define INF 0x3f3f3f3f

int a[MAXN];
int dp[MAXN];

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1; i<=n; i++)
            scanf("%d",&a[i]);
        for(int i=0; i<MAXN; i++)
            dp[i]=INF;
        for(int i=1; i<=n; i++)
            *lower_bound(dp,dp+n,a[i])=a[i];
        printf("%d\n",lower_bound(dp,dp+n,INF)-dp);
    }
    return 0;
}
