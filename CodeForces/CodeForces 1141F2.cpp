/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2019-07-25
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
#define MAXN 1505

int a[MAXN];
int sum[MAXN];
map<int,vector<PII> > mp;
vector<PII> ans;

int main()
{
    int n;
    scanf("%d",&n);
    int Max = 0, val = -1;
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&a[i]);
        sum[i] = sum[i-1] + a[i];
        for(int j=0; j<i; j++)
        {
            int tmp = sum[i] - sum[j];
            if(mp[tmp].empty()) //该键值对应的数组为空，则直接插入
                mp[tmp].PB(MP(j+1,i));
            else    //该键值对应的数组非空
            {
                if(mp[tmp].back().second < j+1) //判断要插入的区间与之前插入的区间是否相交
                    mp[tmp].PB(MP(j+1,i));
            }
            if(mp[tmp].size() > Max)
            {
                Max = mp[tmp].size();
                val = tmp;
            }
        }
    }
    printf("%d\n",Max);
    for(const auto &p: mp[val]) //只读的时候加const和引用&，修改的时候仅使用引用&，拷贝的时候不适用引用&
        printf("%d %d\n",p.first,p.second);
    return 0;
}
