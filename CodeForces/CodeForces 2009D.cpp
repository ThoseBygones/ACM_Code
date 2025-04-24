/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2025-04-22
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

const int MAXN = 200005;

bool mp[MAXN][2];
LL l[MAXN], r[MAXN];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        for(int i = 0; i <= n; i++)
        {
            mp[i][0] = mp[i][1] = false;
            l[i] = r[i] = 0;
        }
        for(int i = 0; i < n; i++)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            mp[x][y] = true;
        }
        for(int i = 0; i <= n; i++)
        {
            l[i] = mp[i][0] + mp[i][1];
            if(i)
                l[i] += l[i - 1];
        }
        for(int i = n; i >= 0; i--)
        {
            r[i] = mp[i][0] + mp[i][1];
            if(i < n)
                r[i] += r[i + 1];
        }
        LL ans = 0;
        for(int i = 0; i <= n; i++)
        {
            if(mp[i][0] && mp[i][1])
            {
                if(i)
                    ans += l[i - 1];    //加上左侧的所有点
                if(i < n)
                    ans += r[i + 1];    //加上右侧的所有点
            }
            if(i && i < n)  //点在中间
            {
                if(mp[i][0])    //(i, 0)有点
                    ans += (mp[i - 1][1] && mp[i + 1][1]);  //(i - 1, 1)和(i + 1, 1)有点则能构成直角三角形
                if(mp[i][1])    //(i, 1)有点
                    ans += (mp[i - 1][0] && mp[i + 1][0]);  //(i - 1, 0)和(i + 1, 0)有点则能构成直角三角形
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
