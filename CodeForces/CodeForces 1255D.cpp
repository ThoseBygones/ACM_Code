/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-04-08
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
#define MAXN 105

const char ch[63] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

char g[MAXN][MAXN];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int r, c, k;
        scanf("%d%d%d", &r, &c, &k);
        for(int i = 1; i <= r; i++)
            scanf("%s", g[i] + 1);
        int cnt = 0;
        for(int i = 1; i <= r; i++)
        {
            for(int j = 1; j <= c; j++)
            {
                if(g[i][j] == 'R')
                    cnt++;
            }
        }
        int avg = cnt / k, left = cnt % k;  //每只鸡平均获得饲料数；平分后多出的饲料数
        int id = 0, tmp = avg;  //当前分配的鸡编号以及该鸡能获得的饲料数
        if(left)
        {
            left--;
            tmp++;
        }
        for(int i = 1; i <= r; i++)
        {
            if(i & 1)   //奇数行从左往右分配领地
            {
                for(int j = 1; j <= c; j++)
                {
                    if(g[i][j] == 'R')
                    {
                        if(!tmp)    //该鸡的饲料已经分配完毕
                        {
                            id++;
                            //printf("%d %d: %d\n", i, j, id);
                            tmp = avg;
                            if(left)    //饲料取平均数还有余，则多给一个
                            {
                                left--;
                                tmp++;
                            }
                        }
                        tmp--;
                    }
                    g[i][j] = ch[id];

                }
            }
            else
            {
                for(int j = c; j; j--)
                {
                    if(g[i][j] == 'R')
                    {
                        if(!tmp)    //该鸡的饲料已经分配完毕
                        {
                            id++;
                            //printf("%d %d: %d\n", i, j, id);
                            tmp = avg;
                            if(left)
                            {
                                left--;
                                tmp++;
                            }
                        }
                        tmp--;
                    }
                    g[i][j] = ch[id];
                }
            }
        }
        for(int i = 1; i <= r; i++)
            printf("%s\n", g[i] + 1);
    }
    return 0;
}
