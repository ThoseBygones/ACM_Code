/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-04-22
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: POJ
 *  Algorithm: ����ͼ����ƥ��KM�㷨
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

#define MAXN 55

int w[MAXN][MAXN * MAXN];  //�ڽӾ���
int match[MAXN * MAXN], slack[MAXN * MAXN], lx[MAXN], ly[MAXN * MAXN];   //�±��0��ʼ
int visx[MAXN], visy[MAXN * MAXN];
int nx, ny; //���Ҽ��ϵĵ���

bool find(int u)
{
    visx[u] = true;
    for(int i = 0; i < ny; i++)
    {
        if(visy[i])
            continue;
        int t = lx[u] + ly[i] - w[u][i];
        if(!t)
        {
            visy[i] = true;
            if(match[i] == -1 || find(match[i]))
            {
                match[i] = u;
                return true;
            }
        }
        else
            slack[i] = min(slack[i], t);
    }
    return false;
}

bool update()
{
    int d =	INF;
    for(int i = 0; i < ny; i++)
    {
        if(!visy[i])
            d = min(d, slack[i]);
    }
    if(d == INF)
        return false;   //˵���޷�ƥ����
    for(int i = 0; i < nx; i++)
    {
        if(visx[i])
            lx[i] -= d, visx[i] = false;
    }
    for(int i = 0; i < ny; i++)
    {
        if(visy[i])
            ly[i] += d, visy[i] = false;
        else
            slack[i] -= d;
    }
    return true;
}

int km()
{
    memset(match, -1, sizeof(int) * ny);
    memset(ly, 0, sizeof(int) * ny);
    for(int i = 0; i < nx; i++)
    {
        lx[i] = -INF;
        for(int j = 0; j < ny; j++)
            lx[i] = max(lx[i], w[i][j]);
    }
    for(int i = 0; i < nx; i++)
    {
        for(int j = 0; j < ny; j++)
            slack[j] = INF;
        memset(visx, 0, sizeof(int) * nx);
        memset(visy, 0, sizeof(int) * ny);
        while(!find(i))
        {
            if(!update())
                break;  //�޷�ƥ��
        }
    }
    int ans = 0;
    for(int i = 0; i < ny; i++)
    {
        if(match[i] != -1)
            ans += w[match[i]][i];
    }
    return -ans;
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        nx = n;
        ny = n * m; //ÿ̨�������m���㣨��Ӧ�ڲ�ͬʱ�䴦��ͬ����ߣ�
        for(int i = 0; i < n; i++)  //ö�����
        {
            int cnt = 0;
            for(int j = 0; j < m; j++)  //ö�ٻ���
            {
                int cost;
                scanf("%d", &cost);
                for(int k = n; k >= 1; k--) //ö����߱������ʱ�䣨����ɵĶ�Ӧ��kԽ��
                    w[i][cnt++] = - cost * k;
            }
        }
        double ans = 1.0 * km() / n;
        printf("%.6f\n", ans);
    }
    return 0;
}
