//概率dp求期望
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 1005

double dp[MAXN][MAXN]; //dp[i][j]表示已经在j个系统里找到了i个bug，达到目标状态dp[n][s]（即s个系统里找到n个bug）还需要的天数的期望

int main()
{
    int n,s;
    scanf("%d%d",&n,&s);
    dp[n][s]=0;
    for(int i=n; i>=0; i--)
    {
        for(int j=s; j>=0; j--)
        {
            if(i==n && j==s)
                continue;
            //dp[i][j]，发现一个bug属于已有的分类和系统。概率为(i/n)*(j/s)
            //dp[i][j+1]，发现一个bug属于已有的分类和一个新的系统。概率为(i/n)*(1-j/s);
            //dp[i+1][j]，发现一个bug属于一个新的分类已有的系统。概率为(1-i/n)*(j/s);
            //dp[i+1][j+1]，发现一个bug属于一个新的分类和一个新的系统。概率为(1-i/n)*(1-j/s);
            dp[i][j]=(i*(s-j)*dp[i][j+1]+(n-i)*j*dp[i+1][j]+(n-i)*(s-j)*dp[i+1][j+1]+n*s)/(1.0*(n*s-i*j));  //化简后得到
        }
    }
    printf("%.4f\n",dp[0][0]);
}
