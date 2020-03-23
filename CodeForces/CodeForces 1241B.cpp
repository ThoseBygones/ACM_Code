/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-03-20
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
#define MAXN 105

char s[MAXN], t[MAXN];
int vis1[30], vis2[30];

int main()
{
    int q;
    scanf("%d",&q);
    while(q--)
    {
        scanf("%s%s",s,t);
        int len = strlen(s);
        memset(vis1,0,sizeof(vis1));
        memset(vis2,0,sizeof(vis2));
        for(int i=0; i<len; i++)
        {
            vis1[s[i]-'a']++;
            vis2[t[i]-'a']++;
        }
        bool flag = false;
        for(int i=0; i<26; i++)
        {
            if(vis1[i] && vis2[i])
            {
                flag = true;
                break;
            }
        }
        if(flag)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}
