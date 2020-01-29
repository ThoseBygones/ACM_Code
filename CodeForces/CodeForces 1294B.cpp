/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-01-28
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
#define MAXN 1005

struct Point
{
    int x,y;
    bool operator <(const Point &pt) const
    {
        if(x == pt.x)
            return y < pt.y;
        return x < pt.x;
    }
} p[MAXN];

int main()
{
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int n;
        scanf("%d",&n);
        p[0].x = 0, p[0].y = 0;
        for(int i=1; i<=n; i++)
            scanf("%d%d",&p[i].x,&p[i].y);
        sort(p,p+1+n);
        vector<char> ans;
        bool flag = true;
        for(int i=0; i<n; i++)
        {
            if(p[i].y <= p[i+1].y)
            {
                for(int j=p[i].x; j<p[i+1].x; j++)
                    ans.PB('R');
                for(int j=p[i].y; j<p[i+1].y; j++)
                    ans.PB('U');
            }
            else
            {
                flag = false;
                break;
            }
        }
        if(flag)
        {
            puts("YES");
            for(int i=0; i<ans.size(); i++)
                printf("%c",ans[i]);
            puts("");
        }
        else
            puts("NO");
    }
    return 0;
}
