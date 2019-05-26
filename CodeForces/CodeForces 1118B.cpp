/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2019-05-26
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm: 前缀和
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

int a[MAXN];
int sum[MAXN];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%d",&a[i]);
    for(int i=1; i<=n; i++)
        sum[i] = (i>1?sum[i-2]:0) + a[i];
    int oddsum = 0, evensum = 0;
    if(n&1)
    {
        oddsum = sum[n];
        evensum = sum[n-1];
    }
    else
    {
        oddsum = sum[n-1];
        evensum = sum[n];
    }
    //cout << oddsum << " " << evensum << endl;
    int ans = 0;
    for(int i=1; i<=n; i++)
    {
        int sum1 = oddsum, sum2 = evensum;
        if(i&1) //抽掉的是奇数
        {
            sum1 = sum1 - sum[i] + sum[i-1];
            sum2 = sum2 - sum[i-1] + (i>1?sum[i-2]:0);
        }
        else    //抽掉的是偶数
        {
            sum1 = sum1 - sum[i-1] + (i>1?sum[i-2]:0);
            sum2 = sum2 - sum[i] + sum[i-1];
        }
        if(sum1 == sum2)
            ans++;
    }
    printf("%d\n",ans);
    return 0;
}
