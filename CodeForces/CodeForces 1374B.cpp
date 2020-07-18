/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-07-17
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


int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        int cnt2 = 0, cnt3 = 0;
        while(n % 2 == 0)   //计算因数2的个数
        {
            n /= 2;
            cnt2++;
        }
        while(n % 3 == 0)   //计算因数3的个数
        {
            n /= 3;
            cnt3++;
        }
        if(n != 1 || cnt2 > cnt3)  //还有别的因子，则无解;如果因子2的数量比因子3多，则无解
        {
            puts("-1");
            continue;
        }
        printf("%d\n", 2 * cnt3 - cnt2);    //变成1需要cnt3-cnt2次的乘2和cnt3次的除6
    }
    return 0;
}
