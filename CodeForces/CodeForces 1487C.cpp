/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2022-03-23
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: 数学规律
 ********************************************************************************
 *  Algo-Description:
 * > 假设总胜场为 w，总平局场数为 d，由于所有队伍分数都为 x，则有
 *   > w + d = n * (n - 1) / 2
 *   > 3 * w + 2 * d = x * n
 * > 解得：w = n * (k - n + 1), d = n * ((3 * n - 3) / 2 - k)
 * > 当 n 为奇数时，要使 d 最小，k = (3 * n - 3) / 2，
 *   > 则总胜场 w = n * (n - 1) / 2，总平局场数 d = 0，
 *   > 每个队的平均胜场数 w_per = (n - 1) / 2，平均平局场数 d_per = 0
 * > 当 n 为偶数时，要使 d 最小，k = (3 * n - 4) / 2，
 *   > 则总胜场 w = n * (n - 2) / 2，总平局场数 d = n / 2，
 *   > 每个队的平均胜场数 w_per = (n - 2) / 2，平均平局场数 d_per = 1
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
        if(n & 1)   //n is odd
        {
            int w = (n - 1) / 2;
            for(int i = 1; i <= n; i++)
            {
                int cnt = 0;
                for(int j = i + 1; j <= n; j++)
                {
                    if(++cnt <= w)
                        printf("1 ");
                    else
                        printf("-1 ");
                }
            }
        }
        else    //n is even
        {
            int w = (n - 2) / 2;
            for(int i = 1; i <= n; i++)
            {
                int cnt = 0;
                for(int j = i + 1; j <= n; j++)
                {
                    if(++cnt <= w)
                        printf("1 ");
                    else if(cnt == w + 1)
                        printf("0 ");
                    else
                        printf("-1 ");
                }
            }
        }
        puts("");
    }
    return 0;
}
