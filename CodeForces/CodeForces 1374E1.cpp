/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-07-17
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: 贪心
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

vector<int> t, a, b;    //一起读/只有Alice读/只有Bob读

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++)
    {
        int tt, aa, bb;
        scanf("%d%d%d", &tt, &aa, &bb);
        if(aa && bb)
            t.PB(tt);
        else if(aa)
            a.PB(tt);
        else if(bb)
            b.PB(tt);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for(int i = 0; i < min(a.size(), b.size()); i++)    //将只有A能读的书和B能读的书需要的时间合并后等价于一起读某本书
        t.PB(a[i] + b[i]);
    sort(t.begin(), t.end());
    if(t.size() < k)
    {
        puts("-1");
        return 0;
    }
    int ans = 0;
    for(int i = 0; i < k; i++)
        ans += t[i];
    printf("%d\n", ans);
    return 0;
}
