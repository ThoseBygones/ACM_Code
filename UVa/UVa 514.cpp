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

const int MAXN = 1005;

int b[MAXN];

int main()
{
    int n;
    while(~scanf("%d", &n), n)
    {
        stack<int> s;
        while(true)
        {
            scanf("%d", &b[1]);
            if(!b[1])
                break;
            for(int i = 2; i <= n; i++)
                scanf("%d", &b[i]);
            int cnt = 1, id = 1;
            bool flag = true;
            while(id <= n)
            {
                if(cnt == b[id])    //当前入栈序列与出栈序列相同
                    cnt++, id++;
                else if(!s.empty() && s.top() == b[id]) //栈不空且当前入栈序列元素与栈顶元素相同
                {
                    s.pop();
                    id++;
                }
                else if(cnt <= n)   //暂时存在栈中
                    s.push(cnt++);
                else    //无解
                {
                    flag = false;
                    break;
                }
            }
            puts(flag ? "Yes" : "No");
        }
        puts("");
    }
    return 0;
}
