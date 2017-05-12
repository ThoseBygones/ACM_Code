#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 105

int a[MAXN],b[MAXN];
int dp[MAXN][MAXN]; //表示第i秒攻击后剩余j魔法值时消耗的boss的血量

int main()
{
    int n,t,q;
    while(~scanf("%d%d%d",&n,&t,&q))
    {
        if(n==0 && t==0 && q==0)
            break;
        for(int i=1; i<=n; i++)
            scanf("%d%d",&a[i],&b[i]);
        a[0]=0; //普通攻击耗费0魔法值
        b[0]=1; //普通攻击消耗boss的血量
        memset(dp,0,sizeof(dp));
        dp[0][100]=0;   //初始状态
        int round;  //英雄能坚持的时间
        if(100%q)
            round=100/q+1;
        else
            round=100/q;
        bool ok=false;
        for(int i=1; i<=round; i++) //枚举战斗中的每一秒
        {
            for(int j=0; j<=100; j++)   //枚举每种可能的魔法剩余量
            {
                int temp=min(j+t,100);
                for(int k=0; k<=n; k++) //枚举所有攻击方式
                {
                    if(100-a[k]>=j)
                        dp[i][temp]=max(dp[i][temp],dp[i-1][j+a[k]]+b[k]);
                }
                if(dp[i][temp]>=100)
                {
                    printf("%d\n",i);
                    ok=true;
                    break;
                }
            }
            if(ok)
                break;
        }
        if(!ok)
            puts("My god");
    }
    return 0;
}
