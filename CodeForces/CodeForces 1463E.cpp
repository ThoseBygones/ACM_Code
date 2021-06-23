/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-06-23
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: 并查集缩点 + 拓扑排序
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

const int MAXN = 300005;

vector<int> G[MAXN];
vector<int> sp; //记录缩点后的点
int a[MAXN], fa[MAXN];
int ind[MAXN];  //点的度数
int nxt[MAXN];  //缩点内nxt[i]表示点i在点nxt[i]之前
bool flag[MAXN];    //标记点i是否是有限制条件点的点
int ord[MAXN];  //缩点后拓扑排序得到的点序

int findSet(int x)
{
    if(x != fa[x])
        return fa[x] = findSet(fa[x]);
    return fa[x];
}

void unionSet(int x, int y)
{
    int fx = findSet(x);
    int fy = findSet(y);
    if(fx != fy)
        fa[fy] = fx;
}

void topoSort(int x)
{
    queue<int> q;
    q.push(x);
    sp.PB(x);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(auto &v: G[u])
        {
            if(!(--ind[v]))
            {
                q.push(v);
                sp.PB(v);
            }
        }
    }
}

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    int rt = 0;
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        fa[i] = i;
        if(a[i] == 0)   //根结点
            rt = i;
    }
    for(int i = 1; i <= k; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        unionSet(x, y); //缩点
        nxt[x] = y;
        flag[x] = true;
    }
    for(int i = 1; i <= n; i++)
    {
        int u = findSet(a[i]);
        int v = findSet(i);
        if(u != v)
        {
            G[u].PB(v);
            ind[v]++;
        }
    }
    topoSort(rt);
    vector<int> ans;
    for(int i = 0; i < sp.size(); i++)
    {
        for(int j = sp[i]; j; j = nxt[j])
        {
            ans.PB(j);
            if(ans.size() > n)
                break;
        }
    }
    if(ans.size() != n)
    {
        puts("0");
        return 0;
    }
    for(int i = 0; i < ans.size(); i++) //缩点后拓扑排序后得到的点序
        ord[ans[i]] = i;
    for(int i = 1; i <= n; i++)
    {
        if(ord[a[i]] > ord[i])  //如果缩点后拓扑排序后得到的点序与原拓扑序冲突
        {
            puts("0");
            return 0;
        }
    }
    for(int i = 0; i < ans.size(); i++)
        printf("%d%c", ans[i], (i == ans.size() - 1 ? '\n' : ' '));
    return 0;
}
