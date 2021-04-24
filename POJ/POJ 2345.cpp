/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-04-24
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: POJ
 *  Algorithm: 高斯消元解异或方程组
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

#define MAXN 255

int a[MAXN][MAXN];  //增广矩阵
int x[MAXN];    //解集
int free_x[MAXN]; //用来存储自由变元（多解枚举自由变元可以使用）
int free_num; //自由变元的个数

/*
高斯消元解异或方程组（对2取模的01方程组）
返回值为-1表示无解，返回值为0表示有唯一解，否则返回自由变元个数
*/
int Gauss_xor(int equ, int var) //equ为方程数，var为未知数个数
{
    int col, k;
    free_num = 0;
    for(k = 0, col = 0; k < equ && col < var; k++, col++)
    {
        int max_r = k;
        for(int i = k + 1; i < equ; i++)
        {
            if(abs(a[i][col]) > abs(a[max_r][col])) //记录第一个第col列系数非零的行
                max_r = i;
        }
        if(a[max_r][col] == 0)
        {
            k--;
            free_x[free_num++] = col;   //这个是自由变元
            continue;
        }
        if(max_r != k)
        {
            for(int j = col; j < var + 1; j++)    //将第一个第col列系数非零的行换到第k行
                swap(a[k][j], a[max_r][j]);
        }
        for(int i = k + 1; i < equ; i++)    //开始消元
        {
            if(a[i][col])   //系数非零
            {
                for(int j = col; j < var + 1; j++)    //从当前第col列开始消元
                    a[i][j] ^= a[k][j];
            }
        }
    }
    /*无解*/
    for(int i = k; i < equ; i++)
    {
        if(a[i][col])
            return -1;
    }
    /*有无穷多解*/
    if(k < var) //
        return var - k; //返回自由变元个数
    /*有唯一解*/
    for(int i = var - 1; i >= 0; i--)
    {
        x[i] = a[i][var];
        for(int j = i + 1; j < var; j++)  //回代求出解集
            x[i] ^= (a[i][j] && x[j]);
    }
    return 0;
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        int col;
        while(~scanf("%d", &col), ~col)
        {
            col--;
            a[col][i] = 1;
        }
        for(int i = 0; i < n; i++)
            a[i][n] = 1;
    }
    int ans = Gauss_xor(n, n);
    if(ans == 0)    //有唯一解
    {
        bool flag = true;
        for(int i = 0; i < n; i++)
        {
            if(x[i])
            {
                if(flag)
                {
                    flag = false;
                    printf("%d", i + 1);
                }
                else
                    printf(" %d", i + 1);
            }
        }
        puts("");
    }
    /*
     * 题目说明每个工人不能被其他工人取代，即方阵中的列向量是线性无关的
     * 故该方程组对应的增广矩阵的秩一定为 n，即 r(A) = r(A,b) = n
     * 因此，非齐次线性方程组 AX = b 有解且有唯一解
     */
    else    //无解或有无穷多解（根据题意，不存在这种情况）
        puts("No solution");
    return 0;
}
