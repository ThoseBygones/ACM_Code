//概率dp求概率
#include <bits/stdc++.h>
using namespace std;

#define MAXN 1005

double dp[MAXN][MAXN];  //dp[i][j]表示轮到公主抓老鼠的时候，袋里还有i只白鼠和j只黑鼠时，公主最终获得胜利的概率

int main()
{
    int w,b;
    scanf("%d%d",&w,&b);
    for(int i=0; i<=b; i++)
        dp[0][i]=0.0;   //袋里没有白鼠（不管有没有黑鼠）都一定是龙赢
    for(int i=1; i<=w; i++)
        dp[i][0]=1.0;   //袋里全是白鼠则一定是公主赢
    for(int i=1; i<=w; i++)
    {
        for(int j=1; j<=b; j++)
        {
            dp[i][j]+=(double)i/(double)(i+j);  //直接抓到白鼠，公主赢
            if(j>=3)    //黑的至少还剩3只时
            {
                //公主抓出一只黑鼠，龙也抓出一只黑鼠，吓跑一只黑鼠
                dp[i][j]+=(double)j/(double)(i+j)*(double)(j-1)/(double)(i+j-1)*(double)(j-2)/(double)(i+j-2)*dp[i][j-3];
            }
            if(j>=2)    //黑的至少还剩2只时
            {
                //公主抓出一只黑鼠，龙也抓出一只黑鼠，吓跑一只白鼠
                dp[i][j]+=(double)j/(double)(i+j)*(double)(j-1)/(double)(i+j-1)*(double)i/(double)(i-1+j-1)*dp[i-1][j-2];
            }
        }
    }
    printf("%.10f\n",dp[w][b]);
    return 0;
}
