/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2019-01-15
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

vector<LL> ans;

int main()
{
    LL n,k,s;
    scanf("%I64d%I64d%I64d",&n,&k,&s);
    if(k > s || k * (n - 1) < s)
    {
        puts("NO");
        return 0;
    }
    puts("YES");
    LL pos = 1;
    while(k--)
    {
        LL len = min(n-1,s-k);  //贪心，优先走满整个坐标轴；当无法走满的时候就改为尽量多走（保证次数不会少）
        if(pos - len < 1)   //正向走
            pos += len;
        else    //反向走
            pos -= len;
        ans.PB(pos);
        s -= len;
    }
    for(int i=0; i<ans.size(); i++)
    {
        if(i)
            printf(" %I64d",ans[i]);
        else
            printf("%I64d",ans[i]);
    }
    puts("");
    return 0;
}
