/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-04-22
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm: bfs + 前缀和
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
#define MAXN 200005

vector<int> G[MAXN];
int p[MAXN];
LL sum[MAXN];   //前缀和数组
int d[3][MAXN];
int n, m, a, b, c;

void bfs(int x, int num)
{
    for(int i = 1; i <= n; i++)
        d[num][i] = INF;
    d[num][x] = 0;
    queue<int> q;
    q.push(x);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(auto v: G[u])
        {
            if(d[num][v] == INF)
            {
                d[num][v] = d[num][u] + 1;
                q.push(v);
            }
        }
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d%d%d%d", &n, &m, &a, &b, &c);
        for(int i = 1; i <= n; i++)
            G[i].clear();
        for(int i = 1; i <= m; i++)
            scanf("%d", &p[i]);
        sort(p + 1, p + 1 + m);
        for(int i = 1; i <= m; i++)
            sum[i] = sum[i-1] + p[i];
        for(int i = 1; i <= m; i++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            G[u].PB(v);
            G[v].PB(u);
        }
        bfs(a, 0);  //从a点开始bfs
        bfs(b, 1);  //从b点开始bfs
        bfs(c, 2);  //从c点开始bfs
        LL ans = LINF;
        for(int i = 1; i <= n; i++) //枚举中间点x找到a->x->b->x->c的路径
        {
            if(d[0][i] + d[1][i] + d[2][i] <= m)    //最坏的情况：路径是一条链，即不存在这样的x，而必须直接a->b->c
                ans = min(ans, sum[d[1][i]] + sum[d[0][i]+d[1][i]+d[2][i]]);    //前缀和优化，根据路径长度把最短的路优先分配到b->x（x->b）段，然后再分配到a->x段和x->c段
        }
        printf("%lld\n", ans);
    }
    return 0;
}
