/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-06-22
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

const int MAXN = 400010;

vector<int> a, b;
bool vis[MAXN];
int n;

bool checkMax(int val)
{
    for(int i = 0; i < val; i++)
    {
        if(b[i] > a[n - val + i])   //实际x的数量小于mid
            return false;
    }
    return true;
}

bool checkMin(int val)
{
    for(int i = val; i < n; i++)
    {
        if(b[i] < a[i - val])   //实际x的数量大于mid
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
        scanf("%d", &n);
        for(int i = 1; i <= 2 * n; i++)
            vis[i] = false;
        a.clear(), b.clear();
        for(int i = 1; i <= n; i++)
        {
            int x;
            scanf("%d", &x);
            vis[x] = true;
        }
        for(int i = 1; i <= 2 * n; i++)
        {
            if(vis[i])
                b.PB(i);
            else
                a.PB(i);
        }
        /*for(int i = 0; i < n; i++)
            printf("%d ", b[i]);
        puts("");
        */
        int ansl = n, ansr = n;
        int l = 0, r = n;
        while(l <= r)  //二分求得最小的x
        {
            int mid = (l + r) >> 1;
            if(checkMin(mid))
            {
                ansl = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        l = 0, r = n;
        while(l <= r)  //二分求得最大的x
        {
            int mid = (l + r) >> 1;
            if(checkMax(mid))
            {
                ansr = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        //printf("%d - %d\n", ansl, ansr);
        printf("%d\n", ansr - ansl + 1);
    }
    return 0;
}
