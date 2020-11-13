/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-11-13
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: HDU
 *  Algorithm: 单调队列 + 尺取法
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

int a[MAXN];
int q1[MAXN], q2[MAXN]; //最大/最小单调队列（记录下标）

int main()
{
    int n, m, k;
    while(~scanf("%d%d%d", &n, &m, &k))
    {
        for(int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        int head1 = 1, tail1 = 0;
        int head2 = 1, tail2 = 0;
        q1[++tail1] = 1;
        q2[++tail2] = 1;
        int ans = 0;
        for(int l = 0, r = 1; r <= n; r++)
        {
            while(head1 <= tail1 && a[q1[tail1]] < a[r])    //单调队列维护最大值
                --tail1;
            q1[++tail1] = r;
            while(head2 <= tail2 && a[q2[tail2]] > a[r])    //单调队列维护最小值
                --tail2;
            q2[++tail2] = r;
            while(a[q1[head1]] - a[q2[head2]] > k)
            {
                if(q1[head1] < q2[head2])
                    l = q1[head1++];
                else
                    l = q2[head2++];
            }
            if(a[q1[head1]] - a[q2[head2]] >= m)
                ans = max(ans, r - l);
        }
        printf("%d\n", ans);
    }
    return 0;
}
