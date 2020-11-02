/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-10-28
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: POJ
 *  Algorithm: ����ö��
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

char h[5][5];
bool s[5][5];   //ÿ������෭תһ�Σ���������壩
PII ans[20];    //�洢��Ҫ��ת�ĵ�

int main()
{
    for(int i = 0; i < 4; i++)
        scanf("%s", h[i]);
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if(h[i][j] == '+')
            {
                s[i][j] ^= 1;   //��һ�α任
                for(int k = 0; k < 4; k++)
                {
                    s[i][k] ^= 1;   //ͬ�еĶ���Ҫһ�α任���ܱ��ԭ��
                    s[k][j] ^= 1;   //ͬ�еĶ���Ҫһ�α任���ܱ��ԭ��
                }
            }
        }
    }
    int cnt = 0;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if(s[i][j])
            {
                ans[cnt].first = i + 1;
                ans[cnt].second = j + 1;
                cnt++;
            }
        }
    }
    printf("%d\n", cnt);
    for(int i = 0; i < cnt; i++)
        printf("%d %d\n", ans[i].first, ans[i].second);
    return 0;
}
