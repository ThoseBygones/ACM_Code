/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2019-08-06
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm: 枚举 + 贪心
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

int a[MAXN],tmp[MAXN];
int sum;
vector<int> mt[MAXN];
int n,m;

bool check(int daycnt)
{
    //cout << "Day = " << daycnt << endl;
    int left = sum;   //剩余未购买的商品数量
    int burle = daycnt;   //剩余可用的钱
    int cost = 0;   //已经花费的钱数
    for(int i=1; i<=n; i++)
        tmp[i] = a[i];
    for(int i=min(daycnt,1000); i; i--)   //从期限的最后一天往前遍历
    {
        burle = min(burle,i);   //第i天可用的钱数
        for(int j=0; j<mt[i].size(); j++)   //枚举当天的所有优惠
        {
            while(tmp[mt[i][j]] && burle)    //优惠的商品需要且钱够
            {
                //cout << "day " << i << ": buy mt No." << mt[i][j] << endl;
                tmp[mt[i][j]]--;
                left--;
                burle--;
                cost++;
                //cout << "cost = " << cost << endl;
            }
        }
    }
    cost += 2 * left;   //剩余未购买的商品只能用原价购买
    //cout << "Total cost: " << cost << endl;
    if(cost > daycnt)
        return false;
    return true;
}

int main()
{
    scanf("%d%d",&n,&m);
    sum = 0;
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&a[i]);
        sum += a[i];
    }
    for(int i=0; i<m; i++)
    {
        int d,t;
        scanf("%d%d",&d,&t);
        mt[d].PB(t);
    }
    for(int i=sum; i<=2*sum; i++)
    {
        if(check(i))
        {
            printf("%d\n",i);
            break;
        }
    }
    return 0;
}
