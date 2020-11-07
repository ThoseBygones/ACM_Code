/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-11-02
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: HDU
 *  Algorithm: ö�� + ���·
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

const int MAXN = 1005;
const int MAXE = (MAXN * MAXN);

typedef int Type;

class Dijkstra
{
public:
    int head[MAXN],nxt[MAXE],cnt;
    Type d[MAXN];
    struct Edge
    {
        int u, v;
        Type cost;
        int flag;  //�ñ��Ƿ���Ա�����
        Edge() {}
        Edge(int u, int v, Type cost, int flag) : u(u), v(v), cost(cost), flag(flag) {}
        bool operator <(const Edge& ed) const
        {
            return cost > ed.cost;
        }
    } e[MAXE];
    bool vis[MAXN];
    int n, m;
    int eid[MAXN];  //���յ��Ӧ�ı߱��

    //��ʼ����nΪ������mΪ����
    void init(int n, int m)
    {
        this -> n = n;
        this -> m = m;
        cnt = 0;
        memset(head, -1, sizeof(head));
    }

    inline void addEdge(int u,int v,Type cost)
    {
        e[cnt] = Edge(u, v, cost, 0);
        int tmp = head[u];
        head[u] = cnt;
        nxt[cnt++] = tmp;
    }

    //void dijkstra(int s)
    Type dijkstra(int s, int t)
    {
        for(int i = 0; i<=n; i++)
            d[i] = INF, vis[i] = false, eid[i] = -1;
        d[s] = 0;
        priority_queue<Edge> q;
        q.push(Edge(-1, s, 0, 0));
        while(!q.empty())
        {
            Edge ed = q.top();
            q.pop();
            if(vis[ed.v])   //û�и��жϻ�TLE
                continue;
            vis[ed.v] = true;
            //if(ed.v == t)
            //    return d[t];
            for(int i = head[ed.v]; ~i; i = nxt[i])
            {
                Edge ee = e[i];
                if(!vis[ee.v] && d[ee.v] > d[ed.v] + ee.cost)
                {
                    if(ee.flag == -1)    //��·�α���ǲ�����
                        continue;
                    d[ee.v] = d[ed.v] + ee.cost;
                    /*
                     *  ���·��
                    	p[ee.v] = MP(u,i);
                    */
                    q.push(Edge(ee.u, ee.v, d[ee.v], 0));
                    eid[ee.v] = i;
                }
            }
        }
        return d[t];
    }

    void solve()
    {
        for(int i = 0; i < m; i++)
        {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            addEdge(u, v, w);
            addEdge(v, u, w);
        }
        dijkstra(1, n);
        int ans = d[n];
        int tmp = n;
        while(tmp != 1) //����ȷ��ÿ����
        {
            e[eid[tmp]].flag = 1;
            tmp = e[eid[tmp]].u;
        }
        for(int i = 0; i < cnt; i++)
        {
            if(e[i].flag == 1)  //�ҵ��������·�еı�
            {
                e[i].flag = -1; //�����䱻�ƻ�
                dijkstra(1, n);
                if(d[n] < INF)
                    ans = max(ans, d[n]);
                e[i].flag = 1;  //��ԭ�ֳ�
            }
        }
        printf("%d\n", ans);
    }
} dij;

int main()
{
    int n, m;
    while(~scanf("%d%d", &n, &m))
    {
        dij.init(n, m);
        dij.solve();
    }
    return 0;
}
