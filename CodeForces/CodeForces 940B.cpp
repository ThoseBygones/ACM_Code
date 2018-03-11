/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date:2018-03-11
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
    LL n,k,a,b;
    scanf("%I64d%I64d%I64d%I64d",&n,&k,&a,&b);
    if(k==1)
        printf("%I64d\n",(n-1)*a);
    else
    {
        LL sum=0;
        while(n>1)
        {
            LL temp=n/k;
            if(n<k)
            {
                sum+=(n-1)*a;
                break;
            }
            if(n%k)
            {
                sum+=(n-temp*k)*a;
                n=temp*k;
            }
            else
            {
                sum+=min(b,(n-temp)*a);
                n/=k;
            }
        }
        printf("%I64d\n",sum);
    }
    return 0;
}
