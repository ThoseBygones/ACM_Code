/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2019-05-31
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm: dp
 ********************************************************************************
 *  Algo-Description:
 ********************************************************************************
 */

//#include <bits/stdc++.h>  //For CodeForces only

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

#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define lowbit(u) (u&(-u))
#define MAXN 5005

int a[MAXN];
int dp[MAXN][MAXN]; //dp[i][j]表示前i个学生分为j组能选上学生的最大数量

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1; i<=n; i++)
        scanf("%d",&a[i]);
    memset(dp,0,sizeof(dp));
    sort(a+1,a+1+n);
    for(int i=1; i<=n; i++)  //枚举学生
    {
        int cnt = upper_bound(a+1,a+1+n,a[i]+5) - a - 1 - i;    //计算不小于a[i]-5的数的个数（不包括自己）
        //cout << "cnt: " << cnt << endl;
        for(int j=0; j<=k; j++)
        {
            dp[i][j] = max(dp[i-1][j],dp[i][j]);    //确定选不选第i+1个人
            if(j+1 <= k)    //集合数量不超过k个
                dp[i+cnt][j+1] = max(dp[i+cnt][j+1],dp[i-1][j]+1+cnt);  //选第i个人并将编程能力与其差小于等于5的人加入该集合
        }
    }
    int ans = 0;
    for(int i=1; i<=k; i++)
        ans = max(ans,dp[n][i]);
    printf("%d\n",ans);
    return 0;
}
