#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int a[105],b[105];
int dp[105][105];   //消耗i点忍耐杀死j只怪以后能获得的最多经验值
int n,m,k,s;

//二维费用背包

int main()
{
    while(~scanf("%d%d%d%d",&n,&m,&k,&s))
    {
        memset(dp,0,sizeof(dp));
        for(int i=1; i<=k; i++)
            scanf("%d%d",&a[i],&b[i]);
        for(int i=1; i<=k; i++)
        {
            for(int j=b[i]; j<=m; j++)  //不能从m->b[i]，这样会对结果有影响
            {
                for(int l=1; l<=s; l++)
                    dp[j][l]=max(dp[j][l],dp[j-b[i]][l-1]+a[i]);
            }
        }
        if(dp[m][s]>=n) //这样的杀怪方式能够获得的经验值符合需要
        {
            for(int i=1; i<=m; i++)
            {
                if(dp[i][s]>=n) //忍耐度保留越多越好
                {
                    printf("%d\n",m-i);
                    break;
                }
            }
        }
        else
            puts("-1");
    }
    return 0;
}
