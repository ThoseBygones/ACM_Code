//概率dp求期望
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

#define MAXN 1005
#define EPS 1e-6

double p1[MAXN][MAXN];
double p2[MAXN][MAXN];
double p3[MAXN][MAXN];
double dp[MAXN][MAXN];  //dp[i][j]表示从(i,j)到终点(r,c)需要消耗的能量

int main()
{
    int r,c;
    while(~scanf("%d%d",&r,&c))
    {
        for(int i=1; i<=r; i++)
        {
            for(int j=1; j<=c; j++)
                scanf("%lf%lf%lf",&p1[i][j],&p2[i][j],&p3[i][j]);
        }
        dp[r][c]=0.0;
        for(int i=r; i>=1; i--)
        {
            for(int j=c; j>=1; j--)
            {
                if(i==r && j==c)
                    continue;
                if(fabs(1-p1[i][j])<EPS)    //p1[i][j]的概率不能为1，否则走到这点是死路一条，以后无法转移
                    continue;
                dp[i][j]=(p2[i][j]*dp[i][j+1]+p3[i][j]*dp[i+1][j]+2.0)/(1.0-p1[i][j]);
            }
        }
        printf("%.3f\n",dp[1][1]);
    }
    return 0;
}
