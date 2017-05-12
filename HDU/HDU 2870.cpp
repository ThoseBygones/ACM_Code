#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 1005

char mat[MAXN][MAXN];
int dp[MAXN][MAXN]; //以第i行为底能达到的最大高度
int l[MAXN],r[MAXN];
int n,m;
int Max;

void init()
{
    for(int j=1; j<=m; j++)
        dp[0][j]=0;
    memset(l,0,sizeof(l));
    memset(r,0,sizeof(r));
}

void solve(char ch)
{
    init();
    if(ch=='a')
    {
        for(int j=1; j<=m; j++)
        {
            for(int i=1; i<=n; i++)
            {
                if(mat[i][j]=='a' || mat[i][j]=='w' || mat[i][j]=='y' || mat[i][j]=='z')
                    dp[i][j]=dp[i-1][j]+1;
                else
                    dp[i][j]=0;
            }
        }
    }
    if(ch=='b')
    {
        for(int j=1; j<=m; j++)
        {
            for(int i=1; i<=n; i++)
            {
                if(mat[i][j]=='b' || mat[i][j]=='w' || mat[i][j]=='x' || mat[i][j]=='z')
                    dp[i][j]=dp[i-1][j]+1;
                else
                    dp[i][j]=0;
            }
        }
    }
    if(ch=='c')
    {
        for(int j=1; j<=m; j++)
        {
            for(int i=1; i<=n; i++)
            {
                if(mat[i][j]=='c' || mat[i][j]=='x' || mat[i][j]=='y' || mat[i][j]=='z')
                    dp[i][j]=dp[i-1][j]+1;
                else
                    dp[i][j]=0;
            }
        }
    }
    /*for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
            printf("%d ",dp[i][j]);
        puts("");
    }*/
    //puts("ok");
    //system("pause");
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
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=1; i<=n; i++)
            scanf("%s",mat[i]+1);
        /*for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
                printf("%c",mat[i][j]);
            puts("");
        }*/
        Max=0;
        solve('a');
        solve('b');
        solve('c');
        printf("%d\n",Max);
    }
    return 0;
}
