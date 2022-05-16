/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2022-05-16
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: 打表 + 规律
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
const int MAXV = 2500000;

int a[MAXN];
PII val[(MAXV << 1) + 5];

void init()
{
    a[1] = 1, a[2] = 1, a[3] = 1, a[4] = 2, a[5] = 3;
    for(int i = 6; ; i++)
    {
        a[i] = a[i - 2] - a[i - 3] + a[i - 1] + 1;
        if(a[i] > MAXV)
        {
            printf("n >= %d\n", i); //n = 3165
            break;
        }
    }
}

int main()
{
    //init();
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for(int i = 1; i <= min(n, 3200); i++)
    {
        for(int j = i + 1; j <=min(n, 3200); j++)
        {
            int sum = a[i] + a[j];
            if(!val[sum].first)
                val[sum] = MP(i, j);
            else
            {
                if(val[sum].first != i && val[sum].first != j && val[sum].second != i && val[sum].second != j)
                {
                    puts("YES");
                    printf("%d %d %d %d\n", i, j, val[sum].first, val[sum].second);
                    return 0;
                }
            }
        }
    }
    puts("NO");
    return 0;
}
