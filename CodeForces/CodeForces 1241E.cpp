/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-03-20
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm: 树形dp
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
#define MAXN 500005

vector<PII> G[MAXN];
LL dp[MAXN][2];    //dp[i][0/1]表示以i为根的子树中，结点i和其父亲fa是否涂相同颜色（以结点i和其父亲fa为端点的边贡献是否取）时能获得的最大贡献和（0表示不取，1表示取）
int n, k;

void dfs(int u, int fa)
{
    dp[u][0] = dp[u][1] = 0;
    vector<LL> val;    //记录更改后更优的方案的贡献增量
    for(auto e: G[u])
    {
        int v = e.first;
        int w = e.second;
        if(v != fa)
        {
            dfs(v, u);
            //无论取不取结点u和结点fa之间这条边，先选择加上所有结点u和结点v之间这条边不取的最优结果
            dp[u][0] += dp[v][0];
            dp[u][1] += dp[v][0];
            if(dp[v][1] + w > dp[v][0]) //如果某个结点v改为选用该结点到其父节点u之间这条边取的方案，且更改后的方案更优，则记录之
                val.PB(dp[v][1] + w - dp[v][0]);
        }
    }
    //cout << "GO" << endl;
    sort(val.begin(), val.end(), greater<LL>());   //按照更改后新方案的贡献值增量从大到小排序
    for(int i = 0; i < min(k, (int)val.size()); i++)   //遍历所有更改后的新方案
    {
        if(i < k - 1)  //如果有k个更改后的方案后更优
            dp[u][1] += val[i];   //如果结点u到其父节点fa的边取，则只取更改后最优的前k-1种方案（留一种颜色让结点u和其父节点fa涂）
        dp[u][0] += val[i]; //结点u到其父节点fa的边不取，则把更改后最优的前k种方案照单全收
    }
}

int main()
{
    int q;
    scanf("%d", &q);
    while(q--)
    {
        scanf("%d%d", &n, &k);
        for(int i = 1; i <= n; i++)
            G[i].clear();
        for(int i = 1; i < n; i++)
        {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            G[u].PB(MP(v, w));
            G[v].PB(MP(u, w));
        }
        dfs(1, 0);
        printf("%lld\n", dp[1][0]);    //结点0是虚根（不存在的），故结点1与结点0之间不需要涂色
    }
    return 0;
}
