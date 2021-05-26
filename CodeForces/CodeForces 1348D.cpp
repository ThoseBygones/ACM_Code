/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-05-25
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: 前缀和 + 差分数组
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

vector<LL> cnt;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        LL n;
        scanf("%lld", &n);
        cnt.clear();
        LL sum = 0;
        for(LL i = 1; sum + i <= n; i <<= 1)
        {
            sum += i;
            cnt.PB(i);
        }
        if(sum < n)
            cnt.PB(n - sum);
        sort(cnt.begin(), cnt.end());
        printf("%d\n", cnt.size() - 1);
        for(int i = 1; i < cnt.size(); i++)
            printf("%lld%c", cnt[i] - cnt[i - 1], (i == cnt.size() - 1 ? '\n' : ' '));
    }
    return 0;
}
