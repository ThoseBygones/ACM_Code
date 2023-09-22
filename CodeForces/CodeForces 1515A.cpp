/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2023-09-21
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

int w[MAXN];
vector<int> ans;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, x;
        scanf("%d%d", &n, &x);
        for(int i = 0; i < n; i++)
            scanf("%d", &w[i]);
        sort(w, w + n);
        ans.clear();
        int sum = 0;
        bool flag = true;
        for(int i = 0; i < n; i++)
        {
            if(sum + w[i] != x)
            {
                sum += w[i];
                ans.PB(w[i]);
            }
            else
            {
                if(i < n - 1)
                {
                    sum += w[i] + w[i + 1];
                    ans.PB(w[i + 1]);
                    ans.PB(w[i]);
                    i++;
                }
                else
                    flag = false;
            }
        }
        if(flag)
        {
            puts("YES");
            for(int i = 0; i < ans.size(); i++)
                printf("%d%c", ans[i], i == ans.size() - 1 ? '\n' : ' ');
        }
        else
            puts("NO");
    }
    return 0;
}
