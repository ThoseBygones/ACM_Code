/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-06-30
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: 数学规律
 ********************************************************************************
 *  Algo-Description:
 ********************************************************************************
 */

#include <bits/stdc++.h>
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
const double EPS = 1e-6;
const int INF = 0x3fffffff;
const LL LINF = INF * 1ll * INF;
const double PI = acos(-1.0);

#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define lowbit(u) (u&(-u))

const int MAXN = 100005;

int a[MAXN], cnt[MAXN], ep[MAXN];   //ep[i]表示i作为分割区间的端点数量

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            cnt[i] = ep[i] = 0;
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            cnt[a[i]]++;
        }
        int k = 0;
        for(int i = 1; i < n; i++)
        {
            if(a[i] == a[i + 1])
            {
                ep[a[i]] += 2;
                k++;
            }
        }
        ep[a[1]]++, ep[a[n]]++;
        int tot = 0, ans = 0;
        for(int i = 1; i <= n; i++)
        {
            tot = max(tot, cnt[i]);
            ans = max(ans, ep[i]);
        }
        if(tot > (n + 1) / 2)
            puts("-1");
        else
        {
            if(ans <= k + 2)
                printf("%d\n", k);
            else
                printf("%d\n", ans - 2);    //作为分割区间端点出现次数最多的那个数作为头尾
        }
    }
    return 0;
}
