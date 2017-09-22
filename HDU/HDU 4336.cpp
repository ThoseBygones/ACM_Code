//状态压缩dp+概率dp求期望
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

double p[25];
double dp[1<<21];  //dp[i]表示状态i到达集齐所有卡片的状态还需要购买零食数量的期望

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        double sum=0.0;
        for(int i=1; i<=n; i++)
        {
            scanf("%lf",&p[i]);
            sum+=p[i];
        }
        p[0]=1.0-sum;   //没有卡片的概率
        dp[(1<<n)-1]=0.0;   //全部收集齐的状态
        for(int i=(1<<n)-2; i>=0; i--)
        {
            double need=0.0; //收集到有用卡牌的概率
            sum=0.0;
            for(int j=1; j<=n; j++)
            {
                if(i&(1<<(j-1)))    //如果该卡片还未被收集
                    need+=p[j]; //累计收集到还未收集到卡片的概率
                else
                    sum+=p[j]*dp[i|(1<<(j-1))]; //累计收集到无用卡片的期望（概率*转移前状态的期望）
            }
            dp[i]=(sum+1)/(1.0-p[0]-need);  //得到转移后的期望
        }
        printf("%.5f\n",dp[0]);
    }
    return 0;
}
