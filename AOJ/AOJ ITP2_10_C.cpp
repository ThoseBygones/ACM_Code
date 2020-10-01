/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-09-30
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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    bitset<64> a(0);
    int q;
    cin >> q;
    while(q--)
    {
        int op, x;
        cin >> op;
        if(op == 0)
        {
            cin >> x;
            cout << a.test(x) << endl;
        }
        else if(op == 1)
        {
            cin >> x;
            a.set(x);
        }
        else if(op == 2)
        {
            cin >> x;
            a.reset(x);
        }
        else if(op == 3)
        {
            cin >> x;
            a.flip(x);
        }
        else if(op == 4)
            cout << a.all() << endl;
        else if(op == 5)
            cout << a.any() << endl;
        else if(op == 6)
            cout << a.none() << endl;
        else if(op == 7)
            cout << a.count() << endl;
        else if(op == 8)
            cout << a.to_ullong() << endl;
    }
    return 0;
}
