/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-04-14
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: POJ
 *  Algorithm: ��״���� + ɨ����
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

const int MAXN = 100005;

struct Node
{
    int x, y;
    Node() {}
    Node(int x, int y) : x(x), y(y) {}
    bool operator < (const Node &nd) const
    {
        if(x == nd.x)
            return y < nd.y;
        return x < nd.x;
    }
} p[MAXN];

int bit[MAXN];  //ͳ��ƽ����x���ˮƽɨ�����Ϻڵ�����
int y[MAXN];    //��ɢ��x����
int ml[MAXN], mh[MAXN]; //��ɢ�����ɨ�����������ˣ����º����϶ˣ��ĵ�

void add(int i, int x)
{
    while(i < MAXN)   //MaxVal������ֵ�����ֵ����������Ĵ�С
    {
        bit[i] += x;
        i += lowbit(i);
    }
}

int getsum(int i)
{
    int sum = 0;
    while(i > 0)
    {
        sum += bit[i];
        i -= lowbit(i);
    }
    return sum;
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d%d", &p[i].x, &p[i].y);
        y[i] = p[i].y;
    }
    sort(y + 1, y + 1 + n);
    sort(p + 1, p + 1 + n);
    int cnt = unique(y + 1, y + 1 + n) - y - 1;
    for(int i = 1; i <= n; i++)
        p[i].y = lower_bound(y + 1, y + 1 + cnt, p[i].y) - y;
    for(int i = 1; i <= n; i++)
    {
        ml[i] = INF;
        mh[i] = -INF;
    }
    for(int i = 1; i <= n; i++)
    {
        if(ml[p[i].y] == INF)   //����x�����Ѿ�������˸�ɨ���������·��ĵ����ʼ��һ��
            ml[p[i].y] = p[i].x;
        mh[p[i].y] = p[i].x;    //��¼��ɨ���������Ϸ��ĵ�
    }
    LL ans = 0;
    int i = 1;
    while(i <= n)
    {
        int l = INF, r = -INF;
        int x = p[i].x;
        int j = i;
        while(i <= n && p[i].x == x)    //x������ͬ����ͬһˮƽɨ�����ϣ��ĵ�
        {
            l = min(l, p[i].y);
            r = max(r, p[i].y);
            if(x == ml[p[i].y]) //������״�����ͳ�Ʒ�ʽ������ߵ�ֵ��+1
                add(p[i].y, 1);
            i++;
        }
        ans += getsum(r) - getsum(l - 1);
        while(j < i)
        {
            if(x == mh[p[j].y]) //������״�����ͳ�Ʒ�ʽ�����ұߵ�ֵ��-1
                add(p[j].y, -1);
            j++;
        }
    }
    printf("%lld\n", ans);
    return 0;
}

/*
7
0 1
1 0
2 1
1 2
0 4
2 4
1 5
ans: 9
*/
