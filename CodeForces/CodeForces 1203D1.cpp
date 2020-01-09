/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-01-09
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
#define MAXN 205

char s[MAXN],t[MAXN];
int ml[MAXN],mr[MAXN];  //每个字符最靠左和最靠右的位置

int main()
{
    scanf("%s",s);
    scanf("%s",t);
    int len1 = strlen(s);
    int len2 = strlen(t);
    int pos = 0;
    for(int i=0; i<len1 && pos<len2; i++)   //从前往后遍历
    {
        if(s[i] == t[pos])
        {
            ml[pos] = i;
            pos++;
        }
    }
    pos = len2 - 1;
    for(int i=len1-1; i>=0 && pos>=0; i--)
    {
        if(s[i] == t[pos])
        {
            mr[pos] = i;
            pos--;
        }
    }
    int ans = max(mr[0],len1-ml[len2-1]-1);
    for(int i=1; i<len2; i++)
        ans = max(mr[i]-ml[i-1]-1,ans);
    printf("%d\n",ans);
    return 0;
}
