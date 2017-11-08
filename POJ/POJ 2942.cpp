//点-双连通分量+DFS交叉染色判断奇圈
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

#define MAXN 1005
#define MAXE 1000005
#define MP make_pair
#define PB push_back

typedef pair<int,int> PII;

class Vertex_BCC
{
public:
    int head[MAXN];
    struct Edge
    {
        int to,next;
        Edge() {}
        Edge(int to,int next):to(to),next(next) {}
    } e[MAXE];

    stack <PII> s;  //存储在当前BCC中的边
    int dfs_clock,bcc_cnt;
    int dfn[MAXN];
    int low[MAXN];
    int cut[MAXN];
    int bccno[MAXN];
    vector <int> bcc_nodes;
    PII bcc_edges[MAXE];
    int n,m;
    int cnt;
    int g[MAXN][MAXN];
    int color[MAXN];
    int ans;
    int mark[MAXN];

    void init(int n,int m)
    {
        this -> n = n;
        this -> m = m;
        cnt = 0;
        ans = 0;
        memset(head,-1,sizeof(head));
        memset(dfn,0,sizeof(dfn));
        memset(bccno,0,sizeof(bccno));
        memset(cut,0,sizeof(cut));
        memset(color,0,sizeof(color));
        memset(mark,0,sizeof(mark));
    }

    void addEdge(int u,int v)
    {
        e[cnt].to = v;
        e[cnt].next = head[u];
        head[u] = cnt++;
    }

    //返回边数
    int get_bcc(PII ed)
    {
        bcc_cnt++;
        bcc_nodes.clear();
        int tot = 0;
        while(true)
        {
            PII x = s.top();
            s.pop();
            int u = x.first,v = x.second;
            if(bccno[u]!=bcc_cnt)
            {
                bccno[u] = bcc_cnt;
                bcc_nodes.PB(u);
            }
            if(bccno[v]!=bcc_cnt)
            {
                bccno[v] = bcc_cnt;
                bcc_nodes.PB(v);
            }
            bcc_edges[tot++] = x;
            if(x==ed)
                break;
        }
        return tot;
    }

    void tarjan(int u,int fa)
    {
        low[u] = dfn[u] = ++dfs_clock;
        int child = 0;
        for(int i = head[u]; ~i; i = e[i].next)
        {
            int v = e[i].to;
            PII ed = MP(u,v);
            if(!dfn[v])
            {
                s.push(ed);
                child++;
                tarjan(v,u);
                low[u] = min(low[u],low[v]);
                if(low[v]>=dfn[u])
                {
                    cut[u] = true;
                    int num = get_bcc(ed);
                    //m为当前bcc的边数，bcc_nodes记录结点，bcc_edges记录边
                    color[u] = 1;   //预着色
                    if(!bipartite(u,bcc_cnt))   //dfs交叉染色判定二分图（不是二分图则是奇圈）
                    {
                        for(int i=1; i<=n; i++)
                        {
                            if(bccno[i]==bcc_cnt)   //标记在同一个双连通分量内的点
                                mark[i] = 1;
                        }
                    }
                    color[u] = 0;   //还原现场
                }
            }
            else if(dfn[v]<dfn[u]&&v!=fa)
            {
                s.push(ed);
                low[u] = min(low[u],dfn[v]);
            }
        }
        if(fa==-1&&child==1)
            cut[u] = false;
    }

    //找点-双连通分量
    void find_bcc()
    {
        for(int i = 0; i<n; i++) dfn[i] = cut[i] = bccno[i] = 0;
        dfs_clock = bcc_cnt = 0;
        for(int i = 0; i<n; i++)
        {
            if(!dfn[i])
                tarjan(i,-1);
        }
    }

    bool bipartite(int u,int idx)
    {
        for(int i = head[u]; ~i; i = e[i].next)
        {
            int v = e[i].to;
            if(bccno[v]!=idx) continue; //不在一个双连通分量内，跳过
            if(color[v]==color[u]) return false;
            if(!color[v])
            {
                color[v] = 3-color[u];
                if(!bipartite(v,idx)) return false;
            }
        }
        return true;
    }

    void buildGraph()
    {
        memset(g,0,sizeof(g));
        for(int i=0; i<m; i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            g[u][v] = g[v][u] = 1;
        }
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(i!=j && !g[i][j])    //构造补图
                    addEdge(i,j);
            }
        }
    }

    void solve()
    {
        buildGraph();
        find_bcc();
        for(int i=1; i<=n; i++)
        {
            if(!mark[i])
                ans++;
        }
        printf("%d\n",ans);
    }
} vertex_bcc;

int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        if(n==0 && m==0)
            break;
        vertex_bcc.init(n,m);
        vertex_bcc.solve();
    }
    return 0;
}
