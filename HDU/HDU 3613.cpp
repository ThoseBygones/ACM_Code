/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2018-02-22
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: HDU
 *  Algorithm: 前缀和 + Manacher
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
#define MAXN 500010

int val[30];
char newstr[MAXN<<1];
int rad[MAXN<<1];
int sum[MAXN];  //价值前缀和
bool pre[MAXN]; //字符串的前缀（取到i）能否构成回文串
bool suf[MAXN]; //字符串的后缀（取到i）能否构成回文串
int len;

void manacher(char *str)
{
    int j = 1;
    int Max = 0;
    newstr[0] = '$';
    for(int k=0; k<len; k++)
    {
        newstr[j++] = '#';
        newstr[j++] = str[k];
    }
    newstr[j] = '#';
    newstr[j+1] = '\0';
    int mx = 0, id = 0;
    for(int i=1; i<=j; i++)
    {
        if(mx > i)
            rad[i] = min(rad[2*id-i],mx-i);
        else
            rad[i] = 1;
        while(newstr[i+rad[i]] == newstr[i-rad[i]])
            rad[i]++;
        Max = max(Max,rad[i]);
        if(i + rad[i] > mx)
        {
            mx = i + rad[i];
            id = i;
        }
        //cout << j << endl;
        if(i - rad[i] == 0) //如果以i为中心的回文串是原串的一个前缀
            pre[rad[i]-2] = true;
        if(i + rad[i] == j + 1) //如果以i为中心的回文串是原串的一个后缀
            suf[len-rad[i]] = true;
            //suf[rad[i]-2] = true; //另一种记录方式（同样正确）
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        char str[MAXN];
        for(int i=0; i<26; i++)
            scanf("%d",&val[i]);
        scanf("%s",str);
        len = strlen(str);
        memset(pre,false,sizeof(pre));
        memset(suf,false,sizeof(suf));
        memset(sum,0,sizeof(sum));
        manacher(str);
        sum[0] = val[str[0]-'a'];
        for(int i=0; i<len; i++)
            sum[i] = sum[i-1] + val[str[i]-'a'];
        int ans = -1;
        for(int i=0; i<len-1; i++)
            ans = max(ans,sum[i]*pre[i]+(sum[len-1]-sum[i])*suf[i]);
            //ans = max(ans,sum[i]*pre[i]+(sum[len-1]-sum[i])*suf[len-i-2]);    //另一种记录方式（同样正确）
        printf("%d\n",ans);
    }
    return 0;
}
