/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2025-03-12
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

int a[MAXN], b[MAXN];
bool pre[MAXN], suf[MAXN];   //pre[i]表示前i个数是否单调不减（前缀），suf[i]表示后n-i个数是否单调不减（后缀）

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
        for(int i = 1; i < n; i++)
            b[i] = __gcd(a[i], a[i + 1]);
        b[n] = INT_MAX;
        pre[0] = pre[1] = true;
        for(int i = 2; i < n; i++)
            pre[i] = pre[i - 1] & (b[i - 1] <= b[i]);
        suf[n] = suf[n - 1] = true;
        for(int i = n - 2; i; i--)
            suf[i] = suf[i + 1] & (b[i] <= b[i + 1]);
        bool flag = false;
        if(pre[n - 2] || suf[2])    //第一个数或者最后一个数不单调，则直接修改即可
            flag = true;
        else
        {
            for(int i = 2; i < n; i++)  //枚举删除的位置
            {
                int gcd = __gcd(a[i - 1], a[i + 1]);
                if(pre[i - 2] && suf[i + 1] && b[i - 2] <= gcd && gcd <= b[i + 1])
                {
                    flag = true;
                    break;
                }
            }
        }
        puts(flag ? "YES" : "NO");
    }
    return 0;
}
