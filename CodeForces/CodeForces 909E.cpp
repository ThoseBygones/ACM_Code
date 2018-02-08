/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2018-02-08
 *  Subject: ACM-ICPC
 *  Language: C/C++
 *  OJ: CodeForces
 *  Algorithm: 贪心 + 拓扑排序
 ********************************************************************************
 *  Algo-Description:
 *  > DAG图上拓扑排序;
 *  > 入度为0的（前驱）进程按照flag分类，分别加入主处理器和副处理器的等待队列;
 *  > 一次性处理一个处理器的等待队列，然后切换处理器继续处理。直至处理完所有进程.
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
using namespace std;

vector <int> g[MAXN];   //DAG图
queue <int> q[2];   //主副处理器进程队列

int flag[MAXN]; //进程标志
int ind[MAXN];  //入度

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0; i<n; i++)
        scanf("%d",&flag[i]);
    while(m--)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        g[v].PB(u);
        ind[u]++;
    }
    for(int i=0; i<n; i++)
    {
        if(!ind[i]) //该进程没有前驱进程
            q[flag[i]].push(i);
    }
    int cur=0;
    int ans=0;
    while(!q[0].empty() || !q[1].empty())
    {
        if(q[cur].empty())
        {
            if(cur==0)  //主处理器进程队列已空，则调用副处理器继续处理
                ans++;
            cur^=1; //切换处理器
        }
        //开始执行处理器队列中的进程（拓扑排序）
        int u=q[cur].front();
        q[cur].pop();
        for(int i=0; i<g[u].size(); i++)
        {
            int v=g[u][i];
            ind[v]--;
            if(!ind[v]) //新的入度为0的点加入队列
                q[flag[v]].push(v);
        }
    }
    printf("%d\n",ans);
    return 0;
}
