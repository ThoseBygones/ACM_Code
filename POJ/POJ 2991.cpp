/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-11-25
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: POJ
 *  Algorithm: �߶��� + ���㼸�Σ�������ת��
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

int a[MAXN];
int deg[MAXN];  //deg[i]��ʾ��i���߶�����ڵ�i-1���߶���ת�˶��ٽǶ�

struct Node
{
    double x, y;
    int lazy;
    Node() {}
    Node(double x, double y) : x(x), y(y) {}

    void rotate(int val)    //������ת
    {
        double rad = PI * val / 180.0;
        double tx = x * cos(rad) - y * sin(rad);
        double ty = x * sin(rad) + y * cos(rad);
        x = tx, y = ty;
    }

    void print()
    {
        printf("%.2f %.2f\n", x, y);
    }
} tree[MAXN << 2];

void pushUp(int rt)
{
    tree[rt].x = tree[rt << 1].x + tree[rt << 1 | 1].x;
    tree[rt].y = tree[rt << 1].y + tree[rt << 1 | 1].y;
}

void build(int l, int r, int rt)    //����
{
    tree[rt].x = tree[rt].y = tree[rt].lazy = 0;
    if(l == r)
    {
        tree[rt].y = a[l];
        return ;
    }
    int mid = (l + r) >> 1;
    build(lson);
    build(rson);
    pushUp(rt);
}

void pushDown(int rt)   //������´�
{
    if(tree[rt].lazy)
    {
        tree[rt << 1].rotate(tree[rt].lazy);
        tree[rt << 1 | 1].rotate(tree[rt].lazy);
        tree[rt << 1].lazy += tree[rt].lazy;
        tree[rt << 1 | 1].lazy += tree[rt].lazy;
        tree[rt].lazy = 0;
    }
}

void update(int val, int L, int R, int l, int r, int rt)    //�������
{
    if(L <= l && r <= R)
    {
        tree[rt].rotate(val);
        tree[rt].lazy += val;
        return ;
    }
    int mid = (l + r) >> 1;
    pushDown(rt);
    if(L <= mid)
        update(val, L, R, lson);
    if(R > mid)
        update(val, L, R, rson);
    pushUp(rt);
}

int main()
{
    int n, k;
    while(~scanf("%d%d", &n, &k))
    {
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            deg[i] = 180;   //��ʼ��ǰһ�������ļн�Ϊ180
        }
        build(1, n, 1);
        for(int i = 0; i < k; i++)
        {
            int s, rad;
            scanf("%d%d", &s, &rad);
            int d = rad - deg[s];   //������Լ���ת�ĽǶ�Ϊrad-deg[s]
            deg[s] = rad;   //��ǰһ�������ļн��޸�Ϊrad
            update(d, s + 1, n, 1, n, 1);   //�ĵ��ǵ�s+1��֮�������ĽǶ�
            tree[1].print();
        }
        puts("");
    }
    return 0;
}
