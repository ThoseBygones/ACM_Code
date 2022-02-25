/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2022-02-25
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: POJ
 *  Algorithm: 哈希
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

const int MAXN = 100005;
const int MOD = 100007;

vector<int> Hash[MOD];
int sf[MAXN][6];

bool cmp(int x, int y)
{
    for(int i = 0; i < 6; i++)
    {
        //printf("> %d\n", i);
        if(sf[x][0] == sf[y][i])
        {
            for(int j = 0; j < 6; j++)  //clockwise
            {
                //printf("%d vs %d\n", sf[x][j], sf[y][(i + j) % 6]);
                if(sf[x][j] != sf[y][(i + j) % 6])
                    break;
                if(j + 1 == 6)
                    return true;
            }
            for(int j = 0; j < 6; j++) //counter-clockwise
            {
                //printf("%d vs %d\n", sf[x][j], sf[y][(6 - j + i) % 6]);
                if(sf[x][j] != sf[y][(6 - j + i) % 6])
                    break;
                if(j + 1 == 6)
                    return true;
            }
        }
    }
    return false;
}

int main()
{
    int n;
    scanf("%d", &n);
    bool same = false;
    for(int i = 0; i < n; i++)
    {
        int sum = 0;
        for(int j = 0; j < 6; j++)
        {
            scanf("%d", &sf[i][j]);
            sum += sf[i][j];
        }
        int key = sum % MOD;
        if(!same)
        {
            if(Hash[key].size())
            {
                //printf("%d: %d\n", i, Hash[key].size());
                for(int j = 0; j < Hash[key].size(); j++)
                {
                    if(cmp(i, Hash[key][j]))
                    {
                        same = true;
                        break;
                    }
                }
            }
            Hash[key].PB(i);
        }
    }
    puts(same ? "Twin snowflakes found." : "No two snowflakes are alike.");
    return 0;
}
