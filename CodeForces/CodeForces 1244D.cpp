/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-03-23
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm: 树上dfs
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
int c[5][MAXN];
int deg[MAXN];  //结点的度
int tmp[MAXN];  //某种方案下的涂色情况
int col[MAXN];  //最终的涂色情况
LL sum;

void dfs(int u, int fa)
{
    for(auto v: G[u])
    {
        if(v != fa)
        {
            for(int i = 1; i <= 3; i++)
            {
                if(i != tmp[u] && i != tmp[fa]) //与父结点以及父结点的结点颜色不同
                {
                    tmp[v] = i;
                    sum += c[i][v];
                    dfs(v, u);
                }
            }
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= 3; i++)
    {
        for(int j = 1; j <= n; j++)
            scanf("%d", &c[i][j]);
    }
    for(int i = 1; i < n; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].PB(v);
        G[v].PB(u);
        deg[u]++, deg[v]++;
    }
    int st = 0; //链的一端
    for(int i = 1; i <= n; i++)
    {
        if(deg[i] > 2)
        {
            puts("-1");
            return 0;
        }
        else if(deg[i] == 1)
            st = i;
    }
    LL ans = LINF;
    //假设0号结点为虚根，0号结点连接st结点（st结点的父结点为0号节点）
    for(int i = 1; i <= 3; i++) //枚举0号结点的颜色
    {
        tmp[0] = i;
        for(int j = 1; j <= 3; j++) //枚举st结点的颜色
        {
            if(i != j)  //相邻两个结点颜色不能相同
            {
                tmp[st] = j;
                sum = c[j][st];
                dfs(st, 0);
                if(sum < ans)
                {
                    ans = sum;
                    for(int k = 1; k <= n; k++)
                        col[k] = tmp[k];
                }
            }
        }
    }
    printf("%lld\n", ans);
    for(int i = 1; i <= n; i++)
        printf("%d%c", col[i], i == n ? '\n' : ' ');
    return 0;
}
