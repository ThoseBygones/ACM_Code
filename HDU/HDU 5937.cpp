/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V2.5
 *  Date: 2018-02-06
 *  Subject: ACM-ICPC
 *  Language: C/C++
 *  OJ: HDU
 *  Algorithm: 爆搜（DFS）+剪枝
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

using namespace std;

struct Equation
{
    int x,y,z;
    int cnt;
} e[25];

int cnt[15];
int pre[25];
int ans;

void init() //初始化(1+8)*8/2=36个合法等式
{
    int num=1;
    for(int i=1; i<=9; i++)
    {
        for(int j=i; i+j<=9; j++)
        {
            if(i==j)
            {
                e[num].x=i;
                e[num].y=j;
                e[num].z=i+j;
                e[num++].cnt=1;
            }
            else
            {
                e[num].x=i;
                e[num].y=j;
                e[num].z=i+j;
                e[num++].cnt=2;
            }
        }
    }
    for(int i=1; i<20; i++) //前缀和
        pre[i]=pre[i-1]+e[i].cnt;
}

void dfs(int pos,int sum)
{
    if(pos>20)  //20种合法等式遍历完成，保留最大值
    {
        ans=max(ans,sum);
        return ;
    }
    if(ans-sum>=36-pre[pos-1])  //该方案不可能比现有的更大，退出
        return ;
    int tx=e[pos].x;
    int ty=e[pos].y;
    int tz=e[pos].z;
    int tc=e[pos].cnt;
    if(cnt[tx] && cnt[ty] && cnt[tz]) //现有砖块能组成对称等式的至少一种
    {
        cnt[tx]--;
        cnt[ty]--;
        cnt[tz]--;
        if(cnt[tx]>=0 && cnt[ty]>=0 && cnt[tz]>=0)
            dfs(pos+1,sum+1);
        if(tc==2)
        {
            cnt[tx]--;
            cnt[ty]--;
            cnt[tz]--;
            if(cnt[tx]>=0 && cnt[ty]>=0 && cnt[tz]>=0)  //对称等式的两种均能满足
                dfs(pos+1,sum+2);
            cnt[tx]++;
            cnt[ty]++;
            cnt[tz]++;  //恢复现场
        }
        cnt[tx]++;
        cnt[ty]++;
        cnt[tz]++;  //恢复现场
    }
    dfs(pos+1,sum);
}

int main()
{
    init();
    int kase=1;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        for(int i=1; i<=9; i++)
            scanf("%d",&cnt[i]);
        ans=0;
        dfs(1,0);
        printf("Case #%d: %d\n",kase++,ans);
    }
    return 0;
}
