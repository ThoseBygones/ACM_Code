/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-05-26
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: 构造 + 规律
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

const int MAXN = 100005;

int a[MAXN];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, k;
        scanf("%d%d", &n, &k);
        bool flag = true;
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            if(a[i] == k)
                flag = false;
        }
        if(flag)
        {
            puts("no");
            continue;
        }
        for(int i = 1; i < n; i++)
        {
            if(a[i] >= k)
            {
                if(a[i + 1] >= k || (i + 2 <= n && a[i + 2] >= k))  //至少每3个要有一个大于等于k，否则无法构造一个区间的中位数大于等于k
                {
                    flag = true;
                    break;
                }
            }
        }
        puts(flag || n == 1 ? "yes" : "no");
    }
    return 0;
}
