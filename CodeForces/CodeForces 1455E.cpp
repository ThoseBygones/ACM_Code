/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-06-16
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: 枚举 + 计算几何 + 全排列
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

struct Point
{
    int x, y;
    Point() {}
    Point(int x, int y) : x(x), y(y) {}

    void read()
    {
        scanf("%d%d", &x, &y);
    }
} p[4];

int a[4] = {0, 1, 2, 3};

LL solve()
{
    Point ptl = p[a[0]];    //左上角的点
    Point ptr = p[a[1]];    //右上角的点
    Point pbl = p[a[2]];    //左下角的点
    Point pbr = p[a[3]];    //右下角的点
    int xmin = abs(max(ptl.x, pbl.x) - min(ptr.x, pbr.x));  //平行于x轴边的最小边长
    int xmax = abs(min(ptl.x, pbl.x) - max(ptr.x, pbr.x));  //平行于x轴边的最大边长
    int ymin = abs(max(ptl.y, ptr.y) - min(pbl.y, pbr.y));  //平行于y轴边的最小边长
    int ymax = abs(min(ptl.y, ptr.y) - max(pbl.y, pbr.y));  //平行于y轴边的最大边长
    LL ans = 2LL * max(0, max(xmin, ymin) - min(xmax, ymax));    //向最小的最大边规整
    //LL ans = 2LL * abs(min(0, min(xmax, ymax) - max(xmin, ymin)));    //向最大的最小边规整
    ans += max(ptl.x, pbl.x) - min(ptl.x, pbl.x);   //移动使左上角和左下角的点x坐标相同
    ans += max(ptr.x, pbr.x) - min(ptr.x, pbr.x);   //移动使右上角和右下角的点x坐标相同
    ans += max(ptl.y, ptr.y) - min(ptl.y, ptr.y);   //移动使左上角和右上角的点y坐标相同
    ans += max(pbl.y, pbr.y) - min(pbl.y, pbr.y);   //移动使左下角和右下角的点y坐标相同
    return ans;
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        for(int i = 0; i < 4; i++)
            p[i].read();
        LL ans = LINF;
        do
        {
            ans = min(ans, solve());
        } while(next_permutation(a, a + 4));
        printf("%d\n", ans);
    }
    return 0;
}
