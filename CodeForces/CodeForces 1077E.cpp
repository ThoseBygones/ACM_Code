/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2019-01-05
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

int a[MAXN];
int b[MAXN];
int vis[MAXN];  //vis[j]表示二分过程中位置j是否在第i次暴力枚举第一个数的时候被访问过
map<int,int> mp;

int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
        mp[a[i]]++;
    }
    int cnt = 0;
    forIt(mp,it)
        b[++cnt] = it -> second;
    sort(b+1,b+cnt+1);
    int ans = 0;
    for(int i = 1; i <= b[cnt]; i++)
    {
        //memset(vis,0,sizeof(vis));
        int sum = 0, val = i;
        while(sum <= n)
        {
            int pos = lower_bound(b+1,b+cnt+1,val) - b;
            while(pos <= cnt && vis[pos] == i)
                pos++;
            vis[pos] = i;
            if(pos > cnt)
                break;
            sum += val;
            val *= 2;
        }
        //cout << "sum: " << sum << endl;
        ans = max(ans,sum);
    }
    printf("%d\n",ans);
    return 0;
}
