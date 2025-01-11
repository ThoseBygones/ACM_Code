/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2025-01-10
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: 树状数组
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

int a[MAXN], bit[MAXN];
int n;

void add(int i, int x)
{
    while(i <= n)
    {
        bit[i] += x;
        i += lowbit(i);
    }
}

int getsum(int i)
{
    int sum = 0;
    while(i > 0)
    {
        sum += bit[i];
        i -= lowbit(i);
    }
    return sum;
}

int digitsum(int val)
{
    int sum = 0;
    while(val)
    {
        sum += (val % 10);
        val /= 10;
    }
    return sum;
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int q;
        scanf("%d%d", &n, &q);
        for(int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        for(int i = 0; i <= n + 1; i++)
            bit[i] = 0;
        while(q--)
        {
            int op;
            scanf("%d", &op);
            if(op == 1)
            {
                int l, r;
                scanf("%d%d", &l, &r);
                add(l, 1);  //左端点计数+1
                add(r + 1, -1); //右端点计数+1
            }
            else if(op == 2)
            {
                int x;
                scanf("%d", &x);
                int cnt = getsum(x);
                cnt = min(cnt, 3);  //更新在第3次一定会变为个位数，因此第3次后再更新数值不会再改变
                int val = a[x];
                while(cnt--)
                    val = digitsum(val);
                printf("%d\n", val);
            }
        }
    }
    return 0;
}
