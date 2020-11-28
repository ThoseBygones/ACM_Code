/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-11-28
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: POJ
 *  Algorithm: �߶��� + dp
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

const int MAXN = 50005;
const int MAXM = 500005;

int s[MAXM], e[MAXM];
int dp[MAXN];   //dp[i]��ʾ��ȫ���ǵ���i��Ҫ����С������

class SegTree
{
public:
    int Min[MAXN << 2];

    void pushUp(int rt)
    {
        Min[rt] = min(Min[rt << 1], Min[rt << 1 | 1]);
    }

    void build(int l, int r, int rt)
    {
        if(l == r)
        {
            Min[rt] = INF;
            return ;
        }
        int mid = (l + r) >> 1;
        build(lson);
        build(rson);
        pushUp(rt);
    }

    void update(int x, int val, int l, int r, int rt)   //�������
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

    int query(int L, int R, int l, int r, int rt)  //��������ֵ
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

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; i++)
        scanf("%d%d", &s[i], &e[i]);
    segtree.build(1, n, 1);
    for(int i = 1; i <= n; i++)
        dp[i] = INF;
    dp[1] = 0;
    segtree.update(1, 0, 1, n, 1);  //���䳤������Ϊ2���ʿ��Լ��踲�ǵ�1��û�д��۵�
    for(int i = 1; i <= m ; i++)
    {
        int val = segtree.query(s[i], e[i], 1, n, 1);   //�������ڷ���Ҫ��Ŀ�ת�Ƶĵ�����С�ķ���
        if(val + 1 < dp[e[i]])  //����С�ķ���ת�ƹ����ȵ�ǰ�������Ҫ������������
        {
            segtree.update(e[i], val + 1, 1, n, 1); //���µ�ǰ��ķ���
            dp[e[i]] = val + 1;
        }
    }
    printf("%d\n", dp[n]);
    return 0;
}
