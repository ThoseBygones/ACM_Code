/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-06-13
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

const int MAXN = 1000005;

char a[MAXN], b[MAXN];
int cnta[30], cntb[30];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, k;
        scanf("%d%d", &n, &k);
        scanf("%s%s", a, b);
        for(int i = 0; i < 26; i++)
            cnta[i] = cntb[i] = 0;
        for(int i = 0; i < n; i++)
        {
            cnta[a[i] - 'a']++;
            cntb[b[i] - 'a']++;
        }
        bool flag = true;
        for(int i = 0; i < 26; i++)
        {
            if(cnta[i] < cntb[i] || (cnta[i] - cntb[i]) % k)
            {
                flag = false;
                break;
            }
            if(i != 25)
                cnta[i + 1] += cnta[i] - cntb[i];
        }
        puts(flag ? "Yes" : "No");
    }
    return 0;
}
