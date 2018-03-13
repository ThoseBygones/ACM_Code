/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2018-03-13
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm: dp + DFS染色判环
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
#define MAXM 200005

struct Edge
{
    int to,nxt;
    Edge() {}
    Edge(int to,int nxt):to(to),nxt(nxt) {}
} e[MAXM];

int head[MAXN];
int cnt;
int color[MAXN];    //染色
int outd[MAXN]; //每个点的出度
int dp[MAXN][2];    //dp[i][0/1]表示偶数步（后手）/奇数步（先手）是否能到达i点；值为0表示不可达，值为1表示可达
int pre[MAXN][2];   //记录路径

vector <int> ans;

void addEdge(int u,int v)
{
    e[cnt].to=v;
    e[cnt].nxt=head[u];
    head[u]=cnt++;
}

bool findLoop(int u)
{
    color[u] = 1;
    for(int i = head[u]; ~i; i = e[i].nxt)
    {
        int v = e[i].to;
        if(color[v] == 1)
            return true;
        if(findLoop(v))
            return true;
    }
    color[u] = 2;
    return false;
}

void dfs(int u,int fa,int flag)
{
    if(dp[u][flag])
        return ;
    dp[u][flag]=1;
    pre[u][flag]=fa;
    for(int i=head[u]; ~i; i=e[i].nxt)
    {
        int v=e[i].to;
        dfs(v,u,flag^1);
    }
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    memset(head,-1,sizeof(head));
    for(int u=1; u<=n; u++)
    {
        int num;
        scanf("%d",&num);
        while(num--)
        {
            int v;
            scanf("%d",&v);
            addEdge(u,v);
            outd[u]++;
        }
    }
    int s;
    scanf("%d",&s);
    dfs(s,0,0);
    for(int i=1; i<=n; i++)
    {
        if(dp[i][1] && !outd[i])
        {
            ans.PB(i);
            int x=i,flag=1;
            while(pre[x][flag])
            {
                x=pre[x][flag];
                flag^=1;
                ans.PB(x);
            }
            puts("Win");
            for(int i=ans.size()-1; i>=0; i--)
            {
                if(i)
                    printf("%d ",ans[i]);
                else
                    printf("%d\n",ans[i]);
            }
            return 0;
        }
    }
    if(findLoop(s))
        puts("Draw");
    else
        puts("Lose");
    return 0;
}
