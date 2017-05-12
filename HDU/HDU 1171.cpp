#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 5005
#define MAXM 100010

int v[MAXN];
int dp[MAXM];

int main()
{
    int n;
    while(~scanf("%d",&n)&&n>0)
    {
        memset(v,0,sizeof(v));
        memset(dp,0,sizeof(dp));
        int num=0;
        int sum=0;
        for(int i=1; i<=n; i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            while(b--)
            {
                v[num++]=a;
                sum+=a;
            }
        }
        for(int i=0; i<num; i++)
        {
            for(int j=sum/2; j>=v[i]; j--)
                dp[j]=max(dp[j],dp[j-v[i]]+v[i]);
        }
        printf("%d %d\n",sum-dp[sum/2],dp[sum/2]);
    }
    return 0;
}
