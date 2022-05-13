/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2022-05-10
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: STL Multiset + 数论（gcd + 逆元）
 ********************************************************************************
 *  Algo-Description:
 ********************************************************************************
 */

#include <bits/stdc++.h>
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

const int MAXN = 200005;
const int MOD = 1e9 + 7;

multiset<LL> ms[MAXN];  //ms[x]表示这n个数中各个数质因子x出现的次数（幂次）
map<LL, int> mp[MAXN];  //mp[i][x]表示第i个数有质因子x，该质因子的数量（幂次）
LL gcd;
int n, q;

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

LL modInv(LL x, LL mod)
{
    return quickPow(x, mod - 2, mod);
}

void add(int pos, LL val, int cnt)
{
    if(mp[pos].count(val))  //该质因子出现过
    {
        if(ms[val].size() == n) //质因子val已经出现过n次了（这n个数每个数都有这个因子）
        {
            LL fac = quickPow(val, *ms[val].begin(), MOD);  //求出未修改之前该质因子的幂次及结果（val ^ (*ms[val].begin())）
            gcd = gcd * modInv(fac, MOD) % MOD;  //利用逆元出去原来该质因子及其幂次造成的影响
        }
        //计算修改后该质因子及其幂次造成的影响
        ms[val].erase(ms[val].find(mp[pos][val]));  //在集合中找到该质因子出现的次数（幂次值）并删除
        mp[pos][val] += cnt;    //更新该质因子出现的次数（幂次）
        ms[val].insert(mp[pos][val]);   //将更新过的次数（幂次）插入集合中
        if(ms[val].size() == n) //质因子val已经出现过n次了（这n个数每个数都有这个因子）
            gcd = gcd * quickPow(val, *ms[val].begin(), MOD) % MOD; //更新gcd值
    }
    else    //该质因子未出现过
    {
        mp[pos][val] = cnt;
        ms[val].insert(cnt);
        if(ms[val].size() == n) //质因子val已经出现过n次了（这n个数每个数都有这个因子）
            gcd = gcd * quickPow(val, *ms[val].begin(), MOD) % MOD; //更新gcd值
    }
}

void divide(int pos, LL val) //分解质因数
{
    for(LL i = 2; i * i <= val; i++)
    {
        if(val % i == 0)
        {
            int cnt = 0;
            while(val % i == 0)
            {
                cnt++;
                val /= i;
            }
            add(pos, i, cnt);
        }
    }
    if(val > 1)
        add(pos, val, 1);
}

int main()
{
    scanf("%d%d", &n, &q);
    gcd = 1;
    for(int i = 1; i <= n; i++)
    {
        LL x;
        scanf("%lld", &x);
        divide(i, x);
    }
    while(q--)
    {
        int id;
        LL x;
        scanf("%d%lld", &id, &x);
        divide(id, x);
        printf("%lld\n", gcd);
    }
    return 0;
}
