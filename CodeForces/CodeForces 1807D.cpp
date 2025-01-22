/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2025-01-15
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm:
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

int a[MAXN];
LL presum[MAXN];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, q;
        scanf("%d%d", &n, &q);
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            presum[i] = presum[i - 1] + a[i];
        }
        while(q--)
        {
            int l, r, k;
            scanf("%d%d%d", &l, &r, &k);
            int len = r - l + 1; //区间长度
            LL cursum = presum[r] - presum[l - 1];   //区间和
            LL newsum = 1LL * len * k;  //新区间和
            bool chflag = (cursum & 1) ^ (newsum & 1);  //区间修改后区间和的奇偶性是否改变
            bool ttflag = presum[n] & 1;    //原来总区间和的奇偶性
            puts((chflag ^ ttflag) ? "YES" : "NO");
        }
    }
    return 0;
}
