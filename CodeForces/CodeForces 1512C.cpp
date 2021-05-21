/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-05-21
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

const int MAXN = 200005;

char s[MAXN];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        scanf("%s", s);
        int n = strlen(s);
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '?')
                s[i] = s[n - i - 1];
        }
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '0')
                a--;
            else if(s[i] == '1')
                b--;
        }
        int l = 0, r = n - 1;
        while(l <= r)
        {
            if(l == r)  //字符串长度为奇数
            {
                if(s[l] == '?')
                {
                    if(a)
                    {
                        s[l] = '0';
                        a--;
                    }
                    else
                    {
                        s[l] = '1';
                        b--;
                    }
                }
            }
            else    //字符串长度为偶数
            {
                if(s[l] == '?' && s[r] == '?')
                {
                    if(a >= 2)
                    {
                        s[l] = s[r] = '0';
                        a -= 2;
                    }
                    else if(b >= 2)
                    {
                        s[l] = s[r] = '1';
                        b -= 2;
                    }
                }
            }
            l++, r--;
        }
        bool flag = true;
        for(int i = 0; i < n / 2; i++)
        {
            if(s[i] != s[n - i - 1])
            {
                flag = false;
                break;
            }
        }
        if(flag && !a && !b)
            printf("%s\n", s);
        else
            puts("-1");
    }
    return 0;
}
