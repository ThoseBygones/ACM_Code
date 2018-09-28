/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2018-09-28
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ:
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

int fa[30];

struct City
{
    int s,e,len;
} city[105];

bool cmp(City a,City b)
{
    return a.len<b.len;
}

int findset(int x)
{
    if(x != fa[x])
        return fa[x] = findset(fa[x]);
    return x;
}

bool mergeset(int x,int y)
{
    int xx = findset(x);
    int yy = findset(y);
    if(xx != yy)
    {
        fa[yy] = xx;
        return true;
    }
    return false;
}

int main()
{
    int n;
    while(~scanf("%d",&n),n)
    {
        for(int i=0; i<27; i++)
            fa[i]=i;
        int cnt=0;
        for(int i=0; i<n-1; i++)
        {
            char s1[2];
            int tot;
            scanf("%s %d",s1,&tot);
            for(int j=0; j<tot; j++)
            {
                char s2[2];
                int w;
                scanf("%s %d",s2,&w);
                city[cnt].s = s1[0]-'A';
                city[cnt].e = s2[0]-'A';
                city[cnt++].len = w;
            }
        }
        sort(city,city+cnt,cmp);
        int num = 0;
        int sum = 0;
        for(int i=0; i<cnt; i++)
        {
            if(mergeset(city[i].s,city[i].e))
            {
                sum += city[i].len;
                num++;
            }
            if(num == n-1)
                break;
        }
        printf("%d\n",sum);
    }
    return 0;
}
