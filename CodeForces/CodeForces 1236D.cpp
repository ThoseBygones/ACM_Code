/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-03-25
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
#define MAXN 100005

vector<int> row[MAXN], col[MAXN];

int main()
{
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 0; i < k; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        col[x].PB(y);
        row[y].PB(x);
    }
    for(int i = 1; i <= n; i++)
        sort(col[i].begin(), col[i].end());
    for(int i = 1; i <= m; i++)
        sort(row[i].begin(), row[i].end());
    int xmin = 1, xmax = n, ymin = 1, ymax = m; //本次绕圈的左右上下边界：由于每个格子最多只能经过一次；因此实际路径是走一个半径越来越小的方形螺旋线
    int dir = 1;    //娃娃目前面对的方向
    int x = 1, y = 1;   //娃娃当前的坐标
    bool flag = false;  //特判 (x, y) == (1, 1) 时只能向下走的情况
    LL ans = 1;
    while(true)
    {
        int nx, ny;
        if(dir == 1)    //娃娃面朝右方
        {
            //找到比y坐标大的第一个障碍物位置
            nx = x;
            ny = lower_bound(col[x].begin(), col[x].end(), y) - col[x].begin();
            if(ny == col[x].size()) //不存在坐标比y大的障碍物
                ny = ymax;
            else
                ny = min(ymax, col[x][ny] - 1); //避免路径交叉
            xmin = x + 1; //设置x的最小边界
            dir++;
        }
        else if(dir == 2)   //娃娃面朝下方
        {
            //找到比x坐标大的第一个障碍物位置
            nx = lower_bound(row[y].begin(), row[y].end(), x) - row[y].begin();
            ny = y;
            if(nx == row[y].size()) //不存在坐标比x大的障碍物
                nx = xmax;
            else
                nx = min(xmax, row[y][nx] - 1);
            ymax = y - 1;   //设置y的最大边界
            dir++;
        }
        else if(dir == 3)   //娃娃面朝左方
        {
            //找到比y坐标小的第一个障碍物位置
            nx = x;
            ny = lower_bound(col[x].begin(), col[x].end(), y) - col[x].begin()  - 1;
            if(ny < 0)
                ny = ymin;
            else
                ny = max(ymin, col[x][ny] + 1);
            xmax = x - 1;
            dir++;
        }
        else if(dir == 4)   //娃娃面朝上方
        {
            //找到比x坐标小的第一个障碍物位置
            nx = lower_bound(row[y].begin(), row[y].end(), x) - row[y].begin() - 1;
            ny = y;
            if(nx < 0)
                nx = xmin;
            else
                nx = max(xmin, row[y][nx] + 1);
            ymin = y + 1;
            dir = 1;
        }
        if(x == nx && y == ny && flag)  //判断转向后是否未动
            break;
        ans += 1LL * abs(nx - x) + 1LL * abs(ny - y);
        //printf("%d, %d\n", nx, ny);
        x = nx, y = ny; //更新坐标
        flag = true;    //如果还在 (1, 1) 处，允许转向一次（若娃娃已经直走过了，则若转向后还在原处，判定为无路可走）

    }
    //cout << ans << endl;
    if(ans == 1LL * n * m - k)
        puts("Yes");
    else
        puts("No");
    return 0;
}
