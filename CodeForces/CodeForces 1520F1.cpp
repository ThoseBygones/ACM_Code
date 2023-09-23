/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2023-09-23
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: 二分（交互题）
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

int query(int l, int r)
{
    printf("? %d %d\n", l, r);
    fflush(stdout);
    int x;
    scanf("%d", &x);
    return x;
}

int main()
{
    int n, t;
    scanf("%d%d", &n, &t);
    while(t--)
    {
        int k;
        scanf("%d", &k);
        int l = 1, r = n;
        int mid;
        while(l <= r)
        {
            mid = (l + r) >> 1;
            int cnt1 = query(1, mid);   //查询1的数量
            if(mid - cnt1 >= k)   //查询0的数量
                r = mid - 1;
            else
                l = mid + 1;
        }
        printf("! %d\n", l);
    }
    return 0;
}
