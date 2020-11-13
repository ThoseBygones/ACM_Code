/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-11-12
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: BZOJ
 *  Algorithm: 尺取法 + 单调队列
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

const int MAXN = 2000005;

LL a[MAXN];
LL pref[MAXN];  //前缀和数组
LL sum[MAXN];   //区间和
int q[MAXN]; //单调队列

int main()
{
    int n, d;
    LL p;
    scanf("%d%lld%d", &n, &p, &d);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        pref[i] = pref[i - 1] + a[i];
        sum[i] = pref[i] - pref[i - min(i, d)]; //区间和（i为区间右端点，长度为<=d的最大区间和）
    }
    int ans = d;    //答案至少为d
    LL tmp = pref[d];
    int head = 1, tail = 0;
    q[++tail] = d;
    for(int l = 1, r = d + 1; r <= n; r++)
    {
        tmp += a[r];
        while(head <= tail && sum[r] >= sum[q[tail]])
            --tail;
        q[++tail] = r;
        while(head <= tail && tmp - sum[q[head]] > p)
        {
            tmp -= a[l++];  //检查当前的左端点是否符合要求
            if(q[head] - d + 1 < l)
                ++head;
        }
        ans = max(ans, r - l + 1);
    }
    printf("%d\n", ans);
    return 0;
}
