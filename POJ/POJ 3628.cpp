#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define INF 0x3f3f3f3f

int v[25];
int dp[10000005];   //������ʵӦ����20*1e6�ģ�����������MLE������ֻ�ܿ�СһЩ��������������

int main()
{
    int n,s;
    while(~scanf("%d%d",&n,&s))
    {
        int sum=0;
        memset(v,0,sizeof(v));
        memset(dp,0,sizeof(dp));
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&v[i]);
            sum+=v[i];
        }

        for(int i=1; i<=n; i++)
        {
            for(int j=sum; j>=v[i]; j--)
                dp[j]=max(dp[j],dp[j-v[i]]+v[i]);
        }
        int ans=INF;
        for(int i=1; i<=sum; i++)
        {
            if(dp[i]>=s)
                ans=min(ans,dp[i]-s);
        }
        printf("%d\n",ans);
    }
    return 0;
}
