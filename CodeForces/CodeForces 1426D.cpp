/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-05-11
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: 前缀和 + STL Map
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

map<LL, int> vis;

int main()
{
    int n;
    scanf("%d", &n);
    LL sum = 0;
    int ans = 0;
    vis[0] = 1;
    for(int i = 0; i < n; i++)
    {
        LL x;
        scanf("%lld", &x);
        sum += x;
        if(vis[sum])    //该前缀和值出现过
        {
            vis.clear();    //插入的数为任何数都行，但是可以清空之前的前缀和记录
            sum = x;
            ans++;
            vis[0] = 1;
        }
        vis[sum] = 1;
    }
    printf("%d\n", ans);
    return 0;
}
