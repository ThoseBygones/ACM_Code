/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-08-31
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: POJ
 *  Algorithm: BST
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

struct Node
{
    char c;
    int lc, rc;
} tree[MAXN];

char str[MAXN][MAXN];
int cnt;

void addNode(char c, int rt)
{
    if(!tree[rt].c)
    {
        tree[rt].c = c;
        return ;
    }
    if(c < tree[rt].c)  //在左子树插入
    {
        //cout << rt << ": " << tree[rt].lc << " - " << tree[rt].rc << endl;
        if(!tree[rt].lc)
        {
            tree[++cnt].c = c;
            tree[rt].lc = cnt;
            //cout << "father: " << rt << endl;
            //cout << "cur: " << tree[rt].lc << " - " << tree[rt].rc << endl;
        }
        else
            addNode(c, tree[rt].lc);
    }
    else    //在右子树插入
    {
        if(!tree[rt].rc)
        {
            tree[++cnt].c = c;
            tree[rt].rc = cnt;
            //cout << "father: " << rt << endl;
            //cout << "cur: " << tree[rt].lc << " - " << tree[rt].rc << endl;
        }
        else
            addNode(c, tree[rt].rc);
    }
}

void print(int rt)
{
    if(!tree[rt].c)
        return ;
    printf("%c", tree[rt].c);
    print(tree[rt].lc);
    print(tree[rt].rc);
}

int main()
{
    while(~scanf("%s", str[0]))
    {
        int n = 0;
        while(str[n][0] >= 'A' && str[n][0] <= 'Z')
            scanf("%s", str[++n]);
        memset(tree, 0, sizeof(tree));
        cnt = 1;
        for(int i = n - 1; i >= 0; i--)
        {
            //cout << i << ": " << str[i] << endl;
            for(int j = 0; j < strlen(str[i]); j++)
                addNode(str[i][j], 1);
        }
        print(1);
        puts("");
        if(str[0][0] == '$')
            break;
    }
    return 0;
}
