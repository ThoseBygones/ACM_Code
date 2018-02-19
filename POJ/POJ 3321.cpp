/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2018-02-18
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: POJ
 *  Algorithm: DFS序 + 树状数组
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
#define MAXN 100005
#define MAXE 100005
using namespace std;

struct Edge
{
    int v,nxt;
    Edge() {}
    Edge(int v,int nxt):v(v),nxt(nxt) {}
} e[MAXE<<1];

int head[MAXN];
int cnt;

void addEdge(int u,int v)
{
    e[cnt].v = v;
    e[cnt].nxt = head[u];
    head[u] = cnt++;
}

int dfs_clock;  //dfs序时间戳
int lnd[MAXN],rnd[MAXN];    //为每一个结点赋一个左值lnd和一个右值rnd，这个区间表示这个结点的管辖结点范围。

void init()
{
    memset(head,-1,sizeof(head));
    cnt = 0;
    dfs_clock = 0;
}

void dfs(int u,int fa)  //dfs序
{
    lnd[u] = ++dfs_clock;   //记录dfs序下该结点被访问的起始时间戳
    for(int i=head[u]; ~i; i=e[i].nxt)
    {
        int v = e[i].v;
        if(v != fa)
            dfs(v,u);
    }
    rnd[u] = dfs_clock; //记录dfs序下该结点被访问的结束时间戳
}

int bit[MAXN];
int n;

void add(int i,int x)
{
    while(i <= n)
    {
        bit[i] += x;
        i += lowbit(i);
    }
}

int getSum(int i)
{
    int sum = 0;
    while(i > 0)
    {
        sum += bit[i];
        i -= lowbit(i);
    }
    return sum;
}

int apple[MAXN];    //记录某个结点当前是否有苹果

int main()
{
    scanf("%d",&n);
    init();
    for(int i=1; i<n; i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        addEdge(u,v);
        addEdge(v,u);
    }
    dfs(1,0);
    memset(bit,0,sizeof(bit));
    memset(apple,0,sizeof(apple));
    for(int i=1; i<=n; i++) //初始化所有结点都有一个苹果
    {
        apple[i]=1;
        add(i,1);
    }
    int q;
    scanf("%d",&q);
    while(q--)
    {
        char op[2];
        int x;
        scanf("%s %d",op,&x);
        if(op[0]=='C')
        {
            if(apple[x])    //该结点有苹果，则摘去
                add(lnd[x],-1);
            else    //该结点没有苹果，则长出一个新的
                add(lnd[x],1);
            apple[x]^=1;    //改变该结点状态
        }
        else
            printf("%d\n",getSum(rnd[x])-getSum(lnd[x]-1));
    }
    return 0;
}
