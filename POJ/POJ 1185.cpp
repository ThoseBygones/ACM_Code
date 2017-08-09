//状态压缩dp
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 105
#define MAXM 10

int dp[MAXN][65][65];  //dp[i][j][k]表示第i行状态为j，第i-1行状态为k时，能放的最多的炮兵阵地数量
int s[MAXN];    //一行的状态
int mp[MAXN];  //一行的地图：0为平原（P）,1为山丘（H）
int sum[MAXN];  //每种状态能放的炮兵阵地的数量
int n,m;
int cnt;    //每行可能的状态数。（每行撑死最多摆四个炮兵。摆4个：1种；摆3个：20种；摆2个：28种；摆1个：10种；摆0个：1种；一共不超过60种。）

bool isok(int x)    //计算有多少种可行状态的函数
{
    return !(x&(x<<1) || x&(x<<2) || x&(x>>1) || x&(x>>2));
}

bool check(int x)   //本行状态是否可行（是否与前两行冲突）
{
    if(x&(x<<1))
        return false;
    if(x&(x<<2))
        return false;
    return true;
}

int getSum(int x)   //确定某个状态下能摆几个炮兵阵地
{
    int res=0;
    while(x)
    {
        if(x&1)
            res++;
        x>>=1;
    }
    return res;
}

void getState() //枚举所有状态
{
    memset(s,0,sizeof(s));
    memset(sum,0,sizeof(sum));
    for(int i=0; i<(1<<m); i++)
    {
        if(check(i))
        {
            s[cnt]=i;
            sum[cnt]=getSum(i);
            cnt++;
        }
    }
}

int main()
{
    /*
    //计算一共有多少种可行状态
    int tot=0;
    for(int i=0; i<(1<<10); i++)
        tot+=isok(i);
    printf("%d\n",tot);
    */

    scanf("%d%d",&n,&m);
    memset(dp,0,sizeof(dp));
    for(int i=0; i<n; i++)
    {
        char temp[MAXM];
        scanf("%s",temp);
        for(int j=0; j<m; j++)
        {
            if(temp[j]=='H')
                mp[i]|=(1<<j);  //P--0，H--1
        }
    }
    cnt=0;
    getState();

    for(int i=0; i<cnt; i++)    //初始化第0行状态
    {
        if(s[i]&mp[0])
            continue;
        dp[0][i][0]=sum[i];
    }

    for(int i=0; i<cnt; i++)
    {
        if(s[i]&mp[1])
            continue;
        for(int j=0; j<cnt; j++)
        {
            if(s[j]&mp[0] || s[i]&s[j])
                continue;
            dp[1][i][j]=max(dp[1][i][j],dp[0][j][0]+sum[i]);
        }
    }

    for(int p=2; p<n; p++)  //枚举每一行
    {
        for(int i=0; i<cnt; i++)    //枚举第p行的状态
        {
            if(mp[p]&s[i])  //状态与地图冲突
                continue;
            for(int j=0; j<cnt; j++)
            {
                if(mp[p-1]&s[j] || s[i]&s[j])   //状态与上一行冲突
                    continue;
                for(int k=0; k<cnt; k++)
                {
                    if(mp[p-2]&s[k] || s[i]&s[k] || s[j]&s[k])
                        continue;
                    dp[p][i][j]=max(dp[p][i][j],dp[p-1][j][k]+sum[i]);
                }
            }
        }
    }

    int ans=0;
    for(int i=0; i<cnt; i++)
    {
        for(int j=0; j<cnt; j++)
            ans=max(ans,dp[n-1][i][j]);
    }
    printf("%d\n",ans);
    return 0;
}
