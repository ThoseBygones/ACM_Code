/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-05-21
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: 枚举
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

LL a[MAXN], b[MAXN];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        LL c;
        scanf("%d%lld", &n, &c);
        for(int i = 1; i <= n; i++)
            scanf("%lld", &a[i]);
        for(int i = 1; i < n; i++)
            scanf("%lld", &b[i]);
        LL day = 0, tug = 0;    //已花费的天数和当前拥有的钱
        LL ans = LINF;
        for(int i = 1; i <= n; i++) //枚举最终停留在的位置
        {
            ans = min(ans, (c - tug + a[i] - 1) / a[i] + day);
            if(i != n)  //还可以晋升
            {
                LL tmpd = (b[i] - tug + a[i] - 1) / a[i];  //还需要几天能晋升
                day += tmpd + 1;    //晋升后移动位置还需要一天
                tug += tmpd * a[i] - b[i];  //晋升后还剩多少钱
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
