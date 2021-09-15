/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-09-03
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: POJ
 *  Algorithm: dfs + 剪枝 + 前缀和
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

const int MAXN = 15;

int mins[MAXN], minv[MAXN]; //前i层的最小面积和最小体积（前缀和）
int n, m;
int ans;

void init()
{
    mins[0] = 0, minv[0] = 0;
    for(int i = 1; i < MAXN; i++)
    {
        mins[i] = mins[i - 1] + i * 2 * i;  //PI * 2 * r * h
        minv[i] = minv[i - 1] + i * i * i;  //PI * r * r * h
    }
}

void dfs(int dep, int sums, int sumv, int r, int h) //搜索层数，到上一层之前的面积和、体积和，该层合法的半径和高度
{
    if(!dep)
    {
        if(sumv == n && sums < ans)
            ans = sums;
        return ;
    }
    if(sumv + minv[dep - 1] > n || sums + mins[dep - 1] > ans)  //加上下一层体积超过n且加上下一层表面积大于目前的最小值，则剪枝
        return ;
    if(sums + (n - sumv) / r * 2 >= ans)    //剩余体积全部做成一个半径尽可能大高尽可能小（这样侧面积尽可能小）的圆柱体后，总表面积和依然超过目前的最小值，则剪枝
        return ;
    for(int i = r - 1; i >= dep; i--)   //枚举下一层r的合法值
    {
        if(dep == m)    //初始值为最底层的上表面积
            sums = i * i;   //因为无论几层，从上往下俯视可以发现，上表面积永远等于最底层的上表面积
        int maxh = min((n - sumv - minv[dep - 1]) / (i * i), h - 1);    //留够再上面一层的最小体积以后，枚举下一层的合法高度
        for(int j = maxh; j >= dep; j--)
            dfs(dep - 1, sums + 2 * i * j, sumv + i * i * j, i, j);
    }
}

int main()
{
    init();
    scanf("%d%d", &n, &m);
    ans = INF;
    dfs(m, 0, 0, n + 1, n + 1);
    if(ans != INF)
        printf("%d\n", ans);
    else
        puts("0");
    return 0;
}
