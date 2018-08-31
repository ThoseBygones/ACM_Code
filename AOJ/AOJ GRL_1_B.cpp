/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2018-08-03
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: AOJ
 *  Algorithm:
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
#define MAXN 1005
#define MAXE 4010

typedef int Type;

class SPFA
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
    } e[MAXE];

    bool inq[MAXN];

    void init(int n)
    {
        cnt = 0;
        for(int i = 0; i<=n; i++)
            head[i] = -1;
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
        for(int i = 0; i<n; i++)
            inq[i] = false,d[i] = INF,inqcnt[i] = 0;
        d[s] = 0;
        queue<int> q;
        q.push(s);
        while(!q.empty())
        {
            int x = q.front();
            q.pop();
            inq[x] = false;
            for(int i = head[x]; ~i; i = nxt[i])
            {
                Edge ed = e[i];
                if(d[ed.v]>d[x]+ed.cost)
                {
                    d[ed.v] = d[x]+ed.cost;
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

    void buildGraph(int m)
    {
        int u,v,w;
        for(int i=0; i<m; i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            addEdge(u,v,w);
        }
    }
} spfa;

int main()
{
    int n,m,s;
    scanf("%d%d%d",&n,&m,&s);
    spfa.init(n);
    spfa.buildGraph(m);
    if(spfa.spfa(s,n+1))    //n也能AC
    {
        for(int i=0; i<n; i++)
        {
            if(spfa.d[i]==INF)
                puts("INF");
            else
                printf("%d\n",spfa.d[i]);
        }
    }
    else
        puts("NEGATIVE CYCLE");
    return 0;
}
