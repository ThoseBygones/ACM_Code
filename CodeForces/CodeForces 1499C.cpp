/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2022-05-20
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

const int MAXN = 100005;

LL c[MAXN];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            scanf("%lld", &c[i]);
        LL ans = (c[1] + c[2]) * n; //一个方向走到底再走另一个方向
        LL sum1 = c[1], sum2 = c[2];
        LL min1 = c[1], min2 = c[2];    //当前方向最小值
        for(int i = 3; i <= n; i++)
        {
            if(i & 1)   //i为奇数时，为同一个方向
            {
                min1 = min(min1, c[i]);
                sum1 += c[i];   //如果出现第3,5,...段，则该方向先只走一个单位，后面是否连续走根据情况而定
            }
            else    //i为偶数时，为同一个方向
            {
                min2 = min(min2, c[i]);
                sum2 += c[i];   //如果出现第4,6,...段，则该方向先只走一个单位，后面是否连续走根据情况而定
            }
            ans = min(ans, sum1 + min1 * (n - (i + 1) / 2) + sum2 + min2 * (n - i / 2));    //每个方向都是枚举段数，每段先保证至少一个单位，剩下的由值最小的c[i]去填补
        }
        printf("%lld\n", ans);
    }
    return 0;
}
