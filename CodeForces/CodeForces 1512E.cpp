/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-05-21
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

const int MAXN = 505;

int a[MAXN];
bool vis[MAXN];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, l, r, s;
        scanf("%d%d%d%d", &n, &l, &r, &s);
        memset(a, 0, sizeof(a));
        memset(vis, false, sizeof(vis));
        int len = r - l + 1;
        int mins = (1 + len) * len / 2;
        int maxs = (n - len + 1 + n) * len / 2;
        if(mins > s || s > maxs)
        {
            puts("-1");
            continue;
        }
        int avg = (s - mins) / len, rem = (s - mins) % len;
        int tmp = 0;
        for(int i = len; i; i--)
        {
            if(i + avg + rem <= n)
            {
                vis[i + avg + rem] = true;
                a[l + i - 1] = i + avg + rem;
                tmp = i;
                break;
            }
        }
        for(int i = 1; i <= len; i++)
        {
            if(i != tmp)
            {
                vis[i + avg] = true;
                a[l + i - 1] = i + avg;
            }
        }
        int cnt = 1;
        for(int i = 1; i <= n; i++)
        {
            while(vis[cnt])
                cnt++;
            if(!a[i])
                a[i] = cnt++;
        }
        for(int i = 1; i <= n; i++)
            printf("%d%c", a[i], (i == n ? '\n' : ' '));
    }
    return 0;
}
