/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2019-07-08
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
#define MAXN 150005

char str1[MAXN],str2[MAXN];
queue<int> q1[30];
queue<int> q2;
vector<PII> ans;

int main()
{
    int n;
    scanf("%d",&n);
    scanf("%s%s",str1,str2);
    for(int i=0; i<n; i++)  //记录str1出现的字母
    {
        if(str1[i] == '?')
            q1[26].push(i+1);
        else
            q1[str1[i]-'a'].push(i+1);
    }
    for(int i=0; i<n; i++)  //处理str2出现的字母
    {
        if(str2[i] == '?')
            q2.push(i+1);
        else
        {
            if(!q1[str2[i] - 'a'].empty())  //能找到匹配的字母
            {
                ans.PB(MP(q1[str2[i] - 'a'].front(),i+1));
                q1[str2[i] - 'a'].pop();
            }
            else if(!q1[26].empty())    //找不到则用str1中的'?'来匹配
            {
                ans.PB(MP(q1[26].front(),i+1));
                q1[26].pop();
            }
        }
    }
    for(int i=0; i<=26 && !q2.empty(); i++) //str2中的'?'还有剩
    {
        while(!q1[i].empty() && !q2.empty())
        {
            ans.PB(MP(q1[i].front(),q2.front()));
            q1[i].pop();
            q2.pop();
        }
    }
    int cnt = ans.size();
    printf("%d\n",cnt);
    for(int i=0; i<cnt; i++)
        printf("%d %d\n",ans[i].first,ans[i].second);
    return 0;
}
