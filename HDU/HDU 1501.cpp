//记忆化搜索... 我竟然没想到...
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 205

char a[MAXN],b[MAXN];
char c[MAXN*2];
int dp[MAXN][MAXN];

int dfs(int i,int j,int k)  //i--a串的下标，j--b串的下标，k--c串的下标
{
    if(dp[i][j])
        return dp[i][j];
    if(c[k]=='\0')
        return 1;   //表示访问过改下标且能完成所有匹配
    dp[i][j]=-1;    //表示该下标被访问过但是没有跟任何一个串匹配成功
    if(a[i]==c[k])
        dp[i][j]=dfs(i+1,j,k+1);
    if(b[j]==c[k] && dp[i][j]!=1)
        dp[i][j]=dfs(i,j+1,k+1);
    //printf("%d %d %d\n",i,j,dp[i][j]);
    return dp[i][j];
}

int main()
{
    int t;
    int kase=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s%s%s",a,b,c);
        memset(dp,0,sizeof(dp));    //表示该下标没有被访问过
        if(dfs(0,0,0)==1)
            printf("Data set %d: yes\n",kase++);
        else
            printf("Data set %d: no\n",kase++);
    }
    return 0;
}
