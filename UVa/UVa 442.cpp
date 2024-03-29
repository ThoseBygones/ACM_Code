/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-08-09
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: UVa
 *  Algorithm: 栈
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

const int MAXN = 30;

stack<PII> s;
PII mat[30];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    char alp;
    for(int i = 0; i < n; i++)
    {
        cin >> alp;
        int num = alp - 'A';
        cin >> mat[num].first >> mat[num].second;
    }
    string str;
    while(cin >> str)
    {
        bool flag = true;
        int ans = 0;
        for(int i = 0; i < str.length(); i++)
        {
            if(str[i] >= 'A' && str[i] <= 'Z')
                s.push(mat[str[i] - 'A']);
            else if(str[i] == ')')
            {
                PII mat2 = s.top();
                s.pop();
                PII mat1 = s.top();
                s.pop();
                if(mat1.second != mat2.first)   //矩阵A的第二维与矩阵B的第一维不同，无法相乘
                {
                    flag = false;
                    break;
                }
                ans += mat1.first * mat1.second * mat2.second;
                s.push(MP(mat1.first, mat2.second));
            }
        }
        if(flag)
            cout << ans << endl;
        else
            cout << "error" << endl;
    }
    return 0;
}
