/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-06-05
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

int a[MAXN];
int cnt[MAXN];  //cnt[i]表示第i层还有几个可用结点

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
            cnt[i] = 0;
        }
        cnt[0] = 1;
        int dep = 1;
        for(int i = 1; i < n; i++)
        {
            if(a[i - 1] < a[i])
                cnt[dep]++;
            else
            {
                if(cnt[dep - 1] == 1)
                    cnt[++dep]++;   //准备新开一层
                else
                {
                    cnt[dep - 1]--; //上一层可用结点数量减一
                    cnt[dep]++; //本层可用结点数量加一
                }
            }
        }
        printf("%d\n", dep);
    }
    return 0;
}
