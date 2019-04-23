/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2019-04-23
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: POJ
 *  Algorithm: 贪心
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
#define MAXN 105

struct Wall
{
    int x1,y1,x2,y2;
} w[MAXN];

int cnt[MAXN];  //每列有几堵墙
int vis[MAXN];  //编号为i的墙是否被拆除

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        memset(cnt,0,sizeof(cnt));
        memset(vis,0,sizeof(vis));
        for(int i=0; i<n; i++)
        {
            scanf("%d%d%d%d",&w[i].x1,&w[i].y1,&w[i].x2,&w[i].y2);
            if(w[i].x1 > w[i].x2)
                swap(w[i].x1,w[i].x2);
            for(int j=w[i].x1; j<=w[i].x2; j++)
                cnt[j]++;
        }
        int ans = 0;
        for(int i=0; i<=100; i++)
        {
            while(cnt[i] > k)
            {
                int pos = -1;   //向右延伸最长的墙的编号
                int len = 0;    //向右延伸最长的墙的长度
                for(int j=0; j<n; j++)  //枚举所有墙
                {
                    if(vis[j])  //该墙已被拆除
                        continue;
                    if(w[j].x1 <= i && i <= w[j].x2 && w[j].x2 - i + 1 > len)   //该墙堵在该列上
                    {
                        len = w[j].x2 - i + 1;
                        pos = j;
                    }
                }
                vis[pos] = true;    //标记该墙已被拆除
                for(int j = w[pos].x1; j<=w[pos].x2; j++)
                    cnt[j]--;
                ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
