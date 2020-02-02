/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-02-02
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm: 最短路floyd + 离散化
 ********************************************************************************
 *  Algo-Description:
 * > 对所有的边按权值从小到大排序；
 * > 选取前min(m,k)条边构造新图跑floyd算法；
 * > 对得到的最短路从小到大排序，选第k条即可。
 * > 算法正确性证明：
 *    > 当 k <= m 时，选出的最小的k条边中，若边两两都不连通，则第k短路就是权值最大的那一条边；
 *    > 如果存在某些边连通，则根据排列组合可知，总路径数将>=k条，选择第k短路即可。
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
#define MAXN 405
#define MAXE 200005

struct Edge
{
    int u,v,w;
    bool operator <(const Edge &ed) const
    {
        return w < ed.w;
    }
} e[MAXE];

vector<LL> ans;
int Hash[MAXN<<1];
LL d[MAXN<<1][MAXN<<1];
int cnt;

void floyd()
{
    for(int k=0; k<cnt; k++)
    {
        for(int i=0; i<cnt; i++)
        {
            for(int j=0; j<cnt; j++)
                d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
        }
    }
}

int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0; i<m; i++)
        scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
    sort(e,e+m);
    /*离散化*/
    for(int i=0; i<min(m,k); i++)
    {
        Hash[cnt++] = e[i].u;
        Hash[cnt++] = e[i].v;
    }
    sort(Hash,Hash+cnt);
    cnt = unique(Hash,Hash+cnt) - Hash;
    /*用前k小的边建图*/
    for(int i=0; i<cnt; i++)
        fill(d[i],d[i]+cnt,LINF);
    for(int i=0; i<k; i++)
    {
        int u = lower_bound(Hash,Hash+cnt,e[i].u) - Hash;
        int v = lower_bound(Hash,Hash+cnt,e[i].v) - Hash;
        d[u][v] = d[v][u] = e[i].w;
    }
    floyd();
    /*从所有的边中找出前k小的边*/
    for(int i=0; i<cnt; i++)
    {
        for(int j=i+1; j<cnt; j++)  //只找上三角矩阵，避免重复
        {
            if(d[i][j] != LINF)
                ans.PB(d[i][j]);
        }
    }
    sort(ans.begin(),ans.end());
    printf("%lld\n",ans[k-1]);
    return 0;
}
