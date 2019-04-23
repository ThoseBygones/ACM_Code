/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2019-04-23
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: POJ
 *  Algorithm: 扩展欧几里得算法求逆元 + 高斯消元法解模线性方程组
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
#define MOD 7

#define MAXN 305

int a[MAXN][MAXN];  //增广矩阵
int x[MAXN];    //解集

//扩展欧几里得算法
int exgcd(int a,int b,int &x,int &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    int d=exgcd(b,a%b,x,y);
    int t=x;
    x=y;
    y=t-a/b*y;
    return d;
}

int modInv(int a,int m)
{
    int x,y;
    exgcd(a,m,x,y);
    return (m + x % m) % m;
}

inline int lcm(int a,int b)
{
    return a / __gcd(a,b) * b;  //先除后乘防止溢出
}

/*
返回-2表示有浮点数解，但无整数解；
返回-1表示无解；
返回0表示有唯一解；
返回大于0表示无穷解，返回值为自由变元的个数
*/
int Gauss(int equ,int var)  //equ为方程个数，var为变元个数。增广矩阵为 equ 行 * (var+1) 列（下标均从0开始）
{
    int k, col;
    /*化为阶梯矩阵*/
    for(k = 0, col = 0; k < equ && col < var; k++,col++) //枚举当前处理的行
    {
        int max_r = k;  //当前这列绝对值最大的行
        //找到该col列元素绝对值最大的那行
        for(int i = k + 1; i < equ; i++)
        {
            if(abs(a[i][col]) > abs(a[max_r][col]))
                max_r = i;
        }
        if(a[max_r][col] == 0)  //第col列第k行以下全是0，处理当前行的下一列即可
        {
            k--;
            continue;
        }
        if(max_r != k)
        {
            for(int j = col; j < var + 1; j++)    //与第k行交换，减小除法时的误差
                swap(a[k][j],a[max_r][j]);
        }
        for(int i = k + 1; i < equ; i++)    //消元，化为行阶梯矩阵
        {
            if(a[i][col])   //非零元素
            {
                int LCM = lcm(abs(a[i][col]),abs(a[k][col]));
                int ta = LCM / abs(a[i][col]);
                int tb = LCM / abs(a[k][col]);
                if(a[i][col] * a[k][col] < 0)   //两行对应元素异号
                    tb = -tb;   //其中一个元素系数取反
                for(int j = col; j < var + 1; j++)
                    a[i][j] = ((a[i][j] * ta - a[k][j] * tb) % MOD + MOD) % MOD;
            }
        }
    }

    /*1.无解（行阶梯矩阵中存在(0,0,...;a)这样的行，其中 a != 0 */
    for(int i = k; i < equ; i++)
    {
        if(a[i][col])
            return -1;
    }
    /*2.无穷多解（行阶梯矩阵中出现(0,0,...,0;0)这样的行，则存在自由变元；出现的行数即为自由变元的个数*/
    if(k < var)
        return var - k; //返回自由变元数量
    /*3.唯一解*/
    for(int i = var - 1; i >= 0; i--)
    {
        int tmp = a[i][var];
        for(int j = i + 1; j < var; j++)
        {
            if(a[i][j])
                tmp = ((tmp - a[i][j] * x[j]) % MOD + MOD) % MOD;   //化为 ax = b (mod m) 形式
        }
        x[i] = tmp * modInv(a[i][i],MOD) % MOD; //解出 x = a^(-1) * b (mod m)
    }
    return 0;
}

int trans(char *str)
{
    if(strcmp(str,"MON") == 0)
        return 1;
    if(strcmp(str,"TUE") == 0)
        return 2;
    if(strcmp(str,"WED") == 0)
        return 3;
    if(strcmp(str,"THU") == 0)
        return 4;
    if(strcmp(str,"FRI") == 0)
        return 5;
    if(strcmp(str,"SAT") == 0)
        return 6;
    if(strcmp(str,"SUN") == 0)
        return 7;
}

int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        if(n == 0 && m == 0)
            break;
        char str1[5],str2[5];
        int t,k;
        memset(a,0,sizeof(a));
        for(int i=0; i<m; i++)
        {
            scanf("%d%s%s",&k,str1,str2);
            a[i][n] = (trans(str2) - trans(str1) + 1 + MOD) % MOD;
            while(k--)
            {
                scanf("%d",&t);
                t--;
                a[i][t] = (a[i][t] + 1) % MOD;
            }
        }
        int ans = Gauss(m,n);
        if(ans == 0)    //唯一解
        {
            for(int i=0; i<n; i++)
            {
                if(x[i] <= 2)   //保证解集在[3,9]之间
                    x[i] += 7;
                if(i)
                    printf(" %d",x[i]);
                else
                    printf("%d",x[i]);
            }
            puts("");
        }
        else if(ans == -1)   //无解
            puts("Inconsistent data.");
        else    //多解
            puts("Multiple solutions.");
    }
    return 0;
}
