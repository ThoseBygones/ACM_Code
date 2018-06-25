/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2018-06-19
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: AOJ
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
#define MAXN 30

struct Node
{
    int fa,l,r;
    int ind;    //入度
} nd[MAXN];

void preOrder(int u)
{
    printf(" %d",u);
    int l=nd[u].l,r=nd[u].r;
    if(~l)
        preOrder(l);
    if(~r)
        preOrder(r);
}

void inOrder(int u)
{
    int l=nd[u].l,r=nd[u].r;
    if(~l)
        inOrder(l);
    printf(" %d",u);
    if(~r)
        inOrder(r);
}

void postOrder(int u)
{
    int l=nd[u].l,r=nd[u].r;
    if(~l)
        postOrder(l);
    if(~r)
        postOrder(r);
    printf(" %d",u);
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        nd[i].ind=0;
    for(int i=0; i<n; i++)
    {
        int id;
        scanf("%d",&id);
        scanf("%d%d",&nd[id].l,&nd[id].r);
        nd[nd[id].l].ind++;
        nd[nd[id].r].ind++;
    }
    int root=0;
    for(int i=0; i<n; i++)
    {
        if(nd[i].ind==0)
        {
            root=i;
            break;
        }
    }
    printf("Preorder\n");
    preOrder(root);
    puts("");
    printf("Inorder\n");
    inOrder(root);
    puts("");
    printf("Postorder\n");
    postOrder(root);
    puts("");
    return 0;
}
