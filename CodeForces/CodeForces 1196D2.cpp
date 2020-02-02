/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2019-08-13
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm: 枚举 + 前缀和
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
#define MAXN 200005

const char rgb[4] = "RGB";
int sum[MAXN];  //前缀和数组

int main()
{
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int n,k;
        char str[MAXN];
        scanf("%d%d",&n,&k);
        scanf("%s",str+1);
        int ans = 0;
        for(int i=0; i<3; i++)  //枚举字母RGB
        {
            int p = i;
            for(int j=1; j<=n; j++) //预处理前缀和数组
            {
                sum[j] = sum[j-1] + (rgb[p] == str[j] ? 1 : 0);
                p = (p + 1) % 3;
            }
            for(int j=0; j+k<=n; j++)
                ans = max(ans,sum[j+k]-sum[j]);
        }
        printf("%d\n",k-ans);
    }
    return 0;
}
