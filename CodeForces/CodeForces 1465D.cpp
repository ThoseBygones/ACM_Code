/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-06-24
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: 贪心 + 思维
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

const int MAXN = 100005;

char s[MAXN];
int pre[2][MAXN], suf[2][MAXN]; //前缀和，后缀和

int main()
{
    scanf("%s", s + 1);
    LL x, y;
    scanf("%lld%lld", &x, &y);
    int n = strlen(s + 1);
    for(int i = 1; i <= n; i++)
    {
        pre[0][i] = pre[0][i - 1] + (s[i] != '1');  //假设所有的问号都是0
        pre[1][i] = pre[1][i - 1] + (s[i] == '1');
    }
    for(int i = n; i; i--)
    {
        suf[0][i] = suf[0][i + 1] + (s[i] != '1');  //假设所有的问号都是0
        suf[1][i] = suf[1][i + 1] + (s[i] == '1');
    }
    /*for(int i = 1; i <= n; i++)
        printf("%d - %d\n", suf[0][i], suf[1][i]);
    */
    LL ans = 0;
    for(int i = 1; i <= n; i++)
    {
        if(s[i] != '1')
            ans += y * pre[1][i - 1];   //10
        else
            ans += x * pre[0][i - 1];   //01
    }
    //printf("-- %lld\n", ans);
    LL tmp = ans;
    if(x > y)   //1尽可能放在前半段，0尽可能放在后半段
    {
        int d0 = 0, d1 = 0; //0和1的增减数
        for(int i = 1; i <= n; i++) //从前往后把问号处改成1
        {
            if(s[i] != '?')
                continue;
            pre[0][i - 1] += d0;
            pre[1][i - 1] += d1;
            tmp += y * (suf[0][i + 1] - pre[1][i - 1]); //10
            tmp += x * (pre[0][i - 1] - suf[1][i + 1]); //01
            d0--, d1++;
            //printf("%lld\n", tmp);
            ans = min(ans, tmp);
        }
    }
    else
    {
        int d0 = 0, d1 = 0; //0和1的增减数
        for(int i = n; i; i--)  //从后往前把问号处改成1
        {
            if(s[i] != '?')
                continue;
            suf[0][i + 1] += d0;
            suf[1][i + 1] += d1;
            //printf("%d - %d\n", suf[0][i + 1], suf[1][i + 1]);
            tmp += y * (suf[0][i + 1] - pre[1][i - 1]); //10
            tmp += x * (pre[0][i - 1] - suf[1][i + 1]); //01
            d0--, d1++;
            //printf("%lld\n", tmp);
            ans = min(ans, tmp);
        }
    }
    printf("%lld\n", ans);
    return 0;
}
