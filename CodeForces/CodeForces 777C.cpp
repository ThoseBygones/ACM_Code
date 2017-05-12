#include <bits/stdc++.h>
#define LL long long
using namespace std;

#define MAXN 100005
#define INF 0x3f3f3f3f

int n,m,k;
vector <int> table[MAXN];
vector <int> dp[MAXN];  //dp[i][j]=第j列到第i行前i+1行能形成的非递减数列，该数列起始元素的下标
int low[MAXN];  //到第i行前i+1行能形成的非递减数列，该数列起始元素的下标的最小值

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            int temp;
            scanf("%d",&temp);
            table[i].push_back(temp);
        }
    }
    for(int i=0; i<n; i++)
        dp[i].resize(m+1);  //申请空间
    /*for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
            dp[i][j]=0;
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
            dp[i][j]=i;
    }*/
    for(int j=0; j<m; j++)
    {
        for(int i=1; i<n; i++)
        {
            if(table[i-1][j]<=table[i][j])
                dp[i][j]=dp[i-1][j];
            else
                dp[i][j]=i;
        }
    }
    /*for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
            printf("%d ",dp[i][j]);
        puts("");
    }*/
    for(int i=0; i<n; i++)
    {
        int Min=dp[i][0];
        for(int j=0; j<m; j++)
            Min=min(Min,dp[i][j]);  //维护区间：每列的最小下标
        low[i]=Min;
    }
    scanf("%d",&k);
    int l,r;
    while(k--)
    {
        scanf("%d%d",&l,&r);
        l--;
        r--;
        if(low[r]<=l)
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}
