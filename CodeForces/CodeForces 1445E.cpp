/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-06-06
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: 可撤销并查集
 ********************************************************************************
 *  Algo-Description:
 * > 从 k 种种选取 2 种，可以想到暴力枚举，一共有 C(k, 2) 种情况；但 k 的范围很大，暴力枚举会超时。
 * > 正难则反，考虑其对偶问题——计算不合法的组合个数，然后由总的方案数减去不合法的组合个数得到答案。
 * > 题目中提到二分图，其定义为“不含有奇环的一个图”。
 * > 而判断二分图的两种方法：
 *   > 直接 dfs 交叉染色；
 *   > 对每个点建立虚点（共 2n 个点），然后利用并查集维护。
 *     > 每个点拆成两个点（点 i 和点 i + n，即实点和虚点），表示选择和不选择这个点；
 *     > 对于一条边的两个点分别将一个点的实点与另一个点的虚点合并（u 与 v + n 合并，v 与 u + n 合并）；
 *     > 如果一条边两个点查找到的祖先结点一样，那么这两个结点在同一个集合中，说明该图不是二分图。
 * > 因为总共数只有 m 条边。即假设每条边 (u, v) 的两个端点 u 和 v 都属于不同的种类，最终也只有 m 种组合方案，故非法的种类数最多只有 m 种。
 * > 对每条边 (u, v) 分类讨论，c[x] 表示结点 x 的种类：
 *   > 如果 c[u] == c[v] ，直接用并查集将其合并；
 *   > 如果 c[u] != c[v] ，将其加入所有连接 (c[u], c[v]) 这两个种类的边的集合中。
 * > 对于每个种类对应的连通分量，如果出现奇环，则说明当前这个种类无论和哪个组合匹配，都不合法。
 * > 对于合并任意两个种类的边分组，依次合并然后检查是否存在奇环。
 * > 注意，由于要的合并每两个组的边集都是相互独立的，所以在进行完一轮“合并”并判断完是不是奇环后需要及时撤销这些合并操作，以保证算法的正确性。
 * > 关于撤销可以直接用并查集的撤销来实现。
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

const int MAXN = 500005;

class Undo_DSU
{
public:
    int fa[MAXN << 1], rk[MAXN << 1]; //结点数量（集合的秩）
    PII sta[MAXN << 1];  //手动模拟栈
    int top;
    //stack<PII> sta;

    void init(int n)
    {
        top = -1;
        //while(!sta.empty())
        //    sta.pop();
        for(int i = 1; i <= n; i++)
        {
            fa[i] = i;
            rk[i] = 1;
        }
    }

    int findSet(int x)
    {
        if(x != fa[x])
            return findSet(fa[x]);  //不可路径压缩
        return x;   //return fa[x];
    }

    bool unionSet(int x, int y)
    {
        int fx = findSet(x);
        int fy = findSet(y);
        if(fx == fy)
            return false;
        if(rk[fx] > rk[fy])
        {
            swap(fx, fy);
            swap(x, y);
        }
        fa[fx] = fy;    //按秩合并
        rk[fy] += rk[fx];
        sta[++top] = MP(fx, fy);
        //sta.push(MP(fx, fy));
        return true;
    }

    void undo()
    {
        /*if(!sta.empty())
        {
            PII cur = sta.top();
            sta.pop();
        */
        if(~top)    //有可以撤销的合并记录
        {
            PII cur = sta[top--];
            fa[cur.first] = cur.first;
            rk[cur.second] -= rk[cur.first];
        }
    }
} dsu;

int a[MAXN], b[MAXN], c[MAXN];
bool flag[MAXN];    //flag[i]表示某个种类自己内部是否存在矛盾（如果存在，这种种类不可选）
map<PII, int> mp;   //记录某个不同种类对组成的合法边是否存在
vector<int> e[MAXN];    //记录这些合法边


int main()
{
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 1; i <= n; i++)
        scanf("%d", &c[i]);
    for(int i = 1; i <= m; i++)
        scanf("%d%d", &a[i], &b[i]);
    dsu.init(2 * n);    //设置虚点，方便判断二分图是否存在奇环
    for(int i = 1; i <= m; i++)
    {
        if(c[a[i]] == c[b[i]])  //同一种类的边
        {
            int faa = dsu.findSet(a[i]);
            int fab = dsu.findSet(b[i]);
            if(faa != fab)
            {
                dsu.unionSet(a[i], b[i] + n);
                dsu.unionSet(b[i], a[i] + n);
            }
            else
                flag[c[a[i]]] = true;
        }
    }
    LL cnt = 0;
    for(int i = 1; i <= k; i++)
    {
        if(!flag[i])
            cnt++;
    }
    LL ans = cnt * (cnt - 1) / 2;
    int id = 0;
    for(int i = 1; i <= m; i++)
    {
        if(!flag[c[a[i]]] && !flag[c[b[i]]] && c[a[i]] != c[b[i]])   //种类不可取或者同种类可取的情况（已经计算过）
        {
            //边上的两个点属于不同种类且合法
            int c1 = c[a[i]], c2 = c[b[i]];
            if(c1 > c2)
                swap(c1, c2);
            if(!mp[MP(c1, c2)])   //该种类对还未被记录
                mp[MP(c1, c2)] = ++id;
            e[mp[MP(c1, c2)]].PB(i);
        }
    }
    for(int i = 1; i <= id; i++)   //枚举这些种类对
    {
        int ucnt = 0;   //合并的次数
        //int tmp = dsu.sta.size();
        for(auto j: e[i])    //枚举对应的边
        {
            int u = a[j], v = b[j];
            //printf("%d: %d - %d\n", i, u, v);
            int fau = dsu.findSet(u);
            int fav = dsu.findSet(v);
            if(fau == fav)  //这两个边在同个集合内
            {
                ans--;  //存在奇环，方案数减一
                break;
            }
            else    //合法，则合并
            {
                ucnt += dsu.unionSet(u, v + n);
                ucnt += dsu.unionSet(v, u + n);
            }
        }
        //while(dsu.sta.size() > tmp)
        while(ucnt--)   //把本轮合并的操作都撤销
            dsu.undo();
    }
    printf("%lld\n", ans);
    return 0;
}
