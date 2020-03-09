/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-03-08
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm: 点的入度和出度
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
#define MAXN 100005

vector<int> G[MAXN];
int ind[MAXN], outd[MAXN];  //点的入度、出度

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        if(u > v)
            swap(u, v);
        G[u].PB(v); //边从权值小的点指向权值大的点（逆转时方便修改边集）
        outd[u]++;
        ind[v]++;
    }
    LL ans = 0;
    for(int i = 1; i <= n; i++)
        ans += 1LL * ind[i] * outd[i];  //贡献为入度*出度
    printf("%lld\n", ans);
    int q;
    scanf("%d", &q);
    while(q--)
    {
        int u;
        scanf("%d", &u);
        ans -= 1LL * ind[u] * outd[u];  //减去u结点的贡献（该结点出度为0，则更新后的贡献为0）
        for(auto v: G[u])
        {
            ans -= 1LL * ind[v] * outd[v];  //减去v结点原来的贡献
            //将边逆转
            ind[u]++;
            outd[u]--;
            G[v].PB(u);
            ind[v]--;
            outd[v]++;
            ans += 1LL * ind[v] * outd[v];  //加上v结点更新后的贡献
        }
        G[u].clear();   //清空u点更新前的边
        printf("%lld\n", ans);
    }
    return 0;
}
