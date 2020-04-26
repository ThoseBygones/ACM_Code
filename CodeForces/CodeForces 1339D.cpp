/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-04-26
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm: 树上dfs + 结点的度
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
int deg[MAXN];  //结点的度
int flag[MAXN]; //该结点距离根节点的路径奇偶性
int n;

void dfs(int u, int fa, int val)
{
    flag[u] = val;
    for(auto v: G[u])
    {
        if(v != fa)
            dfs(v, u, val ^ 1);
    }
}

int main()
{
    scanf("%d", &n);
    for(int i = 1; i < n; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].PB(v);
        G[v].PB(u);
        deg[u]++;
        deg[v]++;
    }
    for(int i = 1; i <= n; i++)
    {
        if(deg[i] == 1) //找到任意一个叶结点作为根结点开始遍历
        {
            dfs(i, 0, 0);
            break;
        }
    }
    int Min = 1, Max = n - 1;   //最少的情况是所有边权值都相等，最多的情况是n-1条边的权值都不等
    for(int i = 1; i <= n; i++) //有任意两个叶结点之间的路径长度为奇数，则需要3条权值不同的边
    {
        if(deg[i] == 1 && flag[i])
        {
            Min = 3;
            break;
        }
    }
    for(int i = 1; i <= n; i++)
    {
        int cnt = 0;    //记录每个结点有多少个子结点是叶结点
        for(auto v: G[i])
        {
            if(deg[v] == 1)
                cnt++;
        }
        if(cnt)
            Max -= (cnt - 1);   //如果该结点有超过两个叶结点，那么该结点到这些叶结点的边权值都必须相等
    }
    printf("%d %d\n", Min, Max);
    return 0;
}
