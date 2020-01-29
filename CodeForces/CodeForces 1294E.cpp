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
#define MAXN 200005

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    vector<vector<int> > a(n);
    for(int i=0; i<n; i++)
        a[i].resize(m);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            scanf("%d",&a[i][j]);
            a[i][j]--;
        }
    }
    int ans = 0;
    for(int j=0; j<m; j++)  //枚举列
    {
        vector<int> cnt(n); //记录每行的元素要shift多少次
        for(int i=0; i<n; i++)  //枚举行
        {
            if(a[i][j] % m == j)    //a[i][j]在其应在的列
            {
                int row = a[i][j] / m;  //该元素应该在的行号
                //cout << row << endl;
                if(row < n) //该行号在合理范围内
                    cnt[(i+n-row)%n]++;
            }
        }
        int Min = n - cnt[0];   //不移动的方案：不在应在位置上的元素直接修改
        for(int i=1; i<n; i++)
            Min = min(Min, i+n-cnt[i]); //移动i次的方案：移动i次 + 移动后不在应在位置上的元素直接修改
        ans += Min;
        //cout << ans << endl;
    }
    printf("%d\n",ans);
    return 0;
}
