/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-06-25
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

vector<PII> ans;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        ans.clear();
        int val = n;
        while(val != 2)
        {
            int tmp = ceil(sqrt(val));  //开根号后向上取整
            for(int i = tmp + 1; i < val; i++)  //这个根号数之后的所有数（除了上一个根号数）都由前一个数变为1
                ans.PB(MP(i, i + 1));
            ans.PB(MP(val, tmp));
            ans.PB(MP(val, tmp)); //两次操作把上一个根号数变为1
            val = tmp;
        }
        printf("%d\n", ans.size());
        for(int i = 0; i < ans.size(); i++)
            printf("%d %d\n", ans[i].first, ans[i].second);
    }
    return 0;
}
