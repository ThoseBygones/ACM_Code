/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-11-24
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: UVa
 *  Algorithm: ’€∞Î√∂æŸ
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

const int MAXN = 1005;

int a[MAXN];

struct Sum
{
    int a, b, sum;
    Sum() {}
    Sum(int a, int b, int sum) : a(a), b(b), sum(sum) {}
    bool operator < (const int &val) const
    {
        return sum < val;
    }
    bool operator < (const Sum &s) const
    {
        return sum < s.sum;
    }
};

vector<Sum> sum;

int main()
{
    int n;
    while(~scanf("%d", &n), n)
    {
        sum.clear();
        for(int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        sort(a, a + n);
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
                sum.PB(Sum(i, j, a[i] + a[j]));
        }
        sort(sum.begin(), sum.end());
        bool flag = false;
        int ans = 0;
        for(int d = n - 1; d >= 0; d--)
        {
            for(int c = n - 1; c >= 0; c--)
            {
                int pos = lower_bound(sum.begin(), sum.end(), a[d] - a[c]) - sum.begin();
                //cout << "pos:" << pos << endl;
                while(pos < sum.size() && sum[pos].sum == a[d] - a[c] && sum[pos].b < c)
                {
                    //cout << sum[pos].a << " " << sum[pos].b << " " << c << " " <<d << endl;
                    if(c != d)
                    {
                        ans = a[d];
                        flag = true;
                        break;
                    }
                    pos++;
                }
                if(flag)
                    break;
            }
            if(flag)
                break;
        }
        if(flag)
            printf("%d\n", ans);
        else
            puts("no solution");
    }
    return 0;
}
