/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-07-22
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: HDU
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

priority_queue<int, vector<int>, greater<int> > pq;

int main()
{
    int n, k;
    while(~scanf("%d%d", &n, &k))
    {
        while(!pq.empty())
            pq.pop();
        for(int i = 0; i < n; i++)
        {
            char op[2];
            scanf("%s", op);
            if(op[0] == 'I')
            {
                int x;
                scanf("%d", &x);
                if(pq.size() < k)
                    pq.push(x);
                else
                {
                    if(pq.top() < x)
                    {
                        pq.pop();
                        pq.push(x);
                    }
                }
            }
            else
                printf("%d\n", pq.top());
        }
    }
    return 0;
}
