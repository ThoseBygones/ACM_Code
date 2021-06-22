/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-06-22
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: 线段树（区间更新 + 区间求和 + 区间求最大/最小值）
 ********************************************************************************
 *  Algo-Description:
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

LL a[MAXN];

typedef LL Type;

class SegTree
{
public:
    Type Max[MAXN << 2];
    Type Min[MAXN << 2];
    Type sum[MAXN << 2];
    Type lazy[MAXN << 2];

    void pushDown(int rt, Type val)
    {
        if(lazy[rt])
        {
            Max[rt << 1] = Max[rt << 1 | 1] = lazy[rt];
            Min[rt << 1] = Min[rt << 1 | 1] = lazy[rt];
            sum[rt << 1] = lazy[rt] * (val - (val >> 1));
            sum[rt << 1 | 1] = lazy[rt] * (val >> 1);
            lazy[rt << 1] = lazy[rt];
            lazy[rt << 1 | 1] = lazy[rt];
            lazy[rt] = 0;
        }
    }

    void pushUp(int rt)
    {
        Max[rt] = max(Max[rt << 1], Max[rt << 1 | 1]);
        Min[rt] = min(Min[rt << 1], Min[rt << 1 | 1]);
        sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
    }

    void build(int l, int r, int rt)
    {
        lazy[rt] = sum[rt] = Max[rt] = 0, Min[rt] = LINF;
        if(l == r)
        {
            sum[rt] = Max[rt] = Min[rt] = a[l];
            return ;
        }
        int mid = (l + r) >> 1;
        build(lson);
        build(rson);
        pushUp(rt);
    }

    /*int findPos(Type val, int l, int r, int rt)
    {
        if(l == r)
            return l;
        //pushDown(rt, r - l + 1);
        int mid = (l + r) >> 1;
        if(Min[rt << 1] >= val)  //在右半区间找
            return findPos(val, rson);
        else    //在右半区间找
            return findPos(val, lson);
    }*/

    void update(int L, int R, Type val, int l, int r, int rt)
    {
        if(Min[rt] >= val)
            return ;
        if(L <= l && r <= R && val > Max[rt])
        {
            lazy[rt] = val;
            Max[rt] = Min[rt] = val;
            sum[rt] = val * (r - l + 1);
            return ;
        }
        pushDown(rt, r - l + 1);
        int mid = (l + r) >> 1;
        if(L <= mid)
            update(L, R, val, lson);
        if(R > mid)
            update(L, R, val, rson);
        pushUp(rt);
    }

    int query(LL &val, int L, int R, int l, int r, int rt)
    {
        if(Min[rt] > val)   //买不起则不买
            return 0;
        if(L <= l && r <= R && val >= sum[rt])  //区间内所有物品都能全买下
        {
            val -= sum[rt];
            return r - l + 1;
        }
        pushDown(rt, r - l + 1);
        int ans = 0;
        int mid = (l + r) >> 1;
        if(L <= mid)
            ans += query(val, L, R, lson);
        if(R > mid)
            ans += query(val, L, R, rson);
        return ans;
    }
} segtree;

int main()
{
    int n, q;
    scanf("%d%d", &n, &q);
    for(int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    segtree.build(1, n, 1);
    while(q--)
    {
        int op, x;
        LL y;
        scanf("%d%d%lld", &op, &x, &y);
        if(op == 1)
            segtree.update(1, x, y, 1, n, 1);
        /*{
            int pos = segtree.findPos(y, 1, n, 1);
            if(pos <= x)
                segtree.update(pos, x, y, 1, n, 1);
        }*/
        else
            printf("%d\n", segtree.query(y, x, n, 1, n, 1));
    }
    return 0;
}
