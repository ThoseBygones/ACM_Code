/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-04-25
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: POJ
 *  Algorithm: 贪心 + 分治
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

const int MAXN = 8005;

char s[MAXN];
int cnt[30];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%s", s);
        int len = strlen(s);
        int odd = 0;
        memset(cnt, 0, sizeof(cnt));
        for(int i = 0; i < len; i++)
            cnt[s[i] - 'a']++;
        for(int i = 0; i < 26; i++)
        {
            if(cnt[i] & 1)
                odd++;
        }
        if(odd > 1)
            puts("Impossible");
        else
        {
            int ans = 0;
            for(int i = 0, j = len - 1; i < j; i++, j--)
            {
                int l, r;
                for(l = i; l < j; l++)
                {
                    if(s[l] == s[j])
                        break;
                }
                for(r = j; r > i; r--)
                {
                    if(s[r] == s[i])
                        break;
                }
                if(l - i < j - r)   //左边开始交换的方案更优
                {
                    ans += l - i;
                    for(int k = l - 1; k >= i; k--)
                        swap(s[k], s[k + 1]);
                }
                else    //右边开始交换的方案更优
                {
                    ans += j - r;
                    for(int k = r; k < j; k++)
                        swap(s[k], s[k + 1]);
                }
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
