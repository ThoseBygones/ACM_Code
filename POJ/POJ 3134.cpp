/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2022-04-30
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: POJ
 *  Algorithm: IDA* + 剪枝
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

int d[MAXN];
int n;

bool dfs(int cur, int dep, int h)
{
    if(dep > h) //当前深度大于估计的深度（限制深度）
        return false;
    if(cur << (h - dep) < n)    //剩下的深度都使用倍增仍无法达到目标值
        return false;
    if(cur == n)    //达到目标值
        return true;
    d[dep] = cur;   //记录深度
    for(int i = 0; i <= dep; i++)   //遍历已经迭代过的深度
    {
        if(dfs(cur + d[i], dep + 1, h)) //乘法
            return true;
        if(dfs(abs(cur - d[i]), dep + 1, h)) //除法
            return true;
    }
    return false;
}

int main()
{
    while(~scanf("%d", &n), n)
    {
        memset(d, 0, sizeof(d));
        for(int i = 0; i < MAXN; i++)
        {
            if(dfs(1, 0, i))
            {
                printf("%d\n", i);
                break;
            }
        }
    }
    return 0;
}
