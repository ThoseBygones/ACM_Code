#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 105

char a[MAXN];
char b[MAXN];
int dp[MAXN][MAXN]; //dp[i][j]：字符串A的第i到j段变成字符串B的第i到j段最少需要多少次操作
int ans[MAXN];

int main()
{
    while(~scanf("%s%s",a,b))
    {
        int len=strlen(a);
        memset(dp,0,sizeof(dp));
        memset(ans,0,sizeof(ans));
        for(int i=0; i<len; i++)
            dp[i][i]=1;
        for(int j=0; j<len; j++)    //j从头指向尾（区间右边界指针）
        {
            for(int i=j-1; i>=0; i--) //i从尾指向头（区间左边界指针）
            {
                dp[i][j]=dp[i+1][j]+1;  //先一个一个刷
                for(int k=i+1; k<=j; k++)    //枚举k为区间中间点的所有状况
                {
                    if(b[i]==b[k])
                        dp[i][j]=min(dp[i][j],dp[i+1][k]+dp[k+1][j]);   //寻找最优解
                }
            }
        }
        for(int i=0; i<len; i++)
            ans[i]=dp[0][i];    //按照定义初始化
        for(int i=0; i<len; i++)
        {
            if(a[i]==b[i])
            {
                if(!i)
                    ans[i]=0;
                else
                    ans[i]=ans[i-1];    //对应位置相等，可以不刷
            }
            else
            {
                for(int j=0; j<i; j++)
                    ans[i]=min(ans[i],ans[j]+dp[j+1][i]); //寻找区间中间的点j来分割区间
            }
        }
        printf("%d\n",ans[len-1]);
    }
    return 0;
}
