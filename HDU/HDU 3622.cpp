#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
#include <cmath>
using namespace std;

#define MAXN 105
#define MAXE 40005
#define EPS 1e-6

typedef double Type;

int sign(Type x)
{
    return x<-EPS?-1:(x>EPS?1:0);
}

struct Point
{
    Type x,y;
    Point(Type x,Type y):x(x),y(y) {}
    Point() {}
    void read()
    {
        scanf("%lf %lf",&x,&y);
    }
    bool operator==(const Point& p) const
    {
        return sign(x-p.x)==0&&sign(y-p.y)==0;
    }
    Point operator-(const Point& p) const
    {
        return Point(x-p.x,y-p.y);
    }
    Point operator*(const Type t) const
    {
        return Point(t*x,t*y);
    }
    Point operator+(const Point & p) const
    {
        return Point(x+p.x,y+p.y);
    }
    bool operator<(const Point& p) const
    {
        return sign(x-p.x)==0?sign(y-p.y)<0:sign(x-p.x)<0;
    }
};

//距离
Type Length(Point a,Point b)
{
    Type x = a.x-b.x,y = a.y-b.y;
    return sqrt(x*x+y*y);
}

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

    int mark[MAXN<<1];  //mark[i<<1]==1，表示点i被选择；mark[i<<1|1]==1，表示点i没有被选择
    int cnt,scc_cnt,dfs_clock;
    int n,m;
    int top;

    stack <int> sta;

    int dfn[MAXN<<1];
    int low[MAXN<<1];
    int belong[MAXN<<1];

    Point p[MAXN<<1];

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

    void buildGraph(Type val)
    {
        memset(head,-1,sizeof(head));
        memset(mark,0,sizeof(mark));
        cnt = scc_cnt = dfs_clock = 0;
        memset(dfn,0,sizeof(dfn));
        memset(belong,0,sizeof(belong));
        while(!sta.empty())
            sta.pop();
        for(int i=0; i<2*n-2; i++)
        {
            for(int j=i+2-i%2; j<2*n; j++)
            {
                if(Length(p[i],p[j])<=2.0*val)
                {
                    addEdge(i,j^1);
                    addEdge(j,i^1);
                }
            }
        }
    }

    void solve()
    {
        for(int i=0; i<n; i++)
        {
            p[i<<1].read();
            p[i<<1|1].read();
        }
        Type l=0.0,r=20000.0;
        while(r-l>=EPS)
        {
            Type mid=(l+r)/2.0;
            buildGraph(mid);
            if(check())
                l=mid;
            else
                r=mid;
        }
        printf("%.2f\n",l);
    }
} twosat;

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        twosat.init(n);
        twosat.solve();
    }
    return 0;
}
