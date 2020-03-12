/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-01-21
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm: BFS（反向建图）
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

vector<int> G[MAXN];
int a[MAXN];
int ans[MAXN];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%d",&a[i]);
    memset(ans,-1,sizeof(ans));
    for(int i=1; i<=n; i++)
    {
        if(i-a[i] >= 1)
        {
            G[i-a[i]].PB(i);
            if((a[i]&1) ^ (a[i-a[i]]&1))
                ans[i] = 1;
        }
        if(i+a[i] <= n)
        {
            G[i+a[i]].PB(i);
            if((a[i]&1) ^ (a[i+a[i]]&1))
                ans[i] = 1;
        }
    }
    queue<int> q;
    for(int i=1; i<=n; i++)
    {
        if(~ans[i])
            q.push(i);
    }
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i=0; i<G[u].size(); i++)
        {
            int v = G[u][i];
            if((ans[v] == -1) && ((a[v]&1) == (a[u]&1)))
            {
                ans[v] = ans[u] + 1;
                q.push(v);
            }
        }
    }
    for(int i=1; i<=n; i++)
    {
        if(i != n)
            printf("%d ",ans[i]);
        else
            printf("%d\n",ans[i]);
    }
    return 0;
}
