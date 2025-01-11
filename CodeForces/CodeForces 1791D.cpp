/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2024-12-27
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

char s[MAXN];
int cnta[30], cntb[30];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d%s", &n, s);
        for(int i = 0; i < 26; i++)
            cnta[i] = cntb[i] = 0;
        for(int i = 0; i < n; i++)
            cntb[s[i] - 'a']++;
        int cura = 0, curb = 0;
        for(int i = 0; i < 26; i++)
        {
            if(cntb[i])
                curb++;
        }
        int ans = cura + curb;
        //printf("start: %d\n", ans);
        for(int i = 0; i < n - 1; i++)
        {
            if(!cnta[s[i] - 'a'])
                cura++;
            cnta[s[i] - 'a']++;
            cntb[s[i] - 'a']--;
            if(!cntb[s[i] - 'a'])
                curb--;
            ans = max(ans, cura + curb);
        }
        printf("%d\n", ans);
    }
    return 0;
}
