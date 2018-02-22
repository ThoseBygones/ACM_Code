/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2018-02-20
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: HDU
 *  Algorithm: Manacher
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

char str[MAXN];
char newstr[MAXN<<1];
int rad[MAXN<<1];
int len;

void manacher(char *str)
{
    int j = 1;
    int Max = 0;
    int l,r;
    newstr[0] = '$';
    for(int k=0; k<len; k++)
    {
        newstr[j++] = '#';
        newstr[j++] = str[k];
    }
    newstr[j] = '#';
    newstr[j+1] = '\0';
    int mx = 0, id = 0;
    int axis = -1;  //最大回文串的对称中心（对称轴）
    for(int i=1; i<=j; i++)
    {
        if(mx > i)
            rad[i] = min(rad[2*id-i],mx-i);
        else
            rad[i] = 1;
        while(newstr[i+rad[i]] == newstr[i-rad[i]])
            rad[i]++;
        if(Max < rad[i])
        {
            Max = rad[i];
            axis = i;
            //l = (i - rad[i]) / 2;
            //r = (i + rad[i]) / 2 - 2;
        }
        if(rad[i] + i > mx)
        {
            mx = rad[i] + i;
            id = i;
        }
    }
    //cout << axis << endl;
    if(Max - 1 == 1)
        puts("No solution!");
    else
    {
        l = (axis - rad[axis]) / 2;
        r = (axis + rad[axis]) / 2 - 2;
        printf("%d %d\n",l,r);
        for(int i=l; i<=r; i++)
            printf("%c",str[i]);
        puts("");
    }
}

int main()
{
    char c[2];
    while(~scanf("%s %s",c,str))
    {
        len = strlen(str);
        int delta = c[0] - 'a';
        for(int i=0; i<len; i++)
            str[i] = (str[i] - 'a' - delta + 26) % 26 + 'a';
        manacher(str);
    }
    return 0;
}
