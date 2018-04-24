/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2018-04-24
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
    int n;
    scanf("%d",&n);
    if(n%4==0)
    {
        printf("0\n%d",n/2);
        for(int i=1; i<=(n%4+(n-n%4)/2); i+=2)
            printf(" %d %d",i,n-i+1);
    }
    else if(n%4==1)
    {
        printf("1\n%d",n/2);
        for(int i=2; i<=(n%4+(n-n%4)/2); i+=2)
            printf(" %d %d",i,n-i+2);
    }
    else if(n%4==2)
    {
        printf("1\n%d 1",n/2);
        for(int i=3; i<=(n%4+(n-n%4)/2); i+=2)
            printf(" %d %d",i,n-i+3);
    }
    else
    {
        printf("0\n%d 3",n/2);
        for(int i=4; i<=(n%4+(n-n%4)/2); i+=2)
            printf(" %d %d",i,n-i+4);
    }
    puts("");
    return 0;
}
