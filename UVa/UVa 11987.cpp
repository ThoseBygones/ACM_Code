/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-06-04
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: UVA
 *  Algorithm: 单点修改并查集
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

const int MAXN = 100005;

int fa[MAXN << 1];
int cnt[MAXN << 1], sum[MAXN << 1];

int findSet(int x)
{
    if(x != fa[x])
        return fa[x] = findSet(fa[x]);
    return fa[x];
}

void unionSet(int x, int y)
{
    int fx = findSet(x);
    int fy = findSet(y);
    if(fx != fy)
    {
        fa[fx] = fy;
        sum[fy] += sum[fx];
        cnt[fy] += cnt[fx];
    }
}

void modifyNode(int x, int y)
{
    int fx = findSet(x);
    int fy = findSet(y);
    if(fx != fy)
    {
        fa[x] = fy;
        sum[fx] -= x;
        sum[fy] += x;
        cnt[fx]--;
        cnt[fy]++;
    }
}

int main()
{
    int n, m;
    while(~scanf("%d%d", &n, &m))
    {
        for(int i = 1; i <= n; i++)
        {
            fa[i] = fa[i + n] = i + n;
            cnt[i + n] = 1;
            sum[i + n] = i;
        }
        while(m--)
        {
            int op;
            scanf("%d", &op);
            if(op == 1)
            {
                int p, q;
                scanf("%d%d", &p, &q);
                unionSet(p, q);
            }
            else if(op == 2)
            {
                int p, q;
                scanf("%d%d", &p, &q);
                modifyNode(p, q);
            }
            else if(op == 3)
            {
                int p;
                scanf("%d", &p);
                int fp = findSet(p);
                printf("%d %d\n", cnt[fp], sum[fp]);
            }
        }
    }
    return 0;
}
/*
5 7
1 1 2
2 3 4
1 3 5
3 4
2 4 1
3 4
3 3
*/
