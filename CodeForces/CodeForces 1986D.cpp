/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2025-04-21
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

const int MAXN = 25;

char s[MAXN];

int calc(vector<int> v)
{
    int sum = 0;
    for(auto a: v)
    {
        if(a != 1)
            sum += a;
    }
    return sum;
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d%s", &n, s);
        int ans = INF;
        bool flag = false;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '0')
            {
                if(n > 3)
                    puts("0");
                else if(n == 3)
                {
                    if(i == 0 || i == 2)
                        puts("0");
                    else
                        printf("%d\n", min(s[0] - '0' + s[2] - '0', (s[0] - '0') * (s[2] - '0')));
                }
                else
                    printf("%d\n", (s[0] - '0') * 10 + s[1] - '0');
                flag = true;
                break;
            }
        }
        if(flag)
            continue;
        for(int i = 0; i < n - 1; i++)
        {
            vector<int> v;
            for(int j = 0; j < n; j++)
            {
                if(j == i)
                {
                    v.PB((s[j] - '0') * 10 + s[j + 1] - '0');
                    j++;
                }
                else
                    v.PB(s[j] - '0');
            }
            ans = min(ans, calc(v));
        }
        printf("%d\n", ans);
    }
    return 0;
}
