/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2019-05-23
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: ZOJ
 *  Algorithm: 枚举 + 二分
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

LL n;

LL getK(int val)
{
    LL l = 2, r = n;
    while(l <= r)
    {
        LL mid = (l + r) >> 1;
        LL sum = 0, tmp = 1;
        for(int i=1; i<=val; i++)
        {
            if(tmp >= n/mid)  //最外圈的蜡烛数量已经超过n（使用除法防止爆longlong）
            {
                sum = n + 1;    //设定k值偏大
                break;
            }
            tmp *= mid;
            sum += tmp;
            if(sum > n) //大于n直接退出，等于n的时候不能退出，因为不知道是刚好能摆完还是超出了
                break;
        }
        if(sum == n || sum == n-1)
            return mid;
        else if(sum < n-1)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return 0;
}

int main()
{
    while(~scanf("%lld",&n))
    {
        LL ans_r = 1, ans_k = n-1;
        for(int i=1; i<=40; i++)
        {
            LL val = getK(i);
            if(val)
            {
                if(val*i < ans_r*ans_k)
                {
                    ans_r = i;
                    ans_k = val;
                }
            }
        }
        printf("%lld %lld\n",ans_r,ans_k);
    }
    return 0;
}
