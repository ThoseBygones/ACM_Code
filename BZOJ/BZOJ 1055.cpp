/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2019-01-30
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: BZOJ
 *  Algorithm: 区间dp
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
#define MAXN 205

int dp[MAXN][MAXN][5];  //dp[i][j][k]表示区间[i.j]的字母是否能够被替换成第k个字母
int a[5];
char sub[MAXN][3];
char ch[MAXN];
char name[] = {'W','I','N','G'};
char str[MAXN];

int sw(char c)
{
    if(c == 'W')
        return 0;
    if(c == 'I')
        return 1;
    if(c == 'N')
        return 2;
    if(c == 'G')
        return 3;
}

int main()
{
    for(int i=0; i<4; i++)
        scanf("%d",&a[i]);
    int cnt=0;
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<a[i]; j++)
        {
            scanf("%s",sub[cnt]);
            ch[cnt++] = name[i];
        }
    }
    scanf("%s",str+1);
    int len = strlen(str+1);
    for(int i=1; i<=len; i++)
        dp[i][i][sw(str[i])] = 1;
    for(int l=1; l<=len; l++)   //枚举区间长度
    {
        for(int i=1; i+l<=len; i++) //枚举起点
        {
            for(int j=i; j<i+l; j++)   //枚举区间划分点
            {
                for(int k=0; k<cnt; k++)    //枚举所有替代方案
                    dp[i][i+l][sw(ch[k])] |= (dp[i][j][sw(sub[k][0])] && dp[j+1][i+l][sw(sub[k][1])]);  //左右区间可以分别合并成该方案的两个字母
            }
        }
    }
    bool flag = true;
    if(dp[1][len][0])
    {
        flag = false;
        printf("W");
    }
    if(dp[1][len][1])
    {
        flag = false;
        printf("I");
    }
    if(dp[1][len][2])
    {
        flag = false;
        printf("N");
    }
    if(dp[1][len][3])
    {
        flag = false;
        printf("G");
    }
    if(flag)
        puts("The name is wrong!");
    else
        puts("");
    return 0;
}
