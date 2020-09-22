/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-09-17
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: AOJ
 *  Algorithm:
 ********************************************************************************
 *  Algo-Description:
 ********************************************************************************
 */

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
//#include <bits/stdc++.h>
using namespace std;

template<class T> inline T sqr(T x) {return x * x;}
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
const double EPS = 1e-6;
const int INF = 0x3fffffff;
const LL LINF = INF * 1ll * INF;
const double PI = acos(-1.0);

#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define lowbit(u) (u&(-u))

const int MAXN = 1005;
const int MAXM = 10005;

int a[MAXN], b[MAXN], ord[MAXM];
bool vis[MAXN];

int main()
{
    int n;
    scanf("%d", &n);
    int Min = INF;
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        b[i] = a[i];
        Min = min(Min, a[i]);
        vis[MAXN] = false;
    }
    sort(b, b + n);
    for(int i = 0; i < n; i++)
        ord[b[i]] = i;
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        if(!vis[i])
        {
            int cur = i;
            int cnt = 0;
            int pmin = INF; //局部（群中的）最小值
            int sum = 0;    //部分和（圈中有序的和）
            while(!vis[cur])    //遍历每个群中的元素
            {
                vis[cur] = true;
                cnt++;
                pmin = min(pmin, a[cur]);
                sum += a[cur];
                cur = ord[a[cur]];
            }
            ans += min(sum + pmin * (cnt - 2), sum + Min * (cnt + 1) + pmin);   //不借用/借用全局最小的元素来交换
        }
    }
    printf("%d\n", ans);
    return 0;
}
