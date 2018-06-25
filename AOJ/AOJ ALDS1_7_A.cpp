/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2018-06-18
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
#define MAXN 100005

struct Node
{
    int fa; //父结点
    int dep;    //深度
    vector <int> c; //子结点
    int ind;    //入度
} nd[MAXN];

int cnt;
int head[MAXN];
struct Edge
{
    int to,nxt;
    Edge() {}
    Edge(int to,int nxt):to(to),nxt(nxt) {}
} e[MAXN<<1];

inline void addEdge(int u,int v)
{
    e[cnt].to = v;
    e[cnt].nxt = head[u];
    head[u] = cnt++;
}

void dfs(int u,int fa,int d)
{
    nd[u].dep=d;
    if(!nd[u].c.size() && ~fa)
        nd[u].ind=1;
    for(int i=0; i<nd[u].c.size(); i++)
    {
        int v=nd[u].c[i];
        dfs(v,u,d+1);
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        nd[i].fa=-1;
        nd[i].ind=0;
    }
    for(int i=0; i<n; i++)
    {
        int id,num;
        scanf("%d%d",&id,&num);
        while(num--)
        {
            int v;
            scanf("%d",&v);
            nd[id].c.PB(v);
            nd[v].fa=id;
            //cout << "$" << nd[v].fa << endl;
            addEdge(id,v);
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
    //cout << root << endl;
    nd[root].ind=-1;
    //cout << nd[root].ind << endl;
    dfs(root,-1,0);
    for(int i=0; i<n; i++)
    {
        printf("node %d: parent = %d, depth = %d, ",i,nd[i].fa,nd[i].dep);
        if(nd[i].ind==-1)
            printf("root");
        else if(nd[i].ind==0)
            printf("internal node");
        else
            printf("leaf");
        printf(", [");
        for(int j=0; j<nd[i].c.size(); j++)
        {
            if(j!=0)
                printf(", %d",nd[i].c[j]);
            else
                printf("%d",nd[i].c[j]);
        }
        printf("]\n");
    }
    return 0;
}
