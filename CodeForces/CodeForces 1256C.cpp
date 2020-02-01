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
#define MAXN 1005

int c[MAXN];
int ans[MAXN];

int main()
{
    int n,m,d;
    scanf("%d%d%d",&n,&m,&d);
    for(int i=1; i<=m; i++)
        scanf("%d",&c[i]);
    int pos = n;
    for(int i=m; i; i--)    //按照木板原来的顺序尽可能靠近河的右岸放置木板
    {
        for(int l=0; l<c[i]; l++)
            ans[pos-l] = i;
        pos -= c[i];
    }
    pos = 0;
    while(true)
    {
        pos += d;
        if(pos >= n+1)    //这一跳能跳到右岸
        {
            puts("YES");
            for(int i=1; i<=n; i++)
            {
                if(i != n)
                    printf("%d ",ans[i]);
                else
                    printf("%d\n",ans[i]);
            }
            return 0;
        }
        if(ans[pos])    //这一跳落点有木板
            continue;
        int nxt = pos + 1;
        while(!ans[nxt])   //找到离这一跳落点最近的木板
            nxt++;
        if(nxt >= n+1)
        {
            puts("NO");
            return 0;
        }
        int len = c[ans[nxt]];
        for(int i=0; i<len; i++)
            swap(ans[pos+i],ans[nxt+i]);
        pos += len - 1;
    }
    return 0;
}
