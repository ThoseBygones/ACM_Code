//区间dp
#include <bits/stdc++.h>
using namespace std;

#define MAXN 5005

char s[MAXN];
int cnt[MAXN];
int dp[MAXN][MAXN]; //区间[i,j]所组成的字符串的级数

int main()
{
    scanf("%s",s);
    int n=strlen(s);
    memset(cnt,0,sizeof(cnt));
    memset(dp,0,sizeof(dp));
    for(int i=0; i<n; i++)  //预处理级数为1的回文串
    {
        cnt[1]++;
        dp[i][i]=1;
    }
    for(int i=1; i<n; i++)  //预处理级数为2的回文串
    {
        if(s[i-1]==s[i])
        {
            cnt[1]++;
            cnt[2]++;
            dp[i-1][i]=2;
        }
    }
    for(int l=3; l<=n; l++)  //枚举长度
    {
        for(int i=0; i+l-1<n; i++)    //枚举左端点
        {
            int j=i+l-1;
            if(s[i]==s[j] && dp[i+1][j-1])
            {
                int k=(i+j)>>1;
                dp[i][j]=(l&1?dp[i][k-1]:dp[i][k])+1;   //长度是奇数还是偶数，分情况求出左右回文部分
                for(int p=1; p<=dp[i][j]; p++)
                    cnt[p]++;
            }
        }
    }
    for(int i=1; i<n; i++)
        printf("%d ",cnt[i]);
    printf("%d\n",cnt[n]);
    return 0;
}
