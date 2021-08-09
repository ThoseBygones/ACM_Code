/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-08-09
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: UVa
 *  Algorithm: STL list
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

list<char> ls;
char str[MAXN];

int main()
{
    while(~scanf("%s", str))
    {
        int len = strlen(str);
        ls.clear();
        auto it = ls.end();
        for(int i = 0; i < len; i++)
        {
            if(str[i] == '[')
                it = ls.begin();
            else if(str[i] == ']')
                it = ls.end();
            else
            {
                it = ls.insert(it, str[i]);   //在it之前插入
                it++;
            }
        }
        for(auto &ch: ls)
            printf("%c", ch);
        puts("");
    }
    return 0;
}
