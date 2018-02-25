/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2018-02-25
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm: 拓扑排序 + dp
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
#define MAXN 300010

struct Edge
{
    int to,nxt;
    Edge() {}
    Edge(int to,int nxt):to(to),nxt(nxt) {}
} e[MAXN];

int head[MAXN];
char w[MAXN];
int ind[MAXN];  //每个结点的入度
int dp[MAXN][30];   //dp[i][j]表示到结点i，字符j出现的最大次数
int n,m;
int cnt;
int viscnt;

void addEdge(int u,int v)
{
    e[cnt].to=v;
    e[cnt].nxt=head[u];
    head[u]=cnt++;
}

void topoSort()
{
    queue <int> q;
    for(int i=1; i<=n; i++)
    {
        if(!ind[i])
        {
            q.push(i);
            dp[i][w[i]-'a']++;
        }
    }
    viscnt=0;   //拓扑排序中已经访问过的结点数
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        viscnt++;
        for(int i=head[u]; ~i; i=e[i].nxt)
        {
            int v=e[i].to;
            ind[v]--;
            if(!ind[v])
                q.push(v);
            for(int j=0; j<26; j++)
            {
                if(w[v]-'a'==j)
                    dp[v][j]=max(dp[v][j],dp[u][j]+1);
                else
                    dp[v][j]=max(dp[v][j],dp[u][j]);
            }
        }
    }
}

int main()
{
    scanf("%d%d%s",&n,&m,w+1);
    memset(head,-1,sizeof(head));
    memset(ind,0,sizeof(ind));
    memset(dp,0,sizeof(dp));
    cnt=0;
    for(int i=0; i<m; i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        addEdge(u,v);
        ind[v]++;
    }
    topoSort();
    if(viscnt<n)   //有环存在，值能无限大
        puts("-1");
    else
    {
        int ans=0;
        for(int i=1; i<=n; i++)
        {
            for(int j=0; j<26; j++)
                ans=max(ans,dp[i][j]);
        }
        printf("%d\n",ans);
    }
    return 0;
}
