#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 1005

char mat[MAXN][MAXN];
int dp[MAXN][MAXN];
int h[MAXN];

bool cmp(int a,int b)
{
    return a>b;
}

int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=1; i<=n; i++)
            scanf("%s",mat[i]+1);
        memset(dp,0,sizeof(dp));
        int ans=0;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(mat[i][j]=='1')
                    dp[i][j]=dp[i-1][j]+1;
                else
                    dp[i][j]=0;
                h[j]=dp[i][j];
            }
            sort(h+1,h+m+1,cmp);
            for(int j=1; j<=m; j++)
            {
                for(int l=j; l<=m; l++)
                {
                    if(h[l]<h[j])
                    {
                        ans=max(ans,(l-1)*h[j]);
                        break;
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
