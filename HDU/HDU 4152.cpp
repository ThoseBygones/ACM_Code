/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2019-03-21
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: HDU
 *  Algorithm: 枚举
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
#define MAXN 25
#define MAXM 20

int goal[MAXN];
int a[MAXM][MAXN];
int sum[MAXN];

int main()
{
    int n,m;
    while(~scanf("%d",&n))
    {
        for(int i=0; i<n; i++)
            scanf("%d",&goal[i]);
        scanf("%d",&m);
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
                scanf("%d",&a[i][j]);
        }
        int ans = 0, status = 0;
        for(int i=1; i<(1<<m); i++) //枚举所有可能的状态集合
        {
            int cnt = 0;
            memset(sum,0,sizeof(sum));
            for(int j=0; j<m; j++)
            {
                if(i&(1<<j))    //某个习惯被选中
                {
                    cnt++;
                    for(int k=0; k<n; k++)
                        sum[k] += a[j][k];
                }
            }
            bool flag = true;
            for(int j=0; j<n; j++)  //枚举每个目标
            {
                if(sum[j] < goal[j])    //判断每个目标的分数是否达到
                {
                    flag = false;
                    break;
                }
            }
            if(flag)
            {
                if(cnt > ans)   //保留的习惯更多，则更新习惯数量和保留的习惯
                {
                    ans = cnt;
                    status = i;
                }
                else if(cnt == ans && status > i)   //保留的习惯一样但习惯的序号更小，则更新保留的习惯
                    status = i;
            }
        }
        printf("%d",ans);
        if(ans)
        {
            for(int i=0; i<m; i++)
            {
                if(status&(1<<i))
                    printf(" %d",i+1);
            }
        }
        puts("");
    }
    return 0;
}
