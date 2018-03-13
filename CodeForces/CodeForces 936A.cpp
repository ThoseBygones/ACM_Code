/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2018-03-13
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


int main()
{
    LL k,d,t;
    scanf("%I64d%I64d%I64d",&k,&d,&t);
    LL left=((k-1)/d+1)*d-k;
    LL round=k+left;    //一个周期
    LL rt=k*2+left;    //一个周期能完成的进度（单位为1个半分钟）
    //printf("round = %I64d, rt = %I64d\n",round,rt);
    LL t1=(2*t/rt)*round*2;
    LL t2=2*t-rt*(2*t/rt);
    if(t2<=2*k)
        t1+=t2;
    else
        t1+=2*k+2*(t2-2*k);
    printf("%.10f\n",(double)t1/2.0);
    return 0;
}
