/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-11-23
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: POJ
 *  Algorithm: 折半枚举
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

PLI sum[1 << 20];
int num[1 << 20];
LL a[40];

LL labs(LL x)
{
    return x < 0 ? -x : x;
}

void init()
{
    for(int s = 0; s < (1 << 20); s++)
    {
        int cnt = 0;
        for(int i = 0; i < 20; i++)
        {
            if(s & (1 << i))
                cnt++;
        }
        num[s] = cnt;
    }
}

int main()
{
    init();
    int n;
    while(~scanf("%d", &n), n)
    {
        for(int i = 0; i < n; i++)
            scanf("%lld", &a[i]);
        int n1 = n / 2;
        PLI ans = MP(LINF, n);
        for(int s = 0; s < (1 << n1); s++)  //遍历左半边
        {
            LL tmpsum = 0;
            for(int i = 0; i < n1; i++)
            {
                if(s & (1 << i))
                    tmpsum += a[i];
            }
            sum[s] = MP(tmpsum, num[s]);
            if(s > 0)   //左半边一个元素都不取的情况不能作为最终的最佳方案（但是可以存在这种情况，即只从右半边取）
                ans = min(ans, PLI(labs(tmpsum), num[s]));
        }
        sort(sum, sum + (1 << n1));
        int n2 = n - n1;
        for(int s = 1; s < (1 << n2); s++)  //遍历右半边
        {
            LL tmpsum = 0;
            for(int i = n1; i < n; i++)
            {
                if(s & (1 << (i - n1)))
                    tmpsum += a[i];
            }
            int pos = lower_bound(sum, sum + (1 << n1), MP(-tmpsum, -1)) - sum;  //找到合适的负值
            for(int i = max(0, pos - 1); i <= min(pos + 1, (1 << n1) - 1); i++) //枚举其左右两个数和它自己选最小的即可
                ans = min(ans, PLI(labs(tmpsum + sum[i].first), num[s] + sum[i].second));
        }
        printf("%lld %d\n", ans.first, ans.second);
    }
    return 0;
}
