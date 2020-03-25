/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-03-23
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm: 贪心
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
#define MAXN 1000005

int a[MAXN], b[MAXN];

int main()
{
    int n;
    LL k;
    scanf("%d%lld", &n, &k);
    LL sum = 1LL * n * (n + 1) / 2;
    if(k < sum)
    {
        puts("-1");
        return 0;
    }
    for(int i = 1; i <= n; i++)
        a[i] = b[i] = i;
    for(int i = 1; i <= n / 2; i++) //从首尾开始交换，尽可能在使sum<=k的情况下扩大sum
    {
        //if(sum == k)    //刚好相等，结束
        //    break;
        LL d = n - i + 1 - i;
        if(sum + d <= k)
        {
            sum += d;
            //printf(">> %lld\n", sum);
            swap(b[i], b[n-i+1]);
        }
        else    //否则根据差值x直接将b[i]与b[i+x]交换
        {
            LL tmp = k - sum;
            sum += tmp;
            swap(b[i], b[i+tmp]);
        }
    }
    printf("%lld\n", sum);
    for(int i = 1; i <= n; i++)
        printf("%d%c", a[i], (i == n ? '\n' : ' '));
    for(int i = 1; i <= n; i++)
        printf("%d%c", b[i], (i == n ? '\n' : ' '));
    return 0;
}
