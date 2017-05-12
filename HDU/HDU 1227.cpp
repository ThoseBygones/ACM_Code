#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

#define MAXN 205
#define MAXM 35
#define INF 0x3f3f3f3f

int dis[MAXN];    //position of restaurants
int cost[MAXN][MAXN];   //The sum cost building a depot between restaurant i and j
int dp[MAXN][MAXN]; //Building i depots for first j restaurants

int main()
{
    int n,k;
    int kase=1;
    while(~scanf("%d%d",&n,&k))
    {
        if(n==0 && k==0)
            break;
        memset(dis,0,sizeof(dis));
        memset(cost,0,sizeof(cost));
        //memset(dp,0x3f,sizeof(dp));
        for(int i=1; i<=n; i++)
            scanf("%d",&dis[i]);
        for(int i=1; i<=n; i++)
        {
            for(int j=i; j<=n; j++)
            {
                int mid=(i+j)/2;
                for(int h=i; h<=j; h++)
                    cost[i][j]+=abs(dis[mid]-dis[h]);
            }
        }
        for(int j=1; j<=n; j++)
            dp[1][j]=cost[1][j];
        for(int i=2; i<=k; i++)
        {
            for(int j=i; j<=n; j++)
            {
                dp[i][j]=INF;
                //if(i==j)
                //{
                //    dp[i][j]=0;
                //    continue;
                //}
                for(int h=i-1; h<=j-1; h++)
                    dp[i][j]=min(dp[i][j],dp[i-1][h]+cost[h+1][j]);
            }
        }
        printf("Chain %d\nTotal distance sum = %d\n\n",kase++,dp[k][n]);
    }
    return 0;
}


//记忆化搜索
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <ctype.h>
#include <set>
#include <map>
#include <vector>
using namespace std;

int n,k,a[210],i,j,mid,num;
int m[210][210],dp[210][35];

int minn(int x,int y)
{
    return x<=y?x:y;
}

int dfs(int x,int y)
{
    int i,j;
    if(x == 0)
    {
        return 0;
    }

    if(y == 0)
    {
        return dp[209][34];
    }

    if(dp[x][y] != dp[209][34])
    {
        return dp[x][y];
    }

    if(x == y)
    {
        dp[x][y] = 0;
        return 0;
    }

    for(i = y-1; i < n; ++i)
    {
        dp[x][y] = minn(dp[x][y],dfs(i,y-1)+m[i+1][x]);
    }

    return dp[x][y];
}

int main()
{
    scanf("%d%d",&n,&k);
    num = 0;
    while(n != 0 && k != 0)
    {
        memset(m,0,sizeof(m));
        memset(dp,0x7f,sizeof(dp));
        ++num;
        for(int i = 1; i <= n; ++i)
        {
            scanf("%d",&a[i]);
        }

        for(int i = 1; i <= n; ++i)
        {
            for(int v = i; v <= n; ++v)
            {
                mid = (i+v)/2;
                for(int j = i; j <= v; ++j)
                {
                    m[i][v] += abs(a[j] - a[mid]);
                }
            }
        }

        for(int i = 1; i <= n; ++i)
        {
            dp[i][1] = m[1][i];
        }

        printf("Chain %dnTotal distance sum = %dnn",num,dfs(n,k));
        scanf("%d%d",&n,&k);
    }
    return 0;
}



//滚动数组优化的递推
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <ctype.h>
#include <set>
#include <map>
#include <vector>
using namespace std;

int n,k,a[210],i,j,mid,num;
int m[210][210],dp[210],pre[210];

int minn(int x,int y)
{
    return x<=y?x:y;
}

int main()
{
    scanf("%d%d",&n,&k);
    num = 0;
    while(n != 0 && k != 0)
    {
        memset(m,0,sizeof(m));
        memset(dp,0x7f,sizeof(dp));
        ++num;
        memset(pre,0,sizeof(pre));
        for(int i = 1; i <= n; ++i)
        {
            scanf("%d",&a[i]);
        }

        for(int i = 1; i <= n; ++i)
        {
            for(int v = i; v <= n; ++v)
            {
                mid = (i+v)/2;
                for(int j = i; j <= v; ++j)
                {
                    m[i][v] += abs(a[j] - a[mid]);
                }
            }
        }

        for(int i = 1; i <= n; ++i)
        {
            pre[i] = m[1][i];
            dp[i] = m[1][i];
        }

        for(int i = 2; i <= k; ++i)
        {
            for(int j = i; j <= n; ++j)
            {
                if(i == j)
                {
                    dp[i] = 0;
                    continue;
                }
                for(int v = i - 1; v < j; ++v)
                {
                    dp[j] = minn(dp[j],pre[v]+m[v+1][j]);
                }
            }
            for(int j = 1; j <= n; ++j)
            {
                pre[j] = dp[j];
            }
        }

        printf("Chain %dnTotal distance sum = %dnn",num,dp[n]);
        scanf("%d%d",&n,&k);
    }
    return 0;
}
