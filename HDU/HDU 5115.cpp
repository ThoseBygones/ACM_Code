#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <string>
using namespace std;

#define MAXN 205
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define LL long long
#define PII pair
#define MP make_pair
#define PB push_back

int a[MAXN];    //基础攻击力
int b[MAXN];    //给相邻两只狼加的buff
int dp[MAXN][MAXN]; //dp[i][j]表示杀死区间[i,j]内所有狼需要损失的最小血量

int main()
{
    int kase=1;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1; i<=n; i++)
            scanf("%d",&a[i]);
        for(int i=1; i<=n; i++)
            scanf("%d",&b[i]);
        a[0]=b[0]=a[n+1]=b[n+1]=0;
        for(int i=0; i<=n+1; i++)
            fill(dp[i],dp[i]+n+2,INF);
        for(int i=1; i<=n; i++) //初始化杀死每只狼需要损失的血量
            dp[i][i]=a[i]+b[i-1]+b[i+1];
        for(int l=2; l<=n; l++) //枚举区间长度
        {
            for(int i=1; i+l-1<=n; i++) //枚举区间起点
            {
                int j=i+l-1;
                dp[i][j]=min(dp[i+1][j]+a[i]+b[i-1]+b[j+1],dp[i][j-1]+a[j]+b[j+1]+b[i-1]);
                for(int k=i+1; k<j; k++)    //枚举区间中点
                    dp[i][j]=min(dp[i][j],dp[i][k-1]+dp[k+1][j]+a[k]+b[i-1]+b[j+1]);
            }
        }
        printf("Case #%d: %d\n",kase++,dp[1][n]);
    }
    return 0;
}
