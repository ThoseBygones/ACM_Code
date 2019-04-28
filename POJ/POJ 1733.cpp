/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2019-04-27
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: POJ
 *  Algorithm: 并查集 + 离散化
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
#define MAXN 5010

struct Query
{
    int l,r;
    char str[5];
} q[MAXN];

int Hash[MAXN<<1];
int fa[MAXN<<1];
int rel[MAXN<<1];  //记录关系

int findset(int x)
{
    if(x != fa[x])
    {
        int r = fa[x];
        fa[x] = findset(fa[x]); //压缩路径
        rel[x] ^= rel[r];   //从根节点向下更新相对关系
    }
    return fa[x];
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    //sort + unique 离散化
    int cnt = 0;
    for(int i=0; i<m; i++)
    {
        scanf("%d%d%s",&q[i].l,&q[i].r,q[i].str);
        Hash[++cnt] = q[i].l;
        Hash[++cnt] = ++q[i].r;
    }
    sort(Hash+1,Hash+1+cnt);
    cnt = unique(Hash+1,Hash+1+cnt) - Hash - 1;
    for(int i=1; i<=cnt; i++)
    {
        fa[i] = i;
        rel[i] = 0;
    }
    int ans = m;    //如果全队则输出值为case的数量
    for(int i=0; i<m; i++)
    {
        int x = lower_bound(Hash+1,Hash+1+cnt,q[i].l) - Hash;
        int y = lower_bound(Hash+1,Hash+1+cnt,q[i].r) - Hash;
        //cout << x << " " << y << endl;
        int xx = findset(x), yy = findset(y);
        if(xx != yy)
        {
            fa[yy] = xx;
            if(q[i].str[0] == 'o')  //奇数
                rel[yy] = rel[x] ^ rel[y] ^ 1;
            else    //偶数
                rel[yy] = rel[x] ^ rel[y];
        }
        else
        {
            if(rel[x] ^ rel[y] != (q[i].str[0] == 'o')) //当前给定的条件与之前的条件不符合
            {
                ans = i;
                break;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
