/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2019-04-21
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: POJ
 *  Algorithm: 枚举 + 贪心 / DP
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
#define MAXN 30

struct Lake
{
    int id,f,d;
    bool operator <(const Lake &lk) const
    {
        if(f == lk.f)
            return id > lk.id;
        return f < lk.f;
    }
} lake[MAXN];

int dis[MAXN];  //表示1号湖到i号湖的距离
int res[MAXN];  //当前方案下在各个湖的捕鱼时间
int t[MAXN];    //最佳方案下在各个湖的捕鱼时间

int main()
{
    int kase = 0;
    int n;
    while(~scanf("%d",&n),n)
    {
        if(kase++)
            puts("");
        int h;
        scanf("%d",&h);
        int m = h * 12; //转化为5分钟一个单位时间
        for(int i=1; i<=n; i++)
        {
            lake[i].id = i;
            scanf("%d",&lake[i].f);
        }
        for(int i=1; i<=n; i++)
            scanf("%d",&lake[i].d);
        dis[1] = 0;
        for(int i=2; i<=n; i++)
        {
            scanf("%d",&dis[i]);
            dis[i] += dis[i-1];
        }
        int ans = -1;
        memset(t,0,sizeof(t));
        for(int i=1; i<=n; i++) //枚举结束抓鱼时候的湖
        {
            memset(res,0,sizeof(res));
            priority_queue<Lake> pq;
            int sum = 0;
            for(int j=1; j<=i; j++) //枚举抓鱼的过程
                pq.push(lake[j]);
            int tt = m - dis[i]; //减去路上耗费的时间，剩余的是用来抓鱼的时间
            while(tt > 0)    //还有时间可以抓鱼
            {
                Lake tmp = pq.top();    //取可以抓鱼最多的湖
                pq.pop();
                tt--;
                sum += tmp.f;
                tmp.f -= tmp.d;
                res[tmp.id] += 5;
                if(tmp.f < 0)
                    tmp.f = 0;
                pq.push(tmp);
            }
            if(sum > ans)   //更优解的时候，更新答案
            {
                ans = sum;
                for(int j=1; j<=n; j++)
                    t[j] = res[j];
            }
        }
        for(int i=1; i<=n; i++)
        {
            if(i != n)
                printf("%d, ",t[i]);
            else
                printf("%d\n",t[i]);
        }
        printf("Number of fish expected: %d\n",ans);
    }
    return 0;
}
