/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2025-01-15
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

const int MAXN = 2005;

char s[MAXN];
int idx[30];
bool flag[30];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d%s", &n, s);
        for(int i = 0; i <= 26; i++)
        {
            idx[i] = 0;
            flag[i] = true;
        }
        for(int i = 0; i < n; i++)
        {
            if(!idx[s[i] - 'a'])
                idx[s[i] - 'a'] = i + 1;
            else
            {
                if((idx[s[i] - 'a'] % 2) != ((i + 1) % 2))
                    flag[s[i] - 'a'] = false;
            }
        }
        bool ok = true;
        for(int i = 0; i < 26; i++)
        {
            if(!flag[i])
            {
                ok = false;
                break;
            }
        }
        puts(ok ? "YES" : "NO");
    }
    return 0;
}
