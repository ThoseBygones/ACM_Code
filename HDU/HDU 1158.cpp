#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 15
#define MAXM 1005
#define INF 0x3f3f3f3f

int num[MAXN];  //每个月至少需要的员工数
int dp[MAXN][MAXM]; //前i个月（包括第i个月）雇佣j的员工需要花费的最小值

int main()
{
    int n;
    int hire,salary,fire;
    while(~scanf("%d",&n),n)
    {
        scanf("%d%d%d",&hire,&salary,&fire);
        int maxnum=0;
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&num[i]);
            maxnum=max(maxnum,num[i]);
        }
        for(int i=num[1]; i<=maxnum; i++)
            dp[1][i]=(hire+salary)*i;
        for(int i=2; i<=n; i++)
        {
            for(int j=num[i]; j<=maxnum; j++)   //枚举当月雇用员工数
            {
                int Minsum=INF;
                for(int k=num[i-1]; k<=maxnum; k++) //枚举上个月雇佣员工数
                {
                    if(k<j) //上个月比这个月雇佣的员工少
                        Minsum=min(Minsum,dp[i-1][k]+(j-k)*hire+j*salary);
                    else    //上个月比这个月雇佣的员工多
                        Minsum=min(Minsum,dp[i-1][k]+(k-j)*fire+j*salary);
                }
                dp[i][j]=Minsum;
            }
        }
        int ans=INF;
        for(int i=num[n]; i<=maxnum; i++)
            ans=min(ans,dp[n][i]);
        printf("%d\n",ans);
    }
    return 0;
}
