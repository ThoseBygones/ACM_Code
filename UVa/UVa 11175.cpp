/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-08-18
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: UVa
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

int g[MAXN][MAXN];

int main()
{
    int kase = 1;
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        memset(g, 0, sizeof(g));
        for(int i = 0; i < m; i++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            g[u][v] = 1;
        }
        bool flag = true;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                bool flag1 = false, flag2 = false;
                for(int k = 0; k < n; k++)
                {
                    if(g[i][k] && g[j][k])  //存在一个点k使得边<i,k><j,k>存在
                        flag1 = true;
                    if(g[i][k] ^ g[j][k])   //存在不一致的点使得<i,k><j,k>只有一个存在
                        flag2 = true;
                }
                if(flag1 && flag2)
                {
                    flag = false;
                    break;
                }
            }
        }
        printf("Case #%d: ", kase++);
        puts(flag ? "Yes" : "No");
    }
    return 0;
}

/*
4
2
1
0 1
5
0
4
3
0 1
2 1
2 3
3
9
0 1
0 2
1 2
1 0
2 0
2 1
0 0
1 1
2 2
*/
