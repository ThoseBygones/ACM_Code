#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005

int a[MAXN];
int dp[MAXN][105];   //dp[i][j]表示数值i，每次加上a[i]+j（同时更新i的值），最后使i>n所需的操作次数

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%d",&a[i]);
    for(int j=1; j<=100; j++)
    {
        for(int i=n; i>=1; i--)
        {
            if(i+a[i]+j>n)
                dp[i][j]=1;
            else
                dp[i][j]=dp[i+a[i]+j][j]+1;
        }
    }
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int p,k;
        scanf("%d%d",&p,&k);
        if(k>100)
        {
            int cnt=0;
            while(p<=n)
            {
                cnt++;
                p+=a[p]+k;
            }
            printf("%d\n",cnt);
        }
        else
            printf("%d\n",dp[p][k]);
    }
    return 0;
}
