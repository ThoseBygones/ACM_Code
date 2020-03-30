/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-03-28
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm:
 ********************************************************************************
 *  Algo-Description:
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

bool check(int x, int k)
{
    int val = x, cnt = 0, d = 0;
    while(val)
    {
        if(val & 1)
            cnt++;
        d++;
        val >>= 1;
    }
    return cnt <= k && k <= d;  //x转化成二进制位数不能小于分解后的数量
}

int main()
{
    int n, p;
    scanf("%d%d", &n, &p);
    int ans = -1;
    for(int i = 1; i <= 30; i++)
    {
        int val = n - i * p;
        if(val > 0 && check(val, i))
        {
            ans = i;
            break;
        }
    }
    printf("%d\n", ans);
    return 0;
}
