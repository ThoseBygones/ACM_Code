/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2018-06-19
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
#define MAXN 30

struct Node
{
    int fa; //父结点
    int l,r;    //左右子结点
    int sib;    //兄弟结点
    int dep;    //深度
    int hei;    //高度
    int ind;    //入度
    int outd;   //出度
} nd[MAXN];

int head[MAXN];
struct Edge
{
    int to,nxt;
    Edge() {}
    Edge(int to,int nxt):to(to),nxt(nxt) {}
} e[MAXN<<1];

int cnt;

inline void addEdge(int u,int v)
{
    e[cnt].to = v;
    e[cnt].nxt = head[u];
    head[u] = cnt++;
}

int dfs(int u,int d)
{
    nd[u].dep=d;
    nd[u].hei=0;
    int h1=0,h2=0;
    if(~nd[u].l)
        h1=dfs(nd[u].l,d+1);
    if(~nd[u].r)
        h2=dfs(nd[u].r,d+1);
    nd[u].hei=max(h1,h2);
    return nd[u].hei+1;
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        nd[i].fa=-1;
        nd[i].sib=-1;
        nd[i].ind=0;
        nd[i].outd=0;
    }
    for(int i=0; i<n; i++)
    {
        int id,l,r;
        scanf("%d%d%d",&id,&l,&r);
        nd[id].l=l,nd[id].r=r;
        if(~l)
        {
            nd[id].outd++;
            addEdge(id,l);
            nd[l].ind++;
            nd[l].fa=id;
            if(~r)
                nd[l].sib=r;
        }
        if(~r)
        {
            nd[id].outd++;
            addEdge(id,r);
            nd[r].ind++;
            nd[r].fa=id;
            if(~l)
                nd[r].sib=l;
        }
    }
    int root=0;
    for(int i=0; i<n; i++)
    {
        if(nd[i].fa==-1)
        {
            root=i;
            break;
        }
    }
    nd[root].ind=-1;
    dfs(root,0);
    for(int i=0; i<n; i++)
    {
        printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",i,nd[i].fa,nd[i].sib,nd[i].outd,nd[i].dep,nd[i].hei);
        if(nd[i].ind==-1)
            printf("root");
        else if(nd[i].outd==0)
            printf("leaf");
        else
            printf("internal node");
        puts("");
    }
    return 0;
}
