/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-04-02
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm: 二分 + 贪心
 ********************************************************************************
 *  Algo-Description:
 ********************************************************************************
 */

#include <bits/stdc++.h>  //For CodeForces only
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
#define clr(ar,val) memset(ar, val, sizeof(ar))
#define istr stringstream
#define FOR(i,n) for(int i=0;i<(n);++i)
#define forIt(mp,it) for(__typeof(mp.begin()) it = mp.begin();it!=mp.end();it++)
const double EPS = 1e-6;
const int INF = 0x3fffffff;
const LL LINF = INF * 1ll * INF;
const double PI = acos(-1.0);

#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define lowbit(u) (u&(-u))
#define MAXN 200005

struct Salary
{
    int l, r;
    bool operator < (const Salary & s)
    {
        return l < s.l;
    }
} sa[MAXN];

int n;
LL s;

bool check(int val)
{
    LL sum = 0;
    int cnt = 0;
    for(int i = n; i; i--)
    {
        if(cnt * 2 < n && sa[i].r >= val)   //中位数后面的人数还不够且工资帽不会低于设定值
        {
            if(sa[i].l >= val)  //该员工工资最少比val还高
                sum += sa[i].l; //则支付其规定的最低工资
            else
                sum += val; //否则支付设定值
            cnt++;
        }
        else
            sum += sa[i].l; //不在中位数后面的人支付其规定的最低工资
    }
    return sum <= s && cnt * 2 > n;
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%lld", &n, &s);
        for(int i = 1; i <= n; i++)
            scanf("%d%d", &sa[i].l, &sa[i].r);
        sort(sa + 1, sa + 1 + n);
        int l = sa[n/2+1].l, r = INF;
        int ans = sa[n/2+1].l;
        while(l <= r)
        {
            int mid = (l + r) >> 1;
            if(check(mid))
            {
                ans = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        printf("%d\n", ans);
    }
    return 0;
}
