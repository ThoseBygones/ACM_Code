//kmp（扩展kmp）
//#pragma comment(linker,"/STACK:102400000,102400000")
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <climits>
#include <ctime>
#include <numeric>
#include <vector>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <complex>
#include <deque>
#include <functional>
#include <list>
#include <map>
#include <string>
#include <sstream>
#include <set>
#include <stack>
#include <queue>
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
const int MOD = 1000000007;

#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define lowbit(u) (u&(-u))
#define MAXN 1000005
using namespace std;

char s[MAXN];
char p[MAXN];
int nxt[MAXN];
LL cnt[MAXN];

int getFail(char* p,int *f)
{
    int m = strlen(p);
    f[0] = f[1] = 0;
    for(int i = 1; i<m; i++)
    {
        int j = f[i];
        while(j&&p[i]!=p[j])
            j = f[j];
        f[i+1] = p[i]==p[j]?j+1:0;
    }
    return m;
}

//s是匹配串，p是模版串
void kmp(char* s,char*p,int *f)
{
    int n = strlen(s);
    int m = getFail(p,f);
    int j = 0;
    for(int i = 0; i<n; i++)
    {
        while(j&&p[j]!=s[i]) j = f[j];
        if(p[j]==s[i]) j++;
        cnt[j]++;
        if(j==m)
            j = f[j];
    }
}

int main(void)
{
#ifndef ONLINE_JUDGE
    //freopen("/Users/mac/Desktop/data.in","r",stdin);
#endif
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",s);
        scanf("%s",p);
        int lens=strlen(s);
        int lenp=strlen(p);
        reverse(s,s+lens);
        reverse(p,p+lenp);
        memset(cnt,0,sizeof(cnt));
        LL sum=0;
        kmp(s,p,nxt);
        for(int i=lenp; i>=1; i--)
        {
            cnt[nxt[i]]+=cnt[i];
            sum=(sum+cnt[i]*i%MOD)%MOD;
        }
        printf("%I64d\n",sum);
    }
    return 0;
}
