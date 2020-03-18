/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-02-12
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

map<PII,int> mp;
char str[MAXN];

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        scanf("%s",str);
        mp.clear();
        PII p;
        p.first = 0, p.second = 0;
        int Min = INF;
        PII ans;
        mp[p] = 1;
        for(int i=0; i<n; i++)
        {
            if(str[i] == 'L')
                p.first--;
            if(str[i] == 'R')
                p.first++;
            if(str[i] == 'D')
                p.second--;
            if(str[i] == 'U')
                p.second++;
            if(mp[p] && Min > i+2-mp[p])
            {
                Min = i + 2 - mp[p];
                ans = MP(mp[p],i+2);
            }
            mp[p] = i+2;
        }
        if(Min != INF)
            printf("%d %d\n",ans.first,ans.second-1);
        else
            puts("-1");
    }
    return 0;
}
