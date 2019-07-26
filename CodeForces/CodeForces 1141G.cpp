/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2019-07-26
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm: 二分 / 贪心 + 构造
 ********************************************************************************
 *  Algo-Description:
 ********************************************************************************
 */

//#include <bits/stdc++.h>  //For CodeForces only

//#pragma comment(linker,"/STACK:102400000,102400000")
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <climits>
#include <ctime>
#include <numeric>
#include <vector>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <complex>
#include <deque>
#include <functional>
#include <list>
#include <map>
#include <string>
#include <sstream>
#include <set>
#include <stack>
#include <queue>
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

vector<PII> G[MAXN];
int deg[MAXN];  //节点的度数
int cnt[MAXN];  //cnt[i]表示度数为i的节点的数量
int ans[MAXN];  //记录答案的数组
int r;  //需要的公司数量

void dfs(int u,int fa,int col)  //col表示上一条边的颜色
{
    for(int i=0; i<G[u].size(); i++)
    {
        int v = G[u][i].first;
        int idx = G[u][i].second;
        if(v != fa)
        {
            col = (col + 1) % r;
            ans[idx] = col + 1; //col编号从0开始
            dfs(v,u,col);
        }
    }
}

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1; i<n; i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].PB(MP(v,i));
        G[v].PB(MP(u,i));
        deg[u]++, deg[v]++;
    }
    for(int i=1; i<=n; i++)
        cnt[deg[i]]++;
    int sum = 0;
    for(int i=n-1; i>=0; i--)
    {
        sum += cnt[i];
        if(sum > k)
        {
            r = i;
            break;
        }
    }
    dfs(1,0,-1);
    printf("%d\n",r);
    for(int i=1; i<n; i++)
    {
        if(i == 1)
            printf("%d",ans[i]);
        else
            printf(" %d",ans[i]);
    }
    puts("");
    return 0;
}
