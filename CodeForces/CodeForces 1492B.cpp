/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2022-03-28
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

const int MAXN = 100005;

int a[MAXN], pos[MAXN];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            pos[a[i]] = i;
        }
        vector<PII> ans;
        int pre = n + 1;
        for(int i = n; i; i--)
        {
            if(pos[i] < pre)
            {
                ans.PB(MP(pos[i], pre));
                pre = pos[i];
            }
        }
        for(int i = 0; i < ans.size(); i++)
        {
            for(int j = ans[i].first; j < ans[i].second; j++)
                printf("%d%c", a[j], (i == ans.size() - 1 && j == ans[i].second - 1) ? '\n' : ' ');
        }
    }
    return 0;
}
