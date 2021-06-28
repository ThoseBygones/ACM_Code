/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-06-28
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: 数论（因数分解）
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

const int MAXN = 300005;

int a[MAXN];

map<int, int> cnt;

void update(int &val, int n)
{
    for(int i = 2; sqr(i) <= val; i++)
    {
        while(val % sqr(i) == 0)
            val /= sqr(i);
    }
    cnt[val]++;
    //printf("%d\n", val);
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        cnt.clear();
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            update(a[i], n);
            //printf("%d\n", a[i]);
        }
        int ans0 = 0, ans1 = 0, tmp = 0;
        for(auto &val: cnt)
        {
            ans0 = max(ans0, val.second);
            if(val.second & 1)  //奇数项保留最大值不变
                tmp = max(tmp, val.second);
            else    //偶数项变为1
                ans1 += val.second;
        }
        if(cnt[1] & 1)
            ans1 += cnt[1];
        ans1 = max(ans1, tmp);
        int q;
        scanf("%d", &q);
        while(q--)
        {
            LL x;
            scanf("%lld", &x);
            if(x)
                printf("%d\n", ans1);
            else
                printf("%d\n", ans0);
        }
    }
    return 0;
}
