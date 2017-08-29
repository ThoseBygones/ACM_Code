//dp
#include <bits/stdc++.h>
using namespace std;

#define MAXN 5005
#define MAXM 100005

int a[MAXN];
int mod[8]; //a[i]%7==k时，dp[i][j]的最大值
int num[MAXM];   //a[i]==k时，dp[i][j]的最大值
int dp[MAXN][MAXN]; //dp[i][j]表示两组melody一组以第i个结束，一组以第j个结束

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%d",&a[i]);
    memset(dp,0,sizeof(dp));
    int ans=0;
    for(int i=0; i<=n; i++)
    {
        memset(mod,0,sizeof(mod));
        memset(num,0,sizeof(num));
        for(int j=1; j<=i; j++)
        {
            mod[a[j]%7]=max(mod[a[j]%7],dp[i][j]);
            num[a[j]]=max(num[a[j]],dp[i][j]);
        }
        for(int j=i+1; j<=n; j++)
        {
            dp[i][j]=max(dp[i][0]+1,dp[i][j]);  //新起一组melody重新找
            dp[i][j]=max(mod[a[j]%7]+1,dp[i][j]); //与mod7后的最大比较
            dp[i][j]=max(num[a[j]+1]+1,dp[i][j]); //与+1后的最大比较
            dp[i][j]=max(num[a[j]-1]+1,dp[i][j]); //与-1后的最大比较
            mod[a[j]%7]=max(mod[a[j]%7]+1,dp[i][j]);
            num[a[j]]=max(num[a[j]]+1,dp[i][j]);
            dp[j][i]=dp[i][j];
            ans=max(ans,dp[i][j]);
        }
    }
    printf("%d\n",ans);
    return 0;
}
