/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2019-01-05
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm: dp + 单调队列优化
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
#define MAXN 5005

int a[MAXN];
int que[MAXN];   //数组模拟单调队列
LL dp[MAXN][MAXN];  //dp[i][j]表示选择第i幅画后，包括第i幅画已选了j幅画

int main()
{
    int n,k,x;
    scanf("%d%d%d",&n,&k,&x);
    for(int i = 1; i <= n; i++)
        scanf("%d",&a[i]);
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= x; j++)
            dp[i][j] = -LINF;
    }
    dp[0][0] = 0;
    for(int j = 1; j <= x; j++)
    {
        memset(que,0,sizeof(que));  //清空队列
        int head = 1, tail = 1; //向队列中插入下标0
        for(int i = 1; i <= n; i++)
        {
            while(head <= tail && que[head] < i - k)   //弹出下标不在可选范围（i-k）内的元素
                head++;
            dp[i][j] = dp[que[head]][j-1] + a[i];
            while(head <= tail && dp[que[tail]][j-1] <= dp[i][j-1]) //如果选择第i幅画的值比选择第que[tail]幅画的值更优时
                tail--;
            que[++tail] = i;
        }
    }
    LL ans = -LINF;
    for(int i = n-k+1; i <= n; i++)
        ans = max(ans,dp[i][x]);
    if(ans < 0)
        puts("-1");
    else
        printf("%I64d\n",ans);
    return 0;
}
