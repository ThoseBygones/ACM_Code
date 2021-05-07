/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-05-07
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

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, x, y;
        scanf("%d%d%d", &n, &x, &y);
        for(int d = 1; d <= y - x; d++) //枚举相邻两个元素的差
        {
            bool flag = false;
            for(int s = 1; s <= x; s++) //枚举数列的首项
            {
                bool flagx = false, flagy = false;
                for(int i = 1; i <= n; i++)
                {
                    int a = s + (i - 1) * d;
                    if(a == x)
                        flagx = true;
                    if(a == y)
                        flagy = true;
                    if(flagx && flagy)
                        break;
                }
                if(flagx && flagy)
                {
                    //cout << "OK" << endl;
                    for(int i = 1; i <= n; i++)
                        printf("%d%c", s + (i - 1) * d, (i == n ? '\n' : ' '));
                    flag = true;
                    break;
                }
            }
            if(flag)
                break;
        }
    }
    return 0;
}
