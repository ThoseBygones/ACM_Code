/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2019-07-14
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm:
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
#define MAXN 200010

vector<int> in,de;
int vis[MAXN];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        int x;
        scanf("%d",&x);
        vis[x]++;
    }
    for(int i=0; i<=200000; i++)
    {
        if(vis[i] > 2)
        {
            puts("NO");
            return 0;
        }
        if(vis[i] == 2)
        {
            in.PB(i);
            de.PB(i);
        }
        else if(vis[i] == 1)
            de.PB(i);
    }
    sort(in.begin(),in.end());
    sort(de.begin(),de.end());
    reverse(de.begin(),de.end());
    int incnt = in.size(), decnt = de.size();
    puts("YES");
    printf("%d\n",incnt);
    for(int i=0; i<incnt; i++)
    {
        if(i != incnt-1)
            printf("%d ",in[i]);
        else
            printf("%d",in[i]);
    }
    puts("");
    printf("%d\n",decnt);
    for(int i=0; i<decnt; i++)
    {
        if(i != decnt-1)
            printf("%d ",de[i]);
        else
            printf("%d",de[i]);
    }
    puts("");
    return 0;
}
