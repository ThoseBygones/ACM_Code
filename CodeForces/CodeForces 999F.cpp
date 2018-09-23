/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2018-09-12
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm: dp
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
#define MAXN 505
#define MAXM 15

int c[MAXN*MAXM];
int f[MAXN];
int h[MAXM];
int card[100005];   //card[i]表示喜欢点数为i的卡片数量
int player[100005]; //player[i]表示喜欢点数为i的玩家数量
int dp[MAXN][MAXN*MAXM];    //将i个人分j张牌能获得的最大快乐值

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1; i<=n*k; i++)
    {
        scanf("%d",&c[i]);
        card[c[i]]++;
    }
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&f[i]);
        player[f[i]]++;
    }
    for(int i=1; i<=k; i++)
        scanf("%d",&h[i]);
    int ans=0;
    for(int x=1; x<=100000; x++) //枚举玩家喜欢的点数
    {
        if(player[x])
        {
            for(int i=1; i<=player[x]; i++) //枚举能得到自己喜欢点数卡片玩家的数量
            {
                for(int j=1; j<=card[x]; j++)   //枚举该点数的卡片数量
                {
                    for(int l=1; l<=min(k,j); l++)  //枚举每个玩家能得到自己喜欢点数卡片的数量
                        dp[i][j]=max(dp[i][j],dp[i-1][j-l]+h[l]);
                }
            }
            ans+=dp[player[x]][card[x]];
        }
    }
    printf("%d\n",ans);
    return 0;
}
