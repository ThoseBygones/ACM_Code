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
    int side[6];
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
            scanf("%d", &side[i]);
    }

    void roll(char op)
    {
        if(op == 'E')
        {
            int tmp = side[0];
            side[0] = side[3];
            side[3] = side[5];
            side[5] = side[2];
            side[2] = tmp;
        }
        else if(op == 'N')
        {
            int tmp = side[0];
            side[0] = side[1];
            side[1] = side[5];
            side[5] = side[4];
            side[4] = tmp;
        }
        else if(op == 'S')
        {
            int tmp = side[0];
            side[0] = side[4];
            side[4] = side[5];
            side[5] = side[1];
            side[1] = tmp;
        }
        else if(op == 'W')
        {
            int tmp = side[0];
            side[0] = side[2];
            side[2] = side[5];
            side[5] = side[3];
            side[3] = tmp;
        }
        else if(op == 'R')  //������ת
        {
            int tmp = side[1];
            side[1] = side[2];
            side[2] = side[4];
            side[4] = side[3];
            side[3] = tmp;
        }
    }

    bool checkfront(Dice d)
    {
        if(side[1] == d.side[1])
            return true;
        return false;
    }

    bool checkall(Dice d)
    {
        bool flag = true;
        for(int i = 0; i < 6; i++)
        {
            if(side[i] != d.side[i])
            {
                flag = false;
                break;
            }
        }
        return flag;
    }
} dice1, dice2;

char op[7] = "NRNRNN";

int main()
{
    dice1.init();
    dice2.init();
    /*for(int i = 0; i < 6; i++)
        printf("%d ", dice2.side[i]);
    puts("");*/
    for(int i = 0; i < 6; i++)
    {
        if(dice1.checkfront(dice2))
            break;
        dice1.roll(op[i]);
    }
    bool flag = false;
    for(int i = 0; i < 4; i++)
    {
        /*for(int i = 0; i < 6; i++)
            printf("%d ", dice1.side[i]);
        puts("");*/
        if(dice1.checkall(dice2))
        {
            flag = true;
            break;
        }
        dice1.roll('W');
    }
    puts(flag ? "Yes" : "No");
    return 0;
}
