/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-05-30
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: 三分法求凸性函数的最小值
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

const int MAXN = 100005;

int arr[MAXN];
int n, a, b, m;

LL cal(int val)
{
    LL inc = 0, dec = 0;
    for(int i = 1; i <= n; i++)
    {
        if(arr[i] < val)
            inc += val - arr[i];
        else
            dec += arr[i] - val;
    }
    LL ans = 0;
    if(inc > dec)
        ans = (inc - dec) * a + dec * m;
    else
        ans = (dec - inc) * b + inc * m;
    return ans;
}

int main()
{
    scanf("%d%d%d%d", &n, &a, &b, &m);
    m = min(m, a + b);
    for(int i = 1; i <= n; i++)
        scanf("%d", &arr[i]);
    int l = 1, r = 1000000000;
    while(l + 2 < r)    //l, lmid, rmid, r 均各不相同
    {
        int lmid = (l + r) >> 1;
        int rmid = (lmid + r) >> 1;
        //printf("%d %d\n", l, r);
        if(cal(lmid) < cal(rmid))
            r = rmid;
        else
            l = lmid;
    }
    LL ans = LINF;
    for(int i = l; i <= r; i++)
        ans = min(ans, cal(i));
    printf("%lld\n",ans);
    return 0;
}
