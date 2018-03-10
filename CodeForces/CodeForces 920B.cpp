/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2018-02-26
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

struct Student
{
    int l,r;
    int id;
} stu[MAXN];

int ans[MAXN];

bool cmp(Student a,Student b)
{
    if(a.l==b.l)
        return a.id<b.id;
    return a.l<b.l;
}

int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0; i<n; i++)
        {
            scanf("%d%d",&stu[i].l,&stu[i].r);
            stu[i].id=i;
        }
        sort(stu,stu+n,cmp);
        int tt=0;   //时间戳
        for(int i=0; i<n; i++)
        {
            if(tt<=stu[i].l)
            {
                tt=stu[i].l;
                ans[stu[i].id]=tt;
                tt++;
            }
            else
            {
                if(tt<=stu[i].r)
                {
                    ans[stu[i].id]=tt;
                    tt++;
                }
                else
                    ans[stu[i].id]=0;
            }
        }
        for(int i=0; i<n; i++)
        {
            if(i)
                printf(" %d",ans[i]);
            else
                printf("%d",ans[i]);
        }
        puts("");
    }
    return 0;
}
