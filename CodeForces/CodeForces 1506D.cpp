/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-05-20
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

map<int, int> mp;
priority_queue<int> pq;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        mp.clear();
        while(!pq.empty())
            pq.pop();
        for(int i = 0; i < n; i++)
        {
            int x;
            scanf("%d", &x);
            mp[x]++;
        }
        for(auto &val: mp)
            pq.push(val.second);
        int ans = n;
        while(pq.size() >= 2)
        {
            int cnt1 = pq.top();
            pq.pop();
            int cnt2 = pq.top();
            pq.pop();
            cnt1--, cnt2--;
            ans -= 2;
            if(cnt1)
                pq.push(cnt1);
            if(cnt2)
                pq.push(cnt2);
        }
        printf("%d\n", ans);
    }
    return 0;
}
