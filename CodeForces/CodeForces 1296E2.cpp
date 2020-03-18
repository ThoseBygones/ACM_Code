/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-02-12
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

char s[MAXN];
int ans[MAXN];
int Max[30];    //每种颜色能涂到的字母的最大值

int main()
{
    int n;
    scanf("%d",&n);
    scanf("%s",s);
    memset(Max,-1,sizeof(Max));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<26; j++)
        {
            int x = s[i] - 'a';
            if(x >= Max[j])
            {
                Max[j] = x;
                ans[i] = j + 1;
                break;
            }
        }
    }
    int cnt = 0;
    for(int i=0; i<26; i++)
    {
        if(Max[i] == -1)
            break;
        cnt++;
    }
    printf("%d\n",cnt);
    for(int i=0; i<n; i++)
    {
        if(i)
            printf(" %d",ans[i]);
        else
            printf("%d",ans[i]);
    }
    puts("");
    return 0;
}
