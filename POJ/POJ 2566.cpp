/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-11-20
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: POJ
 *  Algorithm: 前缀和 + 尺取法
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

const int MAXN = 100005;

PLI pref[MAXN];

int main()
{
    int n, k;
    while(~scanf("%d%d", &n, &k))
    {
        if(n == 0 && k == 0)
            break;
        pref[0] = MP(0, 0);
        for(int i = 1; i <= n; i++)
        {
            LL x;
            scanf("%lld", &x);
            pref[i] = MP(pref[i - 1].first + x, i);
        }
        sort(pref, pref + 1 + n);
        while(k--)
        {
            LL t;
            scanf("%lld", &t);
            LL Min = LINF, ans;
            int ansl, ansu;
            int l = 0, r = 1;
            while(r <= n)
            {
                LL dif = pref[r].first - pref[l].first;
                if(fabs(t - dif) < Min)
                {
                    Min = fabs(t - dif);
                    ans = dif;
                    ansl = pref[l].second;
                    ansu = pref[r].second;
                }
                if(dif > t)
                    l++;
                else if(dif < t)
                    r++;
                else
                    break;
                if(l == r)
                    r++;
            }
            if(ansl > ansu)
                swap(ansl, ansu);
            printf("%lld %d %d\n", ans, ansl + 1, ansu);
        }
    }
    return 0;
}
