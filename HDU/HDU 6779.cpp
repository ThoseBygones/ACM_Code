/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-07-25
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: HDU
 *  Algorithm: 费用流（最大费用最大流）
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
#define MAXN 25
#define MAXE 205

class MCMF
{
public:
    typedef int CostType;
    struct Edge
    {
        int from,to,cap,flow;
        CostType cost;
        Edge(int from,int to,int cap,int flow,CostType cost):from(from),to(to),cap(cap),flow(flow),cost(cost) {}
        Edge() {}
    } e[MAXE];

    int head[MAXN],nxt[MAXE],a[MAXN],p[MAXN];
    bool inq[MAXN];
    CostType d[MAXN];
    int cnt,s,t;
    int node;
    int n, aa, bb, cc;
    int val[6];

    void init()
    {
        cnt = 0;
    }

    void addEdge(int from,int to,int cap,CostType cost)
    {
        e[cnt] = Edge(from,to,cap,0,cost);
        int tmp = head[from];
        head[from] = cnt;
        nxt[cnt++] = tmp;
        e[cnt] = Edge(to,from,0,0,-cost);
        tmp = head[to];
        head[to] = cnt;
        nxt[cnt++] = tmp;
    }

    bool spfa(int &flow,CostType &cost)
    {
        for(int i = 0; i<=node; i++)
        {
            d[i] = INF;
            inq[i] = false;
        }
        d[s] = 0,inq[s] = true,p[s] = 0,a[s] = INF;
        queue<int> q;
        q.push(s);
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            inq[u] = false;
            for(int i = head[u]; ~i; i = nxt[i])
            {
                Edge &ed = e[i];
                if(ed.cap>ed.flow&&d[ed.to]>d[u]+ed.cost)
                {
                    d[ed.to] = d[u]+ed.cost;
                    p[ed.to] = i;
                    a[ed.to] = min(a[u],ed.cap-ed.flow);
                    if(!inq[ed.to])
                    {
                        inq[ed.to] = true;
                        q.push(ed.to);
                    }
                }
            }
        }
        if(d[t]==INF) return false;
        flow+=a[t];
        cost+=d[t]*a[t];
        int u = t;
        while(u!=s)
        {
            e[p[u]].flow+=a[t];
            e[p[u]^1].flow-=a[t];
            u = e[p[u]].from;
        }
        return true;
    }

    CostType maxFlow()
    //int maxFlow()
    {
        int flow = 0;
        CostType cost = 0;
        while(spfa(flow,cost));
        //return flow;
        return cost;
    }

    void buildGraph()
    {
        memset(head,-1,sizeof(head));
        s = 0;
        t = 10;
        node = t;
        /*源点到三种饮料建边*/
        addEdge(s, 1, aa, 0);
        addEdge(s, 2, bb, 0);
        addEdge(s, 3, cc, 0);
        /*可乐到六种人建边*/
        addEdge(1, 4, aa, -3);
        addEdge(1, 5, aa, -3);
        addEdge(1, 6, aa, -2);
        addEdge(1, 7, aa, -1);
        addEdge(1, 8, aa, -2);
        addEdge(1, 9, aa, -1);
        /*雪碧到六种人建边*/
        addEdge(2, 4, bb, -2);
        addEdge(2, 5, bb, -1);
        addEdge(2, 6, bb, -3);
        addEdge(2, 7, bb, -3);
        addEdge(2, 8, bb, -1);
        addEdge(2, 9, bb, -2);
        /*芬达到六种人建边*/
        addEdge(3, 4, cc, -1);
        addEdge(3, 5, cc, -2);
        addEdge(3, 6, cc, -1);
        addEdge(3, 7, cc, -2);
        addEdge(3, 8, cc, -3);
        addEdge(3, 9, cc, -3);
        /*六种人到汇点建边*/
        for(int i = 0; i < 6; i++)
            addEdge(4 + i, 10, val[i], 0);
    }

    void solve()
    {
        scanf("%d%d%d%d", &n, &aa, &bb, &cc);
        memset(val, 0, sizeof(val));
        for(int i = 0; i < n; i++)
        {
            char s[5];
            scanf("%s", s);
            if(s[0] == '0')
            {
                if(s[1] == '1')
                    val[0]++;
                else if(s[1] == '2')
                    val[1]++;
            }
            else if(s[0] == '1')
            {
                if(s[1] == '0')
                    val[2]++;
                else if(s[1] == '2')
                    val[3]++;
            }
            else if(s[0] == '2')
            {
                if(s[1] == '0')
                    val[4]++;
                else if(s[1] == '1')
                    val[5]++;
            }
        }
        /*
        for(int i = 0; i < 6; i++)
            printf("--%d\n", val[i]);
        */
        buildGraph();
        int ans = maxFlow();
        printf("%d\n", -ans);
    }
} mcmf;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        mcmf.init();
        mcmf.solve();
    }
    return 0;
}
