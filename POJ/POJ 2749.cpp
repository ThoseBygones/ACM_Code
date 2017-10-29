#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

#define MAXN 1005
#define MAXE 2000005

class TwoSat
{
public:
    int head[MAXN<<1];
    struct Edge
    {
        int to,next;
        Edge() {}
        Edge(int to,int next):to(to),next(next) {}
    } e[MAXE];

    struct Barn
    {
        int x,y;
        Barn() {}
        Barn(int x,int y):x(x),y(y) {}
    } barn[MAXN<<1],s1,s2;

    int mark[MAXN<<1];  //mark[i<<1]==1，表示点i被选择；mark[i<<1|1]==1，表示点i没有被选择
    int cnt,scc_cnt,dfs_clock;
    int n,a,b;
    int top;

    int dfn[MAXN<<1];
    int low[MAXN<<1];
    int sta[MAXN<<1];   //数组模拟栈

    int hate1[MAXN];
    int hate2[MAXN];
    int like1[MAXN];
    int like2[MAXN];
    int dis1[MAXN];
    int dis2[MAXN];


    //使用前调用
    void init(int n,int a,int b)
    {
        this -> n = n;
        this -> a = a;
        this -> b = b;
        cnt = scc_cnt = dfs_clock = 0;
        top = 0;
        memset(dfn,0,sizeof(dfn));
    }

    inline void addEdge(int u,int v)
    {
        e[cnt].to = v;
        e[cnt].next = head[u];
        head[u] = cnt++;
    }

    int getDis(Barn a,Barn b)
    {
        return abs(a.x-b.x)+abs(a.y-b.y);
    }

    /*暴力求2-SAT问题的字典序最小解（复杂度O(n*m)）*/
    bool dfs(int u) //判断当前的强连通分量当中有没有出现矛盾
    {
        if(mark[u^1]) return false; //如果需要被选的不能被选那么矛盾
        if(mark[u]) return true;    //如果需要被选的已经被选，那么当前联通分量一定不会出现矛盾
        mark[u] = true; //如果当前点需要被选，那么选上它，并且标记
        sta[top++] = u; //当前的强连通分量加上这个点
        //找到与当前点相连点，判断他们的状态
        for(int i = head[u]; ~i; i = e[i].next)
        {
            int v = e[i].to;
            if(!dfs(v))
                return false;
        }
        return true;
    }

    bool solve()   //n是变量数
    {
        for(int i = 0; i<n*2; i+=2)
        {
            if(!mark[i]&&!mark[i^1])
            {
                top = 0;
                if(!dfs(i)) //如果矛盾，那么这个强连通分量里的点都不能选取
                {
                    while(top>0)
                        mark[sta[--top]] = false;
                    if(!dfs(i^1))
                        return false;
                }
            }
        }
        return true;
    }

    void buildGraph(int val)
    {
        memset(head,-1,sizeof(head));
        memset(mark,0,sizeof(mark));
        int len=getDis(s1,s2);
        for(int i=0; i<a; i++)
        {
            int u=hate1[i]<<1;
            int v=hate2[i]<<1;
            addEdge(u,v^1);
            addEdge(u^1,v);
            addEdge(v,u^1);
            addEdge(v^1,u);
        }
        for(int i=0; i<b; i++)
        {
            int u=like1[i]<<1;
            int v=like2[i]<<1;
            addEdge(u,v);
            addEdge(u^1,v^1);
            addEdge(v,u);
            addEdge(v^1,u^1);
        }
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                int u=i<<1;
                    int v=j<<1;
                if(dis1[i]+dis1[j]>val) //不能两条路都连到s1
                {
                    addEdge(u,v^1);
                    addEdge(v,u^1);
                }
                if(dis2[i]+dis2[j]>val) //不能两条路都连到s2
                {
                    addEdge(u^1,v);
                    addEdge(v^1,u);
                }
                if(dis1[i]+dis2[j]+len>val) //不能前一个连s1，后一个连s2
                {
                    addEdge(u,v);
                    addEdge(v^1,u^1);
                }
                if(dis2[i]+dis1[j]+len>val) //不能前一个连s2，后一个连s1
                {
                    addEdge(u^1,v^1);
                    addEdge(v,u);
                }
            }
        }
    }

    void work()
    {
        scanf("%d%d%d%d",&s1.x,&s1.y,&s2.x,&s2.y);
        for(int i=0; i<n; i++)
        {
            scanf("%d%d",&barn[i].x,&barn[i].y);
            dis1[i]=getDis(barn[i],s1);
            dis2[i]=getDis(barn[i],s2);
        }
        for(int i=0; i<a; i++)
        {
            scanf("%d%d",&hate1[i],&hate2[i]);
            hate1[i]--;
            hate2[i]--;
        }
        for(int i=0; i<b; i++)
        {
            scanf("%d%d",&like1[i],&like2[i]);
            like1[i]--;
            like2[i]--;
        }
        int l=0,r=5000000;
        int ans=-1;
        while(l<=r)
        {
            int mid=(l+r)>>1;
            buildGraph(mid);
            if(solve())
            {
                ans=mid;
                r=mid-1;
            }
            else
                l=mid+1;
        }
        printf("%d\n",ans);
    }
} twosat;

int main()
{
    int n,a,b;
    while(~scanf("%d%d%d",&n,&a,&b))
    {
        twosat.init(n,a,b);
        twosat.work();
    }
    return 0;
}
