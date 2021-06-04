/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-06-04
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: STL set
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

set<PII> s;
int a[10], b[MAXN];
int cnt[MAXN];  //每个音还能在几根弦上有选择

int main()
{
    for(int i = 1; i <= 6; i++)
        scanf("%d", &a[i]);
    sort(a + 1, a + 1 + 6);
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &b[i]);
        cnt[i] = 1;
        //cnt[i] = 6;
    }
    sort(b + 1, b + 1 + n);
    for(int i = 1; i <= n; i++)
        s.insert(MP(b[i] - a[cnt[i]], i));
    int ans = (*s.rbegin()).first - (*s.begin()).first;
    while(!s.empty())
    {
        int id = (*s.rbegin()).second;  //当前集合中的最大值
        //int id = (*s.begin()).second;  //当前集合中的最小值
        if(cnt[id] == 6)
        //if(cnt[id] == 1)
            break;
        s.erase(*s.rbegin());
        //s.earse(s.begin());
        s.insert(MP(b[id] - a[++cnt[id]], id));
        //s.insert(MP(b[id] - a[--cnt[id]], id));
        ans = min(ans, (*s.rbegin()).first - (*s.begin()).first);
    }
    printf("%d\n", ans);
    return 0;
}
