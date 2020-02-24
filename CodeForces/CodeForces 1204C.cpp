/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-02-17
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm: Floyd求最短路
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
#define MAXM 1000005

vector<int> ans;
char g[MAXN][MAXN];
int d[MAXN][MAXN];
int p[MAXM];
int n,m;

void floyd()
{
    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
                d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
        }
    }
}

int main()
{
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%s",g[i]+1);
    scanf("%d",&m);
    for(int i=1; i<=m; i++)
        scanf("%d",&p[i]);
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(g[i][j] == '1')
                d[i][j] = 1;
            else
                d[i][j] = INF;
        }
    }
    floyd();
    ans.PB(p[1]);
    int pre = p[1];
    for(int i=2; i<m; i++)
    {
        if(d[pre][p[i]]+d[p[i]][p[i+1]] != d[pre][p[i+1]] || pre == p[i+1]) //点p[i]不能被忽略，否则序列(pre,p[i+1])与序列(pre,p[i],p[i+1])表示的路径不同（特判环的情况）
        {
            ans.PB(p[i]);
            pre = p[i];
        }
    }
    ans.PB(p[m]);
    int cnt = ans.size();
    printf("%d\n",cnt);
    for(int i=0; i<cnt; i++)
    {
        if(i)
            printf(" %d",ans[i]);
        else
            printf("%d",ans[i]);
    }
    puts("");
    return 0;
}
