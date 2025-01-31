/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2025-01-23
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

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        queue<int> q;
        int n, m;
        scanf("%d%d", &n, &m);
        bool flag = false;
        q.push(n);
        while(!q.empty())
        {
            int x = q.front();
            q.pop();
            if(x == m)
            {
                flag = true;
                break;
            }
            if(x % 3 == 0)
            {
                int a = x / 3 * 2;
                int b = x / 3;
                if(a == m || b == m)
                {
                    flag = true;
                    break;
                }
                if(a > m)
                    q.push(a);
                if(b > m)
                    q.push(b);
            }
        }
        puts(flag ? "YES" : "NO");
    }
    return 0;
}
