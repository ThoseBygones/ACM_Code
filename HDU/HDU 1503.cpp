//LCS+路径记录输出
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 105

char a[MAXN],b[MAXN];
int dp[MAXN][MAXN];
int mark[MAXN][MAXN];   //标记数组

void Print(int x,int y)
{
    if(x || y)
    {
        if(mark[x][y]==0)
        {
            Print(x-1,y-1);
            printf("%c",a[x-1]);
        }
        if(mark[x][y]==1)
        {
            Print(x-1,y);
            printf("%c",a[x-1]);
        }
        if(mark[x][y]==-1)
        {
            Print(x,y-1);
            printf("%c",b[y-1]);
        }
    }
}

int main()
{
    while(~scanf("%s%s",a,b))
    {
        memset(dp,0,sizeof(dp));
        memset(mark,0,sizeof(mark));
        int len1=strlen(a);
        int len2=strlen(b);
        for(int i=1; i<=len1; i++)
            mark[i][0]=1;
        for(int j=1; j<=len2; j++)
            mark[0][j]=-1;
        for(int i=1; i<=len1; i++)
        {
            for(int j=1; j<=len2; j++)
            {
                if(a[i-1]==b[j-1])
                {
                    dp[i][j]=dp[i-1][j-1]+1;
                    mark[i][j]=0;
                }
                else if(dp[i-1][j]>dp[i][j-1])
                {
                    dp[i][j]=dp[i-1][j];
                    mark[i][j]=1;
                }
                else
                {
                    dp[i][j]=dp[i][j-1];
                    mark[i][j]=-1;
                }
            }
        }
        Print(len1,len2);
        puts("");
    }
    return 0;
}
