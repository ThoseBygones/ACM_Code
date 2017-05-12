#include <bits/stdc++.h>
using namespace std;

#define MAXN 105
#define INF 0x3f3f3f3f

int n,m;
char s[MAXN];
int a[MAXN][MAXN];
int dp[MAXN][5];    //dp[i][k]第k类数字在第i行更改光标所需要移动的最小步数

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++)
    {
        scanf("%s",s+1);
        for(int j=1; j<=m; j++)
        {
            if(s[j]>='0' && s[j]<='9')
                a[i][j]=1;
            if(s[j]>='a' && s[j]<='z')
                a[i][j]=2;
            if(s[j]=='#' || s[j]=='*' || s[j]=='&')
                a[i][j]=3;
        }
    }
    for(int i=1; i<=n; i++)
    {
        for(int k=1; k<=3; k++)
            dp[i][k]=INF/3;
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
            dp[i][a[i][j]]=min(dp[i][a[i][j]],j-1);
        for(int j=m; j>=1; j--)
            dp[i][a[i][j]]=min(dp[i][a[i][j]],m-j+1);
    }
    int ans=INF;
    /*for(int i=1; i<=n; i++)
    {
        for(int k=1; k<=3; k++)
            cout << dp[i][k] << " ";
        cout << endl;
    }*/
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            for(int k=1; k<=n; k++)
            {
                if(i!=j && i!=k && j!=k)
                    ans=min(ans,dp[i][1]+dp[j][2]+dp[k][3]);
                //cout << "@" << ans << endl;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
