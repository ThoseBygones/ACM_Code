/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-06-18
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

const int MAXN = 305;

char g[MAXN][MAXN];
int cnt[2][3];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            scanf("%s", g[i] + 1);
        memset(cnt, 0, sizeof(cnt));
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(g[i][j] != '.')
                    cnt[g[i][j] == 'X'][(i + j) % 3]++;
            }
        }
        int num1 = 0, num2 = 1;
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                if(i == j)
                    continue;
                if(cnt[0][num1] + cnt[1][num2] > cnt[0][i] + cnt[1][j])
                {
                    num1 = i;
                    num2 = j;
                }
            }
        }
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(g[i][j] == '.')
                    continue;
                if((i + j) % 3 == num1)
                    g[i][j] = 'X';
                else if((i + j) % 3 == num2)
                    g[i][j] = 'O';
            }
        }
        for(int i = 1; i <= n; i++)
            printf("%s\n", g[i] + 1);
    }
    return 0;
}
