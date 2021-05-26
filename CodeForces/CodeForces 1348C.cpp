/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-05-25
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

const int MAXN = 100005;

char s[MAXN];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, k;
        scanf("%d%d", &n, &k);
        scanf("%s", s);
        sort(s, s + n);
        if(s[0] != s[k - 1])
            printf("%c\n", s[k - 1]);
        else
        {
            bool same = true;
            for(int i = k + 1; i < n; i++)
            {
                if(s[i - 1] != s[i])
                {
                    same = false;
                    break;
                }
            }
            printf("%c", s[0]);
            if(same)    //都相同
            {
                for(int i = 1; i <= (n - 1) / k; i++)
                    printf("%c", s[k]);
            }
            else
            {
                for(int i = k; i < n; i++)
                    printf("%c", s[i]);
            }
            puts("");
        }
    }
    return 0;
}
