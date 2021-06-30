/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-06-30
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

const int MAXN = 300005;

int a[MAXN];

bool check(int i, int n)
{
    if(i == 1 || i == n)
        return false;
    return (a[i - 1] > a[i] && a[i] < a[i + 1]) || (a[i - 1] < a[i] && a[i] > a[i + 1]);
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        int cnt = 0;
        for(int i = 2; i < n; i++)
        {
            if(check(i, n))
                cnt++;
        }
        int del = 0;
        for(int i = 2; i < n; i++)
        {
            if(check(i, n))
            {
                int res = check(i - 1, n) + check(i, n) + check(i + 1, n);
                int tmp = a[i];
                a[i] = a[i - 1];
                del = max(del, res - check(i - 1, n) - check(i, n) - check(i + 1, n));
                a[i] = a[i + 1];
                del = max(del, res - check(i - 1, n) - check(i, n) - check(i + 1, n));
                a[i] = tmp;
            }
        }
        printf("%d\n", cnt - del);
    }
    return 0;
}
