/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-09-15
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: AOJ
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

struct Dice
{
    PII side[6];
    /*
    side[0]: top
    side[1]: front
    side[2]: right
    side[3]: left
    side[4]: back
    side[5]: bottom
    */
    void init()
    {
        for(int i = 0; i < 6; i++)
        {
            side[i].first = i + 1;
            scanf("%d", &side[i].second);
        }
    }

    void check(int t, int f)
    {
        if(side[0].second == t && side[1].second == f)  //top: 1, front: 2, right: 3
            printf("%d\n", side[2].second);
        else if(side[0].second == t && side[2].second == f) //top: 1, front: 3, right: 5
            printf("%d\n", side[4].second);
        else if(side[0].second == t && side[4].second == f) //top: 1, front: 5, right: 4
            printf("%d\n", side[3].second);
        else if(side[0].second == t && side[3].second == f) //top: 1, front: 4, right: 2
            printf("%d\n", side[1].second);
        else if(side[1].second == t && side[0].second == f) //top: 2, front: 1, right: 4
            printf("%d\n", side[3].second);
        else if(side[1].second == t && side[3].second == f) //top: 2, front: 4, right: 6
            printf("%d\n", side[5].second);
        else if(side[1].second == t && side[5].second == f) //top: 2, front: 6, right: 3
            printf("%d\n", side[2].second);
        else if(side[1].second == t && side[2].second == f) //top: 2, front: 3, right: 1
            printf("%d\n", side[0].second);
        else if(side[2].second == t && side[0].second == f) //top: 3, front: 1, right: 2
            printf("%d\n", side[1].second);
        else if(side[2].second == t && side[1].second == f) //top: 3, front: 2, right: 6
            printf("%d\n", side[5].second);
        else if(side[2].second == t && side[5].second == f) //top: 3, front: 6, right: 5
            printf("%d\n", side[4].second);
        else if(side[2].second == t && side[4].second == f) //top: 3, front: 5, right: 1
            printf("%d\n", side[0].second);
        else if(side[3].second == t && side[0].second == f) //top: 4, front: 1, right: 5
            printf("%d\n", side[4].second);
        else if(side[3].second == t && side[4].second == f) //top: 4, front: 5, right: 6
            printf("%d\n", side[5].second);
        else if(side[3].second == t && side[5].second == f) //top: 4, front: 6, right: 2
            printf("%d\n", side[1].second);
        else if(side[3].second == t && side[1].second == f) //top: 4, front: 2, right: 1
            printf("%d\n", side[0].second);
        else if(side[4].second == t && side[0].second == f) //top: 5, front: 1, right: 3
            printf("%d\n", side[2].second);
        else if(side[4].second == t && side[2].second == f) //top: 5, front: 3, right: 6
            printf("%d\n", side[5].second);
        else if(side[4].second == t && side[5].second == f) //top: 5, front: 6, right: 4
            printf("%d\n", side[3].second);
        else if(side[4].second == t && side[3].second == f) //top: 5, front: 4, right: 1
            printf("%d\n", side[0].second);
        else if(side[5].second == t && side[1].second == f) //top: 6, front: 2, right: 4
            printf("%d\n", side[3].second);
        else if(side[5].second == t && side[3].second == f) //top: 6, front: 4, right: 5
            printf("%d\n", side[4].second);
        else if(side[5].second == t && side[4].second == f) //top: 6, front: 5, right: 3
            printf("%d\n", side[2].second);
        else if(side[5].second == t && side[2].second == f) //top: 6, front: 3, right: 2
            printf("%d\n", side[1].second);
    }
} dice;

int main()
{
    dice.init();
    int q;
    scanf("%d", &q);
    while(q--)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        dice.check(x, y);
    }
    return 0;
}
