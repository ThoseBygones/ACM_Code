/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-04-25
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: BZOJ
 *  Algorithm: 高斯消元解线性方程组 + 基尔霍夫定律（节点电位法）
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
const double EPS = 1e-6;
const int INF = 0x3fffffff;
const LL LINF = INF * 1ll * INF;
const double PI = acos(-1.0);

#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define lowbit(u) (u&(-u))

const int MAXN = 105;

double a[MAXN][MAXN];   //系数矩阵
double x[MAXN]; //解集（初始化时存储增广矩阵的常系数）

/*
高斯消元解浮点数系数方程
返回0表示无解，返回1表示有解
*/
int Gauss(int equ, int var) //equ为方程数，var为未知数个数
{
    int k, col;
    for(k = 0, col = 0; k < equ && col < var; k++, col++)
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
                swap(a[k][j], a[max_r][j]);
            swap(x[k], x[max_r]);
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

int main()
{
    int n, m;
    while(~scanf("%d%d", &n, &m))
    {
        memset(a, 0, sizeof(a));
        memset(x, 0, sizeof(x));
        for(int i = 0; i < m; i++)
        {
            int u, v;
            double r;
            scanf("%d%d%lf", &u, &v, &r);
            u--, v--;
            //并联电路的电流计算公式为 I = Sigma(I_i)
            //根据基尔霍夫定律：对于一个结点，某一时刻流出的电流等于流入的电流
            //即 Sigma(I_in) = Sigma(I_out)
            if(u)
            {
                a[u][u] += 1.0 / r; //结点流入的电流
                a[u][v] -= 1.0 / r; //相对于u点有电势差因此流出的电流
            }
            if(v)
            {
                a[v][v] += 1.0 / r; //结点流入的电流
                a[v][u] -= 1.0 / r; //相对于v点有电势差因此流出的电流
            }
        }
        a[0][0] = 1;    //设0号点为零电位点（电势为0）
        x[n - 1] = 1;   //设n-1号点电势为1
        int ans = Gauss(n, n);
        printf("%.2f\n", fabs(x[n - 1]));   //答案为 fabs(x[0] - x[n - 1])，由于 x[0] = 0 故省略
    }
    return 0;
}
