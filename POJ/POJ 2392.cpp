#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 405
#define MAXM 40005

int sum[MAXM];  //达到某个高度需要的木块数量
int dp[MAXM];   //某个高度是否能达到？
int k;

struct Blocks
{
    int h;
    int a;
    int c;
} b[MAXN];

bool cmp(Blocks x,Blocks y)
{
    return x.a<y.a;
}

int main()
{
    scanf("%d",&k);
    for(int i=1; i<=k; i++)
        scanf("%d%d%d",&b[i].h,&b[i].a,&b[i].c);
    sort(b+1,b+k+1,cmp);
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    int ans=0;
    for(int i=1; i<=k; i++)
    {
        memset(sum,0,sizeof(sum));
        for(int j=b[i].h; j<=b[i].a; j++)
        {
            if(!dp[j] && dp[j-b[i].h] && sum[j-b[i].h]+1<=b[i].c)  //这个高度之前未达到过且这个高度减去某个木块的高度之前能达到且该种木块数量没超过限制
            {
                dp[j]=1;    //这个高度被访问过
                sum[j]=sum[j-b[i].h]+1; //记录木块总数
                ans=max(ans,j); //求出最大高度
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
