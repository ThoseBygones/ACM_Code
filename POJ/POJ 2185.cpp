/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2019-04-18
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: POJ
 *  Algorithm: 二维KMP
 ********************************************************************************
 *  Algo-Description:
 * > 将每一列看成一个字符，对每一列求出next[i]
 * > 列最短循环节长度 = 小矩阵的宽 = ans1 = c - next[c]
 * > 将每一行看成一个字符，对每一行求出next[j]
 * > 行最短循环节长度 = 小矩阵的高 = ans2 = r - next[r]
 * > 答案 = ans1 * ans2，即所求矩阵的面积
 ********************************************************************************
 */

//#include <bits/stdc++.h>  //For CodeForces only

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
using namespace std;
template<class T> inline T sqr(T x)
{
    return x * x;
}
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
#define clr(ar,val) memset(ar, val, sizeof(ar))
#define istr stringstream
#define FOR(i,n) for(int i=0;i<(n);++i)
#define forIt(mp,it) for(__typeof(mp.begin()) it = mp.begin();it!=mp.end();it++)
const double EPS = 1e-6;
const int INF = 0x3fffffff;
const LL LINF = INF * 1ll * INF;
const double PI = acos(-1.0);

#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define lowbit(u) (u&(-u))
#define MAXN 10005

char str[MAXN][80];
int nxt[MAXN];
int n,m;

//比较每行字符串是否相等
bool cmp_row(int x,int y)
{
    for(int j=0; j<m; j++)
    {
        if(str[x][j] != str[y][j])
            return false;
    }
    return true;
}

bool cmp_col(int x,int y)
{
    for(int i=0; i<n; i++)
    {
        if(str[i][x] != str[i][y])
            return false;
    }
    return true;
}

//计算行的next数组
void getNext_row(int *f)
{
    f[0] = f[1] = 0;
    for(int i = 1; i<n; i++)
    {
        int j = f[i];
        while(j && !cmp_row(i,j))
            j = f[j];
        f[i+1] = cmp_row(i,j) ? j + 1 : 0;
    }
}

//计算列的next数组
void getNext_col(int *f)
{
    f[0] = f[1] = 0;
    for(int i = 1; i<m; i++)
    {
        int j = f[i];
        while(j && !cmp_col(i,j))
            j = f[j];
        f[i+1] = cmp_col(i,j) ? j + 1 : 0;
    }
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=0; i<n; i++)
            scanf("%s",str[i]);
        getNext_row(nxt);
        int ans1 = n-nxt[n];
        getNext_col(nxt);
        int ans2 = m-nxt[m];
        printf("%d\n",ans1*ans2);
    }
    return 0;
}
