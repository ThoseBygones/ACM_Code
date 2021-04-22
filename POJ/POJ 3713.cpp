/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-04-22
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: POJ
 *  Algorithm: ����ͨ�����жϣ�Tarjan�㷨���㣩
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

const int MAXN = 505;
const int MAXE = 40005;

class CUT
{
public:
    int head[MAXN];
    int cnt;
    struct Edge
    {
        int from, to, nxt;
        Edge() {}
        Edge(int from, int to, int nxt) : from(from), to(to), nxt(nxt) {}
    } e[MAXE];

    int cut[MAXN], dfn[MAXN], low[MAXN];
    int dfs_clock;

    bool del[MAXN]; //�õ��Ƿ�ö��ɾ��

    void init(int n)
    {
        dfs_clock = 0;
        for(int i = 0; i < n; i++)
        {
            dfn[i] = 0;
            cut[i] = false;
        }
    }

    inline void addEdge(int u, int v)
    {
        e[cnt].from = u;
        e[cnt].to = v;
        e[cnt].nxt = head[u];
        head[u] = cnt++;
    }

    int dfs(int u, int fa)
    {
        int lowu = dfn[u] = ++dfs_clock;
        int child = 0;
        for(int i = head[u]; ~i; i = e[i].nxt)
        {
            int v = e[i].to;
            if(del[v])
                continue;
            if(!dfn[v])
            {
                child++;
                int lowv = dfs(v, u);
                lowu = min(lowu, lowv);
                if(lowv >= dfn[u])
                    cut[u] = true;
            }
            else if(dfn[v] < dfn[u] && v != fa)
                lowu = min(lowu, dfn[v]);
        }
        if(fa == -1 && child == 1)
            cut[u] = 0;
        low[u] = lowu;
        return lowu;
    }

    void buildGraph(int m)
    {
        memset(head, -1, sizeof(head));
        cnt = 0;
        for(int i = 0; i < m; i++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            addEdge(u, v);
            addEdge(v, u);
        }
    }

    void solve(int n, int m)
    {
        buildGraph(m);
        bool flag = true;
        for(int i = 0; i < n; i++)  //ö�ٱ�ɾ���ĵ�
        {
            init(n);
            del[i] = true;  //�õ㱻ɾ��
            dfs((i + 1) % n, -1);
            for(int u = 0; u < n; u++)
            {
                if(u == i)
                    continue;
                //printf("%d: %d %d\n", u, cut[u], dfn[u]);
                if(cut[u] || !dfn[u])   //���ڸ����߲���ͨ
                {
                    flag = false;
                    break;
                }
            }
            del[i] = false; //�ָ��ֳ�
            if(!flag)
                break;
        }
        puts(flag ? "YES" : "NO");
    }
} cut;

int main()
{
    int n, m;
    while(~scanf("%d%d", &n, &m))
    {
        if(!n && !m)
            break;
        cut.solve(n, m);
    }
    return 0;
}
