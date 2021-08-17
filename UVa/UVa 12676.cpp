/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-08-17
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: UVa
 *  Algorithm: 逆哈夫曼编码
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

const int MAXN = 55;

vector<LL> dep[MAXN];

int main()
{
    int n;
    while(~scanf("%d", &n))
    {
        for(int i = 0; i < n; i++)
            dep[i].clear();
        int maxd = 0;   //最大深度
        for(int i = 0; i < n; i++)
        {
            int d;
            scanf("%d", &d);
            maxd = max(maxd, d);
            dep[d].PB(0);
        }
        LL val = 1;
        for(int i = maxd; i; i--)   //从最深一层开始往上合并计算
        {
            for(int j = 0; j < dep[i].size(); j++)
            {
                if(!dep[i][j])
                    dep[i][j] = val;
            }
            //sort(dep[i].begin(), dep[i].end());
            for(int j = 0; j < dep[i].size(); j += 2)   //两两合并后计入上一层的结点
                dep[i - 1].PB(dep[i][j] + dep[i][j + 1]);
            val = *max_element(dep[i].begin(), dep[i].end());
            //*dep[i].rbegin(); //上一层结点的权值至少为这一层权值最大结点的权值
        }
        printf("%lld\n", dep[0][0]);    //输出根结点的权值
    }
    return 0;
}

/*
2
1 1
4
2 2 2 2
10
8 2 4 7 5 1 6 9 3 9
*/
