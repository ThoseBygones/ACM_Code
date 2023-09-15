/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date:2023-09-06
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

const int MAXN = 105;

int l[MAXN], r[MAXN];
int b[MAXN][MAXN], ans[MAXN][MAXN];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
                scanf("%d", &b[i][j]);
            sort(b[i] + 1, b[i] + 1 + m);
            l[i] = 1, r[i] = m;
        }
        for(int j = 1; j <= m; j++) //枚举跑者
        {
            int Min = INF;  //当前跑者的最小疲劳度
            int cp = 1; //用作计算最小疲劳度路段的id记录
            for(int i = 1; i <= n; i++) //枚举路段
            {
                if(b[i][l[i]] < Min)
                {
                    Min = b[i][l[i]];
                    cp = i;
                }
            }
            for(int i = 1; i <= n; i++)
            {
                if(i == cp)
                    ans[i][j] = b[i][l[i]++];
                else
                    ans[i][j] = b[i][r[i]--];
            }
        }
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
                printf("%d%c", ans[i][j], j == m ? '\n' : ' ');
        }
    }
    return 0;
}
