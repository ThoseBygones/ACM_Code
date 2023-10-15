/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2023-10-11
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: 贪心 + 堆（优先队列）
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

const int MAXN = 200005;

vector<int> a[MAXN];
int p[MAXN], q[MAXN];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            a[i].clear();
        priority_queue<int> pq;
        for(int i = 1; i <= n; i++)
        {
            int x;
            scanf("%d", &x);
            a[x].PB(i);
        }
        for(int i = 1; i <= n; i++)
        {
            if(!a[i].size())
                pq.push(i);
        }
        bool flag = true;
        for(int i = n; i; i--)
        {
            if(a[i].size() > 2)
            {
                flag = false;
                break;
            }
            else if(a[i].size() == 2)
            {
                int val = pq.top();
                pq.pop();
                int id1 = a[i][0], id2 = a[i][1];
                if(val > i)
                {
                    flag = false;
                    break;
                }
                else
                    p[id1] = val, q[id1] = i;
                    p[id2] = i, q[id2] = val;
            }
            else if(a[i].size() == 1)
            {
                int id = a[i][0];
                p[id] = i, q[id] = i;
            }
        }
        if(flag)
        {
            puts("YES");
            for(int i = 1; i <= n; i++)
                printf("%d%c", p[i], i == n ? '\n' : ' ');
            for(int i = 1; i <= n; i++)
                printf("%d%c", q[i], i == n ? '\n' : ' ');
        }
        else
            puts("NO");
    }
    return 0;
}
