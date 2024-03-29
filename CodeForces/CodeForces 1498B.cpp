/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2022-10-24
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: 优先队列
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

int a[MAXN];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, w;
        scanf("%d%d", &n, &w);
        for(int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        sort(a, a + n, greater<int>());
        priority_queue<int> pq;
        for(int i = 0; i < n; i++)
        {
            if(!pq.empty())
            {
                int x = pq.top();
                if(a[i] <= x)
                {
                    pq.pop();
                    pq.push(x - a[i]);
                }
                else
                    pq.push(w - a[i]);
            }
            else
                pq.push(w - a[i]);
        }
        printf("%d\n", pq.size());
    }
    return 0;
}
