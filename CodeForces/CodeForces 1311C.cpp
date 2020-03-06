/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-02-27
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm: 前缀和
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

char s[MAXN];
int cnt[MAXN];
int ans[30];

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        scanf("%s",s+1);
        memset(cnt,0,sizeof(cnt));
        memset(ans,0,sizeof(ans));
        for(int i=1; i<=m; i++)
        {
            int p;
            scanf("%d",&p);
            cnt[p]++;
        }
        cnt[n]++;
        for(int i=n; i; i--)
        {
            cnt[i] += cnt[i+1];
            ans[s[i]-'a'] += cnt[i];
        }
        for(int i=0; i<26; i++)
        {
            if(i)
                printf(" %d",ans[i]);
            else
                printf("%d",ans[i]);
        }
        puts("");
    }
    return 0;
}
