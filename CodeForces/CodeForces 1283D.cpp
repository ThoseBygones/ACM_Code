/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-01-25
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm: BFS
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

map<int,int> vis;   //记录某个点是否被访问过
queue<PII> q;
vector<int> rec;

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0; i<n; i++)
    {
        int x;
        scanf("%d",&x);
        vis[x] = 1;
        q.push(MP(x-1,1));
        q.push(MP(x+1,1));
    }
    LL ans = 0;
    while(m && !q.empty())
    {
        PII x = q.front();
        q.pop();
        if(!vis[x.first])  //该点没有被占用
        {
            vis[x.first] = 1;
            ans += x.second;
            rec.PB(x.first);
            if(!vis[x.first-1]) //该点左边的点未被占用
                q.push(MP(x.first-1,x.second+1));
            if(!vis[x.first+1]) //该点右边的点未被占用
                q.push(MP(x.first+1,x.second+1));
            m--;
        }
    }
    printf("%lld\n",ans);
    for(int i=0; i<rec.size(); i++)
    {
        if(i)
            printf(" %d",rec[i]);
        else
            printf("%d",rec[i]);
    }
    puts("");
    return 0;
}
