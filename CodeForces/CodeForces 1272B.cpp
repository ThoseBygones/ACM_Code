/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-01-21
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
#define MAXN 100005

char str[MAXN];

int main()
{
    int q;
    scanf("%d",&q);
    while(q--)
    {
        scanf("%s",str);
        int len = strlen(str);
        int l = 0, r = 0, u = 0, d = 0;
        for(int i=0; i<len; i++)
        {
            if(str[i] == 'L')
                l++;
            if(str[i] == 'R')
                r++;
            if(str[i] == 'U')
                u++;
            if(str[i] == 'D')
                d++;
        }
        int x = min(l,r), y = min(u,d);
        if(x && y)
        {
            printf("%d\n",x*2+y*2);
            for(int i=0; i<x; i++)
                printf("L");
            for(int i=0; i<y; i++)
                printf("U");
            for(int i=0; i<x; i++)
                printf("R");
            for(int i=0; i<y; i++)
                printf("D");
            puts("");
        }
        else
        {
            if(x)
                printf("2\nLR\n");
            else if(y)
                printf("2\nUD\n");
            else
                printf("0\n\n");
        }
    }
    return 0;
}
