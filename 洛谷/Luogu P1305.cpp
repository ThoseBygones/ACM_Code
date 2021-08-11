/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-08-11
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: 洛谷
 *  Algorithm: 二叉树的先序遍历
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

const int MAXN = 30;

char s[5];
int ls[MAXN], rs[MAXN];
int ind[MAXN];  //树上每个点的入度
bool vis[MAXN];

void preOrder(int rt)
{
    if(~rt)
    {
        printf("%c", rt + 'a');
        preOrder(ls[rt]);
        preOrder(rs[rt]);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    memset(vis, false, sizeof(vis));
    memset(ind, 0, sizeof(ind));
    for(int i = 0; i < n; i++)
    {
        scanf("%s", s);
        for(int i = 0; i <= 2; i++)
        {
            if(s[i] != '*')
                vis[s[i] - 'a'] = true;
        }
        if(s[1] != '*')
        {
            ls[s[0] - 'a'] = s[1] - 'a';
            ind[s[1] - 'a']++;
        }
        else
            ls[s[0] - 'a'] = -1;
        if(s[2] != '*')
        {
            rs[s[0] - 'a'] = s[2] - 'a';
            ind[s[2] - 'a']++;
        }
        else
            rs[s[0] - 'a'] = -1;
    }
    for(int i = 0; i < 26; i++)
    {
        if(vis[i] && !ind[i])
        {
            preOrder(i);
            puts("");
            break;
        }
    }
    return 0;
}
