/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-10-28
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: POJ
 *  Algorithm: 二分 + 前缀和
 ********************************************************************************
 *  Algo-Description:
 ********************************************************************************
 */

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
//#include <bits/stdc++.h>
using namespace std;

template<class T> inline T sqr(T x) {return x * x;}
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
const double EPS = 1e-6;
const int INF = 0x3fffffff;
const LL LINF = INF * 1ll * INF;
const double PI = acos(-1.0);

#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define lowbit(u) (u&(-u))

const int MAXN = 20005;

char s[MAXN];
LL x[MAXN], y[MAXN], z[MAXN];
int cnt;

LL cal(LL val)
{
    LL sum = 0;
    for(int i = 0; i < cnt; i++)
    {
        if(x[i] > val)  //该数列首项大于val则跳过该数列
            continue;
        sum += (min(y[i], val) - x[i]) / z[i] + 1;  //求值小于val的项数
    }
    return sum;
}

void solve()
{
    LL l = 1, r = LINF;
    LL ans = -1;
    while(l <= r)   //二分出现次数为奇数的数的值
    {
        LL mid = (l + r) >> 1;
        if(cal(mid) & 1)  //前缀和为奇数
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    if(ans == -1)
        puts("no corruption");
    else
        printf("%lld %lld\n", ans, cal(ans) - cal(ans - 1));
}

int main()
{
    while(gets(s))
    {
        if(!strlen(s))
        {
            if(!cnt)
                continue;
            solve();
            cnt = 0;
        }
        else
        {
            sscanf(s, "%lld%lld%lld", &x[cnt], &y[cnt], &z[cnt]);
            cnt++;
        }
    }
    if(cnt) //处理最后一组输入
        solve();
    return 0;
}
