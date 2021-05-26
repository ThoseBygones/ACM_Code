/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-05-26
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: 贪心 + 线段树
 ********************************************************************************
 *  Algo-Description:
 * > 先找到一种解：
 *   > 用贪心的方法：按照 L[i] 排序，枚举加入的 L[i]​，每次选择 R[i]​ 最小的那个人。
 *   > 用一个 set 维护即可。
 * > 记标号为 i 的人打乱后位置在 pos[i] 。
 * > 考虑什么情况下两个人的标号可以交换：
 *   > L[pos[i]] <= i <= R[pos[i]]
 *   > L[pos[j]] <= j <= R[pos[j]]
 * > 假设 i < j，要满足 i 和 j 可以交换，必须满足：
 *   > L[pos[j]] <= i < j <= R[pos[i]]，即枚举 i，只需要找到一个 j 满足该不等式。
 * > 由于 R[pos[i​]] 已知，也就是在标号为 [i + 1, R[pos[i]]] 里找到一个 j，其 L[pos[j​]] 最小
 * > 若 L[pos[j]] <= i，则可以交换。
 * > 这部分可以用线段树查找区间最小值实现。
 ********************************************************************************
 */

#include <bits/stdc++.h>
using namespace std;

template<class T> inline T sqr(T x) {return x * x;}
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

int a[MAXN], b[MAXN], pos[MAXN];
int ans[MAXN];
vector<PII> seg[MAXN];  //区间左右边界
set<PII> s;

class SegTree
{
public:
    int Min[MAXN << 2]; //记录左边界的最小值
    int id[MAXN << 2];

    void pushUp(int rt)
    {
        if(Min[rt << 1] < Min[rt << 1 | 1])
        {
            Min[rt] = Min[rt << 1];
            id[rt] = id[rt << 1];
        }
        else
        {
            Min[rt] = Min[rt << 1 | 1];
            id[rt] = id[rt << 1 | 1];
        }
    }

    void build(int l, int r, int rt)
    {
        if(l == r)
        {
            Min[rt] = a[pos[l]];
            id[rt] = l;
            return ;
        }
        int mid = (l + r) >> 1;
        build(lson);
        build(rson);
        pushUp(rt);
    }

    PII query(int L, int R, int l, int r, int rt)
    {
        if(L <= l && r <= R)
            return MP(Min[rt], id[rt]);
        int mid = (l + r) >> 1;
        PII ret = MP(INF, -1);
        if(L <= mid)
            ret = min(ret, query(L, R, lson));
        if(R > mid)
            ret = min(ret, query(L, R, rson));
        return ret;
    }
} segtree;


int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d%d", &a[i], &b[i]);
        seg[a[i]].PB(MP(b[i], i));  //同样左边界的人有哪些对应右边界
    }
    for(int i = 1; i <= n; i++) //贪心把人尽可能放在靠左边的位置
    {
        if(seg[i].size())   //可以不加这句判断
            s.insert(seg[i].begin(), seg[i].end()); //插入左边界为1时可选择的人的右边界
        pos[i] = (*s.begin()).second;   //贪心排序后位置i对应的人的id
        ans[pos[i]] = i;    //把左边界为i，右边界最小（最靠近左边）的人贪心的放在位置i
        s.erase(s.begin()); //从集合中删除这个人
    }
    segtree.build(1, n, 1);
    bool flag = true;
    for(int i = 1; i <= n; i++)
    {
        if(i + 1 > b[pos[i]])
            continue;
        PII res = segtree.query(i + 1, b[pos[i]], 1, n, 1); //在区间[i + 1, R[pos[i]]]中找到一个L[pos[j]]最小的j
        if(res.first == INF || res.first > i)   //没找到可以交换的人（查到的人其可以处于的区间左端点不能大于i）
            continue;
        puts("NO");
        for(int i = 1; i <= n; i++)
            printf("%d%c", ans[i], (i == n ? '\n' : ' '));
        swap(ans[pos[i]], ans[pos[res.second]]);
        for(int i = 1; i <= n; i++)
            printf("%d%c", ans[i], (i == n ? '\n' : ' '));
        flag = false;
        break;
    }
    if(flag)
    {
        puts("YES");
        for(int i = 1; i <= n; i++)
            printf("%d%c", ans[i], (i == n ? '\n' : ' '));
    }
    return 0;
}
