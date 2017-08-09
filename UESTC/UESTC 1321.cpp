//区间dp
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 305
#define LL long long
#define MOD 1000000007

int n;
char s[MAXN];
LL dp[MAXN][MAXN];  //区间[i,j]之间存在多少合法的括号序列

bool match(int i,int j)
{
    if(s[i]=='(' && s[j]==')')
        return true;
    if(s[i]=='[' && s[j]==']')
        return true;
    return false;
}

LL dfs(int l,int r)
{
    if(dp[l][r]>=0)
        return dp[l][r];
    if(l>=r)
        return dp[l][r]=0;
    if(s[l]==')' || s[l]==']')
        return dp[l][r]=dfs(l+1,r);
    dp[l][r]=dfs(l+1,r);
    for(int m=l+1; m<=r; m++)
    {
        if(match(l,m))  //l,m为一对匹配括号
            dp[l][r]=(dp[l][r]+(dfs(l+1,m-1)+1)*(dfs(m+1,r)+1)%MOD)%MOD;
    }
    return dp[l][r];
}

int main()
{
    while(~scanf("%d",&n))
    {
        scanf("%s",s);
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
                dp[i][j]=-1;
        }
        LL ans=dfs(0,n-1);
        printf("%d\n",ans);
    }
    return 0;
}
