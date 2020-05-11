/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-05-09
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

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, k;
        scanf("%d%d", &n, &k);
        vector<int> ans;
        if(n & 1)   //和为奇数
        {
            if(k & 1 && n >= k)   //分为奇数个且n>=k
            {
                puts("YES");
                for(int i = 1; i < k; i++)
                {
                    printf("1 ");
                    n--;
                }
                printf("%d\n", n);
            }
            else
                puts("NO");
        }
        else    //和为偶数
        {
            if(!(k & 1) && n >= k)    //分为偶数个
            {
                puts("YES");
                for(int i = 1; i < k; i++)
                {
                    printf("1 ");
                    n--;
                }
                printf("%d\n", n);
            }
            else    //分为奇数个
            {
                if(n >= 2 * k)
                {
                    puts("YES");
                    for(int i = 1; i < k; i++)
                    {
                        printf("2 ");
                        n -= 2;
                    }
                    printf("%d\n", n);
                }
                else
                    puts("NO");
            }
        }
    }
    return 0;
}
