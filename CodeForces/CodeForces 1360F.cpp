/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-06-16
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: 暴力
 ********************************************************************************
 *  Algo-Description:
 ********************************************************************************
 */

#include <bits/stdc++.h>
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

const int MAXN = 15;

char s[MAXN][MAXN];
char s0[MAXN];
int n, m;

bool check()
{
    for(int i = 0; i < n; i++)
    {
        int difcnt = 0;
        for(int j = 0; j < m; j++)
        {
            if(s[i][j] != s0[j])
                difcnt++;
        }
        if(difcnt > 1)  //模板串与其他串不同的字符数超过一个
            return false;
    }
    return true;
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &n, &m);
        for(int i = 0; i < n; i++)
            scanf("%s", s[i]);
        bool flag = false;
        for(int i = 0; i < m; i++)  //枚举模板串的每一位
        {
            for(int j = 0; j < m; j++)
                s0[j] = s[0][j];
            s0[m] = '\0';   //截断字符串
            for(int k = 0; k < 26; k++) //枚举变化后的字符
            {
                s0[i] = 'a' + k;
                if(check())
                {
                    flag = true;
                    break;
                }
            }
            if(flag)
                break;
        }
        if(flag)
            printf("%s\n", s0);
        else
            puts("-1");
    }
    return 0;
}
