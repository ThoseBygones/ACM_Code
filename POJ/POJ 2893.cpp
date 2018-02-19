/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2018-02-19
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: POJ
 *  Algorithm: 判断 M * N 数码问题是否有解 + 树状数组求逆序对
 ********************************************************************************
 *  Algo-Description:
 *  > M * N 数码问题是否有解
 *  > 定义某状态的奇偶性为逆序对总数（不包括0）的奇偶性。
 *  > 将 M * N 数码从左往右从上往下展开成一维序列；
 *  > 这样，此题目终态为偶数（逆序对总数为0）
 *  > 原二维平面上左右（水平）移动0不改变奇偶性。
 *  > N（列数）为奇数时，上下移动0不改变奇偶性，则逆序数为偶数的有解，为奇的无解；
 *  > N（列数）为偶数时，上下移动0每移动一次奇偶性改变一次。因此还要考虑0上下移动的次数。
 *  > 逆序数与上下移动次数同奇偶时有解，否则无解。
 *  > 以上证明详见：http://blog.csdn.net/tailzhou/article/details/3002442
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
using namespace std;

//vector <int> a;   //用vector速度稍慢一些
int a[MAXN*MAXN];
int bit[MAXN*MAXN];
int cnt;

void add(int i,int x)
{
    while(i <= cnt)
    {
        bit[i] += x;
        i += lowbit(i);
    }
}

int getSum(int i)
{
    int sum = 0;
    while(i > 0)
    {
        sum += bit[i];
        i -= lowbit(i);
    }
    return sum;
}

int main()
{
    int n,m;
    while(~scanf("%d%d",&m,&n))
    {
        if(m==0 && n==0)
            break;
        int dis;
        //a.clear();
        cnt = 0;
        memset(bit,0,sizeof(bit));
        for(int i=1; i<=m; i++)
        {
            for(int j=1; j<=n; j++)
            {
                int temp;
                scanf("%d",&temp);
                if(temp==0)
                    dis=m-i;
                else
                    //a.PB(temp);
                    a[++cnt]=temp;
            }
        }
        //cnt=a.size();
        int revsum=0;
        for(int i=1; i<=cnt; i++)
        {
            add(a[i],1);
            revsum+=i-getSum(a[i]);
        }
        if(n & 1)   //列数为奇数,则上下移动也不改变逆序对数量
            puts((revsum & 1) ? "NO" : "YES");    //终态逆序对数量为0（偶数），因此只有初态逆序对数量为偶数才有解
        else    //列数为偶数，则上下移动改变逆序对数量
            puts(((revsum ^ dis) & 1) ? "NO" : "YES");  //逆序对数量与上下移动次数同奇偶才有解
    }
    return 0;
}
