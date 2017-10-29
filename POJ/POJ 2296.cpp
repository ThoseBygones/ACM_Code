#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
#include <cmath>
using namespace std;

#define MAXN 205
#define MAXE 40005

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

    struct City
    {
        int x,y;
        City() {}
        City(int x,int y):x(x),y(y) {}
    } p[MAXN];

    int mark[MAXN<<1];  //mark[i<<1]==1，表示点i被选择；mark[i<<1|1]==1，表示点i没有被选择
    int cnt,scc_cnt,dfs_clock;
    int n,m;

    stack <int> sta;

    int dfn[MAXN<<1];
    int low[MAXN<<1];
    int belong[MAXN<<1];

    //使用前调用
    void init(int n)
    {
        this -> n = n;
    }

    inline void addEdge(int u,int v)
    {
        e[cnt].to = v;
        e[cnt].next = head[u];
        head[u] = cnt++;
    }


    /*判断2-SAT问题是否有解*/
    void tarjan(int u)  //Tarjan算法求解强连通分量并缩点
    {
        dfn[u] = low[u] = ++dfs_clock;
        mark[u] = 1;
        sta.push(u);
        for(int i = head[u]; ~i; i = e[i].next)
        {
            int v = e[i].to;
            if(!mark[v])
            {
                tarjan(v);
                low[u] = min(low[u],low[v]);
            }
            if(mark[v]==1)
                low[u] = min(low[u],dfn[v]);
        }
        if(dfn[u]==low[u])
        {
            scc_cnt++;
            int temp;
            do
            {
                temp = sta.top();
                belong[temp] = scc_cnt;
                mark[temp] = 2;
                sta.pop();
            }
            while(temp!=u);
        }
    }

    bool check()    //判断缩点后有没有冲突
    {
        for(int i = 0; i<2*n; i++)
        {
            if(!mark[i])
                tarjan(i);
        }
        for(int i = 0; i<n; i++)
        {
            if(belong[i<<1]==belong[i<<1|1])
                return false;
        }
        return true;
    }

    void buildGraph(int val)
    {
        memset(head,-1,sizeof(head));
        memset(mark,0,sizeof(mark));
        cnt = scc_cnt = dfs_clock = 0;
        memset(dfn,0,sizeof(dfn));
        memset(belong,0,sizeof(belong));
        while(!sta.empty())
            sta.pop();
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                if(abs(p[i].x-p[j].x)>=val)  //横坐标差大于一个边长，则可以随便放
                    continue;
                int u=i<<1;
                int v=j<<1; //放下边0，放上边1
                if(abs(p[i].y-p[j].y)<val)  //纵坐标差小于一个边长
                {
                    if(p[i].y==p[j].y)  //纵坐标相等，一个上一个下
                    {
                        addEdge(u,v^1);
                        addEdge(v,u^1);
                        addEdge(u^1,v);
                        addEdge(v^1,u);
                    }
                    else if(p[i].y<p[j].y)  //i所在的正方形低于j所在的正方形，i放上边j放下边
                    {
                        addEdge(u,u^1);
                        addEdge(v^1,v);
                    }
                    else    //i所在的正方形高于j所在的正方形，i放下边j放上边
                    {
                        addEdge(u^1,u);
                        addEdge(v,v^1);
                    }
                }
                else if(abs(p[i].y-p[j].y)<2*val)   //纵坐标差小于两个边长
                {
                    if(p[i].y<p[j].y)  //i所在的正方形低于j所在的正方形，ij不能放同样一边
                    {
                        addEdge(u,v);
                        addEdge(v^1,u^1);
                    }
                    else  //i所在的正方形高于j所在的正方形，ij不能放同样一边
                    {
                        addEdge(u^1,v^1);
                        addEdge(v,u);
                    }
                }
            }
        }
    }

    void solve()
    {
        for(int i=0; i<n; i++)
            scanf("%d%d",&p[i].x,&p[i].y);
        int l=0,r=20000;
        int ans;
        while(l<=r) //二分枚举正方形的边长
        {
            int mid=(l+r)>>1;
            buildGraph(mid);
            if(check())
            {
                ans=mid;
                l=mid+1;
            }
            else
                r=mid-1;
        }
        printf("%d\n",ans);
    }
} twosat;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        twosat.init(n);
        twosat.solve();
    }
    return 0;
}
