#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <vector>
#include <map>
using namespace std;

#define INF 0x3f3f3f3f
#define PII pair
#define MP make_pair
#define LL long long
#define PB push_back
#define MOD 1000000007
#define MOD1 5837501
#define MOD2 9860381
#define MOD3 8475871

#define MAXN 1005
#define MAXE (MAXN*MAXN)

typedef LL Type;

class Dijkstra
{
public:
    int head[MAXN],nxt[MAXE],cnt;
    Type d[MAXN];
    struct Edge
    {
        int v;
        Type cost;
        Edge() {}
        Edge(int v,Type cost):v(v),cost(cost) {}
        bool operator<(const Edge& ed) const
        {
            return cost>ed.cost;
        }
    } e[MAXE];
    bool vis[MAXN];
    int n,m;
    LL x[MAXN*MAXN];
    LL y[MAXN*MAXN];
    LL z[MAXN*MAXN];

    //初始化，n为点数
    void init(int n,int m)
    {
        cnt = 0;
        this -> n = n;
        this -> m = m;
        for(int i = 0; i<n; i++) head[i] = -1;
    }

    inline void addEdge(int u,int v,Type cost)
    {
        e[cnt] = Edge(v,cost);
        int tmp = head[u];
        head[u] = cnt;
        nxt[cnt++] = tmp;
    }

    void dijkstra(int s)
    {
        for(int i = 0; i<n; i++) d[i] = INF,vis[i] = false;
        d[s] = 0;
        priority_queue<Edge> q;
        q.push(Edge(s,0));
        while(!q.empty())
        {
            Edge ed = q.top();
            q.pop();
            vis[ed.v] = true;
            //if(ed.v==t) return d[t];
            for(int i = head[ed.v]; ~i; i = nxt[i])
            {
                Edge ee = e[i];
                if(!vis[ee.v]&&d[ee.v]>d[ed.v]+ee.cost)
                {
                    d[ee.v] = d[ed.v]+ee.cost;
                    /*
                     *  最短路树
                    	p[ee.v] = MP(u,i);
                    */
                    q.push(Edge(ee.v,d[ee.v]));
                }
            }
        }
        //return d[t];
    }

    void solve()
    {
        scanf("%d%d%d%d",&x[0],&x[1],&y[0],&y[1]);
        for(int i=0; i<=1; i++)
            z[i]=(x[i]*90123+y[i])%MOD3+1;
        for(int i=2; i<=n*n; i++)
        {
            x[i]=(12345+x[i-1]*23456+x[i-2]*34567+x[i-1]*x[i-2]*45678)%MOD1;
            y[i]=(56789+y[i-1]*67890+y[i-2]*78901+y[i-1]*y[i-2]*89012)%MOD2;
            z[i]=(x[i]*90123+y[i])%MOD3+1;
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i==j)
                    addEdge(i,j,0);
                else
                    addEdge(i,j,z[i*n+j]);
                //cout << (i==j?0:z[i*n+j]) << endl;
            }
        }
        LL ans=INF;
        dijkstra(0);
        for(int i=1; i<n; i++)
        {
            if(d[i]==0)
                continue;
            LL temp=d[i]%m;
            ans=min(ans,temp);
        }
        printf("%I64d\n",ans);
    }
} dij;

int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        dij.init(n,m);
        dij.solve();
    }
    return 0;
}
