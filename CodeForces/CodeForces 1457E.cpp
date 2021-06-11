/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-06-11
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: 贪心 + 排序 + （优先队列）
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

const int MAXN = 500005;

/* 解法一： 贪心 + 排序 （186ms） */

int a[MAXN];
vector<LL> v;

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    sort(a + 1, a + 1 + n, greater<int>());
    LL ans = 0, val = 0;
    int pos = n + 1;
    for(int i = 1; i <= n; i++)
    {
        ans += val;
        val += a[i];
        if(val < 0)
        {
            v.PB(val);
            pos = i + 1;
            break;
        }
        //printf("%d: %lld %lld\n", i, val, ans);
    }
    for(int i = pos; i <= n; i++)
        v.PB(a[i]);
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++)
        ans += v[i] * (i / (k + 1));
    printf("%lld\n", ans);
    return 0;
}


/* 解法二：贪心 + 排序 + 优先队列 （218ms） */

int a[MAXN];
priority_queue<LL> pq;

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    sort(a + 1, a + 1 + n, greater<int>());
    for(int i = 0; i <= k; i++)
        pq.push(0);
    LL ans = 0;
    for(int i = 1; i <= n; i++)
    {
        LL val = pq.top();
        pq.pop();
        ans += val;
        val += a[i];
        pq.push(val);
        //printf("%d: %lld %lld\n", i, val, ans);
    }
    printf("%lld\n", ans);
    return 0;
}
