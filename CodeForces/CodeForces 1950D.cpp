/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2025-03-04
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm:
 ********************************************************************************
 *  Algo-Description:
 ********************************************************************************
 */

#include <bits/stdc++.h>
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

const int MAXN = 100000;

vector<int> bin;
set<int> ans;

bool check(int x)
{
    while(x)
    {
        if(x % 10 > 1)
            return false;
        x /= 10;
    }
    return true;
}

void init()
{
    for(int i = 1; i <= MAXN; i++)
    {
        if(check(i))
            bin.PB(i);
    }
    ans.insert(1);
    for(auto x: bin)
    {
        for(auto y: bin)
        {
            if(y != 1)
            {
                LL res = 1LL * x * y;
                while(res <= 1LL * MAXN)
                {
                    ans.insert((int)res);
                    res *= y;
                }
            }
        }
    }
}

int main()
{
    init();
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int x;
        scanf("%d", &x);
        puts(ans.find(x) != ans.end() ? "YES" : "NO");
    }
    return 0;
}
