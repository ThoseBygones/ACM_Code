/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2025-04-10
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

map<int, int> mpx, mpy;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        mpx.clear(), mpy.clear();
        vector<vector<int>> a(n + 1, vector<int> (m + 1));
        vector<vector<int>> b(n + 1, vector<int> (m + 1));
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                scanf("%d", &a[i][j]);
                mpx[a[i][j]] = i;
                mpy[a[i][j]] = j;
            }
        }
        bool flag = true;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                scanf("%d", &b[i][j]);
                if(mpx[b[i][j]] != mpx[b[i][1]] || mpy[b[i][j]] != mpy[b[1][j]])    //同行或同列中对应的数是否不变
                    flag = false;
            }
        }
        puts(flag ? "YES" : "NO");
    }
    return 0;
}
