#include <bits/stdc++.h>
using namespace std;

#define MAXN 20
#define MAXM 110
#define INF 0x3f3f3f3f

int l[MAXN];
int r[MAXN];
int dp[MAXN][2];    //dp[i][0]表示第i层选择左边楼梯的最小花费，dp[i][1]表示第i层选择右边楼梯的最小花费

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    memset(l,0,sizeof(l));
    memset(r,0,sizeof(r));
    for(int i=0; i<n; i++)
        dp[i][0]=dp[i][1]=INF;
    for(int i=n-1; i>=0; i--)
    {
        char s[MAXM];
        scanf("%s",s);
        for(int j=0; j<m+2; j++)
        {
            if(s[j]=='1')
            {
                l[i]=j;
                break;
            }
        }
        for(int j=m+1; j>=0; j--)
        {
            if(s[j]=='1')
            {
                r[i]=j;
                break;
            }
        }
    }
    for(int i=n-1; i>=0; i--)
    {
        if(l[i]==0 && r[i]==0)
            n--;
        else
            break;
    }
    if(n==1)
        printf("%d\n",r[0]);
    else
    {
        dp[0][0]=2*r[0]+1;
        dp[0][1]=m+1+1;
        for(int i=1; i<n-1; i++)
        {
            if(l[i]==0 && r[i]==0)
            {
                dp[i][0]=dp[i-1][0]+1;
                dp[i][1]=dp[i-1][1]+1;
            }
            else
            {
                dp[i][0]=min(dp[i-1][0]+2*r[i],dp[i-1][1]+m+1)+1;
                dp[i][1]=min(dp[i-1][0]+m+1,dp[i-1][1]+2*(m-l[i]+1))+1;
            }
        }
        printf("%d\n",min(dp[n-2][0]+r[n-1],dp[n-2][1]+m-l[n-1]+1));
    }
    return 0;
}
