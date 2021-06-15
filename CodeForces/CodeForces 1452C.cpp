/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-06-15
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

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%s", s);
        int n = strlen(s);
        int cnt1 = 0, cnt2 = 0, ans = 0;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '(')
                cnt1++;
            else if(s[i] == '[')
                cnt2++;
            else if(s[i] == ')')
            {
                if(cnt1)
                {
                    cnt1--;
                    ans++;
                }
            }
            else if(s[i] == ']')
            {
                if(cnt2)
                {
                    cnt2--;
                    ans++;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
