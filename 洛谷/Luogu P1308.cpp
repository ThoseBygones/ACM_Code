/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-08-30
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: 洛谷
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

string a, b;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    getline(cin, a, '\n');
    transform(a.begin(), a.end(), a.begin(), ::tolower);
    getline(cin, b, '\n');
    transform(b.begin(), b.end(), b.begin(), ::tolower);
    b.insert(0, " ");
    b += " ";
    //cout << a << endl;
    //cout << b << endl;
    int pos = 0, ans = 0;
    int j;
    for(int i = 1; i < b.length(); i++)
    {
        if(a[0] != b[i])
            continue;
        for(j = 0; j < a.length(); j++)
        {
            if(a[j] != b[i + j])
                break;
        }
        if(j == a.length() && b[i - 1] == ' ' && b[i + j] == ' ')
        {
            ans++;
            if(ans == 1)
                pos = i;
        }
    }
    if(ans)
        cout << ans << " " << pos - 1 << endl;
    else
        cout << "-1" << endl;
    return 0;
}
