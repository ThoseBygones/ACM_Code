/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-05-19
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: 贪心 + 前缀和
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

struct Player
{
    LL a;
    int id;
    bool operator < (const Player &p) const
    {
        return a < p.a;
    }
} p[MAXN];

LL sum[MAXN];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
        {
            scanf("%lld", &p[i].a);
            p[i].id = i;
        }
        sort(p + 1, p + 1 + n);
        for(int i = 1; i <= n; i++)
            sum[i] = sum[i - 1] + p[i].a;
        vector<int> ans;
        ans.PB(p[n].id);
        for(int i = n - 1; i; i--)
        {
            if(sum[i] >= p[i + 1].a)
                ans.PB(p[i].id);
            else
                break;
        }
        sort(ans.begin(), ans.end());
        printf("%d\n", ans.size());
        for(int i = 0; i < ans.size(); i++)
            printf("%d%c", ans[i], (i == ans.size() - 1 ? '\n' : ' '));
    }
    return 0;
}
