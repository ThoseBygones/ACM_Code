/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2019-05-04
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: POJ
 *  Algorithm: 高斯消元解异或方程组 + 枚举自由变元
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
const double EPS = 1e-6;
const int INF = 0x3fffffff;
const LL LINF = INF * 1ll * INF;
const double PI = acos(-1.0);

#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define lowbit(u) (u&(-u))
#define MAXN 20

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
    memset(free_x,0,sizeof(free_x));
    for(k = 0, col = 0; k < equ && col < var; k++, col++)
    {
        int max_r = k;
        for(int i = k+1; i < equ; i++)
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
            for(int j = col; j < var+1; j++)    //将第一个第col列系数非零的行换到第k行
                swap(a[k][j],a[max_r][j]);
        }
        for(int i = k+1; i < equ; i++)    //开始消元
        {
            if(a[i][col])   //系数非零
            {
                for(int j = col; j < var+1; j++)    //从当前第col列开始消元
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
    for(int i = var-1; i >= 0; i--)
    {
        x[i] = a[i][var];
        for(int j = i+1; j < var; j++)  //回代求出解集
            x[i] ^= (a[i][j] && x[j]);
    }
    return 0;
}

int solve(int equ, int var) //枚举自由变元
{
    int res = Gauss_xor(equ,var);
    if(res == -1)   //无解
        return -1;
    else if(res == 0)   //唯一解
    {
        int ans = 0;
        for(int i = 0; i < var; i++)
            ans += x[i];
        return ans;
    }
    else    //多解（枚举自由变元）
    {
        int ans = INF;
        for(int i = 0; i < (1<<res); i++)   //枚举所有状态
        {
            int cnt = 0;   //当前涂色方案需要涂的次数
            for(int j = 0; j < res; j++)  //枚举自由变元
            {
                if(i & (1<<j))    //该自由变元取1
                {
                    x[free_x[j]] = 1;
                    cnt++;
                }
                else
                    x[free_x[j]] = 0;
            }
            for(int j = var-res-1; j >= 0; j--)   //从消完元矩阵的主对角线非0的最后一行开始回代
            {
                int idx;
                for(idx = j; idx < var; idx++)
                {
                    if(a[j][idx])
                        break;
                }
                x[idx] = a[j][var];
                for(int l = idx+1; l < var; l++)  //回代求出解集
                {
                    if(a[j][l])
                        x[idx] ^= x[l];
                }
                cnt += x[idx];
            }
            ans = min(ans,cnt);
        }
        return ans;
    }
}

char str[5][5];

void init(bool flag)    //最终全变成0或最终全变成1
{
    memset(a,0,sizeof(a));
    memset(x,0,sizeof(x));
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            a[i*4+j][i*4+j] = 1;
            if(i > 0)
                a[(i-1)*4+j][i*4+j] = 1;
            if(i < 3)
                a[(i+1)*4+j][i*4+j] = 1;
            if(j > 0)
                a[i*4+j-1][i*4+j] = 1;
            if(j < 3)
                a[i*4+j+1][i*4+j] = 1;
        }
    }
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            if(str[i][j] == 'b')
                a[i*4+j][16] = flag;
            else
                a[i*4+j][16] = flag ^ 1;
        }
    }
}

int main()
{
    for(int i=0; i<4; i++)
        scanf("%s",str[i]);
    init(0);
    int ans1 = solve(4*4,4*4);
    init(1);
    int ans2 = solve(4*4,4*4);
    //cout << ans1 << " " << ans2 << endl;
    if(~ans1 && ~ans2)
        printf("%d\n",min(ans1,ans2));
    else if(~ans1)
        printf("%d\n",ans1);
    else if(~ans2)
        printf("%d\n",ans2);
    else
        puts("Impossible");
    return 0;
}
