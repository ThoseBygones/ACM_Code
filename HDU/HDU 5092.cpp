#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <vector>
#include <map>
using namespace std;

#define MAXN 110
#define INF 0x3f3f3f3f
#define PII pair
#define MP make_pair
#define LL long long
#define PB push_back
#define MOD 1000000007

int a[MAXN][MAXN];
int path[MAXN][MAXN];
int dp[MAXN][MAXN]; //路径走到第i行第j列所能得到的最大总和

void getPath(int cnt,int index)
{
    if(!cnt)
        return ;
    if(path[cnt][index]==-1)
    {
        printf("%d ",index);
        return ;
    }
    else
    {
        getPath(cnt-1,path[cnt][index]);
        printf("%d ",index);
    }
}

int main()
{
    int kase=1;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        memset(path,-1,sizeof(path));
        for(int i=0; i<MAXN; i++)
            {
                for(int j=0; j<MAXN; j++)
                    dp[i][j]=INF;
            }
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
                scanf("%d",&a[i][j]);
        }
        for(int j=1; j<=m; j++)
            dp[1][j]=a[1][j];
        for(int i=2; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(j!=1 && dp[i][j]>=dp[i-1][j-1]+a[i][j])
                {
                    dp[i][j]=dp[i-1][j-1]+a[i][j];
                    path[i][j]=j-1;
                }
                if(dp[i][j]>=dp[i-1][j]+a[i][j])
                {
                    dp[i][j]=dp[i-1][j]+a[i][j];
                    path[i][j]=j;
                }
                if(j!=m && dp[i][j]>=dp[i-1][j+1]+a[i][j])
                {
                    dp[i][j]=dp[i-1][j+1]+a[i][j];
                    path[i][j]=j+1;
                }
            }
        }
        printf("Case %d\n",kase++);
        int Min=INF;
        int p=-1;
        for(int j=m; j>=1; j--)
        {
            if(Min>dp[n][j])
            {
                Min=dp[n][j];
                p=j;
            }
        }
        getPath(n-1,path[n][p]);
        printf("%d\n",p);
    }
    return 0;
}
