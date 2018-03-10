/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2018-02-26
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

set <int> g[MAXN];
set <int> s;
vector <int> ans;
int n,m;

int bfs(int st)
{
    int cnt=0;
    queue <int> q;
    q.push(st);
    s.erase(st);
    cnt++;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(set<int>::iterator it=s.begin(); it!=s.end();)
        {
            if(!g[u].count(*it))    //原图中无边（补图中右边）
            {
                q.push(*it);
                s.erase(it++);
                cnt++;
            }
            else
                it++;
        }
    }
    return cnt;
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0; i<m; i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].insert(v);
        g[v].insert(u);
    }
    for(int i=1; i<=n; i++)
        s.insert(i);
    while(!s.empty())
    {
        int st=*s.begin();
        //cout << st << endl;
        ans.PB(bfs(st));
    }
    sort(ans.begin(),ans.end());
    int sz=ans.size();
    printf("%d\n",sz);
    for(int i=0; i<sz; i++)
    {
        if(i)
            printf(" %d",ans[i]);
        else
            printf("%d",ans[i]);
    }
    puts("");
    return 0;
}
