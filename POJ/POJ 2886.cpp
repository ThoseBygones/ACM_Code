/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-11-06
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: POJ
 *  Algorithm: 线段树 + 素数筛（反素数）
 ********************************************************************************
 *  Algo-Description:
 ********************************************************************************
 */

//#pragma comment(linker,"/STACK:102400000,102400000")
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <climits>
#include <ctime>
#include <numeric>
#include <vector>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <complex>
#include <deque>
#include <functional>
#include <list>
#include <map>
#include <string>
#include <sstream>
#include <set>
#include <stack>
#include <queue>
//#include <bits/stdc++.h>
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

const int MAXN = 500005;

char name[MAXN][15];
int a[MAXN];
int ap[MAXN];   //反素数数组

void init() //埃式筛法求反素数
{
    for(int i = 1; i < MAXN; i++)
    {
        for(int j = 1; i * j < MAXN; j++)
            ap[i * j]++;
    }
}

class SegTree
{
public:
    int sum[MAXN << 2];

    void pushUp(int rt)
    {
        sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
    }

    void build(int l, int r, int rt)
    {
        if(l == r)
        {
            sum[rt] = 1;
            return ;
        }
        int mid = (l + r) >> 1;
        build(lson);
        build(rson);
        pushUp(rt);
    }

    int update(int pos, int l, int r, int rt) //单点更新
    {
        if(l == r)
        {
            sum[rt]--;
            return l;
        }
        int mid = (l + r) >> 1;
        int ret = 0;
        if(pos <= sum[rt << 1]) //该删除的数在左半边区间
            ret = update(pos, lson);
        else    //该删除的数在右半边区间
            ret = update(pos - sum[rt << 1], rson);
        pushUp(rt);
        return ret;
    }

    int query(int L, int R, int l, int r, int rt)   //区间求和
    {
        if(L <= l && r <= R)
            return sum[rt];
        int mid = (l + r) >> 1;
        int ret = 0;
        if(L <= mid)
            ret += query(L, R, lson);
        if(R > mid)
            ret += query(L, R, rson);
        return ret;
    }
} segtree;

int main()
{
    init();
    int n, k;
    while(~scanf("%d%d", &n, &k))
    {

        for(int i = 1; i <= n; i++)
            scanf("%s %d", name[i], &a[i]);
        segtree.build(1, n, 1);
        int mod = n;
        int pos = segtree.update(k, 1, n, 1);
        //cout << pos << endl;
        mod--;
        int ans = ap[k], res = pos;
        for(int i = 2; i <= n; i++)
        {
            int tmp = a[pos];
            if(tmp > 0)
                k = ((k - 1 + tmp - 1) % mod + mod) % mod + 1;  //a[pos]被删除后右边的数变成第k个，故需要减1
            else
                k = ((k + tmp - 1) % mod + mod) % mod + 1;  //-1后再加1是使得第mod个不会被取模后变成0
            pos = segtree.update(k, 1, n, 1);
            //cout << name[pos] << ": " << pos << " - " << ap[pos] << endl;
            if(ap[i] > ans)
            {
                ans = ap[i];
                res = pos;
            }
            mod--;
        }
        printf("%s %d\n", name[res], ans);
    }
    return 0;
}
