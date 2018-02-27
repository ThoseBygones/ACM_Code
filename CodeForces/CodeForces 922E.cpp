/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2018-02-27
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm: dp（多重背包）
 ********************************************************************************
 *  Algo-Description:
 ********************************************************************************
 */

#include <bits/stdc++.h>  //For CodeForces only
using namespace std;
template<class T> inline T sqr(T x)
{
    return x * x;
}
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;
typedef pair<LL, LL> PLL;
typedef pair<LL, int> PLI;
typedef pair<LD, LD> PDD;
#define MP make_pair
#define PB push_back
#define sz(x) ((int)(x).size())
#define clr(ar,val) memset(ar, val, sizeof(ar))
#define istr stringstream
#define FOR(i,n) for(int i=0;i<(n);++i)
#define forIt(mp,it) for(__typeof(mp.begin()) it = mp.begin();it!=mp.end();it++)
const double EPS = 1e-6;
const int INF = 0x3fffffff;
const LL LINF = INF * 1ll * INF;
const double PI = acos(-1.0);

#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define lowbit(u) (u&(-u))
#define MAXN 1005
#define MAXM 10005

int c[MAXN];    //每棵树上鸟的数量
int cost[MAXN]; //召集每棵树上一只鸟需要消耗的法力值
LL dp[MAXN][MAXM]; //dp[i][j]表示走到第i棵树下召集了j只鸟时剩下的法力值最多是多少

int main()
{
    int n,w,b,x;
    scanf("%d%d%d%d",&n,&w,&b,&x);
    for(int i=1; i<=n; i++)
        scanf("%d",&c[i]);
    for(int i=1; i<=n; i++)
        scanf("%d",&cost[i]);
    memset(dp,-1,sizeof(dp));
    dp[0][0]=(LL)w; //初始法力值为w
    int sum=0;  //累计召集鸟的数量
    for(int i=1; i<=n; i++)
    {
        sum+=c[i];
        for(LL j=0; j<=sum; j++)
        {
            for(int k=0; k<=c[i] && k<=j; k++)
            {
                if(dp[i-1][j-k]>=0)   //转移到当前状态的上一状态可达
                    dp[i][j]=max(dp[i][j],min(dp[i-1][j-k]+x,(LL)w+(LL)(j-k)*b)-(LL)cost[i]*k); //增加后的法力值不能超过法力值上限
            }
        }
    }
    for(int i=sum; i>=0; i--)
    {
        if(dp[n][i]>=0)
        {
            printf("%d\n",i);
            return 0;
        }
    }
    return 0;
}
