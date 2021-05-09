/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-05-08
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
int ans[MAXN];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        scanf("%s", s);
        queue<int> q0, q1;
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '0')
            {
                if(q1.empty())  //没有某个字符串以1结尾
                    ans[i] = ++cnt;
                else
                {
                    int x = q1.front();
                    q1.pop();
                    ans[i] = ans[x];
                }
                q0.push(i);
            }
            else
            {
                if(q0.empty()) //没有某个字符串以0结尾
                    ans[i] = ++cnt;
                else
                {
                    int x = q0.front();
                    q0.pop();
                    ans[i] = ans[x];
                }
                q1.push(i);
            }
        }
        printf("%d\n", cnt);
        for(int i = 0; i < n; i++)
            printf("%d%c", ans[i], (i == n - 1 ? '\n' : ' '));
    }
    return 0;
}
