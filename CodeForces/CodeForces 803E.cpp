#include <bits/stdc++.h>
using namespace std;

#define MAXN 1005

char s[MAXN];
bool dp[MAXN][MAXN*2];   //dp[i][j]表示前i场比赛胜场与负场差值（胜场-负场）为j-1000（0~2000表示-1000~1000）的情况能否存在，true表示存在，false表示不存在
char c[MAXN][MAXN];

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    scanf("%s",s+1);
    dp[0][n]=true;
    for(int i=1; i<=n; i++)
    {
        for(int j=-k+1; j<=k-1; j++)
        {
            if(dp[i-1][j+n])
            {
                if(s[i]=='W' || s[i]=='?')
                {
                    dp[i][j+n+1]=true;
                    c[i][j+n+1]='W';
                }
                if(s[i]=='L' || s[i]=='?')
                {
                    dp[i][j+n-1]=true;
                    c[i][j+n-1]='L';
                }
                if(s[i]=='D' || s[i]=='?')
                {
                    dp[i][j+n]=true;
                    c[i][j+n]='D';
                }
            }
        }
    }
    if(dp[n][-k+n] || dp[n][k+n])
    {
        int p=dp[n][k+n]?k+n:-k+n;
        string ans;
        for(int i=n; i>=1; i--)
        {
            ans=c[i][p]+ans;
            if(c[i][p]=='W')
                p--;
            if(c[i][p]=='L')
                p++;
        }
        cout << ans <<endl;
    }
    else
        puts("NO");
    return 0;
}
