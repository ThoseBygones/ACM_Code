/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date:
 *  Subject: ACM-ICPC
 *  Language: C/C++
 *  OJ: CS Academy (CSA)
 *  Algorithm: 暴力枚举 + 数论
 ********************************************************************************
 *  Algo-Description:
 *  > 暴力枚举线段的两个端点
 *  > 利用gcd求出两个端点间的格点数
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
#define MAXN 55
using namespace std;

int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    int ans=0;
    for(int x1=0; x1<=n; x1++)
    {
        for(int y1=0; y1<=m; y1++)
        {
            for(int x2=0; x2<=n; x2++)
            {
                for(int y2=0; y2<=m; y2++)
                {
                    if(x1==x2 && y1==y2)
                        continue;
                    int cnt=__gcd(abs(x1-x2),abs(y1-y2))+1;   //格点数量
                    if(cnt==k)
                        ans++;
                }
            }
        }
    }
    printf("%d\n",ans/2);
    return 0;
}
