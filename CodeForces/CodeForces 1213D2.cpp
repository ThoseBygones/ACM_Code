/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-01-01
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
#define MAXN 200005

vector<int> v[MAXN];

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0; i<n; i++)
    {
        int x;
        scanf("%d",&x);
        int cnt = 0;
        while(x)
        {
            v[x].PB(cnt);
            x /= 2;
            cnt++;
        }
        v[0].PB(cnt);
    }
    for(int i=0; i<=200000; i++)
        sort(v[i].begin(),v[i].end());
    int ans = INF;
    for(int i=0; i<=200000; i++)
    {
        if(v[i].size() >= k)
        {
            int sum = 0;
            for(int j=0; j<k; j++)
                sum += v[i][j];
            ans = min(ans,sum);
        }
    }
    printf("%d\n",ans);
    return 0;
}
