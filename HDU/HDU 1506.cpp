#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define LL long long
using namespace std;

#define MAXN 100005

LL a[MAXN];
LL l[MAXN],r[MAXN]; //记录某个矩形左边（右边）第一个比它低的矩形的下标
LL dp[MAXN];

int main()
{
    int n;
    while(~scanf("%d",&n),n)
    {
        for(int i=1; i<=n; i++)
            scanf("%I64d",&a[i]);
        l[1]=1;
        r[n]=n;
        for(int i=2; i<=n; i++) //这里如果用二重循环扫描可能会超时，因此用动态规划找每个矩形的前一个矩形对应的l[i]值（即每个矩形的前一个矩形左边第一个比它低的矩形的下标）
        {
            int t=i;
            while(t>1 && a[t-1]>=a[i])
                t=l[t-1];
            l[i]=t;
        }
        for(int i=n-1; i>=1; i--)   //每个矩形的前一个矩形对应的r[i]值（即每个矩形的后一个矩形右边第一个比它低的矩形的下标）
        {
            int t=i;
            while(t<n && a[t+1]>=a[i])
                t=r[t+1];
            r[i]=t;
        }
        LL ans=0;
        for(int i=1; i<=n; i++)
            ans=max(ans,(r[i]-l[i]+1)*a[i]);
        printf("%I64d\n",ans);
    }
    return 0;
}
