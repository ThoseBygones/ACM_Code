/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-04-20
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm:
 ********************************************************************************
 *  Algo-Description:
 ********************************************************************************
 */

#include <bits/stdc++.h>  //For CodeForces only
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
#define clr(ar,val) memset(ar, val, sizeof(ar))
#define istr stringstream
#define FOR(i,n) for(int i=0;i<(n);++i)
#define forIt(mp,it) for(__typeof(mp.begin()) it = mp.begin();it!=mp.end();it++)
const double EPS = 1e-6;
const int INF = 0x3fffffff;
const LL LINF = INF * 1ll * INF;
const double PI = acos(-1.0);

#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define lowbit(u) (u&(-u))
#define MAXN 50005

char s1[MAXN], s2[MAXN];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        scanf("%s", s1);
        bool flag = false;
        for(int i = 0; i < n; i++)
        {
            if(s1[i] == '2')
            {
                if(flag)
                {
                    s1[i] = '0';
                    s2[i] = '2';
                }
                else
                {
                    s1[i] = '1';
                    s2[i] = '1';
                }
            }
            else if(s1[i] == '1')
            {
                if(flag)
                {
                    s1[i] = '0';
                    s2[i] = '1';
                }
                else
                {
                    s2[i] = '0';
                    flag = true;
                }
            }
            else
                s2[i] = '0';
        }
        s2[n] = '\0';
        printf("%s\n%s\n", s1, s2);
    }
    return 0;
}
