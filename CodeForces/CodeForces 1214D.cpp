/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-02-23
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
#define MAXN 1000005

char mp[MAXN];
bool vis[MAXN];
int n,m;

bool dfs(int x,int y)
{
    if(x >= n || y >= m || mp[x*m+y]=='#' || vis[x*m+y])
        return false;
    if(x == n-1 && y == m-1)
        return true;
    vis[x*m+y] = true;
    return dfs(x+1,y) || dfs(x,y+1);
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0; i<n; i++)
        scanf("%s",mp+i*m);
    int cnt = dfs(0,0);
    vis[0] = false;
    cnt += dfs(0,0);
    printf("%d\n",cnt);
    return 0;
}
