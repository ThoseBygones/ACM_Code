#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#define MAXN 1005
using namespace std;

int dp[MAXN][MAXN]; //a取前i个字符，b取前j个字符时的最长公共子序列
char a[MAXN],b[MAXN];

int main()
{
    int i,j,lenA,lenB;
    while(~scanf("%s%s",a,b))
    {
        memset(dp,0,sizeof(dp));
        lenA=strlen(a);
        lenB=strlen(b);
        for(i=1; i<=lenA; i++)
        {
            for(j=1; j<=lenB; j++)
            {
                if(a[i-1]==b[j-1])
                    dp[i][j]=max(dp[i-1][j-1]+1,0);
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        printf("%d\n",dp[lenA][lenB]);
    }
    return 0;
}
