/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2025-03-04
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm:
 ********************************************************************************
 *  Algo-Description:
 ********************************************************************************
 */

#include <bits/stdc++.h>
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
const double EPS = 1e-6;
const int INF = 0x3fffffff;
const LL LINF = INF * 1ll * INF;
const double PI = acos(-1.0);

#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define lowbit(u) (u&(-u))

const int MAXN = 200005;

char s[MAXN];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d%s", &n, s);
        for(int len = 1; len <= n; len++)
        {
            //printf("=>%d\n", len);
            bool flag = true;
            if(n % len) //不能被整除直接排除
                continue;
            int cnt = 0;    //前缀段和后缀段不同的字母数量
            for(int i = 0; i < len; i++)
            {
                if(s[i] != s[n - len + i])
                    cnt++;
                if(cnt > 1)
                {
                    flag = false;
                    break;
                }
            }
            if(!flag)
                continue;
            int dif1 = 0, dif2 = 0;
            for(int i = len; i < n - len; i++)
            {
                dif1 += (s[i] != s[(i - len) % len]);   //全部改成跟前缀段相同需要修改的次数
                dif2 += (s[i] != s[i % len + (n - len)]);   //全部改成跟后缀段相同需要修改的次数
                //printf("%d vs. %d\n", dif1, dif2);
                int dif = min(dif1, dif2) + cnt;
                if(dif > 1)
                {
                    flag = false;
                    break;
                }
            }
            if(flag)
            {
                printf("%d\n", len);
                break;
            }
        }
    }
    return 0;
}
