/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-01-01
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm:
 ********************************************************************************
 *  Algo-Description:
 ********************************************************************************
 */

#include <bits/stdc++.h>  //For CodeForces only
using namespace std;
template<class T> inline T sqr(T x)
{
    return x * x;
}
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
#define clr(ar,val) memset(ar, val, sizeof(ar))
#define istr stringstream
#define FOR(i,n) for(int i=0;i<(n);++i)
#define forIt(mp,it) for(__typeof(mp.begin()) it = mp.begin();it!=mp.end();it++)
const double EPS = 1e-6;
const int INF = 0x3fffffff;
const LL LINF = INF * 1ll * INF;
const double PI = acos(-1.0);

#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define lowbit(u) (u&(-u))

int a[10][15];  //a[i][0]记录的是一个循环节中最后一位数字的和
int len[10];    //每个循环节的长度

void pre()  //预处理（打表）
{
    len[0] = 1;
    for(int i=1; i<=9; i++)
    {
        int sum = 0;
        for(int j=1; j<=10; j++)
        {
            a[i][j] = i * j % 10;
            sum += a[i][j];
            if(a[i][j] == 0)    //一次循环结束
            {
                len[i] = j;
                a[i][0] = sum;
                break;
            }
        }
    }
}

int main()
{
    pre();
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> q;
    while(q--)
    {
        LL n,m;
        cin >> n >> m;
        LL rd = n / m;
        LL ld = m % 10;
        LL ans = rd / len[ld] * a[ld][0];
        LL ext = n / m % len[ld];
        for(int i=1; i<=ext; i++)
            ans += a[ld][i];
        cout << ans << endl;
    }
    return 0;
}
