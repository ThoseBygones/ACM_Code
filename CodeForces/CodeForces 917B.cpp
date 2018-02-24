/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2018-02-24
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm: 博弈 + 记忆化搜索（dp）
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
#define MAXN 105

struct Edge
{
    int v,w,nxt;
    Edge() {}
    Edge(int v,int w,int nxt):v(v),w(w),nxt(nxt) {}
} e[MAXN*MAXN];

int head[MAXN];
int cnt;

int dp[MAXN][MAXN][30]; //dp[x][y][c]表示该轮先手者（即马上要走的玩家）在结点x，后手者（即下一回合才走的玩家）在结点y，上一回合经过的边权值为c的状态下的胜负状态（0表示必败，1表示必胜）

void addEdge(int u,int v,int w)
{
    e[cnt].v=v;
    e[cnt].w=w;
    e[cnt].nxt=head[u];
    head[u]=cnt++;
}

int dfs(int x,int y,int prew)   //prew为上一回合经过的边权值
{
    if(dp[x][y][prew])
        return dp[x][y][prew];  //已经搜索过的状态不重复搜索
    dp[x][y][prew]=false;   //初始化如果这步没法走，则处于必败状态
    for(int i=head[x]; ~i; i=e[i].nxt)
    {
        int v=e[i].v;
        int w=e[i].w;
        if(w>=prew && !dfs(y,v,w))  //如果这一步走的边权值大于等于上一回合走的边权值，且下一回合先手者（本回合后手者）无法走（处于必败状态）
        {
            dp[x][y][prew]=true;    //则该回合先手者处于必胜状态
            break;
        }
    }
    return dp[x][y][prew];
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    memset(head,-1,sizeof(head));
    memset(dp,0,sizeof(dp));
    cnt=0;
    for(int i=0; i<m; i++)
    {
        int u,v,w;
        char c[2];
        scanf("%d%d%s",&u,&v,c);
        w=c[0]-'a';
        addEdge(u,v,w);
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(dfs(i,j,0))
                printf("A");
            else
                printf("B");
        }
        puts("");
    }
    return 0;
}
