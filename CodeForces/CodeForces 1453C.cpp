/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-06-19
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

const int MAXN = 2005;

char b[MAXN][MAXN];
int maxr[10], maxc[10], minr[10], minc[10];
int ans[10];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        for(int i = 0; i <= 9; i++)
        {
            maxr[i] = maxc[i] = 0;
            minr[i] = minc[i] = INF;
            ans[i] = 0;
        }
        for(int i = 1; i <= n; i++)
        {
            scanf("%s", b[i] + 1);
            for(int j = 1; j <= n; j++)
            {
                int d = b[i][j] - '0';
                maxr[d] = max(maxr[d], i);
                minr[d] = min(minr[d], i);
                maxc[d] = max(maxc[d], j);
                minc[d] = min(minc[d], j);
            }
        }
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                int d = b[i][j] - '0';
                ans[d] = max(ans[d], max(maxr[d] - i, i - minr[d]) * max(n - j, j - 1));    //固定另一点在同一行上，修改一个不同行的点构成三角形
                ans[d] = max(ans[d], max(maxc[d] - j, j - minc[d]) * max(n - i, i - 1));    //固定另一点在同一列上，修改一个不同列的点构成三角形
            }
        }
        for(int i = 0; i <= 9; i++)
            printf("%d%c", ans[i], (i == 9 ? '\n' : ' '));
    }
    return 0;
}
