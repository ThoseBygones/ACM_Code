//单调队列优化多重背包
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int a[105],c[105];
bool dp[100005];
int q[100005];

int main()
{
    int n,m;
    while(~scanf("%d %d",&n,&m))
    {
        if(n==0 && m==0)
            break;
        //n是种数，m是价值的最大值
        for(int i = 0; i<n; i++)
            scanf("%d",&a[i]); //a是val
        for(int i = 0; i<n; i++)
            scanf("%d",&c[i]); //c是每种val的个数
        for(int i = 1; i<=m; i++)
            dp[i] = false;
        dp[0] = true;
        int ans = 0;
        for(int i = 0; i<n; i++)
        {
            int mx = a[i]*c[i];
            if(c[i]==1)
            {
                for(int j = m; j>=a[i]; j--)
                {
                    if(dp[j-a[i]])
                        dp[j] = true;
                }
            }
            else if(mx>=m)
            {
                for(int j = a[i]; j<=m; j++)
                {
                    if(dp[j-a[i]])
                        dp[j] = true;
                }
            }
            else
            {
                for(int md = 0; md<a[i]; md++)
                {
                    int head = 0,tail = -1;
                    for(int j = md; j<=m; j+=a[i])
                    {
                        while(head<=tail&&j-q[head]>mx)
                            head++;
                        if(dp[j])
                            q[++tail] = j;
                        else if(head<=tail)
                            dp[j] = true;
                    }
                }
            }
        }
        for(int i = 1; i<=m; i++)
        {
            if(dp[i])
                ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}


#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int dp[100010];    //dp[i][j]：用前i种硬币凑成j时第i种硬币最多能剩余多少个
int a[105];
int c[105];

int main()
{
    int n, m;
    while(~scanf("%d%d",&n,&m))
    {
        if(n==0 && m==0)
            break;
        memset(dp, -1, sizeof(dp));
        dp[0] = 0;
        for (int i = 0; i < n; ++i)
            scanf("%d",&a[i]);
        for (int i = 0; i < n; ++i)
            scanf("%d",&c[i]);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j <= m; ++j)
            {
                if (dp[j] >= 0)
                {
                    dp[j] = c[i];
                }
                else if (j < a[i] || dp[j - a[i]] <= 0)
                //用一个就超出，不能用；连凑比j小的数的时候都用完了，此时更加用完了
                {
                    dp[j] = -1;
                }
                else
                {
                    dp[j] = dp[j - a[i]] - 1;   //用上了一个第i个硬币
                }
            }
        }
        //int ans = count_if(dp + 1, dp + 1 + m, bind2nd(greater_equal<int>(), 0));    //总额0不算在答案内
        int ans=0;
        for(int i=1; i<=m; i++)
        {
            if(dp[i]!=-1)
                ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}


//网上某神犇不明觉厉的代码
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int dp[100005];
int sum[100005];
int v[105],c[105];

int main()
{
    int i,j,k,n,m;
    while(~scanf("%d%d",&n,&m),n+m)
    {
        for(i = 1; i<=n; i++)
            scanf("%d",&v[i]);
        for(i = 1; i<=n; i++)
            scanf("%d",&c[i]);
        memset(dp,0,sizeof(dp));
        dp[0] = 1;
        int ans = 0;
        for(i=1; i<=n; i++)
        {
            memset(sum,0,sizeof(sum));
            for(j = v[i]; j<=m; j++)
            {
                if(!dp[j] && dp[j-v[i]] && sum[j-v[i]]<c[i])
                {
                    dp[j] = 1;
                    sum[j] = sum[j-v[i]]+1;
                    ans++;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

