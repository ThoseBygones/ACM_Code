/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2019-04-05
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: HDU
 *  Algorithm: KMP
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
#define MAXN 200010

int getNext(char* p,int *f)
{
    int m = strlen(p);
    f[0] = f[1] = 0;
    for(int i = 1; i<m; i++)
    {
        int j = f[i];
        while(j&&p[i]!=p[j])
            j = f[j];
        f[i+1] = p[i]==p[j]?j+1:0;
    }
    return m;
}

//s是匹配串，p是模版串
bool KMP(char* s,char *p,int *f)
{
    int n = strlen(s);
    int m = getNext(p,f);
    int j = 0;
    for(int i = 0; i<n; i++)
    {
        while(j&&p[j]!=s[i])
            j = f[j];
        if(p[j]==s[i])
            j++;
        if(j==m)
            return true;
    }
    return false;
}

char s[MAXN],t[MAXN];
int nxt[MAXN];

int main()
{
    while(~scanf("%s%s",s,t))
    {
        int len = strlen(s);
        for(int i=0; i<len; i++)
            s[i+len] = s[i];
        getNext(t,nxt);
        if(KMP(s,t,nxt))
            puts("yes");
        else
            puts("no");
    }
    return 0;
}
