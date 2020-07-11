/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-07-10
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

const int MAXN = 2005;

char s[MAXN];
int cnt[30];

bool check(int val, int len)
{
    int sum = 0;
    for(int i = 0; i < 26; i++)
        sum += cnt[i] / val;    //能凑成val组的字符串长度
    return sum >= len;
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, k;
        scanf("%d%d", &n, &k);
        scanf("%s", s);
        for(int i = 0; i < 26; i++)
            cnt[i] = 0;
        for(int i = 0; i < n; i++)
            cnt[s[i]-'a']++;
        int ans = 0;
        for(int i = 1; i <= n; i++) //枚举项链可能的长度
        {
            int gcd = __gcd(i, k);
            int bcnt = i / gcd; //需要bcnt组完全相同的字符串
            if(check(bcnt, gcd))
                ans = i;
        }
        printf("%d\n", ans);
    }
    return 0;
}
