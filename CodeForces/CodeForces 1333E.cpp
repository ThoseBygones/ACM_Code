/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-05-05
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm: 构造
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

const int MAXN = 505;

int b[MAXN][MAXN];

int main()
{
    int n;
    scanf("%d", &n);
    if(n <= 2)
    {
        puts("-1");
        return 0;
    }
    int cnt = 0;
    for(int k = n; k >= 4; k--) //外围从外往内从小到大蛇形填数
    {
        if(k & 1)   //奇数外层
        {
            int i = 0, j = k;
            while(i < k)
                b[++i][j] = ++cnt;
            j--;
            while(j)
                b[i][j--] = ++cnt;
        }
        else    //偶数外层
        {
            int i = k, j = 0;
            while(j < k)
                b[i][++j] = ++cnt;
            i--;
            while(i)
                b[i--][j] = ++cnt;
        }
    }
    //内层构造3*3的特殊矩阵
    b[1][1] = 2;
    b[1][2] = 1;
    b[1][3] = 9;
    b[2][1] = 4;
    b[2][2] = 6;
    b[2][3] = 5;
    b[3][1] = 3;
    b[3][2] = 8;
    b[3][3] = 7;
    for(int i = 1; i <= 3; i++) //内层3*3的矩阵加上偏移量
    {
        for(int j = 1; j <= 3; j++)
            b[i][j] += cnt;
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
            printf("%d%c", b[i][j], (j == n ? '\n' : ' '));
    }
    return 0;
}
