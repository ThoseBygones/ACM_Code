/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-01-11
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: POJ
 *  Algorithm: ������ + dp
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

const int MAXN = 10005;
const int MAXM = 100005;

int a[MAXN];
bool dp[2][MAXM];    //dp[0/1][i]��ʾi��ʯͷ�ܷ���ż��/�����ſ�Ƭ���

int main()
{
    int n, m;
    while(~scanf("%d%d", &n, &m))
    {
        if(n == 0 && m == 0)
            break;
        for(int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        memset(dp, false, sizeof(dp));
        dp[0][0] = true;    //��ʼ��
        for(int i = 1; i <= n; i++) //ö�ٿ���
        {
            for(int j = m; j >= a[i]; j--)  //ö��ʣ��ʯͷ���������Ʊ������⣩
            {
                if(dp[0][j - a[i]]) //�����ǰ��Ƭ��ȡ��ǰһ״̬��ʯͷ��������ż���ſ�Ƭ���
                    dp[1][j] = true;    //��ǰ������ʯͷ���������ſ�Ƭ���
                if(dp[1][j - a[i]]) //�����ǰ��Ƭ��ȡ��ǰһ״̬��ʯͷ�������������ſ�Ƭ���
                    dp[0][j] = true;    //��ǰ������ʯͷ����ż���ſ�Ƭ���
            }
        }
        int ans = 0;
        for(int i = 1; i <= m; i++)
        {
            if(dp[1][i] && !dp[0][i])   //��������ʯ��ֻ�ܱ������ſ�Ƭ���
                ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}
