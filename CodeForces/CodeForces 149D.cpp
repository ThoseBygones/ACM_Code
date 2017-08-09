#include <bits/stdc++.h>
using namespace std;

#define MAXN 705
#define LL long long
#define MOD 1000000007

char s[MAXN];
LL num[MAXN];  //记录左括号的下标
LL match[MAXN];    //match[i]表示编号为i的右括号匹配的左括号的编号
LL dp[MAXN][MAXN][3][3];    //dp[i][j][x][y]表示区间[i,j]左端点i涂x色，右端点j涂y色（0表示不涂色，1表示涂红色，2表示涂蓝色）

void dfs(int l,int r)
{
    if(l+1==r)  //最内层的括号对
    {
        dp[l][r][0][1]=1;
        dp[l][r][1][0]=1;
        dp[l][r][0][2]=1;
        dp[l][r][2][0]=1;
        return ;
    }
    else if(match[l]==r)    //外层的括号能匹配上的
    {
        dfs(l+1,r-1);
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                if(j!=1)
                    dp[l][r][0][1]=(dp[l][r][0][1]+dp[l+1][r-1][i][j])%MOD;
                if(i!=1)
                    dp[l][r][1][0]=(dp[l][r][1][0]+dp[l+1][r-1][i][j])%MOD;
                if(j!=2)
                    dp[l][r][0][2]=(dp[l][r][0][2]+dp[l+1][r-1][i][j])%MOD;
                if(i!=2)
                    dp[l][r][2][0]=(dp[l][r][2][0]+dp[l+1][r-1][i][j])%MOD;
            }
        }
    }
    else    //括号背靠背
    {
        dfs(l,match[l]);
        dfs(match[l]+1,r);
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                for(int x=0; x<3; x++)
                {
                    for(int y=0; y<3; y++)
                    {
                        if(!((x==1 && y==1) || (x==2 && y==2)))
                            dp[l][r][i][j]=(dp[l][r][i][j]+(dp[l][match[l]][i][x]*dp[match[l]+1][r][y][j])%MOD)%MOD;    //基本乘法原理
                    }
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> s;
    int len=strlen(s);
    int cnt=0;
    for(int i=0; i<len; i++)
    {
        if(s[i]=='(')
            num[cnt++]=i;
        else
            match[num[--cnt]]=i;
    }

    dfs(0,len-1);

    LL ans=0;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
            ans=(ans+dp[0][len-1][i][j])%MOD;
    }
    cout << ans << endl;
    return 0;
}
