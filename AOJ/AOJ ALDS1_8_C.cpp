/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2018-06-29
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
#define MAXN 500010

struct Node
{
    int l,r;
    int val;
    void init()
    {
        l=r=-1;
        val=INT_MAX;
    }
} nd[MAXN];

int cnt;
int root;

void addNode(int val)
{
    nd[++cnt].init();
    int cur=root;
    while(nd[cur].val!=INT_MAX)
    {
        if(val<nd[cur].val)
        {
            if(~nd[cur].l)
                cur=nd[cur].l;
            else
            {
                nd[cur].l=cnt;
                break;
            }
        }
        else
        {
            if(~nd[cur].r)
                cur=nd[cur].r;
            else
            {
                nd[cur].r=cnt;
                break;
            }

        }
    }
    nd[cnt].val=val;
}

bool findNode(int val)
{
    int cur=root;
    while(nd[cur].val!=INT_MAX)
    {
        if(val==nd[cur].val)
            return true;
        if(val<nd[cur].val)
        {
            if(~nd[cur].l)
                cur=nd[cur].l;
            else
                return false;
        }
        else
        {
            if(~nd[cur].r)
                cur=nd[cur].r;
            else
                return false;
        }
    }
    return false;
}

PII getNode(int cur,int fa)
{
    fa=cur;
    cur=nd[cur].r;
    while(~nd[cur].l)
    {
        fa=cur;
        cur=nd[cur].l;
    }
    return MP(cur,fa);
}


void delNode(int val)
{
    int cur=root;   //找到的结点
    int pa=-1;
    while(nd[cur].val!=INT_MAX)
    {
        //cout << "cur: " << nd[nd[cur].l].val << "-" << nd[nd[cur].r].val << endl;
        if(val==nd[cur].val)
            break;
        if(val<nd[cur].val)
        {
            if(~nd[cur].l)
            {
                pa=cur;
                cur=nd[cur].l;
            }
        }
        else
        {
            if(~nd[cur].r)
            {
                pa=cur;
                cur=nd[cur].r;
            }
        }
    }
    int del,delfa;    //要删除的结点
    if(~nd[cur].l && ~nd[cur].r)
    {
        PII res=getNode(cur,pa);
        delfa=res.second;
        del=res.first;
        nd[cur].val=nd[del].val;
        if(nd[delfa].l==del)
            nd[delfa].l=-1;
        else if(nd[delfa].r==del)
            nd[delfa].r=-1;
    }
    else
    {
        int delson=-1;
        if(~nd[cur].l)
            delson=nd[cur].l;
        else if(~nd[cur].r)
            delson=nd[cur].r;
        //cout << "val: " << nd[delson].val << endl;
        //cout << "paval: " << nd[pa].val << endl;
        if(nd[pa].l==cur)
            nd[pa].l=delson;
        else if(nd[pa].r==cur)
            nd[pa].r=delson;
    }
}

void preOrder(int u)
{
    printf(" %d",nd[u].val);
    if(~nd[u].l)
        preOrder(nd[u].l);
    if(~nd[u].r)
        preOrder(nd[u].r);
}

void inOrder(int u)
{
    if(~nd[u].l)
        inOrder(nd[u].l);
    printf(" %d",nd[u].val);
    if(~nd[u].r)
        inOrder(nd[u].r);
}

int main()
{
    int n;
    scanf("%d",&n);
    root=1;
    for(int i=0; i<n; i++)
    {
        char op[10];
        scanf("%s",op);
        if(op[0]=='i')
        {
            int x;
            scanf("%d",&x);
            addNode(x);
        }
        else if(op[0]=='f')
        {
            int x;
            scanf("%d",&x);
            puts(findNode(x)?"yes":"no");
        }
        else if(op[0]=='d')
        {
            int x;
            scanf("%d",&x);
            delNode(x);
        }
        else
        {
            inOrder(root);
            puts("");
            preOrder(root);
            puts("");
        }
    }
    return 0;
}
