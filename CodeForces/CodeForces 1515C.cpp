/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2023-09-21
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: 枚举 + 优先队列
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

int h[MAXN], ans[MAXN];
priority_queue<PII, vector<PII>, greater<PII>> pq;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, m, x;
        scanf("%d%d%d", &n, &m, &x);
        for(int i = 1; i <= n; i++)
            scanf("%d", &h[i]);
        while(!pq.empty())
            pq.pop();
        for(int i = 1; i <= m; i++)
            pq.push(MP(0, i));
        for(int i = 1; i <= n; i++)
        {
            PII tmp = pq.top();
            //printf("out -> id:%d - %d\n", tmp.second, tmp.first);
            pq.pop();
            ans[i] = tmp.second;
            pq.push(MP(tmp.first + h[i], tmp.second));
        }
        puts("YES");
        for(int i = 1; i <= n; i++)
            printf("%d%c", ans[i], i == n ? '\n' : ' ');
    }
    return 0;
}
