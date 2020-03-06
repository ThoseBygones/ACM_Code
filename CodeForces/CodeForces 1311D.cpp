/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-02-27
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm: 暴力 / 枚举
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
    scanf("%d",&t);
    while(t--)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        int A,B,C;
        int ans = INF;
        for(int i=1; i<=c; i++) //枚举A（A不可能比原来的c还大）
        {
            for(int j=1; i*j<=2*c; j++)
            {
                for(int k=1; i*j*k<=2*c; k++)
                {
                    if(ans > abs(a-i)+abs(b-i*j)+abs(c-i*j*k))
                    {
                        ans = abs(a-i) + abs(b-i*j) + abs(c-i*j*k);
                        A = i;
                        B = i * j;
                        C = i * j * k;
                    }
                }
            }
        }
        printf("%d\n%d %d %d\n",ans,A,B,C);
    }
    return 0;
}
