/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-04-11
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm: 数论
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


int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int r, b, k;
        scanf("%d%d%d", &r, &b, &k);
        if(r > b)
            swap(r, b);
        if((b - 1 - __gcd(r, b)) / r + 1 < k)
            puts("OBEY");
        else
            puts("REBEL");
    }
    return 0;
}

/*
3
11 3 4
4 15 4
14 4 4
*/
