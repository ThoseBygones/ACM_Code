/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2022-05-16
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: 数论（质因数分解） + STL Map
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

map<int, int> mp;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, k;
        scanf("%d%d", &n, &k);
        mp.clear();
        int ans = 0;
        for(int i = 1; i <= n; i++)
        {
            int x;
            scanf("%d", &x);
            int val = 1;
            for(int j = 2; j * j <= x; j++)
            {
                int cnt = 0;
                while(x % j == 0)
                {
                    x /= j;
                    cnt++;
                }
                if(cnt & 1) //该质因子出现了奇数次
                    val *= j;
            }
            if(x > 1)   //该数本身就是质数
                val *= x;
            if(mp[val]) //前面存在与x相乘为完全平方数的数
            {
                ans++;
                mp.clear();
            }
            mp[val]++;
        }
        printf("%d\n", ans + 1);    //遍历完最后一个数后，补加上最后一组
    }
    return 0;
}
