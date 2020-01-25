/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-01-25
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm: 树的度 + 优先队列 + 贪心（幂次相关）
 ********************************************************************************
 *  Algo-Description:
 * > 由于 Sigma(1,i)(2^i) < 2^(i+1)，故优先队列中用于比较优先级的值可以由Sigma(1,i)(2^i)替换为i
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
#define MAXN 200005

priority_queue<int,vector<int>,greater<int> > pq;
int a[MAXN];
int deg[MAXN];  //结点的度

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1; i<n; i++)
    {
        scanf("%d",&a[i]);
        deg[a[i]]++;
    }
    printf("%d\n",a[1]);
    for(int i=1; i<=n; i++)
    {
        if(!deg[i]) //度为0的结点（叶结点）入队
            pq.push(i);
    }
    for(int i=n-1; i; i--)
    {
        printf("%d %d\n",a[i],pq.top());
        pq.pop();
        deg[a[i]]--;
        if(!deg[a[i]])  //若连接的结点度为0，则加入优先队列中
            pq.push(a[i]);
    }
    return 0;
}
