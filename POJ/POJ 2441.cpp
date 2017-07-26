#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 22

int like[MAXN][MAXN];
int dp[2][1<<MAXN]; //滚动数组，dp[i][S]表示前i只牛已经使用掉牧场集合S时的总方案数

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++)
    {
        int num;
        scanf("%d",&num);
        while(num--)
        {
            int j;
            scanf("%d",&j);
            like[i][j]=1;
        }
    }

    dp[0][0]=1;
    for(int i=1; i<=n; i++) //枚举所有牛
    {
        memset(dp[i&1],0,sizeof(dp[i&1]));
        for(int j=0; j<(1<<m); j++) //枚举集合状况
        {
            if(dp[(i-1)&1][j])
            {
                for(int k=1; k<=m; k++)
                {
                    if(like[i][k] && !(j&(1<<(k-1))))
                        dp[i&1][j|(1<<(k-1))]+=dp[(i-1)&1][j];
                }
            }
        }
    }
    int ans=0;
    for(int i=0; i<(1<<m); i++)
        ans+=dp[n&1][i];
    printf("%d\n",ans);
    return 0;
}

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 22

int like[MAXN][MAXN];
int dp[2][1<<MAXN]; //滚动数组，dp[i][S]表示前i只牛已经使用掉牧场集合S时的总方案数

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++)
    {
        int num;
        scanf("%d",&num);
        for(int j=1; j<=num; j++)
            scanf("%d",&like[i][j]);
    }

    dp[0][0]=1;
    for(int i=1; i<=n; i++) //枚举所有牛
    {
        memset(dp[i&1],0,sizeof(dp[i&1]));
        for(int j=0; j<(1<<m); j++) //枚举集合状况
        {
            if(dp[(i-1)&1][j])
            {
                for(int k=1; k<=m; k++)
                {
                    if(like[i][k] && !(j&(1<<(like[i][k]-1))))
                        dp[i&1][j|(1<<(like[i][k]-1))]+=dp[(i-1)&1][j];
                }
            }
        }
        //memset(dp[(i-1)&1],0,sizeof(dp[(i-1)&1]));
    }
    int ans=0;
    for(int i=0; i<(1<<m); i++)
        ans+=dp[n&1][i];
    printf("%d\n",ans);
    return 0;
}
