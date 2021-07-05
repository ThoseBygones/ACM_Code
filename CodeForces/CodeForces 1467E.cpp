/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-07-05
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: dfs + 树上差分 + STL map/unordered_map / 离散化 + 二分
 ********************************************************************************
 *  Algo-Description:
 * > 直接找合法点比较困难，因此可以逆向思维，找到所有非法点，剩下的就都是合法点。
 * > 判断非法点的规则：
 *   > 如果当前点子树内有权值与该子树根结点相同的点，那么当前点的子树外（包括该子树的根结点）所有点不合法；
 *   > 如果当前点子树外有权值与该子树根结点相同的点，那么当前点的子树内（包括该子树的根结点）所有点不合法。
 * > 用 dfs 序方法把树上结点的修改变成 dfs 序区间修改的问题。
 * > 用差分数组维护非法点的数量（非法点标记为 1）：
 *   > dfs 完以 u 为根的树时，如果 a[u] 的个数小于总的 a[u] 个数，那么把以 u 为根结点的子树全部标记。
 *   > 在对 u 的子树 dfs 过程中，发现 u 的 v 子树中还有结点点权等于 a[u]，那么就标记 v 的子树以外的全部点。
 *   > 设 [lnd[u], rnd[u]] 表示结点 u 管辖的结点范围，于是区间差分数组的修改方法为：
 *     > 标记 v 子树外全部的点即修改区间 [1, lnd[v] - 1] 和区间 [rnd[v] + 1, n] 的差分数组；
 *     > 因为 v 子树dfs序区间为 [lnd[v], rnd[v]] 。
 ********************************************************************************
 */

#include <bits/stdc++.h>
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
const double EPS = 1e-6;
const int INF = 0x3fffffff;
const LL LINF = INF * 1ll * INF;
const double PI = acos(-1.0);

#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define lowbit(u) (u&(-u))

const int MAXN = 200005;


/* dfs + 树上差分 + STL map（670ms）/unordered_map（405ms） */

//map<int, int> totcnt, curcnt; //全局计数、暂时计数   //670ms
unordered_map<int, int> totcnt, curcnt; //全局计数、暂时计数 //405ms
vector<int> G[MAXN];
int a[MAXN];
int lnd[MAXN], rnd[MAXN];   //dfs序，表示该结点管辖的结点范围
int d[MAXN];    //差分数组
int dfs_clock;  //dfs时间戳

void dfs(int u, int fa)
{
    lnd[u] = ++dfs_clock;
    int precnt = curcnt[a[u]]++;    //记录按dfs序到进入u点时权值为a[u]的点的数目
    for(int i = 0; i < G[u].size(); i++)
    {
        int v = G[u][i];
        if(v != fa)
        {
            int incnt = curcnt[a[u]];   //u的子树（不包括u点）中是否存在权值为a[u]的点
            dfs(v, u);
            if(curcnt[a[u]] > incnt)    //u的子树（不包括u点）中存在权值为a[u]的点
            {
                d[1]++, d[lnd[v]]--;    //标记区间 [1, lnd[v] - 1]
                d[rnd[v] + 1]++;    //标记区间 [rnd[v] + 1, n]
            }
        }
    }
    rnd[u] = dfs_clock;
    if(curcnt[a[u]] - precnt < totcnt[a[u]])    //除了u的子树外，还存在权值为a[u]的点，则标记u的子树区间 [lnd[u], rnd[u]]
        d[lnd[u]]++, d[rnd[u] + 1]--;
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        totcnt[a[i]]++;
    }
    for(int i = 1; i < n; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].PB(v);
        G[v].PB(u);
    }
    dfs(1, 0);
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        d[i] += d[i - 1];
        if(!d[i])   //记录差分数组为0的点
            ans++;
    }
    printf("%d\n", ans);
    return 0;
}


/* dfs + 树上差分 + 离散化（去重） + 二分（311ms） */

vector<int> G[MAXN];
int a[MAXN], b[MAXN];
int lnd[MAXN], rnd[MAXN];   //dfs序，表示该结点管辖的结点范围
int sz[MAXN];   //子树的数量
int d[MAXN];    //差分数组
int curcnt[MAXN], totcnt[MAXN]; //全局计数、暂时计数
int dfs_clock;

void dfs(int u, int fa)
{
    lnd[u] = ++dfs_clock;
    int precnt = curcnt[a[u]]++;    //记录按dfs序到进入u点时权值为a[u]的点的数目
    for(int i = 0; i < G[u].size(); i++)
    {
        int v = G[u][i];
        if(v != fa)
        {
            int incnt = curcnt[a[u]];   //u的子树（不包括u点）中是否存在权值为a[u]的点
            dfs(v, u);
            if(curcnt[a[u]] > incnt)    //u的子树（不包括u点）中存在权值为a[u]的点
            {
                d[1]++, d[lnd[v]]--;    //标记区间 [1, lnd[v] - 1]
                d[rnd[v] + 1]++;    //标记区间 [rnd[v] + 1, n]
            }
        }
    }
    rnd[u] = dfs_clock;
    if(curcnt[a[u]] - precnt < totcnt[a[u]])    //除了u的子树外，还存在权值为a[u]的点，则标记u的子树区间 [lnd[u], rnd[u]]
        d[lnd[u]]++, d[rnd[u] + 1]--;
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }
    //离散化 + 去重
    sort(b + 1, b + 1 + n);
    int cnt = unique(b + 1, b + 1 + n) - b - 1;
    for(int i = 1; i <= n; i++)
    {
        a[i] = lower_bound(b + 1, b + 1 + n, a[i]) - b;
        totcnt[a[i]]++;
    }
    for(int i = 1; i < n; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].PB(v);
        G[v].PB(u);
    }
    dfs(1, 0);
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        d[i] += d[i - 1];
        if(!d[i])   //记录差分数组为0的点
            ans++;
    }
    printf("%d\n", ans);
    return 0;
}
