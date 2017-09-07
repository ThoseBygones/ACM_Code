//数位dp（求给定k进制区间内和给定数值区间内回文数字的数量）
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
template<class T> inline T sqr(T x) { return x * x; }
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
#define MAXN 32
using namespace std;

typedef LL Type;

///注意，要专门开一维记录每个进制的dp状态以实现记忆化搜索，否则会TLE！！！
Type dp[40][MAXN][MAXN][2]; //dp[t][i][j][k]表示寻找t进制数，当前第i位，数字长度为j，状态为k（0表示不是回文串，1表示是回文串）
int a[MAXN];
int temp[MAXN];   //构造的符合要求的数位

Type dfs(int pos, int len, int s, bool lim, int k)
{
    if(pos == -1)
        return s ? k : 1;
    if(!lim && ~dp[k][pos][len][s])
        return dp[k][pos][len][s];
    Type ret = 0;
    int u = lim ? a[pos] : (k - 1);
    for(int i = 0; i <= u; i++)
    {
        temp[pos] = i;
        if(i == 0 && pos == len)    //首位取值0（前导零）
            ret += dfs(pos-1, len-1, s, false, k);
        else if(s && pos < len / 2 + 1) //构造完数位前半段开始比对，且目前还是回文串
            ret += dfs(pos-1, len, i==temp[len-pos], lim&&i==u, k);
        else    //构造前半段数位，不进行比对
            ret += dfs(pos-1, len, s, lim&&i==u, k);
    }
    return lim ? ret : dp[k][pos][len][s] = ret;
}

LL solve(LL val,int k)
{
    int cnt=0;
    while(val)
    {
        a[cnt++]=val%k;
        val/=k;
    }
    return dfs(cnt-1,cnt-1,1,true,k);
}

int main(void){
#ifndef ONLINE_JUDGE
	//freopen("/Users/mac/Desktop/data.in","r",stdin);
#endif
    int kase=1;
    int t;
    scanf("%d",&t);
    memset(dp,-1,sizeof(dp));
    while(t--)
    {
        LL L,R;
        int l,r;
        scanf("%I64d%I64d%d%d",&L,&R,&l,&r);
        LL ans=0;
        for(int i=l; i<=r; i++)
            ans+=solve(R,i)-solve(L-1,i);
        printf("Case #%d: %I64d\n",kase++,ans);
    }
	return 0;
}
