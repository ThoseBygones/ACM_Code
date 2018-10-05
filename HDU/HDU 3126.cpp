/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2018-10-04
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: HDU
 *  Algorithm: 计算几何 + 最大流Dinic
 ********************************************************************************
 *  Algo-Description:
 ********************************************************************************
 */

//#include <bits/stdc++.h>  //For CodeForces only

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
const double EPS = 1e-8;
const int INF = 0x3fffffff;
const LL LINF = INF * 1ll * INF;
const double PI = acos(-1.0);

#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define lowbit(u) (u&(-u))
#define MAXN 1010
#define MAXE 100010
#define Vector Point

typedef double Type;

inline int dcmp(double x)
{
    return (x > EPS) - (x < -EPS);
}

struct Point
{
    Type x, y;
    //int belong;   //属于哪一个圆
    Point(Type x=0,Type y=0):x(x),y(y) {}

    Vector operator + (const Vector& rhs) const
    {
        return Vector(x + rhs.x, y + rhs.y);
    }
    Vector operator - (const Point& rhs) const
    {
        return Vector(x - rhs.x, y - rhs.y);
    }
    Vector operator * (Type p) const
    {
        return Vector(x * p, y * p);
    }
    Vector operator / (Type p) const
    {
        return Vector(x / p, y / p);
    }
    bool operator < (const Point& rhs) const
    {
        return dcmp(x - rhs.x) < 0 || (dcmp(x-rhs.x)==0 && dcmp(y-rhs.y) < 0);
    }
    /*
    bool operator < (const Point& rhs) const
    {
        return x < rhs.x || (x == rhs.x && y < rhs.y);
    }
    */
    bool operator == (const Point& rhs) const
    {
        return dcmp(x - rhs.x) == 0 && dcmp(y - rhs.y) == 0;
    }
    bool operator > (const Point& rhs) const
    {
        return !(*this < rhs || *this == rhs);
    }
    bool operator >= (const Point& rhs) const
    {
        return !(*this < rhs);
    }
    bool operator <= (const Point& rhs) const
    {
        return (*this < rhs || *this == rhs);
    }
    double operator * (const Vector& rhs) const //点积
    {
        return x * rhs.x + y * rhs.y;
    }
    double operator ^ (const Vector& rhs) const //叉积
    {
        return x * rhs.y - y * rhs.x;
    }

    void read()
    {
        scanf("%lf%lf",&x,&y);
    }

    void print() const
    {
        printf("(%f, %f)",x,y);
    }
};

//距离
Type Length(Point p1,Point p2)
{
    Type x = p1.x - p2.x, y = p1.y - p2.y;
    return sqrt(x * x + y * y);
}

//向量的模
Type Length(Vector v)
{
    return sqrt(v * v);
}

struct Line
{
    Point a,b;  //直线（线段）的两个端点（线段的时候可把a当作起点）
    Vector v;   //方向向量，v = b - a
    //double ang;//极角
    Line() {}
    Line(Point a,Point b):a(a),b(b)
    {
        v = b - a; /*ang = atan2(v.y, v.x);*/
    }
};

typedef Line Segment;

Type DistanceToSegment(Point p,Segment seg)
{
    if(seg.a == seg.b)
        return Length(p,seg.a);
    Vector v1 = seg.b - seg.a, v2 = p - seg.a, v3 = p - seg.b;
    if(dcmp(v1 * v2) < 0)
        return Length(v2);
    else if(dcmp(v1 * v3) > 0)
        return Length(v3);
    else
        return fabs(v1 ^ v2) / Length(v1);
}

struct Circle
{
    Point p;
    double r;
    Circle(Point p,double r):p(p),r(r) {}
    Circle() {}
    void read()
    {
        scanf("%lf%lf%lf",&p.x,&p.y,&r);
    }
};

bool isInCircle(Point p, Circle C)
{
    return dcmp((p-C.p)*(p-C.p)-C.r*C.r) <= 0;
}

Circle lich[MAXN>>1],tree[MAXN>>1];
Point wisp[MAXN>>1];
int tt[MAXN>>1];

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
    int n,m,k;
    int node;

    bool bfs()
    {
        for(int i = 0; i<=node; i++)
            d[i] = -1;
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
        if(x==t||a==0)
            return a;
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
                if(a==0)
                    break;
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
    void init(int n,int m,int k)
    {
        this -> n = n;
        this -> m = m;
        this -> k = k;
    }

    int maxFlow()
    {
        int flow = 0;
        while(bfs())
        {
            for(int i = 0; i<=node; i++)
                cur[i] = head[i];
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
        node = t;
        for(int i=1; i<=n; i++)
            addEdge(s,i,val/tt[i]+1);   //源点向每个lisp连一条容量为1的边
        for(int i=1; i<=m; i++)
            addEdge(i+n,t,1);   //每个wisp向汇点连一条容量为1的边
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(!isInCircle(wisp[j],lich[i]))    //wisp在lisp的攻击范围内
                    continue;
                bool flag = true;
                for(int h=1; h<=k; h++)
                {
                    Segment l = Segment(lich[i].p,wisp[j]);
                    if(DistanceToSegment(tree[h].p,l) <= tree[h].r)  //没有tree阻挡
                    {
                        flag = false;
                        break;
                    }
                }
                if(flag)
                    addEdge(i,j+n,1);   //每个lisp向自己可以攻击到的wisp连边，容量为 (估计时间 / 冷却时间 + 1)
            }
        }
    }

    void solve()
    {
        int maxt=0;
        for(int i=1; i<=n; i++)
        {
            lich[i].read();
            scanf("%d",&tt[i]);
            maxt=max(maxt,tt[i]);
        }
        for(int i=1; i<=m; i++)
            wisp[i].read();
        for(int i=1; i<=k; i++)
            tree[i].read();
        int l = 0,r = m * maxt;
        int ans = -1;
        while(l <= r) //二分答案
        {
            int mid = (l + r) >> 1;
            buildGraph(mid);
            if(maxFlow() < m)
                l = mid + 1;
            else
            {
                ans = mid;
                r = mid - 1;
            }
        }
        printf("%d\n",ans);
    }
} dinic;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m,k;
        scanf("%d%d%d",&n,&m,&k);
        dinic.init(n,m,k);
        dinic.solve();
    }
    return 0;
}
