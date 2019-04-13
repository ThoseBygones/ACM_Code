/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2019-04-13
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: HDU
 *  Algorithm: 高斯消元法解浮点数系数方程
 ********************************************************************************
 *  Algo-Description:
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
const double EPS = 1e-9;
const int INF = 0x3fffffff;
const LL LINF = INF * 1ll * INF;
const double PI = acos(-1.0);

#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define lowbit(u) (u&(-u))
#define MAXN 110

double a[MAXN][MAXN];   //增广矩阵
double x[MAXN]; //解集

int Gauss(int equ, int var) //equ为方程数，var为未知数个数
{
    int k, col;
    for(k = 0, col = 0; k < equ && col < var; k++,col++)
    {
        int max_r = k;
        for(int i = k + 1; i < equ; i++)
        {
            if(fabs(a[i][col]) > fabs(a[max_r][col]))
                max_r = i;
        }
        if(fabs(a[max_r][col]) < EPS)
            return 0;
        if(k != max_r)
        {
            for(int j = col; j < var; j++)
                swap(a[k][j],a[max_r][j]);
            swap(x[k],x[max_r]);
        }
        x[k] /= a[k][col];
        for(int j = col + 1; j < var; j++)
            a[k][j] /= a[k][col];
        a[k][col] = 1;
        for(int i = 0; i < equ; i++)
        {
            if(i != k)
            {
                x[i] -= x[k] * a[i][col];
                for(int j = col + 1; j < var; j++)
                    a[i][j] -= a[k][j] * a[i][col];
                a[i][col] = 0;
            }
        }
    }
    return 1;
}

double b[15][15];
int cnt[MAXN][MAXN];    //该格点的值由多少个数取平均值得到

int main()
{
    int kase = 0;
    int m,n,d;
    while(~scanf("%d%d%d",&m,&n,&d))
    {
        if(!m && !n && !d)
            break;
        if(kase++)
            puts("");
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
                scanf("%lf",&b[i][j]);
        }
        memset(a,0,sizeof(a));
        memset(x,0,sizeof(x));
        memset(cnt,0,sizeof(cnt));
        //n*m个方程，n*m个未知数
        for(int i1=0; i1<n; i1++)
        {
            for(int j1=0; j1<m; j1++)
            {
                int cnt = 0;
                for(int i2=0; i2<n; i2++)
                {
                    for(int j2=0; j2<m; j2++)
                    {
                        if(abs(i2-i1) + abs(j2-j1) <= d)
                        {
                            int idx1 = i1 * m + j1;
                            int idx2 = i2 * m + j2;
                            cnt++;
                            a[idx1][idx2] = 1.0;
                        }
                    }
                }
                x[i1*m+j1] = b[i1][j1] * cnt;   //构造常数列向量
            }
        }
        Gauss(n*m,n*m);
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
                printf("%8.2f",x[i*m+j]);
            puts("");
        }
    }
    return 0;
}
