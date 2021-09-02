/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-09-02
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: HDU
 *  Algorithm: 二叉搜索树
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

const int MAXN = 505;

char s[12];
int tree[MAXN], tree2[MAXN];

void build(int val, int pos, int tree[])
{
    if(tree[pos] == -1)
    {
        tree[pos] = val;
        return ;
    }
    if(val < tree[pos])
        build(val, pos << 1, tree);
    else
        build(val, pos << 1 | 1, tree);
}

int main()
{
    int n;
    while(~scanf("%d", &n), n)
    {
        memset(tree, -1, sizeof(tree));
        scanf("%s", s);
        int len = strlen(s);
        for(int i = 0; i < len; i++)
            build(s[i] - '0', 1, tree);
        while(n--)
        {
            bool same = true;
            scanf("%s", s);
            memset(tree2, -1, sizeof(tree2));
            len = strlen(s);
            for(int i = 0; i < len; i++)
                build(s[i] - '0', 1, tree2);
            for(int i = 1; i < MAXN; i++)
            {
                if(tree[i] != tree2[i])
                {
                    same = false;
                    break;
                }
            }
            puts(same ? "YES" : "NO");
        }
    }
    return 0;
}
