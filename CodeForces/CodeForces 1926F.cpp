/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2025-03-01
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: 位运算（bitmask） + 奇偶分别枚举
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

vector<int> xo, yo, xe, ye;
char g[8][8], h[8][8];

void init()
{
    //可能修改的点范围：1 <= x, y <= 5
    for(int i = 1; i < 6; i++)
    {
        for(int j = 1; j < 6; j++)
        {
            if((i + j) & 1) //分类枚举：坐标和为奇数的点和坐标和为偶数的点分别枚举
                xo.PB(i), yo.PB(j);
            else
                xe.PB(i), ye.PB(j);
        }
    }
}

bool check(int flag)
{
    for(int i = 1; i < 6; i++)
    {
        for(int j = 1; j < 6; j++)
        {
            if((i + j) & 1 ^ flag)  //分类判断：判断坐标和为奇数的点是否全部符合要求时，跳过所有坐标和为偶数的点；反之亦然
                continue;
            if(h[i][j] == 'B' && h[i - 1][j - 1] == 'B' && h[i - 1][j + 1] == 'B' && h[i + 1][j - 1] == 'B' && h[i + 1][j + 1] == 'B')
                return false;
        }
    }
    return true;
}

int main()
{
    init();
    int t;
    scanf("%d", &t);
    while(t--)
    {
        for(int i = 0; i < 7; i++)
            scanf("%s", g[i]);
        int ans0 = xe.size(), ans1 = xo.size(); //坐标和为奇数的点和坐标和为偶数的点集合
        for(int s = 0; s < (1 << xe.size()); s++)   //状态s的每一位表示每个坐标和为偶数的点是否修改（0/1对应修改/不修改），枚举所有修改方案
        {
            for(int i = 0; i < 7; i++)  //复制原始格子以进行修改
            {
                for(int j = 0; j < 7; j++)
                    h[i][j] = g[i][j];
            }
            int cnt = 0;
            for(int i = 0; i < xe.size(); i++)  //枚举状态s中的每一位，对应每个坐标和为偶数的点（共13个）
            {
                if((s & (1 << i)) && h[xe[i]][ye[i]] == 'B')    //该方案中该点计划被修改，且该点可以被修改（是黑色点）
                {
                    //printf("(%d, %d)", xe[i], ye[i]);
                    h[xe[i]][ye[i]] = 'W';
                    cnt++;
                }
            }
            //printf("cnt: %d\n", cnt);
            if(check(0))    //检查针对坐标和为偶数的点的修改结果是否符合要求
                ans0 = min(ans0, cnt);  //统计最少修改次数
        }
        for(int s = 0; s < (1 << xo.size()); s++)   //状态s的每一位表示每个坐标和为奇数的点是否修改（0/1对应修改/不修改），枚举所有修改方案
        {
            for(int i = 0; i < 7; i++)
            {
                for(int j = 0; j < 7; j++)
                    h[i][j] = g[i][j];
            }
            int cnt = 0;
            for(int i = 0; i < xo.size(); i++)  //枚举状态中的每一位
            {
                if((s & (1 << i)) && h[xo[i]][yo[i]] == 'B')    //枚举状态s中的每一位，对应每个坐标和为奇数的点（共12个）
                {
                    //printf("(%d, %d)", x[i], y[i]);
                    h[xo[i]][yo[i]] = 'W';
                    cnt++;
                }
            }
            if(check(1))    //检查针对坐标和为奇数的点的修改结果是否符合要求
                ans1 = min(ans1, cnt);  //统计最少修改次数
        }
        printf("%d\n", ans0 + ans1);
    }
    return 0;
}

/*
1
BBBBBBB
BBBBBBB
BBBBBBB
BBBBBBB
BBBBBBB
BBBBBBB
BBBBBBB
ans: 8

1
BBBBBBB
BBBBBWB
BBBBBBB
BBBBBBB
BBBBBBB
BBBBBBB
BBBBBBB
ans: 7
*/
