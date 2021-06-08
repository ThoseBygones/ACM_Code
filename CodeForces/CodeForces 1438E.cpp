/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-06-08
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: 前缀和 + 暴力枚举 + STL set
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

LL a[MAXN], sum[MAXN];  //前缀和
set<PII> s; //用于记录区间左右端点对（去重）

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
        sum[i] = sum[i - 1] + a[i];
    }
    for(int l = 1; l <= n - 2; l++) //枚举左端点
    {
        for(int r = l + 2; r <= n; r++) //枚举右端点
        {
            LL val = sum[r - 1] - sum[l];   //[l + 1, r - 1]区间和
            if(val > a[l] * 2)  //假设a[l] > a[r]
                break;  //区间和已经超出（从二进制最高位判断），则结束
            if(val == (a[l] ^ a[r]))
                s.insert(MP(l, r));
        }
    }
    for(int r = n; r >= 3; r--) //枚举右端点
    {
        for(int l = r - 2; l; l--)  //枚举左端点
        {
            LL val = sum[r - 1] - sum[l];   //[l + 1, r - 1]区间和
            if(val > a[r] * 2)  //假设a[r] > a[l]，补上枚举左端点时可能遗漏的情况
                break;  //区间和已经超出（从二进制最高位判断），则结束
            if(val == (a[l] ^ a[r]))
                s.insert(MP(l, r));
        }
    }
    printf("%d\n", s.size());
    return 0;
}
