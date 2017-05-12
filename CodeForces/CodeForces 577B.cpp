#include <bits/stdc++.h>
#define LL long long
using namespace std;

#define MAXN 1000005
#define MAXM 1005

int a[MAXN];    //记录原始数组
int dp[MAXM][MAXM]; //前i个数中能得到的余数为j

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&a[i]);
        a[i]%=m;
    }
    if(n>m) //貌似是所谓的鸽巢原理？
    {
        puts("YES");
        return 0;
    }
    dp[0][0]=1;
    //for(int i=0; i<=n; i++)
    //    dp[i][0]=1;
    for(int i=1; i<=n; i++) //dp
    {
        for(int j=0; j<=m; j++)
            dp[i][j]=(dp[i-1][j] || dp[i-1][(j+a[i])%m]);
    }
    if(dp[n][m])
        puts("YES");
    else
        puts("NO");
    return 0;
}
