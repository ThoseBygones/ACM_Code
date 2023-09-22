/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2023-09-21
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: 枚举 + 思维
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

const int MAXN = 200005;
int cnt[MAXN];  //+/-x表示袜子的左/右数量多x只

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, l, r;
        scanf("%d%d%d", &n, &l, &r);
        for(int i = 1; i <= n; i++)
        {
            int x;
            scanf("%d", &x);
            if(i <= l)
                cnt[x]++;
            else
                cnt[x]--;
        }
        int lcnt = 0, rcnt = 0;
        int ls = 0, rs = 0;   //通过左右变换抵消后剩余的袜子数量
        int ans = 0;
        for(int i = 1; i <= n; i++) //如果某个颜色左或右袜子多了，如果数量为偶数则直接取一半改变左右直接配对抵消，如果数量为奇数则除剩下的一只为其余的一半改变左右配对抵消
        {
            if(cnt[i] > 0)
            {
                lcnt += cnt[i];
                ls += cnt[i] % 2;
                ans += cnt[i] / 2;
            }
            else if(cnt[i] < 0)
            {
                rcnt += -cnt[i];
                rs += (-cnt[i]) % 2;
                ans += (-cnt[i]) / 2;
            }
            cnt[i] = 0;
        }
        if(ls > rs)
        {
            swap(lcnt, rcnt);
            swap(ls, rs);
        }
        ans += rs;
        int tc = min(lcnt, rs);
        ans -= (tc - ls) / 2;   //如果经过直接变方向后影响着了左右袜子的平衡数，那么就需要调回来
        //rs -= tc;
        printf("%d\n", ans);
    }
    return 0;
}
