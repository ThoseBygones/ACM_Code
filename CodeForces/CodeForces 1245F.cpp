/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-03-31
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm: 数位dp
 ********************************************************************************
 *  Algo-Description:
 * > a + b == a ^ b 的条件等价为 a & b == 0；
 *   > a = 0, b = 0 时 a + b == a ^ b == 0，此时 a & b == 0；
 *   > a = 0, b = 1 时（或 a = 1, b = 0 时） a + b == a ^ b == 1，此时 a & b == 0；
 *   > a = 1, b = 1 时 a + b == 2, a ^ b == 0，此时 a & b == 1；
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
#define MAXN 35

typedef LL Type;

int x[MAXN], y[MAXN];   //分别记录x和y的二进制每一位
LL dp[MAXN][2][2];
//dp[pos][limx][limy]表示对于当前处理a, b值的第pos位（从a, b二进制值的高位往低位数第pos位）时，满足 a & b == 0 的数字对数(0 <= a <= x, 0 <= b <= y)
//limx表示a二进制值的高pos位是否与x的一致，limy表示b二进制值的高pos位是否与y的一致（0表示不等于，1表示等于；等于时表示达到x或y的上界，将对下一位二进制位的值进行限制）

Type dfs(int pos, bool limx, bool limy)
{
    //已经搜到尽头,返回“是否找到了答案”这个状态
    if(pos == -1)
        return 1;

    //dp里保存的是完整的，即不受限的答案。所以如果满足的话，可以直接返回。
    if(~dp[pos][limx][limy])  //即dp[pos][lim1][lim2] != -1
        return dp[pos][limx][limy];

    //前几位是否与上限x（或y）一致？一致的话则下一位（低位）受x（或y）二进制值这一位值的限制，否则可以为0或1
    int ux = limx ? x[pos] : 1;
    int uy = limy ? y[pos] : 1;
    Type ret = 0;

    for(int i = 0; i <= ux; i++)
    {
        for(int j = 0; j <= uy; j++)
        {
            if(!(i & j))
                ret += dfs(pos - 1, limx && (i == ux), limy && (j == uy));  //往下一位传递状态（结合前pos-1位的受限状态和当前位的受限状态）
        }
    }

    //dp里保存完整的、取到尽头的数据
    return dp[pos][limx][limy] = ret;
}

LL solve(int l, int r)
{
    if(l == -1 || r == -1)
        return 0;
    memset(dp, -1, sizeof(dp));
    int cnt = 0;
    while(l || r)
    {
        x[cnt] = l & 1;
        y[cnt] = r & 1;
        cnt++;
        l >>= 1;
        r >>= 1;
    }
    return dfs(cnt-1, true, true);
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%lld\n", solve(r, r) - 2 * solve(l - 1, r) + solve(l - 1, l - 1));
    }
    return 0;
}
