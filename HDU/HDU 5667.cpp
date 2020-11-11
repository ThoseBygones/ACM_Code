/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-11-10
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: HDU
 *  Algorithm: 矩阵快速幂 + 费马小定理 + 快速幂
 ********************************************************************************
 *  Algo-Description:
 * > 先对 f(n) = a ^ b * f(n - 1) ^ c * f(n - 2) 等式两边对 a 取对数
 * > 得到等式：g(n) = b + c * g(n - 1) + g(n - 2)
 * > 构造矩阵：A = c 1 0
 *                 1 0 0
 *                 b 0 1
 * > (g(n), g(n - 1), 1) = (g(n - 1), g(n - 2), 1) * A ^ (n - 2)
 * > 由于 a ^ g(n) 结果可能太大：
 *   > 考虑将 a ^ g(n) 对某个数 q 取模，使得取模后满足：
 *   > a ^ (g(n) % q) % p = a ^ g(n) % p
 *   > 费马小定理：若 gcd(a, p) = 1，则 a ^ (p - 1) = 1 (mod p)
 *   > 即 a ^ (p - 1) % p = a ^ 0 % p，可以看出循环节为 (p - 1)
 *   > 因此得到：q = p - 1，即 a ^ (g(n) % (p - 1)) % p = a ^ g(n) % p
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

typedef LL Type;

const int MAXN = 5;

int n;
Type mod;

struct Matrix   //矩阵的类
{
    Type x[MAXN][MAXN];
    void init()
    {
        memset(x, 0, sizeof(x));
    }
    void toIdentity() //将其初始化为单位矩阵
    {
        memset(x, 0, sizeof(x));
        for(int i = 0; i < n; i++)
            x[i][i] = 1;
    }
} A;

Matrix mul(Matrix a, Matrix b)   //(a*b)%mod 矩阵乘法
{
    Matrix ans;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            ans.x[i][j] = 0;
            for(int k = 0; k < n; k++)
                ans.x[i][j] += a.x[i][k] * b.x[k][j];
            ans.x[i][j] %= mod;
        }
    }
    return ans;
}

Matrix pow(Matrix a, Type k)  //(a^n)%mod 矩阵快速幂
{
    Matrix ans;
    ans.toIdentity();
    while(k)
    {
        if(k & 1) //k%2
            ans = mul(ans, a);
        k /= 2;
        a = mul(a, a);
    }
    return ans;
}

void print(Matrix a)    //输出矩阵
{
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            printf("%lld%c",a.x[i][j],j==n-1?'\n':' ');
}

LL quickPow(LL x, LL k, LL mod)
{
    LL res = 1;
    while(k > 0)
    {
        if(k & 1)
            res = res * x % mod;
        x = x * x % mod;
        k >>= 1;
    }
    return res;
}

int main()
{
    n = 3;
    int t;
    scanf("%d", &t);
    while(t--)
    {
        LL k, a, b, c, p;
        scanf("%lld%lld%lld%lld%lld", &k, &a, &b, &c, &p);
        mod = p - 1;
        if(k == 1)
            puts("1");
        else if(k == 2)
            printf("%lld\n", quickPow(a, b, p));
        else
        {
            A.init();
            A.x[0][0] = c;
            A.x[0][1] = A.x[1][0] = A.x[2][2] = 1;
            A.x[2][0] = b;
            Matrix B = pow(A, k - 2);
            //print(A);
            LL ans = B.x[0][0] * b + B.x[2][0]; //[b, 0, 1] * A ^ k
            printf("%lld\n", quickPow(a, ans, p));
        }
    }
    return 0;
}
