/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-05-08
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

const int MAXN = 55;

int cnt[MAXN];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        memset(cnt, 0, sizeof(cnt));
        for(int i = 0; i < n; i++)
        {
            int w;
            scanf("%d", &w);
            cnt[w]++;
        }
        int ans = 0;
        for(int i = 2; i <= n * 2; i++) //枚举每个队的体重和
        {
            int sum = 0;
            for(int j = 1; j <= (i - 1) / 2; j++)
            {
                if(i - j > n)
                    continue;
                sum += min(cnt[j], cnt[i - j]);
            }
            if(i % 2 == 0)
                sum += cnt[i / 2] / 2;
            ans = max(ans, sum);
            //printf("sum: %d, cnt: %d\n", i, sum);
        }
        printf("%d\n", ans);
    }
    return 0;
}
