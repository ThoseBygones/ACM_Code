/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2025-04-11
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: 模拟
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

struct Fountain
{
    int x, y, id;
    Fountain() {}
    Fountain(int x, int y, int id) : x(x), y(y), id(id) {}
    bool operator < (const Fountain &f) const
    {
        if(x == f.x)
            return y < f.y;
        return x > f.x;
    }
} f[MAXN];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, m, k;
        scanf("%d%d%d", &n, &m, &k);
        for(int i = 1; i <= k; i++)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            f[i] = Fountain(x, y, i);
            //printf("=> %d %d %d\n", x, y, i);
        }
        sort(f + 1, f + k + 1);
        vector<int> ans(k + 1, 0);
        LL sum = 0;
        int maxd = n, maxl = m + 1;
        for(int i = 1; i <= k; i++) //从底部往上计算（从左往右计算需要计算第一个喷泉左边的部分，比较麻烦）
        {
            //printf("maxd: %d\n", maxd);
            if(maxl > f[i].y)
            {
                //printf("GO");
                ans[f[i].id] = 1;
                sum += 1LL * (maxl - 1) * (maxd - f[i].x);
                //printf("=> i: %d, sum: %d\n", i, sum);
                maxd = f[i].x;
                maxl = f[i].y;
            }
        }
        sum += 1LL * maxd * (maxl - 1);
        printf("%lld\n", sum);
        for(int i = 1; i <= k; i++)
            printf("%d%c", ans[i], i == k ? '\n' : ' ');
    }
    return 0;
}
