/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2019-04-12
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: HDU
 *  Algorithm: 高斯消元法解异或方程组
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
#define MAXN 55

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
                swap(a[k][j],a[max_r][j]);
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

int b[MAXN][MAXN];

int main()
{
    int kase = 1;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        memset(b,0,sizeof(b));
        for(int j=0; j<m; j++)
        {
            int num;
            scanf("%d",&num);
            while(num--)
            {
                int i;
                scanf("%d",&i);
                i--;
                b[i][j] = 1;
            }
        }
        printf("Case %d:\n",kase++);
        int q;
        scanf("%d",&q);
        while(q--)
        {
            for(int i=0; i<n; i++)
                scanf("%d",&a[i][m]);
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<m; j++)
                    a[i][j] = b[i][j];
            }
            int cnt = Gauss_xor(n,m);   //方程一定有解
            if(cnt == -1)
                puts("0");
            else
            {
                LL ans = (1LL << cnt);
                printf("%lld\n",ans);
            }
        }
    }
    return 0;
}
