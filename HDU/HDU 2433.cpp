/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-11-16
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: HDU
 *  Algorithm: ���·��dijkstra
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

const int MAXN = 105;
const int MAXE = 6010;

typedef int Type;

class Dijkstra
{
public:
    int head[MAXN], nxt[MAXE], cnt;
    int pre[MAXN];  //ǰһ�����
    Type d[MAXN];
    struct Edge
    {
        int v;
        Type cost;
        Edge() {}
        Edge(int v, Type cost) : v(v), cost(cost) {}
        bool operator < (const Edge& ed) const
        {
            return cost > ed.cost;
        }
    } e[MAXE];
    bool vis[MAXN];
    int u[MAXE], v[MAXE];
    int sum[MAXN];  //��ĳ����Ϊ����õ����·��·�����Ⱥ�
    int ecnt[MAXN][MAXN];   //����֮��ߵ�����
    bool exist[MAXN][MAXN][MAXN];   //exist[s][i][j]��ʾ��sΪ�������·���У�i��j��������Ƿ����
    int n, m;

    //��ʼ����nΪ������mΪ����
    void init(int n, int m)
    {
        this -> n = n;
        this -> m = m;
        cnt = 0;
        memset(head, -1, sizeof(head));
    }

    inline void addEdge(int u, int v, Type cost)
    {
        e[cnt] = Edge(v, cost);
        int tmp = head[u];
        head[u] = cnt;
        nxt[cnt++] = tmp;
    }

    Type dijkstra(int s, int eid)   //eid��ʾ��ֹͨ���ı߱��
    {
        for(int i = 0; i <= n; i++)
        {
            d[i] = INF;
            vis[i] = false;
            pre[i] = -1;
        }
        d[s] = 0;
        priority_queue<Edge> q;
        q.push(Edge(s, 0));
        while(!q.empty())
        {
            Edge ed = q.top();
            q.pop();
            if(vis[ed.v])   //û�и��жϻ�TLE
                continue;
            vis[ed.v] = true;
            for(int i = head[ed.v]; ~i; i = nxt[i])
            {
                //cout << "id: " << i << " - " << (i ^ 1) << endl;
                if(i == eid || (i ^ 1) == eid)  //��ֹͨ���ıߺ��䷴��߾�����ͨ��
                    continue;
                Edge ee = e[i];
                if(!vis[ee.v] && d[ee.v] > d[ed.v] + ee.cost)
                {
                    d[ee.v] = d[ed.v] + ee.cost;
                    pre[ee.v] = ed.v;
                    q.push(Edge(ee.v, d[ee.v]));
                }
            }
        }
        int tmpsum = 0;
        for(int i = 1; i <= n; i++)
        {
            //cout << i << ": " << d[i] << endl;
            if(d[i] >= INF)
                return -1;
            tmpsum += d[i];
        }
        return tmpsum;
    }

    void buildGraph()
    {
        memset(ecnt, 0, sizeof(ecnt));
        for(int i = 0; i < m; i++)
        {
            scanf("%d%d", &u[i], &v[i]);
            if(!ecnt[u[i]][v[i]])
            {
                addEdge(u[i], v[i], 1);
                addEdge(v[i], u[i], 1);
            }
            else
                cnt += 2;
            ecnt[u[i]][v[i]]++, ecnt[v[i]][u[i]]++;
        }
    }

    void solve()
    {
        buildGraph();   //��ͼ
        bool flag = true;
        memset(exist, false, sizeof(exist));
        for(int s = 1; s <= n; s++)
        {
            sum[s] = dijkstra(s, -1);
            if(~sum[s])
            {
                for(int i = 1; i <= n; i++)
                {
                    if(~pre[i])
                    {
                        exist[s][pre[i]][i] = true;
                        exist[s][i][pre[i]] = true;
                    }
                }
            }
            else
            {
                flag = false;
                break;
            }
        }
        for(int i = 0; i < m; i++) //ö�ٱ�
        {
            //cout << ecnt[u[i]][v[i]] << endl;
            if(flag)
            {
                int ans = 0;
                bool flag2 = true;
                for(int s = 1; s <= n; s++) //ö�����
                {
                    if(exist[s][u[i]][v[i]] && ecnt[u[i]][v[i]] == 1)   //��ֹͨ���ı���ԭ�������·�����Ҳ����ر�
                    {
                        int tmpsum = dijkstra(s, i << 1);   //���������·��
                        if(~tmpsum)
                            ans += tmpsum;
                        else
                        {
                            flag2 = false;
                            break;
                        }
                    }
                    else    //����Ӱ�����·��
                        ans += sum[s];
                }
                if(flag2)
                    printf("%d\n", ans);
                else
                    puts("INF");
            }
            else
                puts("INF");
        }
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
