/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2019-07-08
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm:
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
#define MAXN 200005

int q[MAXN];
LL sum[MAXN];   //前缀和数组（sum[i]记录q[i]-q[1]的值）
bool vis[MAXN];  //每个数是否出现过

int main()
{
    int n;
    scanf("%d",&n);
    LL Min = 0; //预设最小值为p[1]-p[1]
    for(int i=1; i<n; i++)
    {
        scanf("%d",&q[i]);
        sum[i+1] = sum[i] + q[i];
        Min = min(Min,sum[i+1]);  //求出最小的那个p[Min]-p[1]，这个数应该等于1
    }
    for(int i=1; i<=n; i++)
    {
        sum[i] = sum[i] - Min + 1;
        if(sum[i] > n)  //超出数字范围
        {
            puts("-1");
            return 0;
        }
        if(vis[sum[i]])
        {
            puts("-1");
            return 0;
        }
        vis[sum[i]] = true;
    }
    for(int i=1; i<=n; i++)
    {
        if(i!=n)
            printf("%I64d ",sum[i]);
        else
            printf("%I64d\n",sum[i]);
    }
    return 0;
}
