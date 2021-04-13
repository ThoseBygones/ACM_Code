/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-04-11
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: HDU
 *  Algorithm: �߶��� + ��ɢ�� + ɨ����
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

const int MAXN = 205;

int cov[MAXN << 2];
double x[MAXN << 2];   //��ɢ������
double sum[MAXN << 2];

struct ScanLine //ɨ����
{
    double l, r, h; //��˵㣬�Ҷ˵㣬�߶ȣ�y���꣩
    int flag;   //�ϱ߻����±ߣ�1��ʾ�±ߣ�-1��ʾ�ϱߣ�
    ScanLine() {}
    ScanLine(double l, double r, double h, int flag) : l(l), r(r), h(h), flag(flag) {}
    bool operator < (const ScanLine &l) const
    {
        return h < l.h;
    }
} sl[MAXN];

void pushUp(int l, int r, int rt)   //���ϸ���
{
    if(cov[rt]) //��ǰ�����м���
        sum[rt] = x[r + 1] - x[l];  //�����l��r��Ҫ���ȥ��[l,r+1)���ұգ�
    else if(l == r) //�������غ�
        sum[rt] = 0;
    else
        sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}

void update(int val, int L, int R, int l, int r, int rt)    //�������
{
    if(L <= l && r <= R)
    {
        cov[rt] += val;
        pushUp(l, r, rt);
        return ;
    }
    int mid = (l + r) >> 1;
    if(L <= mid)
        update(val, L, R, lson);
    if(R > mid)
        update(val, L, R, rson);
    pushUp(l, r, rt);
}

int main()
{
    int kase = 1;
    int n;
    while(~scanf("%d", &n), n)
    {
        int cnt = 0;
        double ans = 0.0;
        for(int i = 0; i < n; i++)
        {
            double x1, y1, x2, y2;
            scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
            x[++cnt] = x1;
            sl[cnt] = ScanLine(x1, x2, y1, 1);
            x[++cnt] = x2;
            sl[cnt] = ScanLine(x1, x2, y2, -1);
        }
        sort(x + 1, x + 1 + cnt);
        sort(sl + 1, sl + 1 + cnt);
        int m = unique(x + 1, x + 1 + cnt) - x - 1;   //ȥ��
        //printf("%d\n", cnt);
        memset(cov, 0, sizeof(cov));
        memset(sum, 0, sizeof(sum));
        for(int i = 1; i < cnt; i++)
        {
            //printf("%d: %.2f %.2f\n", i, sl[i].l, sl[i].r);
            int l = lower_bound(x + 1, x + 1 + m, sl[i].l) - x;
            int r = lower_bound(x + 1, x + 1 + m, sl[i].r) - x - 1;
            //printf("%d:%.2f %d:%.2f\n", l, x[l], r, x[r]);
            //printf("%.2f %.2f\n", sl[i].h, sl[i + 1].h);
            update(sl[i].flag, l, r, 1, m, 1);
            ans += (sum[1] * (sl[i + 1].h - sl[i].h));
        }
        printf("Test case #%d\nTotal explored area: %.2f\n\n", kase++, ans);
    }
    return 0;
}
