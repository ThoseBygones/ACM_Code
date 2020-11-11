/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-11-11
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: LightOJ
 *  Algorithm: ����ɸ����ŷ������ + ����
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

const int MAXN = 1000005;

bool isprime[MAXN];
int prime[MAXN];
int phi[MAXN];
int phicnt;

void fastEuler()
{
    memset(isprime, true, sizeof(isprime));
    isprime[0] = isprime[1] = false;
    phi[1] = 1;
    phicnt = 0;
    for(int i = 2; i < MAXN; i++)
    {
        if(isprime[i])
        {
            prime[phicnt++] = i;
            phi[i] = i - 1; //��� n = p ^ k �� p Ϊ�������� phi(n) = p ^ k - p ^ (k - 1) = (p - 1) * p ^ (k - 1)
        }
        for(int j = 0; j < phicnt; j++)
        {
            if(i * prime[j] > MAXN)
                break;
            isprime[i * prime[j]] = false;
            if(i % prime[j] == 0)
            {
                phi[i * prime[j]] = phi[i] * prime[j];  //ŷ����������ʽ
                break;
            }
            phi[i * prime[j]] = phi[i] * (prime[j] - 1);
        }
    }
    phi[1] = 0;
    for(int i = 2; i < MAXN; i++)
        phi[i] = max(phi[i], phi[i - 1]);   //��phi����ת��Ϊ�������������з���������
}

int main()
{
    fastEuler();
    int kase = 1;
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        LL ans = 0;
        for(int i = 1; i <= n; i++)
        {
            int x;
            scanf("%d", &x);
            ans += lower_bound(phi, phi + MAXN, x) - phi;
        }
        printf("Case %d: %lld Xukha\n", kase++, ans);
    }
    return 0;
}
