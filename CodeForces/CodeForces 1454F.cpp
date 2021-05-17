/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-05-16
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: 线段树 / ST表 RMQ + 二分
 ********************************************************************************
 *  Algo-Description:
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


/* 解法一：线段树 + 二分 */

class SegTree
{
public:
    int Max[MAXN << 2];
    int Min[MAXN << 2];

    void pushUp(int rt)
    {
        Max[rt] = max(Max[rt << 1], Max[rt << 1 | 1]);
        Min[rt] = min(Min[rt << 1], Min[rt << 1 | 1]);
    }

    void build(int l, int r, int rt)
    {
        if(l == r)
        {
            scanf("%d", &Max[rt]);
            Min[rt] = Max[rt];
            return ;
        }
        int mid = (l + r) >> 1;
        build(lson);
        build(rson);
        pushUp(rt);
    }

    int queryMax(int L, int R, int l, int r, int rt)   //区间求最大值
    {
        if(L <= l && r <= R)
            return Max[rt];
        int mid = (l + r) >> 1;
        int ret = 0;
        if(L <= mid)
            ret = max(ret, queryMax(L, R, lson));
        if(R > mid)
            ret = max(ret, queryMax(L, R, rson));
        return ret;
    }

    int queryMin(int L, int R, int l, int r, int rt)   //区间求最小值
    {
        if(L <= l && r <= R)
            return Min[rt];
        int mid = (l + r) >> 1;
        int ret = INF;
        if(L <= mid)
            ret = min(ret, queryMin(L, R, lson));
        if(R > mid)
            ret = min(ret, queryMin(L, R, rson));
        return ret;
    }

    bool biSearch(int L, int val, int &y, int n)
    {
        int l = L + 1, r = n - 1;
        while(l <= r)
        {
            //printf("%d - %d\n", l, r);
            int mid = (l + r) >> 1;
            int Min = queryMin(L + 1, mid, 1, n, 1);
            int Max = queryMax(mid + 1, n, 1, n, 1);
            //printf("min: %d, max: %d, val: %d\n", Min, Max, val);
            if(Min > val || Max > val)  //最小值区间和最大值区间随着端点右移只能单调不减
                l = mid + 1;
            else if(Min < val || Max < val) //最小值区间和最大值区间随着端点左移只能单调不增
                r = mid - 1;
            else
            {
                y = mid;
                return true;
            }
        }
        return false;
    }

    void solve(int n)
    {
        build(1, n, 1);
        for(int x = 1; x <= n - 2; x++) //枚举第一个区间和第二个区间的分割点
        {
            int val = queryMax(1, x, 1, n, 1);
            int y = -1;
            if(biSearch(x, val, y, n))    //二分第二个区间和第三个区间的分割点
            {
                puts("YES");
                //printf("i: %d, x: %d, y: %d\n", x, val, y);
                printf("%d %d %d\n", x, y - x, n - y);
                return ;
            }
        }
        puts("NO");
    }
} segtree;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        segtree.solve(n);
    }
    return 0;
}


/* 解法二：ST表 + 二分 */

int logg[MAXN]; //计算log2(i)
int st_max[21][MAXN], st_min[21][MAXN];

void init_rmq(int n)
{
    logg[1] = 0;
    for(int i = 2; i <= n; i++) //预处理log2(i)
        logg[i] = logg[i >> 1] + 1;
    for(int i = 1; i <= n; i++) //初始化ST表
    {
        scanf("%d", &st_max[0][i]);
        st_min[0][i] = st_max[0][i];
    }
    for(int j = 1; (1 << j) < n; j++)   //预处理计算出ST表
    {
        for(int i = 1; i + (1 << j) - 1 <= n; i++)
        {
            st_min[j][i] = min(st_min[j - 1][i], st_min[j - 1][i + (1 << (j - 1))]);
            st_max[j][i] = max(st_max[j - 1][i], st_max[j - 1][i + (1 << (j - 1))]);
        }
    }
}

int RMQ_min(int l, int r)   //利用ST表O(1)复杂度RMQ
{
    int k = logg[r - l + 1];
    return min(st_min[k][l], st_min[k][r - (1 << k) + 1]);
}

int RMQ_max(int l, int r)   //利用ST表O(1)复杂度RMQ
{
    int k = logg[r - l + 1];
    return max(st_max[k][l], st_max[k][r - (1 << k) + 1]);
}

bool biSearch(int L, int val, int &y, int n)
{
    int l = L + 1, r = n - 1;
    while(l <= r)
    {
        //printf("%d - %d\n", l, r);
        int mid = (l + r) >> 1;
        int Min = RMQ_min(L + 1, mid);
        int Max = RMQ_max(mid + 1, n);
        //printf("min: %d, max: %d, val: %d\n", Min, Max, val);
        if(Min > val || Max > val)  //最小值区间和最大值区间随着端点右移只能单调不减
            l = mid + 1;
        else if(Min < val || Max < val) //最小值区间和最大值区间随着端点左移只能单调不增
            r = mid - 1;
        else
        {
            y = mid;
            return true;
        }
    }
    return false;
}

void solve(int n)
{
    for(int x = 1; x <= n - 2; x++) //枚举第一个区间和第二个区间的分割点
    {
        int val = RMQ_max(1, x);
        int y = -1;
        if(biSearch(x, val, y, n))    //二分第二个区间和第三个区间的分割点
        {
            puts("YES");
            //printf("i: %d, x: %d, y: %d\n", x, val, y);
            printf("%d %d %d\n", x, y - x, n - y);
            return ;
        }
    }
    puts("NO");
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        init_rmq(n);
        solve(n);
    }
}
