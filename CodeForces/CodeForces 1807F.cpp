/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2025-01-22
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

const int MAXN = 25005;

map<int, int> cnt[MAXN];
int n, m;

bool inRoom(int x, int y)
{
    if(x >= 1 && x <= n && y >= 1 && y <= m)
        return true;
    return false;
}

bool atCorner(int x, int y)
{
    if((x == 1 || x == n) && (y == 1 || y == m))
        return true;
    return false;
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int x, y, u, v;
        char d[3];
        scanf("%d%d%d%d%d%d%s", &n, &m, &x, &y, &u, &v, d);
        bool ok = false;
        int ans = 0;
        for(int i = 0; i <= n; i++)
            cnt[i].clear();
        int dx = 0, dy = 0;
        if(strcmp(d, "DR") == 0)
            dx = 1, dy = 1;
        else if(strcmp(d, "DL") == 0)
            dx = 1, dy = -1;
        else if(strcmp(d, "UR") == 0)
            dx = -1, dy = 1;
        else if(strcmp(d, "UL") == 0)
            dx = -1, dy = -1;
        while(true)
        {
            //printf("(%d, %d) -> ", x, y);
            if(x == u && y == v)
            {
                ok = true;
                break;
            }
            int nx = x + dx, ny = y + dy;
            if(!inRoom(nx, ny))
            {
                /*if(atCorner(x, y))  //At corner
                {
                    ans++;
                    dx = -dx, dy = -dy;
                }*/
                if(nx < 1 || nx > n)   //At x-axis edge
                    dx = -dx;
                if(ny < 1 || ny > m)   //At y-axis edge
                    dy = -dy;
                ans++;
                nx = x + dx, ny = y + dy;
            }
            cnt[x][y]++;
            if(cnt[x][y] > 4)   //每个点（非边缘点）最多从四个方向各经过一次（共4次），如果超过4次必定可以判定死循环
                break;
            x = nx, y = ny;
        }
        if(ok)
            printf("%d\n", ans);
        else
            puts("-1");
    }
    return 0;
}
