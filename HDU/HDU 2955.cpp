#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 105
#define MAXM 10010

int m[MAXN];
double p[MAXN]; //被抓的可能性
double dp[MAXM];    //抢某个银行不被抓的最大可能性

int main()
{
    int t,n;
    double pos;
    scanf("%d",&t);
    while(t--)
    {
        int sum=0;
        scanf("%lf%d",&pos,&n);
        memset(dp,0,sizeof(dp));
        for(int i=0; i<n; i++)
        {
            scanf("%d%lf",&m[i],&p[i]);
            sum+=m[i];
        }
        dp[0]=1.0;
        for(int i=0; i<n; i++)
        {
            for(int j=sum; j>=m[i]; j--)
                dp[j]=max(dp[j],dp[j-m[i]]*(1.0-p[i])); //求出不被抓的可能性
        }
        for(int i=sum; i>=0; i--)
        {
            if(dp[i]>=(1.0-pos))    //根据不被抓最大可能性求出抢银行能抢到钱数的最大值
            {
                printf("%d\n",i);
                break;
            }
        }
    }
    return 0;
}
