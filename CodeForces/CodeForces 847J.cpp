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
#define clr(ar,val) memset(ar, val, sizeof(ar))
#define istr stringstream
#define FOR(i,n) for(int i=0;i<(n);++i)
#define forIt(mp,it) for(__typeof(mp.begin()) it = mp.begin();it!=mp.end();it++)
const double EPS = 1e-6;
const int INF = 0x3fffffff;
const LL LINF = INF * 1ll * INF;
const double PI = acos(-1.0);

#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define lowbit(u) (u&(-u))
#define MAXN 10005
#define MAXE 100005
using namespace std;

class Dinic
{
private:
    int d[MAXN];
    int head[MAXN],nxt[MAXE],cur[MAXN];
    struct Edge
    {
        int from,to,cap,flow;
        Edge(int from,int to,int cap,int flow):from(from),to(to),cap(cap),flow(flow) {}
        Edge() {}
    } e[MAXE];

    int s,t,cnt;
    int n,m;
    int u[MAXN],v[MAXN];

    bool bfs()
    {
        for(int i = 0; i<=t; i++) d[i] = -1;
        d[s] = 0;
        queue<int> q;
        q.push(s);
        while(!q.empty())
        {
            int x = q.front();
            q.pop();
            for(int i = head[x]; ~i; i = nxt[i])
            {
                Edge &ed = e[i];
                if(d[ed.to]==-1&&ed.cap>ed.flow)
                {
                    d[ed.to] = d[x]+1;
                    q.push(ed.to);
                }
            }
        }
        return d[t]!=-1;
    }
    int dfs(int x,int a)
    {
        if(x==t||a==0) return a;
        int flow = 0,f;
        for(; ~cur[x]; cur[x] = nxt[cur[x]])
        {
            Edge &ed = e[cur[x]];
            if(d[ed.to]==d[x]+1&&(f = dfs(ed.to,min(ed.cap-ed.flow,a)))>0)
            {
                flow+=f;
                ed.flow+=f;
                e[cur[x]^1].flow-=f;
                a-=f;
                if(a==0) break;
            }
        }
        return flow;
    }

    void addEdge(int from,int to,int cap)
    {
        e[cnt] = Edge(from,to,cap,0);
        int tmp = head[from];
        head[from] = cnt;
        nxt[cnt++] = tmp;
        e[cnt] = Edge(to,from,0,0);
        tmp = head[to];
        head[to] = cnt;
        nxt[cnt++] = tmp;
    }
public:
    void init(int n,int m)
    {
        this -> n = n;
        this -> m = m;
    }

    int maxFlow()
    {
        int flow = 0;
        while(bfs())
        {
            for(int i = 0; i<=t; i++) cur[i] = head[i];
            flow+=dfs(s,INF);
        }
        return flow;
    }

    void buildGraph(int val)
    {
        cnt = 0;
        memset(head,-1,sizeof(head));
        s = 0;
        t = n + m + 1;
        for(int i=1; i<=m; i++)
        {
            addEdge(u[i],n+i,1);
            addEdge(v[i],n+i,1);
            addEdge(n+i,t,1);
        }
        for(int i=1; i<=n; i++)
            addEdge(s,i,val);
    }

    bool check(int val)
    {
        buildGraph(val);
        return maxFlow()==m?true:false;
    }

    void solve()
    {
        for(int i=1; i<=m; i++)
            scanf("%d%d",&u[i],&v[i]);
        int l=0,r=10000;
        int ans;
        while(l<=r)
        {
            int mid=(l+r)>>1;
            if(check(mid))
            {
                ans=mid;
                r=mid-1;
            }
            else
                l=mid+1;
        }
        check(ans);
        printf("%d\n",ans);
        for(int i=0; i<cnt; i++)
        {
            if(e[i].flow && e[i].from<=n && e[i].to>n && e[i].to!=n+m+1)
            {
                int j=e[i].to-n;
                int x=e[i].from;
                int y=u[j]^v[j]^x;  //异或得到u,v中的另一个
                printf("%d %d\n",x,y);
            }
        }
    }
} dinic;


int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    dinic.init(n,m);
    dinic.solve();
    return 0;
}
