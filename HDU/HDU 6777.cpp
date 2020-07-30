/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-07-25
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: HDU
 *  Algorithm: 暴力
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

const int MAXN = 20005;
const int MAXT = 200005;
const int MAXP = 12;

vector<int> per[MAXT][MAXP];

bool covid[MAXN];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        for(int i = 0; i < MAXT; i++)
        {
            for(int j = 0; j < MAXP; j++)
                per[i][j].clear();
        }
        memset(covid, false, sizeof(covid));
        covid[1] = true;
        int MaxT = 0;
        for(int i = 1; i <= n; i++)
        {
            int len;
            scanf("%d", &len);
            while(len--)
            {
                int t, p;
                scanf("%d%d", &t, &p);
                MaxT = max(MaxT, t);
                per[t][p].PB(i);
            }
        }
        for(int i = 1; i <= MaxT; i++)
        {
            for(int j = 1; j <= 10; j++)
            {
                bool infected = false;
                for(int k = 0; k < per[i][j].size(); k++)
                {
                    if(covid[per[i][j][k]])
                    {
                        infected = true;
                        break;
                    }
                }
                if(infected)
                {
                    for(int k = 0; k < per[i][j].size(); k++)
                        covid[per[i][j][k]] = true;
                }
            }
        }
        vector<int> ans;
        for(int i = 1; i <= n; i++)
        {
            if(covid[i])
                ans.PB(i);
        }
        for(int i = 0; i < ans.size(); i++)
            printf("%d%c", ans[i], (i == ans.size() - 1 ? '\n' : ' '));
    }
    return 0;
}
