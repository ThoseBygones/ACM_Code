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

const int MAXN = 405;

char g[MAXN][MAXN];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%s", g[i]);
        vector<PII> star;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(g[i][j] == '*')
                    star.emplace_back(MP(i, j));
            }
        }
        if(star[0].first == star[1].first)  //在同一行
        {
            g[star[0].first + (star[0].first ? -1 : 1)][star[0].second] = '*';
            g[star[1].first + (star[0].first ? -1 : 1)][star[1].second] = '*';
        }
        else if(star[0].second == star[1].second)   //在同一列
        {
            g[star[0].first][star[0].second + (star[0].second ? -1 : 1)] = '*';
            g[star[1].first][star[1].second + (star[0].second ? -1 : 1)] = '*';
        }
        else    //既不在同一行也不在同一列
        {
            g[star[0].first][star[1].second] = '*';
            g[star[1].first][star[0].second] = '*';
        }
        for(int i = 0; i < n; i++)
            printf("%s\n", g[i]);
    }
    return 0;
}
