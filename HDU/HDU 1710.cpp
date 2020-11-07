/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-11-04
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: HDU
 *  Algorithm: 已知二叉树前序序列和中序序列求后序序列
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
const double EPS = 1e-6;
const int INF = 0x3fffffff;
const LL LINF = INF * 1ll * INF;
const double PI = acos(-1.0);

#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define lowbit(u) (u&(-u))

const int MAXN = 1005;

vector<int> post;
int pre[MAXN], in[MAXN];
int cnt;

void build(int l, int r)
{
    if(l > r)
        return ;
    cnt++;
    if(l == r)
    {
        post.PB(in[l]);
        return ;
    }
    int rt = cnt;
    for(int i = l; i <= r; i++)
    {
        if(pre[rt] == in[i])
        {
            build(l, i - 1);
            build(i + 1, r);
            break;
        }
    }
    post.PB(pre[rt]);
}

int main()
{
    int n;
    while(~scanf("%d", &n))
    {
        for(int i = 1; i <= n; i++)
            scanf("%d", &pre[i]);
        for(int i = 1; i <= n; i++)
            scanf("%d", &in[i]);
        cnt = 0;
        post.clear();
        build(1, n);
        for(int i = 0; i < post.size(); i++)
            printf("%d%c", post[i], i == post.size() - 1 ? '\n' : ' ');
    }
    return 0;
}
