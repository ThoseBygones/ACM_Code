/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-08-03
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: POJ
 *  Algorithm: STL
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

stack<string> fs, bs;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string com;
    string url = "http://www.acm.org/";
    while(cin >> com && com != "QUIT")
    {
        if(com == "VISIT")
        {
            bs.push(url);
            //cout << "cur: " << url << endl;
            cin >> url;
            cout << url << endl;
            while(!fs.empty())
                fs.pop();
        }
        else if(com == "BACK")
        {
            if(bs.empty())
                cout << "Ignored" << endl;
            else
            {
                fs.push(url);
                url = bs.top();
                bs.pop();
                cout << url << endl;
            }
        }
        else if(com == "FORWARD")
        {
            if(fs.empty())
                cout << "Ignored" << endl;
            else
            {
                bs.push(url);
                url = fs.top();
                fs.pop();
                cout << url << endl;
            }
        }
    }
    return 0;
}
