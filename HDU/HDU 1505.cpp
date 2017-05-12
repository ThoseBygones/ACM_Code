#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 1005

char city[MAXN][MAXN];
int dp[MAXN][MAXN]; //以第i行为底能达到的最大高度
int l[MAXN],r[MAXN];
int n,m;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int Max=0;
        scanf("%d%d",&n,&m);
        getchar();
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                cin >> city[i][j];
            }
        }
        for(int j=1; j<=m; j++)
            dp[0][j]=0;
        for(int j=1; j<=m; j++)
        {
            for(int i=1; i<=n; i++)
            {
                if(city[i][j]=='F')
                    dp[i][j]=dp[i-1][j]+1;
                else
                    dp[i][j]=0;
            }
        }
        for(int i=1; i<=n; i++)
        {
            l[1]=1;
            r[m]=m;
            int t;
            for(int j=2; j<=m; j++)
            {
                if(dp[i][j]!=0)
                {
                    t=j;
                    while(t>1 && dp[i][j]<=dp[i][t-1])
                        t=l[t-1];
                    l[j]=t;
                }
            }
            //cout << "ok" << endl;
            for(int j=m-1; j>=1; j--)
            {
                if(dp[i][j]!=0)
                {
                    t=j;
                    while(t<m && dp[i][j]<=dp[i][t+1])
                        t=r[t+1];
                    r[j]=t;
                }
            }
            for(int j=1; j<=m; j++)
                Max=max(Max,(r[j]-l[j]+1)*dp[i][j]);
        }
        printf("%d\n",Max*3);
    }
    return 0;
}
