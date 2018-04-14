/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2018-04-14
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: HDU
 *  Algorithm: 差分约束
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
const double EPS = 1e-6;
const int INF = 0x3fffffff;
const LL LINF = INF * 1ll * INF;
const double PI = acos(-1.0);

#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define lowbit(u) (u&(-u))
#define MAXN 4010
#define MAXM 4010
#define MAXE 8010

typedef int Type;

int kase=1;

class Diff_Constrain
{
public:
    int head[MAXM],nxt[MAXE],cnt;
    Type dis[MAXN];
    struct Edge
    {
        int v;
        Type cost;
        Edge() {}
        Edge(int v,Type cost):v(v),cost(cost) {}
    } e[MAXE];

    bool inq[MAXM];

    void init()
    {
        cnt = 0;
        memset(head,-1,sizeof(head));
    }

    inline void addEdge(int u,int v,Type cost)
    {
        e[cnt] = Edge(v,cost);
        int tmp = head[u];
        head[u] = cnt;
        nxt[cnt++] = tmp;
    }

    int inqcnt[MAXN];

    bool spfa(int s,int n)
    {
        for(int i=0; i<=n; i++)
        {
            inq[i] = false;
            dis[i] = INF;
            inqcnt[i] = 0;
        }
        dis[s] = 0;
        inq[s] = true;
        inqcnt[s] = 1;
        queue <int> q;
        q.push(s);
        while(!q.empty())
        {
            int x = q.front();
            q.pop();
            inq[x] = false;
            for(int i=head[x]; ~i; i=nxt[i])
            {
                Edge ed = e[i];
                if(dis[ed.v]>dis[x]+ed.cost)
                {
                    dis[ed.v] = dis[x] + ed.cost;
                    if(!inq[ed.v])
                    {
                        if(++inqcnt[ed.v]>n)
                            return false;
                        inq[ed.v] = true;
                        q.push(ed.v);
                    }
                }
            }
        }
        return true;
    }

    void solve()
    {
        int n,m,x;
        scanf("%d%d%d",&n,&m,&x);
        init();
        for(int i=1; i<=n; i++)
        {
            addEdge(0,i,0);
            if(i!=1)
                addEdge(i,i-1,-1);
        }
        int a,b,c,d;
        bool flag=true;
        while(m--)
        {
            scanf("%d%d%d%d",&a,&b,&c,&d);
            if(a==b)
            {
                if(c==d)
                {
                    if(b==c)
                    {
                        flag=false;
                        continue;
                    }
                    else
                    {
                        addEdge(a,c,x);
                        addEdge(c,a,-x);
                    }
                }
                else
                {
                    if(b==c)
                        addEdge(d,c,-x-1);
                    else
                    {
                        addEdge(a,c,x-1);
                        addEdge(d,a,-x-1);
                    }
                }
            }
            else
            {
                if(c==d)
                {
                    if(b==c)
                        addEdge(b,a,-x-1);
                    else
                    {
                        addEdge(b,c,x-1);
                        addEdge(c,a,-x-1);
                    }
                }
                else
                {
                    if(a==c && b==d)
                        addEdge(b,a,-x-1);
                    else
                    {
                        addEdge(b,c,x-1);
                        addEdge(d,a,-x-1);
                    }
                }
            }
        }
        printf("Case #%d:",kase++);
        if(!flag || !spfa(0,n+1))
            puts(" IMPOSSIBLE");
        else
        {
            for(int i=2; i<=n; i++)
                printf(" %d",dis[i]-dis[i-1]);
            puts("");
        }
    }
} diff_con;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
        diff_con.solve();
    return 0;
}
