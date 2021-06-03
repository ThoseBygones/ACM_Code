/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-06-02
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: 线段树 / 树状数组
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

const int MAXN = 100005;

class SegTree
{
public:
    int Min[MAXN << 2];

    void pushUp(int rt)
    {
        Min[rt] = min(Min[rt << 1], Min[rt << 1 | 1]);
    }

    void update(int x, int val, int l, int r, int rt)   //单点更新
    {
        if(l == r)
        {
            Min[rt] = val;
            return ;
        }
        int mid = (l + r) >> 1;
        if(x <= mid)
            update(x, val, lson);
        else
            update(x, val, rson);
        pushUp(rt);
    }

    int query(int L, int R, int l, int r, int rt)   //区间求最小值
    {
        if(L <= l && r <= R)
            return Min[rt];
        int mid = (l + r) >> 1;
        int ret = INF;
        if(L <= mid)
            ret = min(ret, query(L, R, lson));
        if(R > mid)
            ret = min(ret, query(L, R, rson));
        return ret;
    }
} segtree;

int a[MAXN], last[MAXN];    //last[i]表示元素i上一次（之前最后一次）出现的位置
bool mex[MAXN]; //mex[i]表示最终的集合中元素i是否出现

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for(int i = 1; i <= n; i++)
    {
        if(a[i] > 1)
        {
            mex[1] = 1; //只要有个元素值不为1，那么1就一定会出现在最终的那个集合中
            int pos = segtree.query(1, a[i] - 1, 1, n, 1);  //查找比a[i]小的数中出现位置最早的那个数出现的位置
            if(pos > last[a[i]])    //该位置比a[i]上一次出现的位置还靠后，说明区间[last[a[i]] + 1, a[i] - 1]区间的MEX为a[i]
                mex[a[i]] = true;
        }
        segtree.update(a[i], i, 1, n, 1);
        last[a[i]] = i;
    }
    for(int i = 2; i <= n + 1; i++) //枚举每个数素是否可能是某个区间的MEX，是则加入最终集合
    {
        if(!mex[i]) //还不知道是否是某个区间MEX
        {
            int pos = segtree.query(1, i - 1, 1, n, 1); //查找比i小的数中出现位置最早的那个数出现的位置
            if(pos > last[i])   //该位置比i上一次出现的位置还靠后，说明区间[last[i] + 1, i - 1]区间的MEX为i
                mex[i] = true;
        }
    }
    int ans = 0;
    for(int i = 1; i <= n + 2; i++)
    {
        if(!mex[i])
        {
            ans = i;
            break;
        }
    }
    printf("%d\n", ans);
    return 0;
}
