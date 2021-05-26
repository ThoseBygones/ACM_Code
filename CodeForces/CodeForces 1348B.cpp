/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-05-25
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: 构造
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

const int MAXN = 10005;

int a[MAXN];
set<int> s;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, k;
        scanf("%d%d", &n, &k);
        s.clear();
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            s.insert(a[i]);
        }
        if(s.size() > k)
        {
            puts("-1");
            continue;
        }
        for(int i = 1; i <= n; i++)
        {
            if(s.size() == k)
                break;
            s.insert(i);
        }
        printf("%d\n", n * k);
        vector<int> ans;
        for(int i = 1; i <= n; i++)
        {
            for(auto &val: s)
                ans.PB(val);
        }
        for(int i = 0; i < ans.size(); i++)
            printf("%d%c", ans[i], (i == ans.size() - 1 ? '\n' : ' '));
    }
    return 0;
}
