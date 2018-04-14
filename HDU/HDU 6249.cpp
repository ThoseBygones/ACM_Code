/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2018-04-14
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: HDU
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
#define MAXN 2005

struct Stamp
{
    int l,r;
    bool operator <(const Stamp &x) const   //每个邮票集合按照左端点排序
    {
        return l<x.l;
    }
} s[MAXN];

int dp[MAXN][MAXN]; //dp[i][j]表示从编号1~i的邮票中选择了j个set能收集到的最大邮票数

int main()
{
    int kase=1;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m,k;
        scanf("%d%d%d",&n,&m,&k);
        for(int i=0; i<m; i++)
            scanf("%d%d",&s[i].l,&s[i].r);
        sort(s,s+m);
        memset(dp,0,sizeof(dp));
        int pos=0,len=0;
        for(int i=0; i<n; i++)
        {
            while(pos<m && s[pos].l==i+1)   //对于每个起点，寻找其最远的右端点
            {
                len=max(len,s[pos].r-s[pos].l+1);
                pos++;
            }
            for(int j=0; j<=k; j++)
            {
                dp[i+1][j]=max(dp[i][j],dp[i+1][j]);
                dp[i+len][j+1]=max(dp[i][j]+len,dp[i+len][j+1]);
            }
            if(len>0)
                len-=1; //起点右移
        }
        printf("Case #%d: %d\n",kase++,dp[n][k]);
    }
    return 0;
}
