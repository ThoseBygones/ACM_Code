/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-01-17
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
#define MAXN 105

int a[MAXN];
bool mov[MAXN];

int main()
{
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int n;
        scanf("%d",&n);
        memset(mov,false,sizeof(mov));
        for(int i=1; i<=n; i++)
            scanf("%d",&a[i]);
        for(int i=1; i<=n; i++)
        {
            int pos = 1;
            while(a[pos] != i)
                pos++;
            while(pos > 1 && !mov[pos-1] && a[pos-1] > a[pos])
            {
                swap(a[pos-1],a[pos]);
                mov[pos-1] = 1;
                pos--;
            }
        }
        for(int i=1; i<=n; i++)
        {
            if(i != n)
                printf("%d ",a[i]);
            else
                printf("%d\n",a[i]);
        }
    }
    return 0;
}
