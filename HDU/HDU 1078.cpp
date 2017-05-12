//¼ÇÒä»¯ËÑË÷
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAXN 105

int a[MAXN][MAXN];
int dp[MAXN][MAXN];
int dx[]= {-1,0,0,1};
int dy[]= {0,-1,1,0};
int n,k;

bool inMap(int x,int y)
{
    if(x>=1 && x<=n && y>=1 && y<=n)
        return true;
    return false;
}

int dfs(int x,int y)
{
    int sum=0;
    if(!dp[x][y])
    {
        for(int i=1; i<=k; i++)
        {
            for(int j=0; j<4; j++)
            {
                int nx=x+dx[j]*i;
                int ny=y+dy[j]*i;
                if(inMap(nx,ny) && a[nx][ny]>a[x][y])
                    sum=max(sum,dfs(nx,ny));
            }
        }
        dp[x][y]=sum+a[x][y];
    }
    return dp[x][y];
}

int main()
{
    while(~scanf("%d%d",&n,&k))
    {
        if(n==-1 && k==-1)
            break;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
                scanf("%d",&a[i][j]);
        }
        memset(dp,0,sizeof(dp));
        printf("%d\n",dfs(1,1));
    }
    return 0;
}
