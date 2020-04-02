/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-03-30
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm: 规律
 ********************************************************************************
 *  Algo-Description:
 * > 具有n个结点的符合条件的平衡二叉排序树只可能有1个或者0个（不存在同态的树）
 * > 画出前几种以后得知，n = 1, 2, 4, 5, 9, 10, 20, 21, ... 时符合条件
 * > 每两种树为一对，后一对中的两种树是由前一对中的两种树演变而来的。
 * > 找规律即可。
 ********************************************************************************
 */

#include <bits/stdc++.h>  //For CodeForces only
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
#define clr(ar,val) memset(ar, val, sizeof(ar))
#define istr stringstream
#define FOR(i,n) for(int i=0;i<(n);++i)
#define forIt(mp,it) for(__typeof(mp.begin()) it = mp.begin();it!=mp.end();it++)
const double EPS = 1e-6;
const int INF = 0x3fffffff;
const LL LINF = INF * 1ll * INF;
const double PI = acos(-1.0);

#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define lowbit(u) (u&(-u))

int main()
{
    int n;
    scanf("%d", &n);
    int val = 1;
    while(val <= n)
    {
        if(val == n || val + 1 == n)
        {
            puts("1");
            return 0;
        }
        if(val & 1)
            val = (val + 1) << 1;
        else
            val = (val << 1) + 1;
    }
    puts("0");
    return 0;
}
