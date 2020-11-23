/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-11-20
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: POJ
 *  Algorithm:
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

const int MAXN = 32005;

struct Person
{
    char dir[2];
    double pos;
    char name[255];
    bool operator < (const Person &p) const
    {
        return pos < p.pos;
    }
} p[MAXN];

int main()
{
    int n;
    while(~scanf("%d", &n), n)
    {
        double l, v;
        scanf("%lf%lf", &l, &v);
        for(int i = 0; i < n; i++)
            scanf("%s%lf%s", p[i].dir, &p[i].pos, p[i].name);
        sort(p, p + n);
        double maxDis = 0.0;
        int rec = 0;
        for(int i = 0; i < n; i++)
        {
            double tmp = 0.0;
            if(p[i].dir[0] == 'P' || p[i].dir[0] == 'p')
                tmp = l - p[i].pos;
            else
                tmp = p[i].pos;
            if(tmp > maxDis)
            {
                maxDis = tmp;
                rec = i;
            }
        }
        int cnt = 0;
        //cout << maxDis << endl;
        printf("%13.2f ", (int)(maxDis / v * 100) / 100.0);
        if(p[rec].dir[0] == 'P' || p[rec].dir[0] == 'p')    //朝坐标轴正方向走
        {
            for(int i = rec + 1; i < n; i++)
            {
                if(p[i].dir[0] == 'N' || p[i].dir[0] == 'n')
                    cnt++;
            }
            printf("%s\n", p[rec + cnt].name);
        }
        else    //朝坐标轴负方向走
        {
            for(int i = 0; i < rec; i++)
            {
                if(p[i].dir[0] == 'P' || p[i].dir[0] == 'p')
                    cnt++;
            }
            printf("%s\n", p[rec - cnt].name);
        }
    }
    return 0;
}
