/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-06-19
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: 树形dp + 贪心
 ********************************************************************************
 *  Algo-Description:
 ********************************************************************************
 */

#include <bits/stdc++.h>
using namespace std;

template<class T> inline T sqr(T x) {return x * x;}
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
const double EPS = 1e-6;
const int INF = 0x3fffffff;
const LL LINF = INF * 1ll * INF;
const double PI = acos(-1.0);

#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define lowbit(u) (u&(-u))

const int MAXN = 200005;

vector<int> G[MAXN];
int dp[MAXN];   //dp[i]表示以结点i为根结点的子树中深度最浅的结点深度（结点1特判为深度最深的结点）
int ans;

void dfs(int u, int fa, int d)
{
    vector<int> dep;    //记录以各个结点为根结点的子树中深度最浅的结点深度
    for(auto v: G[u])
    {
        if(v != fa)
        {
            dfs(v, u, d + 1);
            dep.PB(dp[v]);
        }
    }
    sort(dep.begin(), dep.end(), greater<int>());   //按各个结点为根结点的子树中深度最浅的结点深度从大到小排序
    if(!dep.size()) //叶子结点
        dp[u] = d;
    else if(u == 1) //根结点
    {
        if(dep.size() == 1)  //有单子树
            ans = max(ans, dep[0]); //深度最深的子树中深度最浅的叶结点返回子树
        else if(dep.size() > 1) //有多子树
            ans = max(ans, dep[1] + 1); //深度次深的子树中深度最浅的叶结点返回子树后再走一步到深度最深的子树
    }
    else    //其它结点
    {
        dp[u] = dep.back();
        ans = max(ans, dep[0] - d + 1);
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            G[i].clear();
        for(int i = 1; i < n; i++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            G[u].PB(v);
            G[v].PB(u);
        }
        ans = 0;
        dfs(1, 0, 0);
        printf("%d\n", ans);
    }
    return 0;
}
