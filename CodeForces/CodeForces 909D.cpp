/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V2.3
 *  Date: 2018-02-05
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
#define MAXN 1000005
using namespace std;

struct PointSet
{
    char val;
    int num;
} ps[MAXN];

char s[MAXN];
int len;

void unionPoint()
{
    int cnt=0;
    for(int i=1; i<=len; i++)
    {
        if(ps[i].num>0)
        {
            if(ps[i].val==ps[cnt].val)
                ps[cnt].num+=ps[i].num;
            else
                ps[++cnt]=ps[i];
        }
    }
    len=cnt;
}

int main()
{
    scanf("%s",s+1);
    len=strlen(s+1);
    ps[0]={'#',0};   //下标0的数组作为比较标志，不参与删减
    for(int i=1; i<=len; i++)
    {
        ps[i].val=s[i];
        ps[i].num=1;
    }
    unionPoint();
    int ans=0;
    while(len>1)
    {
        ans++;
        for(int i=1; i<=len; i++)
        {
            if(i==1 || i==len)
                ps[i].num--;
            else
                ps[i].num-=2;
        }
        unionPoint();
    }
    printf("%d\n",ans);
    return 0;
}
