//区间dp
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 2005

char s[MAXN];
int cost[30];
int dp[MAXN][MAXN];

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    scanf("%s",s);
    for(int i=0; i<n; i++)
    {
        char alp[2];
        int add,del;
        scanf("%s%d%d",alp,&add,&del);
        cost[alp[0]-'a']=min(add,del);
    }
    for(int i=m-1; i>=0; i--)   //i从末尾趋近于首
    {
        for(int j=i+1; j<m; j++)    //j从首趋近于末尾
        {
            if(s[i]==s[j])  //首尾相同，即满足要求不必动，相当于把首尾都删除
                dp[i][j]=dp[i+1][j-1];
            else    //首尾不同，则要么删除首字母，或在末尾添加与首字母相同的字母（其实删除或添加都一样的，使首尾相同而已）
                dp[i][j]=min(dp[i+1][j]+cost[s[i]-'a'],dp[i][j-1]+cost[s[j]-'a']);
        }
    }
    printf("%d\n",dp[0][m-1]);
    return 0;
}
