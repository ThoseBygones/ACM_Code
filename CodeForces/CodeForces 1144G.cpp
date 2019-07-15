/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2019-07-14
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
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
#define MAXN 200005

int a[MAXN];
int ans[MAXN];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%d",&a[i]);
    int Max = -1, Min = INF;    //递增序列的最大值和递减序列的最小值
    for(int i=1; i<=n; i++)
    {
        if(a[i] >= Min && a[i] <= Max)  //无法放进递增和递减任何一个序列
        {
            puts("NO");
            return 0;
        }
        else if(a[i] < Min && a[i] > Max)   //可以放进递增递减两个序列中的任何一个
        {
            if(i != n)  //如果是最后一个元素，则随便放（放入递增序列中）；否则考虑再后一个元素的大小，尽可能的使后面的元素可以选择的空间更大
            {
                if(a[i] > a[i+1])   //该元素比后一个元素大，则把该元素放入递减序列
                {
                    Min = a[i];
                    ans[i] = 1;
                }
                else    //否则放入递增序列
                    Max = a[i];
            }
        }
        else if(a[i] > Max) //只能放入递增序列
            Max = a[i];
        else    //只能放入递减序列
        {
            Min = a[i];
            ans[i] = 1;
        }
    }
    puts("YES");
    for(int i=1; i<=n; i++)
    {
        if(i == n)
            printf("%d\n",ans[i]);
        else
            printf("%d ",ans[i]);
    }
    return 0;
}
