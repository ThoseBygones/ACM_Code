/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2019-01-11
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm:
 ********************************************************************************
 *  Algo-Description:
 ********************************************************************************
 */

#include <bits/stdc++.h>  //For CodeForces only
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
#define MAXN 200005

vector<int> g[MAXN];
int d[MAXN];
int ans;

void dfs(int u,int fa,int dep)
{
    bool modify = false;    //该结点是否与根结点连边（最多连一条边）
    d[u] = dep;
    for(int i = 0; i < g[u].size(); i++)
    {
        int v = g[u][i];
        if(v != fa)
        {
            dfs(v,u,dep+1);
            if(d[v] > 2)    //如果叶结点深度大于2
            {
                modify = true;
                d[u] = 1;   //叶结点的父结点与根连边
                d[fa] = min(d[fa],2);  //更新其父节点到根结点1的距离
            }
        }
    }
    if(modify)
        ans++;
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 1; i < n; i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].PB(v);
        g[v].PB(u);
    }
    dfs(1,0,0);
    printf("%d\n",ans);
    return 0;
}
