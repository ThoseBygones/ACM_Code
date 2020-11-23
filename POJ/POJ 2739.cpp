/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-11-20
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: POJ
 *  Algorithm: ËØÊýÉ¸ + ³ßÈ¡·¨
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

const int MAXN = 10005;

vector<int> prime;
bool isprime[MAXN];

void init()
{
    memset(isprime, true, sizeof(isprime));
    isprime[1] = false;
    for(int i = 2; i < MAXN; i++)
    {
        if(isprime[i])
        {
            prime.PB(i);
            for(int j = i * 2; j < MAXN; j += i)
                isprime[j] = false;
        }
    }
}

int main()
{
    init();
    int n;
    while(~scanf("%d", &n), n)
    {
        int l = 0, r = 0;
        int sum = 0, ans = 0;
        while(r < prime.size())
        {
            if(sum <= n)
            {
                if(sum == n)
                    ans++;
                sum += prime[r++];
            }
            if(sum > n)
                sum -= prime[l++];
        }
        printf("%d\n", ans);
    }
    return 0;
}
