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
#define MAXN 110010

char newstr[MAXN<<1];   //转换后的新字符串
int rad[MAXN<<1];  //rad[i]表示i的回文半径

int manacher(char *str)
{
    int j;
    int Max = 0;
    newstr[0] = '$';    //字符串开头增加一个特殊字符，防止越界
    int len;
    //int len=strlen(str);
    //for(int k=0; k<len; k++)
    for(len=0,j=1; str[len]!='\0'; len++)
    {
        newstr[j++] = '#';
        newstr[j++] = str[len];
    }
    newstr[j] = '#';
    newstr[j+1] = '\0';
    if(len == 0)
        return -1;
    int mx = 0,id = 0;  //mx为以newstr[id]为中心的最长回文串的右边界，即mx=id+rad[id]
    for(int i=1; i<=j; i++)
    {
        if(mx > i)
            rad[i] = min(rad[2*id-i], mx-i);    //在rad[j]和mx-i中取值小的
        else
            rad[i] = 1; //若i>=mx，则要重新计算rad[i]
        while(newstr[i+rad[i]] == newstr[i-rad[i]]) //不需边界判断，因为左有'$',右有'\0'
            rad[i]++;
        Max = max(Max,rad[i]);
        if(rad[i] + i > mx) //若新得到的回文串右端点位置大于mx，则要更新id和mx的值
        {
            mx = rad[i] + i;
            id = i;
        }
    }
    return Max-1;   //返回rad[i]中的最大值-1即为原串的最长回文子串的长度
}

int main()
{
    char str[MAXN];
    while(~scanf("%s",str))
        printf("%d\n",manacher(str));
    return 0;
}
