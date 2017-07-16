//注意几个要点：
//1.建双向边
//2.更新次短路时要注意 if(d2[ed.v]<ed.cost) continue;
//3.不要设置vis标记数组（因为算次短路一个点可能要被考虑多次）
//4.次短路也要入队，这就决定了dij三角形关系不能拿d[ed.v]和ee.cost来加，而应该拿刚出队的ed.cost和ee.cost相加
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

#define MAXN 10005
#define MAXE 200010
#define INF 0x3f3f3f3f

typedef int Type;

class Dijkstra
{
public:
    int head[MAXN],nxt[MAXE],cnt;
    Type d[MAXN];
    Type d2[MAXN];
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

    //初始化，n为点数
    void init(int n)
    {
        cnt = 0;
        for(int i = 0; i<=n; i++) head[i] = -1;
    }

    inline void addEdge(int u,int v,Type cost)
    {
        e[cnt] = Edge(v,cost);
        int tmp = head[u];
        head[u] = cnt;
        nxt[cnt++] = tmp;
    }

    Type dijkstra(int s,int t,int n)
    {
        for(int i = 0; i<=n; i++)
        {
            d[i] = INF;
            d2[i] = INF;
        }
        d[s] = 0;
        priority_queue<Edge> q;
        q.push(Edge(s,0));
        while(!q.empty())
        {
            Edge ed = q.top();
            q.pop();
            if(d2[ed.v]<ed.cost)
                continue;
            for(int i = head[ed.v]; ~i; i = nxt[i])
            {
                Edge ee = e[i];
                int dis = ed.cost+ee.cost;  //注意，这里是ed.cost+ee.cost而不是d[ed.v]+ee.cost与最短路不一样
                if(d[ee.v]>dis)
                {
                    swap(dis,d[ee.v]);
                    /*
                     *  最短路树
                    	p[ee.v] = MP(u,i);
                    */
                    q.push(Edge(ee.v,d[ee.v]));
                }
                if(d[ee.v]<dis && d2[ee.v]>dis)
                {
                    d2[ee.v] = dis;
                    q.push(Edge(ee.v,d2[ee.v]));
                }
            }
        }
        return d2[t];
    }
} dij;

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    dij.init(n);
    for(int i=1; i<=m; i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        dij.addEdge(u,v,w);
        dij.addEdge(v,u,w);
    }
    int ans=dij.dijkstra(1,n,n);
    printf("%d\n",ans);
    return 0;
}

/*附一组数据
4 6
1 2 1
1 2 5
1 3 2
2 3 2
2 4 1
2 4 6

ans: 4
*/
