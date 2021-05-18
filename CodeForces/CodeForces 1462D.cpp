/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-05-18
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

const int MAXN = 3005;

int a[MAXN];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        int sum = 0;
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            sum += a[i];
        }
        for(int i = n; i; i--)
        {
            if(sum % i == 0)    //可以被除尽
            {
                int val = sum / i;
                int tmp = 0;    //当前和
                int cnt = 0;    //操作次数
                bool flag = true;
                for(int j = 1; j <= n; j++)
                {
                    if(tmp + a[j] < val)
                        tmp += a[j];
                    else if(tmp + a[j] == val)
                        tmp = 0;
                    else
                    {
                        flag = false;
                        break;
                    }
                }
                if(flag)
                {
                    printf("%d\n", n - i);
                    break;
                }
            }
        }
    }
    return 0;
}
