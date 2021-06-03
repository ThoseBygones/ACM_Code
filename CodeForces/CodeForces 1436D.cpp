/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-06-02
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: dfs / 树形dp
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

LL a[MAXN];
int p[MAXN];
int cnt[MAXN];  //每个子树的叶子结点数量
bool vis[MAXN];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        cnt[i] = 1;
    p[1] = 0;
    for(int i = 2; i <= n; i++)
    {
        scanf("%d", &p[i]);
        cnt[p[i]] = 0;  //初始默认父结点没有叶子结点
    }
    for(int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    LL ans = -1;
    for(int i = n; i; i--)  //由于 p[i] < i，所以可以直接倒序遍历（这样子树的根结点一定把所有子结点都包括了）
    {
        ans = max(ans, a[i] / cnt[i] + (a[i] % cnt[i] ? 1 : 0));
        cnt[p[i]] += cnt[i];
        a[p[i]] += a[i];
    }
    printf("%lld\n", ans);
    return 0;
}
