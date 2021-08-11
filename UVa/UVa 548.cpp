/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-08-11
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: UVa
 *  Algorithm: 二叉树遍历
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

const int MAXN = 10005;

int in[MAXN], post[MAXN];
int ls[MAXN], rs[MAXN];
int node, ans;

int buildTree(int l1, int l2, int n)
{
    if(n <= 0)
        return -1;
    int rt = post[l2 + n - 1];  //后序序列的最后一个结点是该子树的根
    int pos = 0;
    while(in[l1 + pos] != rt)
        pos++;
    ls[rt] = buildTree(l1, l2, pos);
    rs[rt] = buildTree(l1 + pos + 1, l2 + pos, n - pos - 1);
    //cout << ls[rt] << " - " << rs[rt] << endl;
    return rt;
}

void dfs(int u, int sum)
{
    sum += u;
    if(ls[u] == -1 && rs[u] == -1)    //叶子结点
    {
        if(sum < ans || (sum == ans && u < node))
        {
            node = u;
            ans = sum;
        }
    }
    if(~ls[u])
        dfs(ls[u], sum);
    if(~rs[u])
        dfs(rs[u], sum);
}

int main()
{
    while(~scanf("%d", &in[0]))
    {
        int cnt = 1;
        while(getchar() != '\n')
            scanf("%d", &in[cnt++]);
        for(int i = 0; i < cnt; i++)
            scanf("%d", &post[i]);
        /*for(int i = 0; i < cnt; i++)
            printf("%d ", in[i]);
        cout << endl;*/
        buildTree(0, 0, cnt);
        node = MAXN, ans = INF;
        dfs(post[cnt - 1], 0);
        printf("%d\n", node);
    }
    return 0;
}
