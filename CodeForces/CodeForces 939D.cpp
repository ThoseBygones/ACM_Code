/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2018-03-08
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
#define MAXN 100005

vector <int> g[30];
vector <PII> ans;
bool vis[30];
char s[MAXN],t[MAXN];

void dfs(int u)
{
    vis[u]=true;
    for(int i=0; i<g[u].size(); i++)
    {
        int v=g[u][i];
        if(!vis[v])
        {
            ans.PB(MP(u,v));
            dfs(v);
        }
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    scanf("%s %s",s,t);
    for(int i=0; i<n; i++)
    {
        int u=s[i]-'a';
        int v=t[i]-'a';
        g[u].PB(v);
        g[v].PB(u);
    }
    for(int i=0; i<26; i++)
    {
        if(!vis[i])
            dfs(i);
    }
    int sz=ans.size();
    printf("%d\n",sz);
    for(int i=0; i<sz; i++)
        printf("%c %c\n",ans[i].first+'a',ans[i].second+'a');
    return 0;
}
