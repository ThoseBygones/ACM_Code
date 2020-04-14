/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-02-25
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
#define MAXN 200005

char s[MAXN],t[MAXN];
queue<int> ab,ba;

int main()
{
    int n;
    scanf("%d",&n);
    scanf("%s",s);
    scanf("%s",t);
    int abcnt = 0, bacnt = 0;
    for(int i=0; i<n; i++)
    {
        if(s[i] == 'a' && t[i] == 'b')
        {
            ab.push(i+1);
            abcnt++;
        }

        if(s[i] == 'b' && t[i] == 'a')
        {
            ba.push(i+1);
            bacnt++;
        }
    }
    if((abcnt+bacnt) & 1)
        puts("-1");
    else
    {
        printf("%d\n",abcnt%2+bacnt%2+abcnt/2+bacnt/2);
        while(abcnt >= 2)
        {
            int x = ab.front();
            ab.pop();
            int y = ab.front();
            ab.pop();
            abcnt -= 2;
            printf("%d %d\n",x,y);
        }
        while(bacnt >= 2)
        {
            int x = ba.front();
            ba.pop();
            int y = ba.front();
            ba.pop();
            bacnt -= 2;
            printf("%d %d\n",x,y);
        }
        if(abcnt && bacnt)
        {
            int x = ab.front();
            ab.pop();
            int y = ba.front();
            ba.pop();
            abcnt--;
            bacnt--;
            printf("%d %d\n",x,x);
            printf("%d %d\n",x,y);
        }
    }
    return 0;
}