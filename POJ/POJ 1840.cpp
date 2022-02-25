/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2022-02-25
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: POJ
 *  Algorithm: 哈希
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

const int MAXN = 25000001;

short Hash[MAXN];

int main()
{
    int a1, a2, a3, a4, a5;
    scanf("%d%d%d%d%d", &a1, &a2, &a3, &a4, &a5);
    int ans = 0;
    for(int i = -50; i <= 50; i++)
    {
        for(int j = -50; j <= 50; j++)
        {
            if(i && j)
            {
                int sum = -(a1 * i * i * i + a2 * j * j * j) + 12500000;  //result + offset
                Hash[sum]++;
            }
        }
    }
    for(int i = -50; i <= 50; i++)
    {
        for(int j = -50; j <= 50; j++)
        {
            for(int k = -50; k <= 50; k++)
            {
                if(i && j && k)
                {
                    int sum = a3 * i * i * i + a4 * j * j * j + a5 * k * k * k + 12500000;
                    if(sum >= 0 && sum < MAXN && Hash[sum])
                        ans += Hash[sum];
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
